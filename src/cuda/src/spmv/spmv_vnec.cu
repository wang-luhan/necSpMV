#include <cuda.h>
#include <cuda_runtime.h>
#include <spmv_cuda.h>
#include "cuda_timer.h"

#define test_iter 2000
#define NUM_ROW_BLOCKS 128

void MergePathDivide(
    int diagonal,
    perfSpB_index *a,
    int *b,
    int a_len,
    int b_len,
    perfSpB_coord *path_coordinate)
{
    // Diagonal search range (in x coordinate space)
    int x_min = max(diagonal - b_len, 0);
    int x_max = min(diagonal, a_len);
    // printf("\n x_min = %d and x_max = %d \n", x_min, x_max);

    // 2D binary-search along the diagonal search range
    while (x_min < x_max)
    {
        int pivot = (x_min + x_max) >> 1;
        if ((int)a[pivot] <= b[diagonal - pivot - 1])
        {
            // Keep top-right half of diagonal range
            x_min = pivot + 1;
        }
        else
        {
            // Keep bottom-left half of diagonal range
            x_max = pivot;
        }
    }
    path_coordinate->x = min(x_min, a_len);
    path_coordinate->y = diagonal - x_min;
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

// template <typename ValueType, unsigned int VECTORS_PER_BLOCK, unsigned int THREADS_PER_VECTOR>
// __global__ void spmv_vnec_kernel_cuda(ValueType *__restrict__ y,
//                                       const ValueType *__restrict__ A_value,
//                                       const perfSpB_index *__restrict__ A_col_index,
//                                       const perfSpB_index *__restrict__ A_row_offset,
//                                       const ValueType *__restrict__ x,
//                                       perfSpB_index row_num)
// {
//     const perfSpB_index THREADS_PER_BLOCK = VECTORS_PER_BLOCK * THREADS_PER_VECTOR;
//     const perfSpB_index thread_id = THREADS_PER_BLOCK * blockIdx.x + threadIdx.x; // global thread index
//     const perfSpB_index thread_lane = threadIdx.x & (THREADS_PER_VECTOR - 1);     // thread index within the vector/row
//     const perfSpB_index row_id = thread_id / THREADS_PER_VECTOR;                  // global vector index

//     if (row_id < row_num)
//     {
//         const perfSpB_index row_start = A_row_offset[row_id]; // same as: row_start = Ap[row];
//         const perfSpB_index row_end = A_row_offset[row_id + 1];

//         // initialize local sum
//         ValueType sum = 0;

//         // accumulate local sums
//         for (perfSpB_index jj = row_start + thread_lane; jj < row_end; jj += THREADS_PER_VECTOR)
//             sum += A_value[jj] * x[A_col_index[jj]];

//         sum = warpReduceSum<THREADS_PER_VECTOR>(sum);
//         if (thread_lane == 0)
//         {
//             y[row_id] = sum;
//         }
//     }
// }



template <typename ValueType, unsigned int VECTORS_PER_BLOCK, unsigned int THREADS_PER_VECTOR>
__global__ void vnec_spmv(ValueType *__restrict__ y,
                                      const ValueType *__restrict__ A_value,
                                      const perfSpB_index *__restrict__ A_row_offset,
                                      int * A_ecr_indices,
                                      ValueType * ecr_x,
                                      perfSpB_index row_num,
                                      perfSpB_index *ROW_BLOCK_ID,
                                      int * row_block_ptr)
{
    const perfSpB_index thread_id = blockDim.x * blockIdx.x + threadIdx.x; // global thread index
    const perfSpB_index thread_lane = threadIdx.x & (THREADS_PER_VECTOR - 1);     // thread index within the vector/row
    const perfSpB_index row_id = thread_id / THREADS_PER_VECTOR;                  // global vector index
    const perfSpB_index row_block_id = ROW_BLOCK_ID[row_id];                  // global vector index

    perfSpB_index row_block_start = row_block_ptr[row_block_id];
    float *local_ecr_xx_val = ecr_x + row_block_start;

    if (row_id < row_num)
    {
        const perfSpB_index row_start = A_row_offset[row_id]; // same as: row_start = Ap[row];
        const perfSpB_index row_end = A_row_offset[row_id + 1];

        // initialize local sum
        ValueType sum = 0;

        // accumulate local sums
        for (perfSpB_index jj = row_start + thread_lane; jj < row_end; jj += THREADS_PER_VECTOR)
            sum += A_value[jj] * local_ecr_xx_val[A_ecr_indices[jj]];

        sum = warpReduceSum<THREADS_PER_VECTOR>(sum);
        if (thread_lane == 0)
        {
            y[row_id] = sum;
        }
    }
}


template <typename ValueType, unsigned int VECTORS_PER_BLOCK, unsigned int THREADS_PER_VECTOR>
__global__ void vnec_spmv_L(ValueType *__restrict__ y,
                                      const ValueType *__restrict__ A_value,
                                      const perfSpB_index *__restrict__ A_row_offset,
                                      int * A_ecr_indices,
                                      ValueType * ecr_x,
                                      perfSpB_index row_num,
                                      perfSpB_index *ROW_BLOCK_ID,
                                      int * row_block_ptr)
{
    const perfSpB_index thread_id = blockDim.x * blockIdx.x + threadIdx.x; // global thread index
    const perfSpB_index thread_lane = threadIdx.x & (THREADS_PER_VECTOR - 1);     // thread index within the vector/row
    const perfSpB_index row_id = thread_id / THREADS_PER_VECTOR;                  // global vector index
    const perfSpB_index row_block_id = ROW_BLOCK_ID[row_id];                  // global vector index
    const perfSpB_index lane_id = threadIdx.x % 32;                         // global vector index

    perfSpB_index row_block_start = row_block_ptr[row_block_id];
    float *local_ecr_xx_val = ecr_x + row_block_start;

    if (row_id < row_num)
    {
        const perfSpB_index row_start = A_row_offset[row_id]; // same as: row_start = Ap[row];
        const perfSpB_index row_end = A_row_offset[row_id + 1];

        // initialize local sum
        ValueType sum = 0;

        // accumulate local sums
        for (perfSpB_index jj = row_start + thread_lane; jj < row_end; jj += THREADS_PER_VECTOR)
            sum += A_value[jj] * local_ecr_xx_val[A_ecr_indices[jj]];

        for (int offset = 16; offset > 0; offset >>= 1)
        {
            sum += __shfl_down_sync(0xffffffff, sum, offset);
        }
        if (lane_id == 0)
        {
            atomicAdd(&y[row_id], sum);
        }
    }
}

// TODO: 时间太长
template <typename ValueType>
__global__ void vector_preprocess_kernel(ValueType *ecr_x,
                        int *use_x_indices,
                        const ValueType *x,
                        int ecr_x_size)
{
    int thread_id = blockDim.x * blockIdx.x + threadIdx.x;
    if(thread_id < ecr_x_size)
    {
        ecr_x[thread_id] = *((ValueType *)x + use_x_indices[thread_id]);
    }
}

perfSpB_info perfSpB_SpMV_VNEC_FP32(perfSpB_operation_t op,
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

    int *NEC_NUM;
    int **use_x_indices;
    float **ecr_xx_val;

    perfSpB_index nrows = matA->row;
    perfSpB_index ncols = matA->col;
    perfSpB_index nvals = matA_csr->nnz;
    /////////////////////////////////////merge-path opt/////////////////////////////////////
    int num_merge_items = nvals + nrows;
    int items_per_thread = (num_merge_items + NUM_ROW_BLOCKS - 1) / NUM_ROW_BLOCKS;
    int *diagonal_start = (int *)malloc((NUM_ROW_BLOCKS) * sizeof(int));
    int *diagonal_end = (int *)malloc((NUM_ROW_BLOCKS) * sizeof(int));
    perfSpB_coord *row_block_coo_start = (perfSpB_coord *)malloc((NUM_ROW_BLOCKS) * sizeof(perfSpB_coord));
    perfSpB_coord *row_block_coo_end = (perfSpB_coord *)malloc((NUM_ROW_BLOCKS) * sizeof(perfSpB_coord));
    int *nz_indices = (int *)malloc((nvals) * sizeof(int));
    for (perfSpB_index i = 0; i < nvals; i++)
    {
        nz_indices[i] = i;
    }
    for (int row_blk_id = 0; row_blk_id < NUM_ROW_BLOCKS; row_blk_id++)
    {
        diagonal_start[row_blk_id] = min(items_per_thread * row_blk_id, num_merge_items);
        diagonal_end[row_blk_id] = min(diagonal_start[row_blk_id] + items_per_thread, num_merge_items);
        MergePathDivide(diagonal_start[row_blk_id], (matA_csr->ptr + 1), nz_indices, nrows, nvals, row_block_coo_start + row_blk_id);
        MergePathDivide(diagonal_end[row_blk_id], (matA_csr->ptr + 1), nz_indices, nrows, nvals, row_block_coo_end + row_blk_id);
        row_block_coo_end[row_blk_id].x = (row_block_coo_end[row_blk_id].x) + 1;
        row_block_coo_start[row_blk_id].x = (row_block_coo_start[row_blk_id].x) + 1;
        if (row_blk_id == 0)
            row_block_coo_start[row_blk_id].x--;
        if (row_blk_id == NUM_ROW_BLOCKS - 1)
            row_block_coo_end[row_blk_id].x--;
        row_block_coo_start[row_blk_id].y = matA_csr->ptr[row_block_coo_start[row_blk_id].x];
        row_block_coo_end[row_blk_id].y = matA_csr->ptr[row_block_coo_end[row_blk_id].x];
    }
    /////////////////////////////////////ECR/////////////////////////////////////

    perfSpB_index A_COLS = ncols;
    perfSpB_index A_ROWS = nrows;
    int *ecr_indices = (int *)malloc((nvals + 10) * sizeof(int));
    memset(ecr_indices, 0, (nvals + 10) * sizeof(int));

    NEC_NUM = (int *)malloc((NUM_ROW_BLOCKS + 1) * sizeof(int));
    memset(NEC_NUM, 0, sizeof(int) * (NUM_ROW_BLOCKS + 1));

    use_x_indices = (int **)malloc((NUM_ROW_BLOCKS + 1) * sizeof(int *));
    ecr_xx_val = (float **)malloc((NUM_ROW_BLOCKS + 1) * sizeof(float *));
    int acc_nec_num = 0;
    for (int row_blk_id = 0; row_blk_id < NUM_ROW_BLOCKS; row_blk_id++)
    {
        int *not_null_col_flag = (int *)malloc(A_COLS * sizeof(int));
        int *IDX_MAP = (int *)malloc(A_COLS * sizeof(int));
        int *IDX_OFFSET = (int *)malloc(A_COLS * sizeof(int));
        use_x_indices[row_blk_id] = (int *)malloc(A_COLS * sizeof(int));
        memset(use_x_indices[row_blk_id], 0, A_COLS * sizeof(int));

        perfSpB_coord row_block_coo_start_t = row_block_coo_start[row_blk_id];
        perfSpB_coord row_block_coo_end_t = row_block_coo_end[row_blk_id];

        for (perfSpB_index col = 0; col < A_COLS; col++)
        {
            IDX_MAP[col] = col;
            not_null_col_flag[col] = 1;
            IDX_OFFSET[col] = 1;
        }
        for (int j = row_block_coo_start_t.y; j < row_block_coo_end_t.y; ++j)
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
            for (int j = row_block_coo_start_t.y; j < row_block_coo_end_t.y; ++j)
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
    // 转换为一维
    int * row_blk_ptr =  (int *)malloc((NUM_ROW_BLOCKS) * sizeof(int));
    // int compact_x_dim = (NUM_ROW_BLOCKS * A_COLS + 1);// TODO: 太多冗余了
    int *h_use_x_indices = (int *)malloc((acc_nec_num) * sizeof(int));
    float *h_ecr_xx_val = (float *)malloc((acc_nec_num) * sizeof(float));
    memset(h_use_x_indices, 0, (acc_nec_num) * sizeof(int));
    memset(h_ecr_xx_val, 0.0, (acc_nec_num) * sizeof(float));
    perfSpB_index p = 0, acc = 0;
    for (int row_blk_id = 0; row_blk_id < NUM_ROW_BLOCKS; row_blk_id++)
    {
        int nec_num = NEC_NUM[row_blk_id];
        row_blk_ptr[row_blk_id] = acc;
        for (int j = 0; j < nec_num; j++)
        {
            h_use_x_indices[p++] = use_x_indices[row_blk_id][j];
        }
        acc += nec_num;
    }

    perfSpB_index *h_ROW_BLOCK_ID = (perfSpB_index *)malloc((A_ROWS) * sizeof(perfSpB_index));
    memset(h_ROW_BLOCK_ID, 0, (A_ROWS) * sizeof(perfSpB_index));

    for (int row_blk_id = 0; row_blk_id < NUM_ROW_BLOCKS; row_blk_id++)
    {
        for (int row = row_block_coo_start[row_blk_id].x; row < row_block_coo_end[row_blk_id].x; ++row)
        {
            h_ROW_BLOCK_ID[row] = row_blk_id;
        }
    }

    /////////////////////////////////////VNEC Kernel/////////////////////////////////////

    int *d_NEC_NUM;
    int *d_use_x_indices;
    int *d_row_blk_ptr;
    float *d_ecr_xx_val;
    float *d_vecX_csr;

    cudaMalloc(&d_NEC_NUM, (NUM_ROW_BLOCKS + 1) * sizeof(int));
    cudaMalloc(&d_use_x_indices, acc_nec_num * sizeof(int));
    cudaMalloc(&d_row_blk_ptr, NUM_ROW_BLOCKS * sizeof(int));
    cudaMalloc(&d_ecr_xx_val, acc_nec_num * sizeof(float));
    cudaMalloc(&d_vecX_csr, sizeof(float) * vecX->n);
    cudaMemcpy(d_NEC_NUM, NEC_NUM, sizeof(int) * (NUM_ROW_BLOCKS + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_use_x_indices, h_use_x_indices, sizeof(int) * acc_nec_num, cudaMemcpyHostToDevice);
    cudaMemcpy(d_row_blk_ptr, row_blk_ptr, sizeof(int) * NUM_ROW_BLOCKS, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ecr_xx_val, h_ecr_xx_val, sizeof(float) * acc_nec_num, cudaMemcpyHostToDevice);
    cudaMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, cudaMemcpyHostToDevice);
    



    float *d_vecY_csr, *d_val;
    perfSpB_index *d_ptr, *d_ROW_BLOCK_ID;
    int * d_ecr_indices;
    cudaMalloc(&d_vecY_csr, sizeof(float) * vecY->n);
    cudaMalloc(&d_val, sizeof(float) * matA_csr->nnz);
    cudaMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));
    cudaMalloc(&d_ROW_BLOCK_ID, sizeof(perfSpB_index) * A_ROWS);
    cudaMalloc(&d_ecr_indices, (nvals + 10) * sizeof(int));
    cudaMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_ROW_BLOCK_ID, h_ROW_BLOCK_ID, sizeof(perfSpB_index) * A_ROWS, cudaMemcpyHostToDevice);
    cudaMemcpy(d_ecr_indices, ecr_indices, sizeof(int) * (nvals + 10), cudaMemcpyHostToDevice);

    int mean_col_num = (matA_csr->nnz + (vecY->n - 1)) / vecY->n;
    printf("\n  The average col num is: %d\n", mean_col_num);
    int block_size_ = 256;
    unsigned int NUM_BLOCKS = static_cast<unsigned int>((acc_nec_num + (block_size_ - 1)) / block_size_);
    // vector_preprocess_kernel<float><<<NUM_BLOCKS, 256>>>(d_ecr_xx_val, d_use_x_indices, d_NEC_NUM, d_vecX_csr, d_row_blk_ptr);
    cuda_time_test_start();

    for (int i = 0; i < test_iter; i++)
    {
        // cudaMemset(d_vecY_csr, 0.0, sizeof(float) * (vecY->n)); //TODO: Accuracy test
        vector_preprocess_kernel<float><<<NUM_BLOCKS, block_size_>>>(d_ecr_xx_val, d_use_x_indices, d_vecX_csr, acc_nec_num);
        
        if (mean_col_num <= 2)
        {
            const int THREADS_PER_VECTOR = 2;
            const unsigned int VECTORS_PER_BLOCK = 128;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            vnec_spmv<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_ptr, d_ecr_indices, d_ecr_xx_val, vecY->n, d_ROW_BLOCK_ID, d_row_blk_ptr);
        }
        else if (mean_col_num > 2 && mean_col_num <= 4)
        {
            const int THREADS_PER_VECTOR = 4;
            const unsigned int VECTORS_PER_BLOCK = 64;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            vnec_spmv<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_ptr, d_ecr_indices, d_ecr_xx_val, vecY->n, d_ROW_BLOCK_ID, d_row_blk_ptr);
        }
        else if (mean_col_num > 4 && mean_col_num <= 8)
        {
            const int THREADS_PER_VECTOR = 8;
            const unsigned int VECTORS_PER_BLOCK = 32;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            vnec_spmv<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_ptr, d_ecr_indices, d_ecr_xx_val, vecY->n, d_ROW_BLOCK_ID, d_row_blk_ptr);
        }
        else if (mean_col_num > 8 && mean_col_num <= 16)
        {
            const int THREADS_PER_VECTOR = 16;
            const unsigned int VECTORS_PER_BLOCK = 16;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            vnec_spmv<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_ptr, d_ecr_indices, d_ecr_xx_val, vecY->n, d_ROW_BLOCK_ID, d_row_blk_ptr);
        }
        else if (mean_col_num > 16 && mean_col_num <= 64)
        {
            const int THREADS_PER_VECTOR = 32;
            const unsigned int VECTORS_PER_BLOCK = 8;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            vnec_spmv<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_ptr, d_ecr_indices, d_ecr_xx_val, vecY->n, d_ROW_BLOCK_ID, d_row_blk_ptr);
        }
        else if (mean_col_num > 64)
    
        {
            const int THREADS_PER_VECTOR = 256;
            const unsigned int VECTORS_PER_BLOCK = 1;
            const unsigned int NUM_BLOCKS = static_cast<unsigned int>((vecY->n + (VECTORS_PER_BLOCK - 1)) / VECTORS_PER_BLOCK);
            vnec_spmv_L<float, VECTORS_PER_BLOCK, THREADS_PER_VECTOR><<<NUM_BLOCKS, 256>>>(d_vecY_csr, d_val, d_ptr, d_ecr_indices, d_ecr_xx_val, vecY->n, d_ROW_BLOCK_ID, d_row_blk_ptr);
        }
    }
    cuda_time_test_end();
    
    // cudaMemcpy(h_ecr_xx_val, d_ecr_xx_val, sizeof(float) * acc_nec_num, cudaMemcpyDeviceToHost);
    // for (int row_blk_id = 0; row_blk_id < NUM_ROW_BLOCKS; row_blk_id++)
    // {

    //     perfSpB_index row_blk_start = row_blk_ptr[row_blk_id];
    //     float *local_ecr_xx_val = h_ecr_xx_val + row_blk_start;
    //     float t1, t2, t3;
    //     for (int i = row_block_coo_start[row_blk_id].x; i < row_block_coo_end[row_blk_id].x; ++i)
    //     {
    //         t1 = 0.0f;
    //         perfSpB_index ptr_start = matA_csr->ptr[i];
    //         perfSpB_index n_one_line = matA_csr->ptr[i + 1] - ptr_start;

    //         for (perfSpB_index j = 0; j < n_one_line; j++)
    //         {
    //             t2 = ((float *)matA_csr->val)[j + ptr_start];
    //             t3 = 0.0f;
    //             perfSpB_index v_idx = ecr_indices[j + ptr_start];
    //             t3 = local_ecr_xx_val[v_idx];
    //             t1 += t2 * t3;
    //         }
    //         ((float *)vecY_csr->values)[i] = t1;
    //     }
    // }


    /////////////////////////////////////CUDA 计算结束/////////////////////////////////////
    double runtime = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime / 1000) * 1e9);
    cudaDeviceSynchronize();
    printf("\n -------------------------------------------------- \n");
    printf(" SpMV VNEC CUDA kernel runtime = %g ms\n", runtime);
    printf("\n SpMV VNEC Performance  = %lf GFLOPS", gflops);
    printf("\n -------------------------------------------------- \n");


    cudaMemcpy(((float *)vecY_csr->values), d_vecY_csr, sizeof(float) * vecY->n, cudaMemcpyDeviceToHost);

    cudaError_t cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess)
    {
        printf("Error:%s\n", cudaGetErrorString(cudaStatus));
        exit(EXIT_FAILURE);
    }
    cudaFree(d_vecY_csr);

    cudaFree(d_NEC_NUM);
    cudaFree(d_use_x_indices);
    cudaFree(d_ecr_xx_val);
    cudaFree(d_vecX_csr);

    cudaFree(d_val);
    cudaFree(d_ecr_indices);
    cudaFree(d_ptr);
    cudaFree(d_ROW_BLOCK_ID);


    

    return perfSpB_success;
}