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

#define hipWarpSize 32

#define BlockDim 1024

#define ITER 3

template <typename T>
__global__ void spmv_csr_adaptive_kernel(T * d_val,T * d_vector,perfSpB_index * d_cols,perfSpB_index * d_ptr,perfSpB_index N, perfSpB_index * d_rowBlocks, T * d_out)
{
    	perfSpB_index startRow = d_rowBlocks[blockIdx.x];
    	perfSpB_index nextStartRow = d_rowBlocks[blockIdx.x + 1];
    	perfSpB_index num_rows = nextStartRow -  startRow;
    	perfSpB_index i = threadIdx.x;
    	__shared__ volatile T LDS[BlockDim];
    	// If the block consists of more than one row then run CSR Stream
    	if (num_rows > 1) {
		perfSpB_index nnz = d_ptr[nextStartRow] - d_ptr[startRow];
        	perfSpB_index first_col = d_ptr[startRow];

		// Each thread writes to shared memory
        	if (i < nnz)
		{
			LDS[i] = d_val[first_col + i] * d_vector[d_cols[first_col + i]];
		}
		__syncthreads();     
		
		// Threads that fall within a range sum up the partial results
		for (perfSpB_index k = startRow + i; k < nextStartRow; k += blockDim.x)
		{
			T temp = 0;
			for (perfSpB_index j= (d_ptr[k] - first_col); j < (d_ptr[k + 1] - first_col); j++){
		    		temp = temp + LDS[j];
			}
			d_out[k] = temp;
    		}
	}
	// If the block consists of only one row then run CSR Vector
    	else {
    		// Thread ID in warp
        	perfSpB_index rowStart = d_ptr[startRow];
        	perfSpB_index rowEnd = d_ptr[nextStartRow];

        	T sum = 0;

		// Use all threads in a warp to accumulate multiplied elements
        	for (perfSpB_index j = rowStart + i; j < rowEnd; j += BlockDim)
        	{
            		perfSpB_index col = d_cols[j];
            		sum += d_val[j] * d_vector[col];
        	}

        	LDS[i] = sum;
		__syncthreads();

        	// Reduce partial sums
		for (perfSpB_index stride = blockDim.x >> 1; stride > 0; stride >>= 1) {
			__syncthreads();
			if (i < stride)
				LDS[i] += LDS[i + stride]; 
		}
        	// Write result
        	if (i == 0)
           		d_out[startRow] = LDS[i];
    	}	
}


// calculates the number of rows of a CSR matrix that can fit perfSpB_indexo BlockDim entries.
perfSpB_index spmv_csr_adaptive_rowblocks(perfSpB_index *ptr,perfSpB_index totalRows,perfSpB_index *rowBlocks)
{
    	rowBlocks[0] = 0; 
    	perfSpB_index sum = 0; 
    	perfSpB_index last_i = 0; 
    	perfSpB_index ctr = 1;
    	for (perfSpB_index i = 1; i < totalRows; i++) {
    	// Count non-zeroes in this row 
        	sum += ptr[i] - ptr[i-1];
        	if (sum == BlockDim){
            		// This row fills up LOCAL_SIZE 
            		last_i = i;
            		rowBlocks[ctr++] = i;
            		sum = 0;
        	}
        	else if (sum > BlockDim){
        		if (i - last_i > 1) {
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

perfSpB_info perfSpB_SpMV_Adaptive_FP32(perfSpB_operation_t op,
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
    for (perfSpB_index i = 0; i < matA->row; i++)
    {
        if (*((float *)vecY_csr->values) != 0)
        {
            printf("\n %f \n", *((float *)vecY_csr->values));
        }
    }

    hipMalloc(&d_vecY_csr, sizeof(float) * vecY->n);
    hipMalloc(&d_vecX_csr, sizeof(float) * vecX->n);
    hipMalloc(&d_val, sizeof(float) * matA_csr->nnz);

    hipMalloc(&d_indices, sizeof(perfSpB_index) * matA_csr->nnz);
    hipMalloc(&d_ptr, sizeof(perfSpB_index) * (vecY->n + 1));

    hipMemcpy(d_val, matA_csr->val, sizeof(float) * matA_csr->nnz, hipMemcpyHostToDevice);
    hipMemcpy(d_indices, matA_csr->indices, sizeof(perfSpB_index) * matA_csr->nnz, hipMemcpyHostToDevice);
    hipMemcpy(d_ptr, matA_csr->ptr, sizeof(perfSpB_index) * (vecY->n + 1), hipMemcpyHostToDevice);
    hipMemcpy(d_vecX_csr, ((float *)vecX_csr->values), sizeof(float) * vecX->n, hipMemcpyHostToDevice);

    perfSpB_index *rowBlocks, *d_rowBlocks;
    rowBlocks = (perfSpB_index *)malloc((vecY->n) * sizeof(perfSpB_index));
    perfSpB_index countRowBlocks = spmv_csr_adaptive_rowblocks(matA_csr->ptr, vecY->n, rowBlocks);
    hipMalloc(&d_rowBlocks, countRowBlocks * sizeof(perfSpB_index));
    hipMemcpy(d_rowBlocks, rowBlocks, countRowBlocks * sizeof(perfSpB_index), hipMemcpyHostToDevice);
    hip_time_test_start();

    for (perfSpB_index i = 0; i < test_iter; i++)
    {
        hipLaunchKernelGGL(spmv_csr_adaptive_kernel<float>, dim3((countRowBlocks - 1)), dim3(BlockDim), 0, 0, d_val, d_vecX_csr, d_indices, d_ptr, vecY->n, d_rowBlocks, d_vecY_csr);
    }

    hip_time_test_end();
    double runtime1 = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime1 / 1000) * 1e9);

    hipDeviceSynchronize();
    printf("\n ------------------------------------------------------------------------------");
    printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime1);
    // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
    printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);
    printf(" ------------------------------------------------------------------------------ \n");

    hipMemcpy(((float *)vecY_csr->values), d_vecY_csr, sizeof(float) * vecY->n, hipMemcpyDeviceToHost);

    hipError_t cudaStatus = hipGetLastError();
    if (cudaStatus != hipSuccess)
    {
        printf("Error:%s\n", hipGetErrorString(cudaStatus));
        exit(EXIT_FAILURE);
    }
    free(rowBlocks);
    hipFree(d_rowBlocks);
    hipFree(d_vecY_csr);
    hipFree(d_vecX_csr);
    hipFree(d_val);
    hipFree(d_indices);
    hipFree(d_ptr);

    return perfSpB_success;
}

perfSpB_info perfSpB_SpMV_Adaptive_FP64(perfSpB_operation_t op,
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
    for (perfSpB_index i = 0; i < matA->row; i++)
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

    perfSpB_index *rowBlocks, *d_rowBlocks;
    rowBlocks = (perfSpB_index *)malloc((vecY->n) * sizeof(perfSpB_index));
    perfSpB_index countRowBlocks = spmv_csr_adaptive_rowblocks(matA_csr->ptr, vecY->n, rowBlocks);
    hipMalloc(&d_rowBlocks, countRowBlocks * sizeof(perfSpB_index));
    hipMemcpy(d_rowBlocks, rowBlocks, countRowBlocks * sizeof(perfSpB_index), hipMemcpyHostToDevice);
    hip_time_test_start();

    for (perfSpB_index i = 0; i < test_iter; i++)
    {
        hipLaunchKernelGGL(spmv_csr_adaptive_kernel<double>, dim3((countRowBlocks - 1)), dim3(BlockDim), 0, 0, d_val, d_vecX_csr, d_indices, d_ptr, vecY->n, d_rowBlocks, d_vecY_csr);
    }

    hip_time_test_end();
    double runtime1 = (elapsedTime) / test_iter;
    double gflops = (2.0 * matA_csr->nnz) / ((runtime1 / 1000) * 1e9);

    hipDeviceSynchronize();
    printf("\n ------------------------------------------------------------------------------");
    printf("\n SpMV CUDA kernel runtime = %g ms\n", runtime1);
    // printf("\n SpMV CUDA kernel2 runtime = %g ms\n", runtime2);
    printf("\n SpMV Performance  = %lf GFLOPS\n", gflops);
    printf(" ------------------------------------------------------------------------------ \n");

    hipMemcpy(((double *)vecY_csr->values), d_vecY_csr, sizeof(double) * vecY->n, hipMemcpyDeviceToHost);

    hipError_t cudaStatus = hipGetLastError();
    if (cudaStatus != hipSuccess)
    {
        printf("Error:%s\n", hipGetErrorString(cudaStatus));
        exit(EXIT_FAILURE);
    }
    free(rowBlocks);
    hipFree(d_rowBlocks);
    hipFree(d_vecY_csr);
    hipFree(d_vecX_csr);
    hipFree(d_val);
    hipFree(d_indices);
    hipFree(d_ptr);

    return perfSpB_success;
}
