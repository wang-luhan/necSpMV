#include <cuda.h>
#include <cuda_runtime.h>
#include <spmv_cuda.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cuda_timer.h"

#define test_iter 2000

#define threadsPerBlock 256
#define sizeSharedMemory 1024
#define BlockDim 1024

template <unsigned int threads_per_row>
__device__ __forceinline__ float warpReduceSum(float sum)
{
    if (threads_per_row >= 32)
        sum += __shfl_down_sync(0xffffffff, sum, 16); // 0-16, 1-17, 2-18, etc.
    if (threads_per_row >= 16)
        sum += __shfl_down_sync(0xffffffff, sum, 8); // 0-8, 1-9, 2-10, etc.
    if (threads_per_row >= 8)
        sum += __shfl_down_sync(0xffffffff, sum, 4); // 0-4, 1-5, 2-6, etc.
    if (threads_per_row >= 4)
        sum += __shfl_down_sync(0xffffffff, sum, 2); // 0-2, 1-3, 4-6, 5-7, etc.
    if (threads_per_row >= 2)
        sum += __shfl_down_sync(0xffffffff, sum, 1); // 0-1, 2-3, 4-5, etc.
    return sum;
}

template <typename T>
__global__ void spmv_pcsr_kernel1(T *d_val, T *d_vector, perfSpB_index *d_cols, perfSpB_index d_nnz, T *d_middle)
{
    perfSpB_index tid = blockIdx.x * blockDim.x + threadIdx.x;
    perfSpB_index icr = blockDim.x * gridDim.x;
    while (tid < d_nnz)
    {
        d_middle[tid] = d_val[tid] * d_vector[d_cols[tid]];
        tid += icr;
    }
}
template <typename T, unsigned int ROWS_PER_BLOCK, unsigned int THREADS_PER_ROW>
__global__ void spmv_pcsr_kernel2(T *d_middle, perfSpB_index *d_ptr, perfSpB_index nrows, T *d_out)
{
    int gid = blockIdx.x * blockDim.x + threadIdx.x;
    int tid = threadIdx.x;
    int b_0_row_id = (blockIdx.x * blockDim.x) / THREADS_PER_ROW;
    int thread_lane = threadIdx.x & (THREADS_PER_ROW - 1);
    perfSpB_index g_rowid = gid / THREADS_PER_ROW;

    __shared__ volatile T middle_s[sizeSharedMemory];
    int b_last_row_id = (b_0_row_id + ROWS_PER_BLOCK) > (nrows) ? (nrows) : (b_0_row_id + ROWS_PER_BLOCK);

    perfSpB_index temp = (d_ptr[b_last_row_id] - d_ptr[b_0_row_id]) / threadsPerBlock + 1;
    perfSpB_index nlen = min(perfSpB_index(temp * threadsPerBlock), perfSpB_index(sizeSharedMemory));
    T sum = 0, sum_tmp = 0;
    perfSpB_index maxlen = d_ptr[b_last_row_id];
    if (blockIdx.x == gridDim.x) 
        maxlen = d_ptr[nrows + 1];

    // 使用循环分多次加载 d_middle 到共享内存 middle_s[],每次加载量为 nlen
    if (g_rowid < nrows)
    {
        for (perfSpB_index i = d_ptr[b_0_row_id]; i < maxlen; i += nlen)
        {
            perfSpB_index index = i + tid;
            __syncthreads();
            // Load d_middle into the shared memory middle_s, 填满一个1024需要几次迭代 256×4=1024
            for (perfSpB_index j = 0; j < nlen / threadsPerBlock; j++)
            {
                if (index < maxlen)
                {
                    middle_s[tid + j * threadsPerBlock] = d_middle[index];
                    index += threadsPerBlock;
                }
            }
            __syncthreads();
            // 填满了一个1024，计算这个1024
            //  Sum up the elements for a row
            //TODO: ↓  最后一块 出  bug 
            sum_tmp = 0;
            if (d_ptr[g_rowid + 1] > i && d_ptr[g_rowid] <= i + nlen - 1)//一行的元素 有一点落在1024中就计算
            {
                perfSpB_index row_s = max(perfSpB_index(d_ptr[g_rowid] - i), perfSpB_index(0));
                perfSpB_index row_e = min(perfSpB_index(d_ptr[g_rowid + 1] - i), perfSpB_index(nlen));
                for (perfSpB_index j = row_s + thread_lane; j < row_e; j += THREADS_PER_ROW)
                {
                    sum_tmp += middle_s[j];
                }
                sum_tmp = warpReduceSum<THREADS_PER_ROW>(sum_tmp);
                sum += sum_tmp;
            }
        }
        // Write result
        if (thread_lane == 0)
        {
            d_out[g_rowid] = sum;
        }
    }
}

perfSpB_info perfSpB_SpMV_PCSR_W_FP32(perfSpB_operation_t op,
                                      const void *alpha,
                                      const perfSpB_matrix matA,
                                      const perfSpB_vector vecX,
                                      const void *beta,
                                      perfSpB_vector vecY)
{
    UNUSED(op);
    UNUSED(alpha);
    UNUSED(beta);
    perfSpB_vector_Dense *vecY_csr = (perfSpB_vector_Dense *)(vecY);
    perfSpB_vector_Dense *vecX_csr = (perfSpB_vector_Dense *)(vecX);
    perfSpB_matrix_CSC_or_CSR *matA_csr = (perfSpB_matrix_CSC_or_CSR *)(matA);
    float *d_vecY_csr, *d_vecX_csr, *d_val, *d_v;
    perfSpB_index *d_indices, *d_ptr;

    cudaMalloc(&d_vecY_csr, sizeof(float) * vecY->n);
    cudaMalloc(&d_vecX_csr, sizeof(float) * vecX->n);
    cudaMalloc(&d_val, sizeof(float) * matA_csr->nnz);
    cudaMalloc(&d_v, sizeof(float) * matA_csr->nnz);
    cudaMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
    cudaMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

    cudaMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, cudaMemcpyHostToDevice);
    const int THREADS_PER_ROW = 32;
    const unsigned int ROWS_PER_BLOCK = 8;
    const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (ROWS_PER_BLOCK - 1)) / ROWS_PER_BLOCK);
    cuda_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        spmv_pcsr_kernel1<float><<<ceil(matA_csr->nnz / (float)BlockDim), BlockDim>>>(d_val, d_vecX_csr, d_indices, matA_csr->nnz, d_v);
        spmv_pcsr_kernel2<float, ROWS_PER_BLOCK, THREADS_PER_ROW><<<NUM_BLOCKS, threadsPerBlock>>>(d_v, d_ptr, vecY->n, d_vecY_csr);
    }
    cuda_time_test_end();
    double runtime1 = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime1 / 1000) * 1e9);

    // cuda_time_test_start();
    // for (int i = 0; i < test_iter; i++)
    // {
    //     // spmv_pcsr_kernel1<float><<<ceil(matA_csr->nnz / (float)BlockDim), BlockDim>>>(d_val, d_vecX_csr, d_indices, matA_csr->nnz, d_v);
    // 	spmv_pcsr_kernel2<float><<<ceil(vecY->n / (float)threadsPerBlock), threadsPerBlock>>>(d_v, d_ptr, vecY->n, d_vecY_csr);
    // }
    // cuda_time_test_end();
    // double runtime2 = (elapsedTime) / test_iter;

    cudaDeviceSynchronize();
    printf("\n SpMV CUDA kernel1 runtime = %g ms\n", runtime1);
    // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
    printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);

    cudaMemcpy(((float *)vecY_csr->values), d_vecY_csr, sizeof(float) * vecY->n, cudaMemcpyDeviceToHost);

    cudaError_t cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess)
    {
        printf("Error:%s\n", cudaGetErrorString(cudaStatus));
        exit(EXIT_FAILURE);
    }
    cudaFree(d_vecY_csr);
    cudaFree(d_vecX_csr);
    cudaFree(d_val);
    cudaFree(d_indices);
    cudaFree(d_ptr);

    return perfSpB_success;
}
