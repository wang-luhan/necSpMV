#include <cuda.h>
#include <cuda_runtime.h>
#include <spmv_cuda.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cuda_timer.h"

#define test_iter 2000

#define BlockDim 512
#define MAX_NUM_THREADS_PER_BLOCK 512

template <typename T, int THREADS_PER_VECTOR, int MAX_NUM_VECTORS_PER_BLOCK>
__global__ void spmv_light_kernel(int *cudaRowCounter, perfSpB_index *d_ptr, perfSpB_index *d_cols, T *d_val, T *d_vector, T *d_out, perfSpB_index N)
{
    int i;
    T sum;
    int row;
    int rowStart, rowEnd;
    int vectorLaneId = threadIdx.x % THREADS_PER_VECTOR; // lane index in the vector
    int vectorId = threadIdx.x / THREADS_PER_VECTOR;     // vector index in the thread block

    int warpLaneId = threadIdx.x & 31;            // lane index in the warp
    int warpId = warpLaneId / THREADS_PER_VECTOR; // vector index in the warp

    __shared__ volatile int space[MAX_NUM_VECTORS_PER_BLOCK][2];

    // Get the row index
    if (warpLaneId == 0)
    {
        row = atomicAdd(cudaRowCounter, 32 / THREADS_PER_VECTOR);
    }
    // Broadcast the value to other threads in the same warp and compute the row index of each vector
    row = __shfl_sync(0xffffffff, row, 0) + warpId;

    while (row < N)
    {
        // Use two threads to fetch the row offset
        if (vectorLaneId < 2)
        {
            space[vectorId][vectorLaneId] = d_ptr[row + vectorLaneId];
        }
        rowStart = space[vectorId][0];
        rowEnd = space[vectorId][1];

        sum = 0;
        // Compute dot product
        if (THREADS_PER_VECTOR == 32)
        {

            // Ensure aligned memory access
            i = rowStart - (rowStart & (THREADS_PER_VECTOR - 1)) + vectorLaneId;

            // Process the unaligned part
            if (i >= rowStart && i < rowEnd)
            {
                sum += d_val[i] * d_vector[d_cols[i]];
            }

            // Process the aligned part
            for (i += THREADS_PER_VECTOR; i < rowEnd; i += THREADS_PER_VECTOR)
            {
                sum += d_val[i] * d_vector[d_cols[i]];
            }
        }
        else
        {
            for (i = rowStart + vectorLaneId; i < rowEnd; i += THREADS_PER_VECTOR)
            {
                sum += d_val[i] * d_vector[d_cols[i]];
            }
        }
        // Intra-vector reduction
        for (i = THREADS_PER_VECTOR >> 1; i > 0; i >>= 1)
        {
            sum += __shfl_down_sync(0xffffffff, sum, i);
        }

        // Save the results
        if (vectorLaneId == 0)
        {
            d_out[row] = sum;
        }

        // Get a new row index
        if (warpLaneId == 0)
        {
            row = atomicAdd(cudaRowCounter, 32 / THREADS_PER_VECTOR);
        }
        // Broadcast the row index to the other threads in the same warp and compute the row index of each vector
        row = __shfl_sync(0xffffffff, row, 0) + warpId;
    }
}

perfSpB_info perfSpB_SpMV_LIGHT_FP32(perfSpB_operation_t op,
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
    float *d_vecY_csr, *d_vecX_csr, *d_val;
    perfSpB_index *d_indices, *d_ptr;
    for (int i = 0; i < matA->row; i++)
    {
        if (*((float *)vecY_csr->values) != 0)
        {
            printf("\n %f \n", *((float *)vecY_csr->values));
        }
    }

    cudaMalloc(&d_vecY_csr, sizeof(float) * vecY->n);
    cudaMalloc(&d_vecX_csr, sizeof(float) * vecX->n);
    cudaMalloc(&d_val, sizeof(float) * matA_csr->nnz);

    cudaMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
    cudaMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

    cudaMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, cudaMemcpyHostToDevice);

    int meanElementsPerRow = matA_csr->nnz / vecY->n;
    int *cudaRowCounter;
    cudaMalloc((void **)&cudaRowCounter, sizeof(int));
    cudaMemset(cudaRowCounter, 0, sizeof(int));
    cuda_time_test_start();
    if (meanElementsPerRow <= 2)
    {
        for (int i = 0; i < test_iter; i++)
        {
            spmv_light_kernel<float, 2, MAX_NUM_THREADS_PER_BLOCK / 2><<<ceil(vecY->n / (float)BlockDim), BlockDim>>>(
                cudaRowCounter, d_ptr, d_indices, d_val, d_vecX_csr, d_vecY_csr, vecY->n);
            cudaMemset(cudaRowCounter, 0, sizeof(int));
        }
    }
    else if (meanElementsPerRow <= 4)
    {
        for (int i = 0; i < test_iter; i++)
        {
            spmv_light_kernel<float, 4, MAX_NUM_THREADS_PER_BLOCK / 4><<<ceil(vecY->n / (float)BlockDim), BlockDim>>>(
                cudaRowCounter, d_ptr, d_indices, d_val, d_vecX_csr, d_vecY_csr, vecY->n);
            cudaMemset(cudaRowCounter, 0, sizeof(int));
        }
    }
    else if (meanElementsPerRow <= 64)
    {
        for (int i = 0; i < test_iter; i++)
        {
            spmv_light_kernel<float, 8, MAX_NUM_THREADS_PER_BLOCK / 8><<<ceil(vecY->n / (float)BlockDim), BlockDim>>>(
                cudaRowCounter, d_ptr, d_indices, d_val, d_vecX_csr, d_vecY_csr, vecY->n);
            cudaMemset(cudaRowCounter, 0, sizeof(int));
        }
    }
    else
    {
        for (int i = 0; i < test_iter; i++)
        {
            spmv_light_kernel<float, 32, MAX_NUM_THREADS_PER_BLOCK / 32><<<ceil(vecY->n / (float)BlockDim), BlockDim>>>(
                cudaRowCounter, d_ptr, d_indices, d_val, d_vecX_csr, d_vecY_csr, vecY->n);
            cudaMemset(cudaRowCounter, 0, sizeof(int));
        }
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

perfSpB_info perfSpB_SpMV_LIGHT_FP64(perfSpB_operation_t op,
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
    double *d_vecY_csr, *d_vecX_csr, *d_val;
    perfSpB_index *d_indices, *d_ptr;
    for (int i = 0; i < matA->row; i++)
    {
        if (*((double *)vecY_csr->values) != 0)
        {
            printf("\n %f \n", *((double *)vecY_csr->values));
        }
    }

    cudaMalloc(&d_vecY_csr, sizeof(double) * vecY->n);
    cudaMalloc(&d_vecX_csr, sizeof(double) * vecX->n);
    cudaMalloc(&d_val, sizeof(double) * matA_csr->nnz);

    cudaMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
    cudaMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

    cudaMemcpy(d_val, matA_csr->val, sizeof(double) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_vecX_csr, ((double *)vecX_csr->values), sizeof(double) * vecX->n, cudaMemcpyHostToDevice);

    int meanElementsPerRow = matA_csr->nnz / vecY->n;
    int *cudaRowCounter;
    cudaMalloc((void **)&cudaRowCounter, sizeof(int));
    cudaMemset(cudaRowCounter, 0, sizeof(int));
    cuda_time_test_start();
    if (meanElementsPerRow <= 2)
    {
        for (int i = 0; i < test_iter; i++)
        {
            spmv_light_kernel<double, 2, MAX_NUM_THREADS_PER_BLOCK / 2><<<ceil(vecY->n / (double)BlockDim), BlockDim>>>(
                cudaRowCounter, d_ptr, d_indices, d_val, d_vecX_csr, d_vecY_csr, vecY->n);
            cudaMemset(cudaRowCounter, 0, sizeof(int));
        }
    }
    else if (meanElementsPerRow <= 4)
    {
        for (int i = 0; i < test_iter; i++)
        {
            spmv_light_kernel<double, 4, MAX_NUM_THREADS_PER_BLOCK / 4><<<ceil(vecY->n / (double)BlockDim), BlockDim>>>(
                cudaRowCounter, d_ptr, d_indices, d_val, d_vecX_csr, d_vecY_csr, vecY->n);
            cudaMemset(cudaRowCounter, 0, sizeof(int));
        }
    }
    else if (meanElementsPerRow <= 64)
    {
        for (int i = 0; i < test_iter; i++)
        {
            spmv_light_kernel<double, 8, MAX_NUM_THREADS_PER_BLOCK / 8><<<ceil(vecY->n / (double)BlockDim), BlockDim>>>(
                cudaRowCounter, d_ptr, d_indices, d_val, d_vecX_csr, d_vecY_csr, vecY->n);
            cudaMemset(cudaRowCounter, 0, sizeof(int));
        }
    }
    else
    {
        for (int i = 0; i < test_iter; i++)
        {
            spmv_light_kernel<double, 32, MAX_NUM_THREADS_PER_BLOCK / 32><<<ceil(vecY->n / (double)BlockDim), BlockDim>>>(
                cudaRowCounter, d_ptr, d_indices, d_val, d_vecX_csr, d_vecY_csr, vecY->n);
            cudaMemset(cudaRowCounter, 0, sizeof(int));
        }
    }
    cuda_time_test_end();
    double runtime1 = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime1 / 1000) * 1e9);
    cudaDeviceSynchronize();
    printf("\n SpMV CUDA kernel1 runtime = %g ms\n", runtime1);
    // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
    printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);

    cudaMemcpy(((double *)vecY_csr->values), d_vecY_csr, sizeof(double) * vecY->n, cudaMemcpyDeviceToHost);

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
