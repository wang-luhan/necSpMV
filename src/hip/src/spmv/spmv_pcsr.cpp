#include "hip/hip_runtime.h"
#include <hip/hip_runtime.h>
#include <hip/hip_runtime.h>
#include "spmv_hip.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hip_timer.h"

#define test_iter 2000

#define threadsPerBlock 256
#define sizeSharedMemory 1024
#define BlockDim 1024

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

template <typename T>
__global__ void spmv_pcsr_kernel2(T *d_middle, perfSpB_index *d_ptr, perfSpB_index nrows, T *d_out)
{
    int gid = blockIdx.x * blockDim.x + threadIdx.x;
    int tid = threadIdx.x;

    __shared__ volatile perfSpB_index ptr_s[threadsPerBlock + 1];
    __shared__ volatile T middle_s[sizeSharedMemory];

    // Load ptr into the shared memory ptr_s
    ptr_s[tid] = d_ptr[gid];

    // Assign thread 0 of every block to store the pointer for the last row handled by the block into the last shared memory location
    if (tid == 0)
    {
        if (gid + threadsPerBlock > nrows)
        {
            ptr_s[threadsPerBlock] = d_ptr[nrows];
        }
        else
        {
            ptr_s[threadsPerBlock] = d_ptr[gid + threadsPerBlock];
        }
    }
    __syncthreads();

    perfSpB_index temp = (ptr_s[threadsPerBlock] - ptr_s[0]) / threadsPerBlock + 1;
    perfSpB_index nlen = min(perfSpB_index(temp * threadsPerBlock), perfSpB_index(sizeSharedMemory));
    T sum = 0;
    perfSpB_index maxlen = ptr_s[threadsPerBlock];
    //使用循环分多次加载 d_middle 到共享内存 middle_s[],每次加载量为 nlen
    for (perfSpB_index i = ptr_s[0]; i < maxlen; i += nlen)
    {
        perfSpB_index index = i + tid;
        __syncthreads();
        // Load d_middle into the shared memory middle_s, 填满一个1024需要几次迭代
        for (perfSpB_index j = 0; j < nlen / threadsPerBlock; j++)
        {
            if (index < maxlen)
            {
                middle_s[tid + j * threadsPerBlock] = d_middle[index];
                index += threadsPerBlock;
            }
        }
        __syncthreads();
        //填满了一个1024，计算这个1024
        // Sum up the elements for a row
        if (ptr_s[tid + 1] > i && ptr_s[tid] <= i + nlen - 1)
        {
            perfSpB_index row_s = max(perfSpB_index(ptr_s[tid] - i), perfSpB_index(0));
            perfSpB_index row_e = min(perfSpB_index(ptr_s[tid + 1] - i), perfSpB_index(nlen));
            for (perfSpB_index j = row_s; j < row_e; j++)
            {
                sum += middle_s[j];
            }
        }
    }
    // Write result
    d_out[gid] = sum;
}

/*
template <typename T>
__global__ void spmv_pcsr_kernel2(T *d_middle, perfSpB_index *d_ptr, perfSpB_index nrows, T *d_out)
{
    int gid = blockIdx.x * blockDim.x + threadIdx.x;
    int tid = threadIdx.x;
    int b_0_id = blockIdx.x * blockDim.x;

    __shared__ volatile T middle_s[sizeSharedMemory];

    int b_last_id = (b_0_id + threadsPerBlock) > nrows ? nrows : (b_0_id + threadsPerBlock);

    perfSpB_index temp = (d_ptr[b_last_id] - d_ptr[b_0_id]) / threadsPerBlock + 1;
    perfSpB_index nlen = min(perfSpB_index(temp * threadsPerBlock), perfSpB_index(sizeSharedMemory));
    T sum = 0;
    perfSpB_index maxlen = d_ptr[b_last_id];
    // 使用循环分多次加载 d_middle 到共享内存 middle_s[],每次加载量为 nlen
    for (perfSpB_index i = d_ptr[b_0_id]; i < maxlen; i += nlen)
    {
        perfSpB_index index = i + tid;
        __syncthreads();
        // Load d_middle into the shared memory middle_s, 填满一个1024需要几次迭代
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
        if (d_ptr[gid + 1] > i && d_ptr[gid] <= i + nlen - 1)
        {
            perfSpB_index row_s = max(perfSpB_index(d_ptr[gid] - i), perfSpB_index(0));
            perfSpB_index row_e = min(perfSpB_index(d_ptr[gid + 1] - i), perfSpB_index(nlen));
            for (perfSpB_index j = row_s; j < row_e; j++)
            {
                sum += middle_s[j];
            }
        }
    }
    // Write result
    d_out[gid] = sum;
}
*/
perfSpB_info perfSpB_SpMV_PCSR_FP32(perfSpB_operation_t op,
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
    for (int i = 0; i < matA->row; i++)
    {
        if (*((float *)vecY_csr->values) != 0)
        {
            printf("\n %f \n", *((float *)vecY_csr->values));
        }
    }

    hipMalloc(&d_vecY_csr, sizeof(float) * vecY->n);
    hipMalloc(&d_vecX_csr, sizeof(float) * vecX->n);
    hipMalloc(&d_val, sizeof(float) * matA_csr->nnz);
    hipMalloc(&d_v, sizeof(float) * matA_csr->nnz);
    hipMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
    hipMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

    hipMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, hipMemcpyHostToDevice);
    hipMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, hipMemcpyHostToDevice);
    hipMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), hipMemcpyHostToDevice);
    hipMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, hipMemcpyHostToDevice);

    hip_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        hipLaunchKernelGGL(spmv_pcsr_kernel1<float>, dim3(ceil(matA_csr->nnz / (float)BlockDim)), dim3(BlockDim), 0, 0, d_val, d_vecX_csr, d_indices, matA_csr->nnz, d_v);
        hipLaunchKernelGGL(spmv_pcsr_kernel2<float>, dim3(ceil(vecY->n / (float)threadsPerBlock)), dim3(threadsPerBlock), 0, 0, d_v, d_ptr, vecY->n, d_vecY_csr);
    }
    hip_time_test_end();
    double runtime1 = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime1 / 1000) * 1e9);

    // hip_time_test_start();
    // for (int i = 0; i < test_iter; i++)
    // {
    //     // hipLaunchKernelGGL(spmv_pcsr_kernel1<float>, dim3(ceil(matA_csr->nnz / (float)BlockDim)), dim3(BlockDim), 0, 0, d_val, d_vecX_csr, d_indices, matA_csr->nnz, d_v);
    // 	hipLaunchKernelGGL(spmv_pcsr_kernel2<float>, dim3(ceil(vecY->n / (float)threadsPerBlock)), dim3(threadsPerBlock), 0, 0, d_v, d_ptr, vecY->n, d_vecY_csr);
    // }
    // hip_time_test_end();
    // double runtime2 = (elapsedTime) / test_iter;

    hipDeviceSynchronize();
    printf("\n SpMV CUDA kernel1 runtime = %g ms\n", runtime1);
    // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
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

perfSpB_info perfSpB_SpMV_PCSR_FP64(perfSpB_operation_t op,
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
    double *d_vecY_csr, *d_vecX_csr, *d_val, *d_v;
    perfSpB_index *d_indices, *d_ptr;
    for (int i = 0; i < matA->row; i++)
    {
        if (*((double *)vecY_csr->values) != 0)
        {
            printf("\n %f \n", *((double *)vecY_csr->values));
        }
    }

    hipMalloc(&d_vecY_csr, sizeof(double) * vecY->n);
    hipMalloc(&d_vecX_csr, sizeof(double) * vecX->n);
    hipMalloc(&d_val, sizeof(double) * matA_csr->nnz);
    hipMalloc(&d_v, sizeof(double) * matA_csr->nnz);
    hipMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
    hipMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

    hipMemcpy(d_val, matA_csr->val, sizeof(double) * matA_csr->nnz, hipMemcpyHostToDevice);
    hipMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, hipMemcpyHostToDevice);
    hipMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), hipMemcpyHostToDevice);
    hipMemcpy(d_vecX_csr, ((double *)vecX_csr->values), sizeof(double) * vecX->n, hipMemcpyHostToDevice);

    hip_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        hipLaunchKernelGGL(spmv_pcsr_kernel1<double>, dim3(ceil(matA_csr->nnz / (double)BlockDim)), dim3(BlockDim), 0, 0, d_val, d_vecX_csr, d_indices, matA_csr->nnz, d_v);
        hipLaunchKernelGGL(spmv_pcsr_kernel2<double>, dim3(ceil(vecY->n / (double)threadsPerBlock)), dim3(threadsPerBlock), 0, 0, d_v, d_ptr, vecY->n, d_vecY_csr);
    }
    hip_time_test_end();
    double runtime1 = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime1 / 1000) * 1e9);

    hipDeviceSynchronize();
    printf("\n SpMV CUDA kernel1 runtime = %g ms\n", runtime1);
    // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
    printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);

    hipMemcpy(((double *)vecY_csr->values), d_vecY_csr, sizeof(double) * vecY->n, hipMemcpyDeviceToHost);

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
