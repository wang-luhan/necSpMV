#include <cuda.h>
#include <cuda_runtime.h>
#include <spmv_cuda.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>  // 包含 std::sort
#include <functional> // 包含 std::greater

#include "cuda_timer.h"

#define test_iter 1


template <typename I, typename T>
__device__ __forceinline__ void line_enhance_direct_reduce(const I reduce_row_id, const I block_row_end,
                                                           const I reduce_row_idx_begin, const I reduce_row_idx_end,
                                                           const I block_round_inx_start, const I block_round_inx_end,
                                                           const T *shared_val, T &sum) {
  if (reduce_row_id < block_row_end) {
    if (reduce_row_idx_begin < block_round_inx_end && reduce_row_idx_end > block_round_inx_start) {//reduce_range ← vec_range ∩ round_range
      const I reduce_start = max(reduce_row_idx_begin, block_round_inx_start);
      const I reduce_end = min(reduce_row_idx_end, block_round_inx_end);
      for (I j = reduce_start; j < reduce_end; j++) {
        sum += shared_val[j - block_round_inx_start];
      }
    }
  }
}

template <perfSpB_index R, int VEC_SIZE, int ROWS_PER_BLOCK, perfSpB_index THREADS_PER_BLOCK, typename I, typename T>
__global__ void spmv_line_enhance_kernel(T *d_val,
                                         perfSpB_index *d_ptr,
                                         perfSpB_index *d_cols,
                                         perfSpB_index d_nnz,
                                         perfSpB_index nrows,
                                         T *d_vector,
                                         T *d_out)
{
  static_assert(THREADS_PER_BLOCK / VEC_SIZE >= ROWS_PER_BLOCK,
                "vector number in block must larger or equal then the rows processed per block");

  const int g_tid = threadIdx.x + blockDim.x * blockIdx.x; // global thread id
  const int g_bid = blockIdx.x;                            // global block id
  const int tid_in_block = g_tid % THREADS_PER_BLOCK;      // local thread id in current block

  const int shared_len = THREADS_PER_BLOCK * R;
  __shared__ T shared_val[shared_len];

  const I block_row_begin = g_bid * ROWS_PER_BLOCK; // 一个线程块的起始行
  const I block_row_end = min(block_row_begin + ROWS_PER_BLOCK, nrows);

  const I block_row_idx_start = d_ptr[block_row_begin];
  const I block_row_idx_end = d_ptr[block_row_end]; // 此时会触发访存合并，由于同一线程块访问同一地址。比第一个线程加载然后广播性能要高

  //////////////////////////////////////////////////////////////////////////////
  const I vec_id_in_block = g_tid / VEC_SIZE % (THREADS_PER_BLOCK / VEC_SIZE);
  const I tid_in_vec = g_tid % VEC_SIZE;
  const I reduce_row_id = block_row_begin + vec_id_in_block;
  I reduce_row_idx_begin = 0;
  I reduce_row_idx_end = 0;
  if (reduce_row_id < block_row_end)
  {
    reduce_row_idx_begin = d_ptr[reduce_row_id];
    reduce_row_idx_end = d_ptr[reduce_row_id + 1];
  }
  //////////////////////////////////////////////////////////////////////////////

  T sum = static_cast<T>(0);
  const int rounds =
      (block_row_idx_end - block_row_idx_start) / (R * THREADS_PER_BLOCK) +
      ((block_row_idx_end - block_row_idx_start) % (R * THREADS_PER_BLOCK) == 0 ? 0 : 1); // 一个round加载(R * THREADS)个元素

  for (int r = 0; r < rounds; r++)
  {
    // start and end data index in each round
    const I block_round_inx_start = block_row_idx_start + r * R * THREADS_PER_BLOCK;
    const I block_round_inx_end = min(block_round_inx_start + R * THREADS_PER_BLOCK, block_row_idx_end);
    I i = block_round_inx_start + tid_in_block;

    __syncthreads();
// in each inner loop, it processes R*THREADS element at max
#pragma unroll
    for (int k = 0; k < R; k++)
    { // streaming
      if (i < block_row_idx_end)
      {
        const T tmp = d_val[i] * d_vector[d_cols[i]];
        shared_val[i - block_round_inx_start] = tmp;
      }
      i += THREADS_PER_BLOCK;
    }
    __syncthreads();
    // reduce
    {
      line_enhance_direct_reduce<I, T>(reduce_row_id, block_row_end, reduce_row_idx_begin, reduce_row_idx_end,
                                       block_round_inx_start, block_round_inx_end, shared_val, sum);
    }

    if (reduce_row_id < block_row_end)
    {
      d_out[reduce_row_id] = sum + d_out[reduce_row_id];
    }
  }

}

perfSpB_info perfSpB_SpMV_LINE_ENHANCE_FP32(perfSpB_operation_t op,
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
  cudaMemcpy(d_vecY_csr, ((float *)vecY_csr->values), sizeof(float) * vecY->n, cudaMemcpyHostToDevice);

  const int bp_1 = matA_csr->ptr[nrows / 2];
  const int bp_2 = matA_csr->ptr[nrows];

  const int nnz_block_0 = bp_1 - 0;
  const int nnz_block_1 = bp_2 - bp_1;
  int avg_block_nnz_max = max(2 * nnz_block_0 / nrows, 2 * nnz_block_1 / nrows);

  const int R = 2;
  const int THREADS_PER_BLOCK = 512;
  constexpr int ROWS_PER_BLOCK = 32;

  const int WORK_BLOCKS = (nrows / ROWS_PER_BLOCK) + ((nrows % ROWS_PER_BLOCK == 0) ? 0 : 1);

  cuda_time_test_start();
  for (int i = 0; i < test_iter; i++)
  {
    spmv_line_enhance_kernel<R, 4, ROWS_PER_BLOCK, THREADS_PER_BLOCK, perfSpB_index, float><<<(WORK_BLOCKS), (THREADS_PER_BLOCK)>>>(d_val, d_ptr, d_indices, nvals, nrows, d_vecX_csr, d_vecY_csr);
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

  cudaFree(d_vecY_csr);
  cudaFree(d_vecX_csr);
  cudaFree(d_val);
  cudaFree(d_indices);
  cudaFree(d_ptr);

  return perfSpB_success;
}
