#include "hip/hip_runtime.h"
#include <hip/hip_runtime.h>
#include <hip/hip_runtime.h>
#include "spmv_hip.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>  // 包含 std::sort
#include <functional> // 包含 std::greater

#include "hip_timer.h"


#define test_iter 2000

// template <int BREAK_STRIDE, typename I>
// __global__ void pre_startRowPerBlock(const I *__restrict__ row_ptr, const I m, I * startRowPerBlock)
// {
//   const int global_thread_id = threadIdx.x + blockDim.x * blockIdx.x;
//   const int global_threads_num = blockDim.x * gridDim.x;

//   constexpr I break_stride = BREAK_STRIDE;
//   if (global_thread_id == 0)
//   {
//     startRowPerBlock[0] = 0; // start row of the block 0 and the first round.
//   }

//   for (int i = global_thread_id; i < m; i += global_threads_num) // 524,288
//   {
//     // for first element of row i and row i+1, they belong to different blocks.
//     if (row_ptr[i] / break_stride != row_ptr[i + 1] / break_stride)
//     { // fixme: step may be not 1
//       // record the row id of the first element in the block.
//       // note: a row can cross multiple blocks.
//       for (int b = row_ptr[i] / break_stride + 1; b <= row_ptr[i + 1] / break_stride; b++)
//       {
//         startRowPerBlock[b] = i;
//       }
//       if (row_ptr[i + 1] % break_stride == 0)
//       {
//         startRowPerBlock[row_ptr[i + 1] / break_stride] += 1;
//       }
//     }
//   }
// }

template <int BREAK_STRIDE, typename I>
__global__ void pre_startRowPerBlock(const I *__restrict__ row_ptr,
                                     const I m,
                                     I * startRowPerBlock)
{
  const int global_thread_id = blockIdx.x * blockDim.x + threadIdx.x;
  if (global_thread_id > m + 1)
    return;
  int a = row_ptr[global_thread_id];
  int b = row_ptr[min(global_thread_id + 1, (int)m + 1)];

  int blocka = divup<int>(a, BREAK_STRIDE);
  int blockb = (b - 1) / static_cast<int>(BREAK_STRIDE);

  if (a != b)
    for (; blocka <= blockb; ++blocka)
      startRowPerBlock[blocka] = global_thread_id;
}

template <typename I, typename T, perfSpB_index NNZ_PER_BLOCK, perfSpB_index THREADS_PER_BLOCK>
__device__ __forceinline__ void flat_reduce_oneRow_in_thread(const int tid_in_block, const int block_id,
                                                             const I reduceStartRowId, const I reduceEndRowId,
                                                             const I *__restrict__ row_ptr,
                                                             const T *__restrict__ smem, T *__restrict__ y)
{
  I reduce_row_id = reduceStartRowId + tid_in_block;
  I nnz_id_before = block_id * NNZ_PER_BLOCK;
  for (; reduce_row_id < reduceEndRowId; reduce_row_id += THREADS_PER_BLOCK)
  {
    T sum = 0;
    // const I reduce_start_idx = max((perfSpB_index)0, row_ptr[reduce_row_id] - nnz_id_before);
    // const I reduce_end_idx = min(NNZ_PER_BLOCK, row_ptr[reduce_row_id + 1] - nnz_id_before);
    const I reduce_start_idx = (row_ptr[reduce_row_id] - nnz_id_before) < 0 ? 0 : (row_ptr[reduce_row_id] - nnz_id_before);
    const I reduce_end_idx = (row_ptr[reduce_row_id + 1] - nnz_id_before) > NNZ_PER_BLOCK ? NNZ_PER_BLOCK : (row_ptr[reduce_row_id + 1] - nnz_id_before);
    for (int i = reduce_start_idx; i < reduce_end_idx; i++)
    {
      sum += smem[i];
    }
    atomicAdd(y + reduce_row_id, sum);
  }
}
template <perfSpB_index productNnzPerThread, perfSpB_index THREADS_PER_BLOCK, typename I, typename T>
__global__ void spmv_flat_kernel(T *d_val,
                                 perfSpB_index *d_ptr,
                                 perfSpB_index *d_cols,
                                 perfSpB_index nrows,
                                 T *d_vector,
                                 T *d_out,
                                 I * startRowPerBlock)
{
  const int tid_in_block = threadIdx.x;
  const int NNZ_PER_BLOCK = THREADS_PER_BLOCK * productNnzPerThread;
  __shared__ T middle_s[NNZ_PER_BLOCK];
  const I lastElemId = d_ptr[nrows];

  int blockNnzStart = NNZ_PER_BLOCK * blockIdx.x;

  // product and stream in Shared Memory
#pragma unroll
  for (int round = 0; round < productNnzPerThread; round++)
  {
    const I sIdx = tid_in_block + round * THREADS_PER_BLOCK;
    const I gIdx = min(blockNnzStart + sIdx, lastElemId - 1);
    middle_s[sIdx] = d_val[gIdx] * d_vector[d_cols[gIdx]];
  }
  __syncthreads();

  const I reduceStartRowId = min(startRowPerBlock[blockIdx.x], nrows);
  I reduceEndRowId = min(startRowPerBlock[blockIdx.x + 1], nrows);
  reduceEndRowId = (reduceEndRowId == 0) ? nrows : reduceEndRowId;
  if (d_ptr[reduceEndRowId] % NNZ_PER_BLOCK != 0 || reduceEndRowId == reduceStartRowId)
  {
    reduceEndRowId = min(reduceEndRowId + 1, nrows);
  }

  flat_reduce_oneRow_in_thread<I, T, NNZ_PER_BLOCK, THREADS_PER_BLOCK>(tid_in_block, blockIdx.x,
                                                                       reduceStartRowId, reduceEndRowId,
                                                                       d_ptr, middle_s, d_out);
}

perfSpB_info perfSpB_SpMV_flat_FP32(perfSpB_operation_t op,
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
  // for (int i = 0; i < matA->row; i++)
  // {
  //   if (*((float *)vecY_csr->values) != 0)
  //   {
  //     printf("\n %f \n", *((float *)vecY_csr->values));
  //   }
  // }

  // hipMalloc(&d_vecY_csr, sizeof(float) * vecY->n);
  // hipMalloc(&d_vecX_csr, sizeof(float) * vecX->n);
  // hipMalloc(&d_val, sizeof(float) * matA_csr->nnz);
  // hipMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
  // hipMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

    hipError_t cudaStatus;
  if ((cudaStatus = hipMalloc(&d_vecY_csr, sizeof(float) * vecY->n)) != hipSuccess ||
      (cudaStatus = hipMalloc(&d_vecX_csr, sizeof(float) * vecX->n)) != hipSuccess ||
      (cudaStatus = hipMalloc(&d_val, sizeof(float) * matA_csr->nnz)) != hipSuccess ||
      (cudaStatus = hipMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz)) != hipSuccess ||
      (cudaStatus = hipMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1))) != hipSuccess) {
    printf("HIP malloc error: %s\n", hipGetErrorString(cudaStatus));
    return perfSpB_failure;
  }

  hipMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, hipMemcpyHostToDevice);
  hipMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, hipMemcpyHostToDevice);
  hipMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), hipMemcpyHostToDevice);
  hipMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, hipMemcpyHostToDevice);
  hipMemcpy(d_vecY_csr, ((float *)vecY_csr->values), sizeof(float) * vecY->n, hipMemcpyHostToDevice);

  const int productNnzPerThread = 4;
  const int THREADS_PER_BLOCK = 128;

  const int WORK_BLOCKS = nvals / (productNnzPerThread * THREADS_PER_BLOCK) + ((nvals % (productNnzPerThread * THREADS_PER_BLOCK) == 0) ? 0 : 1);

  const perfSpB_index startRowPerBlock_len = WORK_BLOCKS + 1;

  perfSpB_index *startRowPerBlock;
  hipMalloc((void **)&startRowPerBlock, sizeof(perfSpB_index) * startRowPerBlock_len);
  hipMemset(startRowPerBlock, 0, sizeof(perfSpB_index) * startRowPerBlock_len);

  // hipLaunchKernelGGL((pre_startRowPerBlock<productNnzPerThread * THREADS_PER_BLOCK, perfSpB_index>), dim3(divup<int64_t>(nrows + 1, 128)), dim3(128), 1024, 0, d_ptr, nrows, startRowPerBlock);
  // printf("\n 111111111111111111111111111 \n");
  (pre_startRowPerBlock<productNnzPerThread * THREADS_PER_BLOCK, perfSpB_index>)<<<divup<uint32_t>(nrows + 1, 256), 256>>>(d_ptr, nrows, startRowPerBlock);
  // perfSpB_index *h_startRowPerBlock = (perfSpB_index *)malloc((startRowPerBlock_len) * sizeof(perfSpB_index));
  // hipMemcpy(h_startRowPerBlock, startRowPerBlock, (startRowPerBlock_len) * sizeof(perfSpB_index), hipMemcpyDeviceToHost);


  hip_time_test_start();
  for (int i = 0; i < test_iter; i++)
  {
    // hipMemset(d_vecY_csr, 0.0, sizeof(float) * vecY->n);
    // hipLaunchKernelGGL((spmv_flat_kernel<productNnzPerThread, THREADS_PER_BLOCK, perfSpB_index, float>), dim3((WORK_BLOCKS)), dim3((THREADS_PER_BLOCK)), 1024, 0, d_val, d_ptr, d_indices, nrows, d_vecX_csr, d_vecY_csr, startRowPerBlock);
    (spmv_flat_kernel<productNnzPerThread, THREADS_PER_BLOCK, perfSpB_index, float>)<<<(WORK_BLOCKS), (THREADS_PER_BLOCK)>>>(d_val, d_ptr, d_indices, nrows, d_vecX_csr, d_vecY_csr, startRowPerBlock);
  }
  // printf("\n 222222222222222222 \n");

  hip_time_test_end();
  
  

  // printf("\n 333333333333 \n");
  double runtime = (elapsedTime) / test_iter;
  double gflops = (2.0 * matA_csr->nnz) / ((runtime / 1000) * 1e9);

  hipDeviceSynchronize();
  printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime);
  // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
  printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);
  // printf("\n 44444444444444444 \n");
  
  hipMemcpy(((float *)vecY_csr->values), d_vecY_csr, sizeof(float) * vecY->n, hipMemcpyDeviceToHost);
  
  hipError_t cudaStatus1 = hipGetLastError();
  if (cudaStatus1 != hipSuccess)
  {
    printf("Error:%s\n", hipGetErrorString(cudaStatus1));
    exit(EXIT_FAILURE);
  }
  // printf("\n 55555555555555555 \n");

  // hipFree(d_vecY_csr);
  // hipFree(d_vecX_csr);
  // hipFree(d_val);
  // hipFree(d_indices);
  // hipFree(d_ptr);
  // hipFree(startRowPerBlock);

  return perfSpB_success;
}

perfSpB_info perfSpB_SpMV_flat_FP64(perfSpB_operation_t op,
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

  double *d_vecY_csr, *d_vecX_csr, *d_val;
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
  hipMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
  hipMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

  hipMemcpy(d_val, matA_csr->val, sizeof(double) * matA_csr->nnz, hipMemcpyHostToDevice);
  hipMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, hipMemcpyHostToDevice);
  hipMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), hipMemcpyHostToDevice);
  hipMemcpy(d_vecX_csr, ((double *)vecX_csr->values), sizeof(double) * vecX->n, hipMemcpyHostToDevice);
  hipMemcpy(d_vecY_csr, ((double *)vecY_csr->values), sizeof(double) * vecY->n, hipMemcpyHostToDevice);

  const int productNnzPerThread = 4;
  const int THREADS_PER_BLOCK = 128;

  const int WORK_BLOCKS = nvals / (productNnzPerThread * THREADS_PER_BLOCK) + ((nvals % (productNnzPerThread * THREADS_PER_BLOCK) == 0) ? 0 : 1);

  const perfSpB_index startRowPerBlock_len = WORK_BLOCKS + 1;

  perfSpB_index *startRowPerBlock;
  hipMalloc((void **)&startRowPerBlock, sizeof(perfSpB_index) * startRowPerBlock_len);
  hipMemset(startRowPerBlock, 0, sizeof(perfSpB_index) * startRowPerBlock_len);

  hipLaunchKernelGGL((pre_startRowPerBlock<productNnzPerThread * THREADS_PER_BLOCK, perfSpB_index>), dim3(divup<int64_t>(nrows + 1, 128)), dim3(128), 0, 0, d_ptr, nrows, startRowPerBlock);


  hip_time_test_start();
  for (int i = 0; i < test_iter; i++)
  {
    // hipMemset(d_vecY_csr, 0.0, sizeof(double) * vecY->n);
    hipLaunchKernelGGL((spmv_flat_kernel<productNnzPerThread, THREADS_PER_BLOCK, perfSpB_index, double>), dim3((WORK_BLOCKS)), dim3((THREADS_PER_BLOCK)), 0, 0, d_val, d_ptr, d_indices, nrows, d_vecX_csr, d_vecY_csr, startRowPerBlock);
  }
  hip_time_test_end();
  double runtime = (elapsedTime) / test_iter;
  double gflops = (2.0 * matA_csr->nnz) / ((runtime / 1000) * 1e9);

  hipDeviceSynchronize();
  printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime);
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
  hipFree(startRowPerBlock);

  return perfSpB_success;
}
