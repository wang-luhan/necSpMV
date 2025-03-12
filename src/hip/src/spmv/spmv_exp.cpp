#include "hip/hip_runtime.h"
#include <hip/hip_runtime.h>
#include <hip/hip_runtime.h>
#include "spmv_hip.h"
#include "hip_timer.h"

#define test_iter 2000

__global__ void expanded_product_kernel(const perfSpB_index *__restrict__ A_col_index,
                                        const float *elem,
                                        const float *__restrict__ x,
                                        perfSpB_index num_nz,
                                        float *middle)
{
    unsigned int elem_idx = blockIdx.x * blockDim.x + threadIdx.x;
    // __shared__ float v_exp_cache[1024];
    // if (elem_idx < num_nz)
    // {
    //     v_exp_cache[threadIdx.x] = x[A_col_index[elem_idx]];
    // }
    // __syncthreads();
    if (elem_idx < num_nz)
    {
        // middle[elem_idx] = elem[elem_idx] * v_exp_cache[threadIdx.x];
        middle[elem_idx] = elem[elem_idx] * x[A_col_index[elem_idx]];
    }
}

// 一个线程一个row
#define NUM_THREAD_PER_BLOCK 512
#define num_loads_per_thread 24
#define SHARED_MID_PER_BLOCK 6144

__global__ void summation_kernel(const perfSpB_index *rowptr,
                                 float *middle, const perfSpB_index num_row, const perfSpB_index num_nz, float *p)
{
    __shared__ float middle_cache[SHARED_MID_PER_BLOCK];
    __shared__ unsigned int num_nz_before;
    unsigned int thread_begin = blockIdx.x * blockDim.x; // 所在当前块的第0个线程
    if (threadIdx.x == 0)
        num_nz_before = rowptr[thread_begin] / 16 * 16; // 当前块之前的块共有多少元素elem，对齐16
    __syncthreads();
    unsigned int elem_idx, cache_idx;
    // 协调一个区块中的线程共同将数据加载到共享内存中
    for (int i = 0; i < num_loads_per_thread; i++)
    {
        cache_idx = i * NUM_THREAD_PER_BLOCK + threadIdx.x; // 0~24,576    cache内id
        elem_idx = num_nz_before + cache_idx;
        if (cache_idx < SHARED_MID_PER_BLOCK && elem_idx < num_nz)
            middle_cache[cache_idx] = middle[elem_idx]; // 每2048行的行块只存24,576个
    }
    __syncthreads();
    // summation
    unsigned int row = thread_begin + threadIdx.x;
    if (row < num_row)
    {
        float sum = 0.0;
        unsigned int row_begin = rowptr[row];
        unsigned int row_end = rowptr[row + 1];
        for (unsigned int i = row_begin; i < row_end; i++) // 一个线程处理当前行的i个非零元
        {
            if (i >= num_nz_before && (cache_idx = i - num_nz_before) < SHARED_MID_PER_BLOCK) // 如果数据已经缓存在共享内存中
                sum += middle_cache[cache_idx];
            else
                sum += middle[i];
        }
        p[row] = sum;
    }
}

perfSpB_info perfSpB_SpMV_EDA_FP32(perfSpB_operation_t op,
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
    float *d_vecY_csr, *d_vecX_csr, *d_val, *d_middle;
    perfSpB_index *d_indices, *d_ptr;
    for (int i = 0; i < matA->row; i++)
    {
        if (*((float *)vecY_csr->values) != 0)
        {
            printf("\n %f \n", *((float *)vecY_csr->values));
        }
    }

    hipMalloc(&d_vecY_csr, sizeof(float) * vecY->n);
    hipMalloc(&d_vecX_csr, sizeof(float) * vecX->n);
    // hipMalloc(&d_vecX_exp, sizeof(float) * matA_csr->nnz);
    hipMalloc(&d_middle, sizeof(float) * matA_csr->nnz);
    hipMalloc(&d_val, sizeof(float) * matA_csr->nnz);
    hipMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
    hipMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

    hipMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, hipMemcpyHostToDevice);
    hipMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, hipMemcpyHostToDevice);
    hipMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), hipMemcpyHostToDevice);
    hipMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, hipMemcpyHostToDevice);
    // hipMemcpy(d_vecY_csr, ((float *)vecY_csr->values), sizeof(float) * vecY->n, hipMemcpyHostToDevice);
    // hipMemset(d_vecX_exp, 0.0, sizeof(float) * (matA_csr->nnz));
    hipMemset(d_middle, 0.0, sizeof(float) * (matA_csr->nnz));
    const unsigned int NUM_BLOCKS = static_cast<unsigned int>((matA_csr->nnz + (1024 - 1)) / 1024);
    const unsigned int NUM_BLOCKS1 = static_cast<unsigned int>((vecY->n + (NUM_THREAD_PER_BLOCK - 1)) / NUM_THREAD_PER_BLOCK);
    hipLaunchKernelGGL(expanded_product_kernel, dim3(NUM_BLOCKS), dim3(1024), 0, 0, d_indices, d_val, d_vecX_csr, matA_csr->nnz, d_middle);
    hip_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        
        hipLaunchKernelGGL(summation_kernel, dim3(NUM_BLOCKS1), dim3(NUM_THREAD_PER_BLOCK), 0, 0, d_ptr, d_middle, vecY->n, matA_csr->nnz, d_vecY_csr);
    }

    hip_time_test_end();
    double runtime = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime / 1000) * 1e9);
    hipDeviceSynchronize();
    printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime);
    printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);

    hipMemcpy(((float *)vecY_csr->values), d_vecY_csr, sizeof(float) * vecY->n, hipMemcpyDeviceToHost);

    hipError_t cudaStatus = hipGetLastError();
    if (cudaStatus != hipSuccess)
    {
        printf("Error:%s\n", hipGetErrorString(cudaStatus));
        exit(EXIT_FAILURE);
    }
    hipFree(d_vecY_csr);
    hipFree(d_vecX_csr);
    hipFree(d_val);
    hipFree(d_indices);
    hipFree(d_ptr);

    return perfSpB_success;
}
