#include <cuda.h>
#include <cuda_runtime.h>
#include <spmv_cuda.h>
#include "cuda_timer.h"

#define test_iter 1
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

template <typename ValueType, unsigned int VECTORS_PER_BLOCK, unsigned int THREADS_PER_VECTOR>
__global__ void spmv_kernel_small(ValueType *__restrict__ y,
                                  const ValueType *__restrict__ A_value,
                                  const perfSpB_index *__restrict__ A_col_index,
                                  const perfSpB_index *__restrict__ A_row_offset,
                                  perfSpB_index *A_row_id,
                                  const ValueType *__restrict__ x,
                                  perfSpB_index row_num)
{
    const perfSpB_index thread_id = blockDim.x * blockIdx.x + threadIdx.x;    // global thread index
    const perfSpB_index thread_lane = threadIdx.x & (THREADS_PER_VECTOR - 1); // thread index within the vector/row
    const perfSpB_index row_id = thread_id / THREADS_PER_VECTOR;              // global vector index
    if (row_id < row_num && row_id != 0)
    {
        perfSpB_index real_row_id = A_row_id[row_id];
        const perfSpB_index row_start = A_row_offset[real_row_id]; // same as: row_start = Ap[row];
        const perfSpB_index row_end = A_row_offset[real_row_id + 1];

        // initialize local sum
        ValueType sum = 0;

        // accumulate local sums
        for (perfSpB_index jj = row_start + thread_lane; jj < row_end; jj += THREADS_PER_VECTOR)
            sum += A_value[jj] * x[A_col_index[jj]];

        sum = warpReduceSum<THREADS_PER_VECTOR>(sum);
        if (thread_lane == 0)
        {
            y[real_row_id] = sum;
        }
    }
}
template <typename T>
__global__ __forceinline__ void spmv_kernel_large(T *__restrict__ y,
                                                  const T *__restrict__ A_value,
                                                  const perfSpB_index *__restrict__ A_col_index,
                                                  const perfSpB_index *__restrict__ A_row_offset,
                                                  perfSpB_index *A_row_id,
                                                  const T *__restrict__ x,
                                                  perfSpB_index row_num)
{
    int real_row_id = A_row_id[blockIdx.x];
    __shared__ volatile T LDS[BlockDim];
    int rowStart = A_row_offset[real_row_id];
    int rowEnd = A_row_offset[real_row_id + 1];

    T sum = 0;
    for (int j = rowStart + threadIdx.x; j < rowEnd; j += BlockDim)
    {
        int col = A_col_index[j];
        sum += A_value[j] * x[col];
    }

    LDS[threadIdx.x] = sum;
    __syncthreads();

    // Reduce partial sums
    for (int stride = blockDim.x >> 1; stride > 0; stride >>= 1)
    {
        __syncthreads();
        if (threadIdx.x < stride)
            LDS[threadIdx.x] += LDS[threadIdx.x + stride];
    }
    // Write result
    if (threadIdx.x == 0)
        atomicAdd(y + real_row_id, LDS[threadIdx.x]);
}

// template <typename ValueType, unsigned int VECTORS_PER_BLOCK, unsigned int THREADS_PER_VECTOR>
// __global__ void spmv_kernel_cuda_L(ValueType *__restrict__ y,
//                                    const ValueType *__restrict__ A_value,
//                                    const perfSpB_index *__restrict__ A_col_index,
//                                    const perfSpB_index *__restrict__ A_row_offset,
//                                    const ValueType *__restrict__ x,
//                                    perfSpB_index row_num)
// {
//     const perfSpB_index thread_id = blockDim.x * blockIdx.x + threadIdx.x;    // global thread index
//     const perfSpB_index thread_lane = threadIdx.x & (THREADS_PER_VECTOR - 1); // thread index within the vector/row
//     const perfSpB_index row_id = thread_id / THREADS_PER_VECTOR;              // global vector index
//     const perfSpB_index lane_id = threadIdx.x % 32;                           // global vector index

//     if (row_id < row_num)
//     {
//         const perfSpB_index row_start = A_row_offset[row_id]; // same as: row_start = Ap[row];
//         const perfSpB_index row_end = A_row_offset[row_id + 1];

//         // initialize local sum
//         ValueType sum = 0;

//         // accumulate local sums
//         for (perfSpB_index jj = row_start + thread_lane; jj < row_end; jj += THREADS_PER_VECTOR)
//             sum += A_value[jj] * x[A_col_index[jj]];

//         for (int offset = 16; offset > 0; offset >>= 1)
//         {
//             sum += __shfl_down_sync(0xffffffff, sum, offset);
//         }

//         if (lane_id == 0)
//         {
//             atomicAdd(&y[row_id], sum);
//             // y[row_id] = sum;
//             // y[row_id] = s_tmp[0] + s_tmp[1] + s_tmp[2] + s_tmp[3];
//         }
//     }
// }

perfSpB_info perfSpB_SpMV_ACSR_FP32(perfSpB_operation_t op,
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
    int mean_nnz_thresh = mean_col_num * 200;
    
    perfSpB_index *rowId_L = (perfSpB_index *)malloc(matA->row * sizeof(perfSpB_index));
    perfSpB_index *rowId_S = (perfSpB_index *)malloc(matA->row * sizeof(perfSpB_index));
    memset(rowId_L, 0, matA->row * sizeof(perfSpB_index));
    memset(rowId_S, 0, matA->row * sizeof(perfSpB_index));
    int p = 0, q = 0, Lrow_num = 0, Srow_num = 0;
    for (int i = 0; i < matA->row; i++)
    {
        int row_nnz_tmp = matA_csr->ptr[i + 1] - matA_csr->ptr[i];
        if (row_nnz_tmp > mean_nnz_thresh)
        {
            rowId_L[p++] = i;
        }
        else
        {
            rowId_S[q++] = i;
        }
    }
    
    Lrow_num = p;
    Srow_num = q;
    printf("\n %d   %d \n", Lrow_num, Srow_num);
    perfSpB_index *d_rowId_L, *d_rowId_S;
    cudaMalloc(&d_rowId_L, sizeof(perfSpB_index) * Lrow_num);
    cudaMalloc(&d_rowId_S, sizeof(perfSpB_index) * Srow_num);
    cudaMemcpy(d_rowId_L, rowId_L, sizeof(perfSpB_index) * Lrow_num, cudaMemcpyHostToDevice);
    cudaMemcpy(d_rowId_S, rowId_S, sizeof(perfSpB_index) * Srow_num, cudaMemcpyHostToDevice);
    cudaStream_t stream_1;
    cudaStream_t stream_2;
    cudaStreamCreate(&stream_1);
    cudaStreamCreate(&stream_2);

    // double accum = 0.0, max = 0.0;
    // for (int row_id = 1; row_id < matA->row; row_id++)
    // {
    //     double row_nnz_tmp = (double)matA_csr->ptr[row_id + 1] - (double)matA_csr->ptr[row_id];
    //     max = (max < row_nnz_tmp) ? row_nnz_tmp : max;
    //     accum += abs(row_nnz_tmp - mean_col_num);
    // }
    // printf("\n  The average col num is: %lf\n", mean_col_num);
    // // // printf("\n  The variance is: %lf\n", (accum / matA->row));
    // printf("\n  The max nnz per row is: %lf\n", (max));
    // printf("\n  lat_time: %lf\n", (max / mean_col_num));
    
    cuda_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        // cudaMemset(d_vecY_csr, 0.0, sizeof(float) * (vecY->n)); //TODO: Accuracy test
        spmv_kernel_large<float><<<Lrow_num, BlockDim, 0, stream_1>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_rowId_L, d_vecX_csr, Lrow_num);
        
        if (mean_col_num <= 2)
        {
            const int THREADS_PER_VECTOR = 2;
            const unsigned int VECTORS_PER_BLOCK = 128;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((Srow_num + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_small<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256, 0, stream_2>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_rowId_S, d_vecX_csr, Srow_num);
        }
        else if (mean_col_num > 2 && mean_col_num <= 4)
        {
            const int THREADS_PER_VECTOR = 4;
            const unsigned int VECTORS_PER_BLOCK = 64;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((Srow_num + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_small<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256, 0, stream_2>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_rowId_S, d_vecX_csr, Srow_num);
        }
        else if (mean_col_num > 4 && mean_col_num <= 8)
        {
            const int THREADS_PER_VECTOR = 8;
            const unsigned int VECTORS_PER_BLOCK = 32;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((Srow_num + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_small<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256, 0, stream_2>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_rowId_S, d_vecX_csr, Srow_num);
        }
        else if (mean_col_num > 8 && mean_col_num <= 16)
        {
            const int THREADS_PER_VECTOR = 16;
            const unsigned int VECTORS_PER_BLOCK = 16;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((Srow_num + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_small<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256, 0, stream_2>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_rowId_S, d_vecX_csr, Srow_num);
        }
        else if (mean_col_num > 16)
        {
            const int THREADS_PER_VECTOR = 32;
            const unsigned int VECTORS_PER_BLOCK = 8;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((Srow_num + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            spmv_kernel_small<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256, 0, stream_2>>>(d_vecY_csr, d_val, d_indices, d_ptr, d_rowId_S, d_vecX_csr, Srow_num);
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
    cudaStreamDestroy(stream_1);
    cudaStreamDestroy(stream_2);

    return perfSpB_success;
}