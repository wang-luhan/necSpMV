#include <cuda.h>
#include <cuda_runtime.h>
#include <spmv_cuda.h>
#include "cuda_timer.h"

#define test_iter 2000

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

template <typename ValueType, unsigned int VECTORS_PER_BLOCK, unsigned int THREADS_PER_VECTOR>
__global__ void spmv_kernel_cuda(ValueType *__restrict__ y,
                                 const ValueType *__restrict__ A_value,
                                 const perfSpB_index *__restrict__ A_col_index,
                                 const perfSpB_index *__restrict__ A_row_offset,
                                 const ValueType *__restrict__ x,
                                 perfSpB_index row_num)
{
    const perfSpB_index thread_id = blockDim.x * blockIdx.x + threadIdx.x;    // global thread index
    const perfSpB_index thread_lane = threadIdx.x & (THREADS_PER_VECTOR - 1); // thread index within the vector/row
    const perfSpB_index row_id = thread_id / THREADS_PER_VECTOR;              // global vector index
    if (row_id < row_num)
    {
        const perfSpB_index row_start = A_row_offset[row_id]; // same as: row_start = Ap[row];
        const perfSpB_index row_end = A_row_offset[row_id + 1];

        // initialize local sum
        ValueType sum = 0;

        // accumulate local sums
        for (perfSpB_index jj = row_start + thread_lane; jj < row_end; jj += THREADS_PER_VECTOR)
            sum += A_value[jj] * x[A_col_index[jj]];

        sum = warpReduceSum<THREADS_PER_VECTOR>(sum);
        if (thread_lane == 0)
        {
            y[row_id] = sum;
        }
    }
}

template <typename ValueType, unsigned int VECTORS_PER_BLOCK, unsigned int THREADS_PER_VECTOR>
__global__ void spmv_kernel_cuda_L(ValueType *__restrict__ y,
                                   const ValueType *__restrict__ A_value,
                                   const perfSpB_index *__restrict__ A_col_index,
                                   const perfSpB_index *__restrict__ A_row_offset,
                                   const ValueType *__restrict__ x,
                                   perfSpB_index row_num)
{
    const perfSpB_index thread_id = blockDim.x * blockIdx.x + threadIdx.x;    // global thread index
    const perfSpB_index thread_lane = threadIdx.x & (THREADS_PER_VECTOR - 1); // thread index within the vector/row
    const perfSpB_index row_id = thread_id / THREADS_PER_VECTOR;              // global vector index
    const perfSpB_index lane_id = threadIdx.x % 32;                           // global vector index

    // if(row_id < row_num && threadIdx.x == 0)
    // {
    //     if (y[row_id] != 0) printf("\ny[%ld] = %f\n", row_id,y[row_id]);
    // }

    if (row_id < row_num)
    {
        const perfSpB_index row_start = A_row_offset[row_id]; // same as: row_start = Ap[row];
        const perfSpB_index row_end = A_row_offset[row_id + 1];

        // initialize local sum
        ValueType sum = 0;

        // accumulate local sums
        for (perfSpB_index jj = row_start + thread_lane; jj < row_end; jj += THREADS_PER_VECTOR)
            sum += A_value[jj] * x[A_col_index[jj]];

        for (int offset = 16; offset > 0; offset >>= 1)
        {
            sum += __shfl_down_sync(0xffffffff, sum, offset);
        }

        if (lane_id == 0)
        {
            atomicAdd(&y[row_id], sum);
            // y[row_id] = sum;
            // y[row_id] = s_tmp[0] + s_tmp[1] + s_tmp[2] + s_tmp[3];
        }
    }
}

perfSpB_info perfSpB_SpMV_FP32(perfSpB_operation_t op,
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
    // cudaMemcpy(d_vecY_csr, ((float *)vecY_csr->values), sizeof(float) * vecY->n, cudaMemcpyHostToDevice);
    // cudaMemset(d_vecY_csr, 0.0, sizeof(float) * (vecY->n));

    // spmv_kernel_cuda<<<blocks, threads>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n, matA_csr->nnz);
    double mean_col_num = ((double)matA_csr->nnz + (double)(vecY->n - 1)) / (double)vecY->n;
    double accum = 0.0, max = 0.0;
    for (int row_id = 1; row_id < matA->row; row_id++)
    {
        double row_nnz_tmp = (double)matA_csr->ptr[row_id + 1] - (double)matA_csr->ptr[row_id];
        max = (max < row_nnz_tmp) ? row_nnz_tmp : max;
        accum += abs(row_nnz_tmp - mean_col_num);
    }
    // printf("\n  The average col num is: %lf\n", mean_col_num);
    // // printf("\n  The variance is: %lf\n", (accum / matA->row));
    // printf("\n  The max nnz per row is: %lf\n", (max));
    // printf("\n  lat_time: %lf\n", (max / mean_col_num));
    cuda_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        // cudaMemset(d_vecY_csr, 0.0, sizeof(float) * (vecY->n)); //TODO: Accuracy test

        if (mean_col_num <= 2)
        {
            const int THREADS_PER_VECTOR = 2;
            const unsigned int VECTORS_PER_BLOCK = 128;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        else if (mean_col_num > 2 && mean_col_num <= 4)
        {
            const int THREADS_PER_VECTOR = 4;
            const unsigned int VECTORS_PER_BLOCK = 64;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        else if (mean_col_num > 4 && mean_col_num <= 8)
        {
            const int THREADS_PER_VECTOR = 8;
            const unsigned int VECTORS_PER_BLOCK = 32;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        else if (mean_col_num > 8 && mean_col_num <= 16)
        {
            const int THREADS_PER_VECTOR = 16;
            const unsigned int VECTORS_PER_BLOCK = 16;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        else if (mean_col_num > 16)
        {
            const int THREADS_PER_VECTOR = 32;
            const unsigned int VECTORS_PER_BLOCK = 8;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        // else if (mean_col_num > 32 && mean_col_num <= 64)
        // {
        //     const int THREADS_PER_VECTOR = 64;
        //     const unsigned int VECTORS_PER_BLOCK = 4;
        //     const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
        //     spmv_kernel_cuda_L<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        // }
        // else if (mean_col_num > 64)
        // {
        //     const int THREADS_PER_VECTOR = 256;
        //     const unsigned int VECTORS_PER_BLOCK = 1;
        //     const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
        //     spmv_kernel_cuda_L<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        // }
    }

    cuda_time_test_end();
    double runtime = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime / 1000) * 1e9);
    cudaDeviceSynchronize();
    printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime);
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

perfSpB_info perfSpB_SpMV_FP64(perfSpB_operation_t op,
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
    
    double mean_col_num = ((double)matA_csr->nnz + (double)(vecY->n - 1)) / (double)vecY->n;
    double accum = 0.0, max = 0.0;
    for (int row_id = 1; row_id < matA->row; row_id++)
    {
        double row_nnz_tmp = (double)matA_csr->ptr[row_id + 1] - (double)matA_csr->ptr[row_id];
        max = (max < row_nnz_tmp) ? row_nnz_tmp : max;
        accum += abs(row_nnz_tmp - mean_col_num);
    }
    cuda_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        if (mean_col_num <= 2)
        {
            const int THREADS_PER_VECTOR = 2;
            const unsigned int VECTORS_PER_BLOCK = 128;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<double, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        else if (mean_col_num > 2 && mean_col_num <= 4)
        {
            const int THREADS_PER_VECTOR = 4;
            const unsigned int VECTORS_PER_BLOCK = 64;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<double, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        else if (mean_col_num > 4 && mean_col_num <= 8)
        {
            const int THREADS_PER_VECTOR = 8;
            const unsigned int VECTORS_PER_BLOCK = 32;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<double, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        else if (mean_col_num > 8 && mean_col_num <= 16)
        {
            const int THREADS_PER_VECTOR = 16;
            const unsigned int VECTORS_PER_BLOCK = 16;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<double, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
        else if (mean_col_num > 16)
        {
            const int THREADS_PER_VECTOR = 32;
            const unsigned int VECTORS_PER_BLOCK = 8;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_cuda<double, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_vecX_csr, vecY->n);
        }
    }

    cuda_time_test_end();
    double runtime = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime / 1000) * 1e9);
    cudaDeviceSynchronize();
    printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime);
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