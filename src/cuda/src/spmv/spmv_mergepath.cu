#include <cuda.h>
#include <cuda_runtime.h>
#include <spmv_cuda.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cuda_timer.h"

#define test_iter 2000

#define NUM_ROW_BLOCKS 320
#define L_THREADS 256
// #define G_THREADS 81920

// typedef struct T_INFO
// {
//     perfSpB_coord *thread_coord_start;
//     perfSpB_coord *thread_coord_end;
// } T_INFO;

__global__ void spmv_product_kernel(const perfSpB_index *__restrict__ A_col_index,
    const float *elem,
    const float *__restrict__ x,
    perfSpB_index num_nz,
    float *middle)
{
    unsigned int elem_idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (elem_idx < num_nz)
    {
        middle[elem_idx] = elem[elem_idx] * x[A_col_index[elem_idx]];
    }
}


template <typename T>
__global__ void spmv_div_pre(perfSpB_coord *thread_coord_start_array, perfSpB_coord *thread_coord_end_array, perfSpB_index *d_ptr, perfSpB_index d_nnz, perfSpB_index nrows, perfSpB_index *row_block_ptr)
{
    perfSpB_index gid = blockIdx.x * blockDim.x + threadIdx.x;
    perfSpB_index tid = threadIdx.x;

    perfSpB_index block_first_row_id = row_block_ptr[blockIdx.x];
    perfSpB_index block_last_row_id = row_block_ptr[blockIdx.x + 1];
    perfSpB_index block_first_nnz_id = d_ptr[block_first_row_id];
    perfSpB_index block_last_nnz_id = d_ptr[block_last_row_id];

    perfSpB_index block_nnzs = block_last_nnz_id - block_first_nnz_id;
    perfSpB_index block_rows = block_last_row_id - block_first_row_id;

    perfSpB_index thread_nnzs = (block_nnzs + blockDim.x - 1) / blockDim.x;
    perfSpB_index thread_first_nnz_id = min(block_first_nnz_id + tid * thread_nnzs, block_last_nnz_id);
    perfSpB_index thread_last_nnz_id = min(thread_first_nnz_id + thread_nnzs, block_last_nnz_id);
    perfSpB_index thread_first_row_id, thread_last_row_id;
    // if(blockIdx.x == 320)
    // {
    //     printf("\n thread_nnzs = %ld \n", thread_nnzs);
    // }
    for(int i = block_first_row_id; i < block_first_row_id + block_rows; i ++)
    {
        if(thread_first_nnz_id >= d_ptr[i] && thread_first_nnz_id < d_ptr[i + 1])
        {
            thread_first_row_id = i;
            break;
        }
    }

    for(int i = block_first_row_id; i < block_first_row_id + block_rows; i ++)
    {
        if(thread_last_nnz_id >= d_ptr[i] && thread_last_nnz_id < d_ptr[i + 1])
        {
            thread_last_row_id = i;
            break;
        }
    }
    thread_coord_start_array[gid].x = thread_first_row_id;
    thread_coord_start_array[gid].y = thread_first_nnz_id;
    thread_coord_end_array[gid].x = thread_last_row_id;
    thread_coord_end_array[gid].y = thread_last_nnz_id;
}

template <typename T>
__global__ void spmv_merge_kernel_right(perfSpB_coord *thread_coord_start_array,
                                  perfSpB_coord *thread_coord_end_array,
                                  T *d_val,
                                  perfSpB_index *d_ptr,
                                  perfSpB_index *d_cols,
                                  perfSpB_index d_nnz,
                                  T *d_vector,
                                  perfSpB_index nrows,
                                  T *d_out)
{
    int gid = blockIdx.x * blockDim.x + threadIdx.x;
    // int tid = threadIdx.x;

    perfSpB_index *row_end_offsets = d_ptr + 1; // Merge list A
    // __shared__ T value_carry_out[L_THREADS];
    // __shared__ int row_carry_out[L_THREADS];
    perfSpB_coord thread_coord_start = thread_coord_start_array[gid];
    perfSpB_coord thread_coord_end = thread_coord_end_array[gid];
    
    for (; thread_coord_start.x < thread_coord_end.x; ++thread_coord_start.x)
    {
        float row_total = 0.0;
        for (; thread_coord_start.y < (int)row_end_offsets[thread_coord_start.x]; ++thread_coord_start.y)
        {
            row_total += d_val[thread_coord_start.y] * d_vector[d_cols[thread_coord_start.y]];
        } // End of this line
        d_out[thread_coord_start.x] = row_total;
    }
    //  finish one row, calculate the partial sum of the next row
    //  Consume partial portion of thread's last row (accumulate any nonzeros for a partial row shared with the next thread)
    float row_partial = 0.0;
    for (; thread_coord_start.y < thread_coord_end.y; ++thread_coord_start.y)
    {
        row_partial += d_val[thread_coord_start.y] * d_vector[d_cols[thread_coord_start.y]];
    }
    __syncthreads();
    /*
    // save the thread's running total and row-id for subsequent fix-up
    row_carry_out[tid] = thread_coord_end.x; // The value of this row is incomplete
    value_carry_out[tid] = row_partial;    // This row would be a little bit more complete with this. Each thread might have one of these
    __syncthreads();
    */
    // atomicAdd(d_out + row_carry_out[tid], value_carry_out[tid]);
    atomicAdd(d_out + thread_coord_end.x, row_partial);
}


template <typename T>
__global__ void spmv_merge_kernel_right_(perfSpB_coord *thread_coord_start_array,
                                  perfSpB_coord *thread_coord_end_array,
                                  T *d_val,
                                  perfSpB_index *d_ptr,
                                  perfSpB_index *d_cols,
                                  perfSpB_index d_nnz,
                                  T *d_vector,
                                  perfSpB_index nrows,
                                  T *d_out)
{
    int gid = blockIdx.x * blockDim.x + threadIdx.x;
    // int tid = threadIdx.x;

    perfSpB_index *row_end_offsets = d_ptr + 1; // Merge list A

    perfSpB_coord thread_coord_start = thread_coord_start_array[gid];
    perfSpB_coord thread_coord_end = thread_coord_start_array[gid+1];
    
    for (; thread_coord_start.x < thread_coord_end.x; ++thread_coord_start.x)
    {
        float row_total = 0.0;
        for (; thread_coord_start.y < (int)row_end_offsets[thread_coord_start.x]; ++thread_coord_start.y)
        {
            row_total += d_val[thread_coord_start.y] * d_vector[d_cols[thread_coord_start.y]];
        } // End of this line
        d_out[thread_coord_start.x] = row_total;
    }
    //  finish one row, calculate the partial sum of the next row
    //  Consume partial portion of thread's last row (accumulate any nonzeros for a partial row shared with the next thread)
    float row_partial = 0.0;
    for (; thread_coord_start.y < thread_coord_end.y; ++thread_coord_start.y)
    {
        row_partial += d_val[thread_coord_start.y] * d_vector[d_cols[thread_coord_start.y]];
    }
    __syncthreads();

    atomicAdd(d_out + thread_coord_end.x, row_partial);
}

//TODO: eda实现
template <typename T>
__global__ void spmv_merge_kernel(perfSpB_coord *thread_coord_start_array,
                                  perfSpB_coord *thread_coord_end_array,
                                  perfSpB_index *d_ptr,
                                  T* d_middle,
                                  perfSpB_index d_nnz,
                                  perfSpB_index nrows,
                                  T *d_out)
{
    int gid = blockIdx.x * blockDim.x + threadIdx.x;
    // int tid = threadIdx.x;

    perfSpB_index *row_end_offsets = d_ptr + 1; // Merge list A

    perfSpB_coord thread_coord_start = thread_coord_start_array[gid];
    perfSpB_coord thread_coord_end = thread_coord_start_array[gid+1];
    
    for (; thread_coord_start.x < thread_coord_end.x; ++thread_coord_start.x)
    {
        float row_total = 0.0;
        for (; thread_coord_start.y < (int)row_end_offsets[thread_coord_start.x]; ++thread_coord_start.y)
        {
            row_total += d_middle[thread_coord_start.y];
        } // End of this line
        d_out[thread_coord_start.x] = row_total;
    }
    //  finish one row, calculate the partial sum of the next row
    //  Consume partial portion of thread's last row (accumulate any nonzeros for a partial row shared with the next thread)
    float row_partial = 0.0;
    for (; thread_coord_start.y < thread_coord_end.y; ++thread_coord_start.y)
    {
        row_partial += d_middle[thread_coord_start.y];
    }
    __syncthreads();

    atomicAdd(d_out + thread_coord_end.x, row_partial);
}

perfSpB_info perfSpB_SpMV_MERGE_FP32(perfSpB_operation_t op,
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
    perfSpB_index nrows = matA->row;
    // perfSpB_index ncols = matA->col;
    perfSpB_index nvals = matA_csr->nnz;

    perfSpB_index NNZ_PER_ROW_BLOCK = ceil(nvals / (NUM_ROW_BLOCKS));
    perfSpB_index *row_block_ptr = (perfSpB_index *)malloc((640 + 2) * sizeof(perfSpB_index));
    perfSpB_index *row_ptr_local = (perfSpB_index *)malloc((vecY->n + 1) * sizeof(perfSpB_index));

    row_block_ptr[0] = 0;
    int b = 0, r = 0, acc = 0;
    int num_row_block_real = NUM_ROW_BLOCKS;

    for (b = 1; b <= 640; b++)
    {
        acc = matA_csr->ptr[r + 1] - matA_csr->ptr[r];// 第r行首先包含在第(b-1)个行块中
        while (r < nrows)
        {
            r++;
            acc += matA_csr->ptr[r + 1] - matA_csr->ptr[r];// 看r+1行是否包含在这个块，若不包含，r+1赋值给row_block_ptr[b]
            if (acc >= NNZ_PER_ROW_BLOCK)
            {
                break;
            }
        }
        row_block_ptr[b] = r;
        if (r >= nrows)
        {
            num_row_block_real = b;
            // printf("\n 666666  num_row_block_real = %d\n", num_row_block_real);
            break;
        }
    }
    // printf("\n r = %d  nrows = %ld \n", r, nrows);

    for (int b = 0; b < num_row_block_real; b++) // 遍历每一个用到的块
    {
        perfSpB_index block_first_nnz_id = matA_csr->ptr[row_block_ptr[b]]; // 每块第一个非零元id
        for (int i = row_block_ptr[b]; i < row_block_ptr[b + 1]; i++)// 遍历b块的每一行
        {
            row_ptr_local[i] = matA_csr->ptr[i] - block_first_nnz_id;// 0 开始的块内行偏移
        }
    }
  

    // for (b = 0; b < num_row_block_real; b++)
    // {
    //     printf("\n [block%d], row%ld-row%ld  nnz= %ld\n", b, row_block_ptr[b], row_block_ptr[b + 1], matA_csr->ptr[row_block_ptr[b + 1]] - matA_csr->ptr[row_block_ptr[b]]);
    // }


    float *d_vecY_csr, *d_vecX_csr, *d_val, *d_middle;
    perfSpB_index *d_indices, *d_ptr, *d_row_block_ptr, *d_ptr_local;
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
    cudaMalloc(&d_ptr_local, sizeof(perfSpB_index) * (vecY->n + 1));
    cudaMalloc(&d_row_block_ptr, (640 + 2) * sizeof(perfSpB_index));
    cudaMalloc(&d_middle, sizeof(float) * matA_csr->nnz);

    cudaMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_ptr_local, row_ptr_local, sizeof(perfSpB_index) * (vecY->n + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, cudaMemcpyHostToDevice);
    cudaMemcpy(d_row_block_ptr, row_block_ptr, (640 + 2) * sizeof(perfSpB_index), cudaMemcpyHostToDevice);
    cudaMemset(d_middle, 0.0, sizeof(float) * (matA_csr->nnz));

    perfSpB_coord *thread_coord_start_array;
    perfSpB_coord *thread_coord_end_array;
    perfSpB_index G_THREADS = num_row_block_real * L_THREADS;

    perfSpB_coord *thread_break = (perfSpB_coord *)malloc((G_THREADS + 1) * sizeof(perfSpB_coord));
    for(int i = 0; i < G_THREADS + 1; i++)
    {
        thread_break[i].x = nrows;
        thread_break[i].y = nvals;
    }



    cudaMalloc((void **)&thread_coord_start_array, sizeof(perfSpB_coord) * (G_THREADS + 1));
    cudaMalloc((void **)&thread_coord_end_array, sizeof(perfSpB_coord) * G_THREADS);
    // cudaMemset(thread_coord_start_array, 0, sizeof(perfSpB_coord) * G_THREADS);
    cudaMemset(thread_coord_end_array, 0, sizeof(perfSpB_coord) * G_THREADS);
    cudaMemcpy(thread_coord_start_array, thread_break, sizeof(perfSpB_coord) * (G_THREADS + 1), cudaMemcpyHostToDevice);
    

    
    spmv_div_pre<float><<<num_row_block_real, L_THREADS>>>(thread_coord_start_array, thread_coord_end_array, d_ptr, nvals, nrows, d_row_block_ptr);

    /////////////////////////////////////pre test/////////////////////////////////////
    perfSpB_coord *t_coo_start_array = (perfSpB_coord *)malloc(sizeof(perfSpB_coord) * G_THREADS);
    perfSpB_coord *t_coo_end_array = (perfSpB_coord *)malloc(sizeof(perfSpB_coord) * G_THREADS);
    cudaMemcpy(t_coo_start_array, thread_coord_start_array, sizeof(perfSpB_coord) * G_THREADS, cudaMemcpyDeviceToHost);
    cudaMemcpy(t_coo_end_array, thread_coord_end_array, sizeof(perfSpB_coord) * G_THREADS, cudaMemcpyDeviceToHost);
    // for (int i = (num_row_block_real - 1) * L_THREADS; i < num_row_block_real * L_THREADS; i++)
    // {
    //     printf("\n [%d][%d] x_start = %d, x_end = %d, y_start = %d, y_end = %d \n",(int)(i/L_THREADS),i, t_coo_start_array[i].x, t_coo_end_array[i].x, t_coo_start_array[i].y, t_coo_end_array[i].y) ;
    // }
    // printf("\n 400725 %ld ~ %ld \n",matA_csr->ptr[400725], matA_csr->ptr[400726]);
    // printf("\n 400726 %ld ~ %ld \n",matA_csr->ptr[400726], matA_csr->ptr[400727]);
    // printf("\n 2 %ld ~ %ld \n",matA_csr->ptr[2], matA_csr->ptr[3]);

    //TODO: 写一个测试t_coo_start_array与t_coo_end_array的脚本
   

    // for (int i = 0; i < num_row_block_real * L_THREADS - 1; i++)
    // {
    //     if((t_coo_end_array[i].x != t_coo_start_array[i+1].x) || (t_coo_end_array[i].y != t_coo_start_array[i+1].y))
    //     {
    //         printf("\n coo div error!!!!, [%d][%d] x_start = %d, x_end = %d, y_start = %d, y_end = %d \n", (int)(i/L_THREADS),i, t_coo_start_array[i].x, t_coo_end_array[i].x, t_coo_start_array[i].y, t_coo_end_array[i].y);
    //         printf("\n coo div error!!!!, [%d][%d] x_start = %d, x_end = %d, y_start = %d, y_end = %d \n", (int)((i+1)/L_THREADS),i+1, t_coo_start_array[i+1].x, t_coo_end_array[i+1].x, t_coo_start_array[i+1].y, t_coo_end_array[i+1].y);
    //     }
    //     // if((t_coo_end_array[i].x == t_coo_start_array[i].x) )
    //     // {
    //     //     printf("\n !!!!, [%d]\n", t_coo_start_array[i].x);
    //     //     // if(t_coo_start_array[i].x > 15000)
    //     //     // {
    //     //     //     break;
    //     //     // }
    //     // }
    // }
     /////////////////////////////////////pre test/////////////////////////////////////
    const unsigned int NUM_BLOCKS = static_cast<unsigned int>((matA_csr->nnz + (1024 - 1)) / 1024);

    cuda_time_test_start();
    for (int i = 0; i < test_iter; i++)
    {
        spmv_product_kernel<<<NUM_BLOCKS, 1024>>>(d_indices, d_val, d_vecX_csr, matA_csr->nnz, d_middle);
        spmv_merge_kernel<float><<<num_row_block_real, L_THREADS>>>(thread_coord_start_array, thread_coord_end_array, d_ptr, d_middle, nvals, vecY->n, d_vecY_csr);
    }
    cuda_time_test_end();
    double runtime = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime / 1000) * 1e9);

    cudaDeviceSynchronize();
    printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime);
    // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
    printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);

    cudaMemcpy(((float *)vecY_csr->values), d_vecY_csr, sizeof(float) * vecY->n, cudaMemcpyDeviceToHost);

    cudaError_t cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess)
    {
        printf("Error:%s\n", cudaGetErrorString(cudaStatus));
        exit(EXIT_FAILURE);
    }
    cudaFree(thread_coord_start_array);
    cudaFree(thread_coord_end_array);
    cudaFree(d_vecY_csr);
    cudaFree(d_vecX_csr);
    cudaFree(d_val);
    cudaFree(d_indices);
    cudaFree(d_ptr);

    return perfSpB_success;
}
