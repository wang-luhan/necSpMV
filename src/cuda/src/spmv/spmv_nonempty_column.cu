#include <cuda.h>
#include <cuda_runtime.h>
#include <spmv_cuda.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cuda_timer.h"

#define test_iter 2000

#define warpSize 32

#define BlockDim 1024
#define BLOCKS_EXP 640
#define ITER 3

#define SHARED_X_PER_BLOCK 3072
#define NUM_THREAD_PER_BLOCK 256
#define num_loads_per_thread 12

// calculates the number of rows of a CSR matrix that can fit into BlockDim entries.
int spmv_csr_adaptive_rowblocks(perfSpB_index *ptr, int totalRows, int *rowBlocks, perfSpB_index nnzPerBlock)
{
    rowBlocks[0] = 0;
    int sum = 0;
    int last_i = 0;
    int ctr = 1;
    for (int i = 1; i < totalRows; i++)
    {
        // Count non-zeroes in this row
        sum += ptr[i] - ptr[i - 1];
        if (sum == nnzPerBlock)
        {
            // This row fills up LOCAL_SIZE
            last_i = i;
            rowBlocks[ctr++] = i;
            sum = 0;
        }
        else if (sum > nnzPerBlock)
        {
            if (i - last_i > 1)
            {
                // This extra row will not fit
                rowBlocks[ctr++] = i - 1;
                i--;
            }
            else if (i - last_i == 1)
                // This one row is too large
                rowBlocks[ctr++] = i;
            last_i = i;
            sum = 0;
        }
    }
    rowBlocks[ctr++] = totalRows;
    return ctr;
}

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
__global__ void nec_spmv_v(ValueType *__restrict__ y,
                         const ValueType *__restrict__ A_value,
                         const perfSpB_index *__restrict__ A_row_offset,
                         int * __restrict__ A_ecr_indices,
                         ValueType *__restrict__ ecr_x,
                         perfSpB_index row_num,
                         int *__restrict__ ROW_BLOCK,
                         int *__restrict__ row_block_ptr)
{
    float *local_ecr_xx_val = ecr_x + row_block_ptr[blockIdx.x];
    __shared__ volatile float x_cache[SHARED_X_PER_BLOCK];

    for (int i = 0; i < num_loads_per_thread; i++)
    {
        unsigned int cache_idx = i * NUM_THREAD_PER_BLOCK + threadIdx.x;
        if (cache_idx < SHARED_X_PER_BLOCK)
            x_cache[cache_idx] = local_ecr_xx_val[cache_idx];
    }
    __syncthreads();

    // const perfSpB_index thread_id = blockDim.x * blockIdx.x + threadIdx.x;
    const perfSpB_index tid_in_vec = threadIdx.x & (THREADS_PER_VECTOR - 1);
    const perfSpB_index vec_id = threadIdx.x / THREADS_PER_VECTOR;

    const perfSpB_index reduce_start_row_id = ROW_BLOCK[blockIdx.x];
    const perfSpB_index reduce_end_row_id = ROW_BLOCK[blockIdx.x + 1];
    // int num_rows = reduce_end_row_id - reduce_start_row_id;
    int reduce_row_id = reduce_start_row_id + vec_id;

    for (; reduce_row_id < reduce_end_row_id; reduce_row_id += VECTORS_PER_BLOCK)
    {
        float sum = static_cast<float>(0);
        for (int jj = A_row_offset[reduce_row_id] + tid_in_vec; jj < A_row_offset[reduce_row_id + 1]; jj += THREADS_PER_VECTOR)
        {
            int col = A_ecr_indices[jj];
            if(col < SHARED_X_PER_BLOCK)
            {
                sum += A_value[jj] * x_cache[col];
            }
            else
            {
                sum += A_value[jj] * local_ecr_xx_val[col];
            }
        }
        sum = warpReduceSum<THREADS_PER_VECTOR>(sum);
        // store value
        if (tid_in_vec == 0)
        {
            // atomicAdd(y + reduce_row_id, sum);
            y[reduce_row_id] = sum;
        }
    }
}



// __global__ void nec_spmv(float *__restrict__ y,
//                          const float *__restrict__ A_value,
//                          const perfSpB_index *__restrict__ A_row_offset,
//                          int * __restrict__ A_ecr_indices,
//                          float *__restrict__ ecr_x,
//                          perfSpB_index row_num,
//                          int *__restrict__ ROW_BLOCK,
//                          int *__restrict__ row_block_ptr)
// {
//     float *local_ecr_xx_val = ecr_x + row_block_ptr[blockIdx.x];
//     __shared__ volatile float x_cache[SHARED_X_PER_BLOCK];

//     for (int i = 0; i < num_loads_per_thread; i++)
//     {
//         unsigned int cache_idx = i * NUM_THREAD_PER_BLOCK + threadIdx.x;
//         if (cache_idx < SHARED_X_PER_BLOCK)
//             x_cache[cache_idx] = local_ecr_xx_val[cache_idx];
//     }
//     __syncthreads();

//     const perfSpB_index reduce_start_row_id = ROW_BLOCK[blockIdx.x];
//     const perfSpB_index reduce_end_row_id = ROW_BLOCK[blockIdx.x + 1];
//     // int num_rows = reduce_end_row_id - reduce_start_row_id;
//     int reduce_row_id = reduce_start_row_id + threadIdx.x;

//     for (; reduce_row_id < reduce_end_row_id; reduce_row_id += blockDim.x)
//     {
//         float sum = static_cast<float>(0);
//         for (int jj = A_row_offset[reduce_row_id]; jj < A_row_offset[reduce_row_id + 1]; jj ++)
//         {
//             int col = A_ecr_indices[jj];
//             if(col < SHARED_X_PER_BLOCK)
//             {
//                 sum += A_value[jj] * x_cache[col];
//             }
//             else
//             {
//                 sum += A_value[jj] * local_ecr_xx_val[col];
//             }
//         }
//         y[reduce_row_id] = sum;
//     }
// }

template <typename ValueType>
__global__ void nec_vector_preprocess_kernel(ValueType *ecr_x,
                                             int *use_x_indices,
                                             const ValueType *x,
                                             int ecr_x_size)
{
    int thread_id = blockDim.x * blockIdx.x + threadIdx.x;
    if (thread_id < ecr_x_size)
    {
        ecr_x[thread_id] = *((ValueType *)x + use_x_indices[thread_id]);
    }
}

perfSpB_info perfSpB_SpMV_Nec_FP32(perfSpB_operation_t op,
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
    perfSpB_index nvals = matA_csr->nnz;
    perfSpB_index nrows = matA->row;
    perfSpB_index ncols = matA->col;

    perfSpB_index NNZ_PER_BLOCK = ceil(nvals / (BLOCKS_EXP));

    int *rowBlocks, *d_rowBlocks;
    rowBlocks = (int *)malloc((vecY->n) * sizeof(int));
    int countRowBlocks = spmv_csr_adaptive_rowblocks(matA_csr->ptr, vecY->n, rowBlocks, NNZ_PER_BLOCK);
    printf("\n countRowBlocks = %d \n", countRowBlocks);
    //////////////////////////////////ECR start//////////////////////////////////
    int *NEC_NUM;
    int **use_x_indices;
    float **ecr_xx_val;

    perfSpB_index A_COLS = ncols;
    perfSpB_index A_ROWS = nrows;
    int *ecr_indices = (int *)malloc((nvals + 10) * sizeof(int));
    memset(ecr_indices, 0, (nvals + 10) * sizeof(int));

    NEC_NUM = (int *)malloc((countRowBlocks + 1) * sizeof(int));
    memset(NEC_NUM, 0, sizeof(int) * (countRowBlocks + 1));

    use_x_indices = (int **)malloc((countRowBlocks + 1) * sizeof(int *));
    ecr_xx_val = (float **)malloc((countRowBlocks + 1) * sizeof(float *));
    int acc_nec_num = 0;
    for (int row_blk_id = 0; row_blk_id < countRowBlocks; row_blk_id++)
    {
        int *not_null_col_flag = (int *)malloc(A_COLS * sizeof(int));
        int *IDX_MAP = (int *)malloc(A_COLS * sizeof(int));
        int *IDX_OFFSET = (int *)malloc(A_COLS * sizeof(int));
        use_x_indices[row_blk_id] = (int *)malloc(A_COLS * sizeof(int));
        memset(use_x_indices[row_blk_id], 0, A_COLS * sizeof(int));

        int startRow = rowBlocks[row_blk_id];
        int nextStartRow = rowBlocks[row_blk_id + 1];

        for (perfSpB_index col = 0; col < A_COLS; col++)
        {
            IDX_MAP[col] = col;
            not_null_col_flag[col] = 1;
            IDX_OFFSET[col] = 1;
        }
        for (int j = matA_csr->ptr[startRow]; j < matA_csr->ptr[nextStartRow]; ++j)
        {
            not_null_col_flag[matA_csr->indices[j]] = 0;
        }
        IDX_OFFSET[0] = not_null_col_flag[0];
        for (perfSpB_index col = 1; col < A_COLS; col++)
        {
            IDX_OFFSET[col] = IDX_OFFSET[col - 1] + not_null_col_flag[col];
        }
        for (perfSpB_index col = 0; col < A_COLS; col++)
        {
            IDX_MAP[col] = IDX_MAP[col] - IDX_OFFSET[col];
        }
        {
            for (int j = matA_csr->ptr[startRow]; j < matA_csr->ptr[nextStartRow]; ++j)
            {
                ecr_indices[j] = IDX_MAP[matA_csr->indices[j]];
            }
        }
        int p = 0;
        for (perfSpB_index col = 0; col < A_COLS; col++)
        {
            if (not_null_col_flag[col] != 1)
            {
                use_x_indices[row_blk_id][p] = col;
                p++;
            }
        }
        NEC_NUM[row_blk_id] = p;
        acc_nec_num += p;
        ecr_xx_val[row_blk_id] = (float *)malloc(p * sizeof(float));
        free(not_null_col_flag);
        free(IDX_MAP);
        free(IDX_OFFSET);
    }
    // use_x_indices 转换为一维 h_use_x_indices
    int *row_blk_ptr = (int *)malloc((countRowBlocks) * sizeof(int));
    int *h_use_x_indices = (int *)malloc((acc_nec_num) * sizeof(int));
    float *h_ecr_xx_val = (float *)malloc((acc_nec_num) * sizeof(float));
    memset(h_use_x_indices, 0, (acc_nec_num) * sizeof(int));
    memset(h_ecr_xx_val, 0.0, (acc_nec_num) * sizeof(float));
    perfSpB_index p = 0, acc = 0;
    for (int row_blk_id = 0; row_blk_id < countRowBlocks; row_blk_id++)
    {
        int nec_num = NEC_NUM[row_blk_id];
        row_blk_ptr[row_blk_id] = acc;
        for (int j = 0; j < nec_num; j++)
        {
            h_use_x_indices[p++] = use_x_indices[row_blk_id][j];
        }
        acc += nec_num;
    }

    // row 与  每个行块id的映射
    perfSpB_index *h_ROW_BLOCK_ID = (perfSpB_index *)malloc((A_ROWS) * sizeof(perfSpB_index));
    memset(h_ROW_BLOCK_ID, 0, (A_ROWS) * sizeof(perfSpB_index));
    for (int row_blk_id = 0; row_blk_id < countRowBlocks; row_blk_id++)
    {
        for (int row = rowBlocks[row_blk_id]; row < rowBlocks[row_blk_id + 1]; ++row)
        {
            h_ROW_BLOCK_ID[row] = row_blk_id;
        }
    }

    //////////////////////////////////ECR  end//////////////////////////////////
    int *d_NEC_NUM;
    int *d_use_x_indices;
    int *d_row_blk_ptr;
    float *d_ecr_xx_val;
    float *d_vecX_csr;

    cudaMalloc(&d_NEC_NUM, (countRowBlocks + 1) * sizeof(int));
    cudaMalloc(&d_use_x_indices, acc_nec_num * sizeof(int));
    cudaMalloc(&d_row_blk_ptr, countRowBlocks * sizeof(int));
    cudaMalloc(&d_ecr_xx_val, acc_nec_num * sizeof(float));
    cudaMalloc(&d_vecX_csr, sizeof(float) * vecX->n);
    cudaMemcpy(d_NEC_NUM, NEC_NUM, sizeof(int) * (countRowBlocks + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_use_x_indices, h_use_x_indices, sizeof(int) * acc_nec_num, cudaMemcpyHostToDevice);
    cudaMemcpy(d_row_blk_ptr, row_blk_ptr, sizeof(int) * countRowBlocks, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ecr_xx_val, h_ecr_xx_val, sizeof(float) * acc_nec_num, cudaMemcpyHostToDevice);
    cudaMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, cudaMemcpyHostToDevice);

    float *d_vecY_csr, *d_val;
    perfSpB_index *d_ptr, *d_ROW_BLOCK_ID;
    int *d_ecr_indices;
    cudaMalloc(&d_vecY_csr, sizeof(float) * vecY->n);
    cudaMalloc(&d_val, sizeof(float) * matA_csr->nnz);
    cudaMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));
    cudaMalloc(&d_ROW_BLOCK_ID, sizeof(perfSpB_index) * A_ROWS);
    cudaMalloc(&d_ecr_indices, (nvals + 10) * sizeof(int));
    cudaMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_ROW_BLOCK_ID, h_ROW_BLOCK_ID, sizeof(perfSpB_index) * A_ROWS, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ecr_indices, ecr_indices, sizeof(int) * (nvals + 10), cudaMemcpyHostToDevice);

    cudaMalloc(&d_rowBlocks, countRowBlocks * sizeof(int));
    cudaMemcpy(d_rowBlocks, rowBlocks, countRowBlocks * sizeof(int), cudaMemcpyHostToDevice);

    unsigned int NUM_BLOCKS = static_cast<unsigned int>((acc_nec_num + (1024 - 1)) / 1024);
    
    cuda_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        nec_vector_preprocess_kernel<float><<<NUM_BLOCKS, 1024>>>(d_ecr_xx_val, d_use_x_indices, d_vecX_csr, acc_nec_num);
        nec_spmv_v<float, 128, 2><<<countRowBlocks, 256>>>(d_vecY_csr, d_val, d_ptr, d_ecr_indices, d_ecr_xx_val, vecY->n, d_rowBlocks, d_row_blk_ptr);
        // nec_spmv<<<countRowBlocks, 512>>>(d_vecY_csr, d_val, d_ptr, d_ecr_indices, d_ecr_xx_val, vecY->n, d_rowBlocks, d_row_blk_ptr);
    }

    cuda_time_test_end();
    double runtime1 = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime1 / 1000) * 1e9);

    cudaDeviceSynchronize();
    printf("\n ------------------------------------------------------------------------------");
    printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime1);
    // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
    printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);
    printf(" ------------------------------------------------------------------------------ \n");

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
    cudaFree(d_ptr);

    return perfSpB_success;
}
