#include "GrB_Matrix_CSC_or_CSR.h"
#include "GrB_Alloc.h"
#include "GrB_Type.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <type_traits>
#include <omp.h>
#include <gtest/gtest.h>
#include <atomic>

/**
 * @brief Matrix multiplication matrix without Accum
 * @param[out] C The result matrix
 * @param[in] mask_in The mask matrix
 * @param[in] A The left input matrix
 * @param[in] B The right input matrix
 */
template <typename value_t>
void Test_mxm_NAccum_PLUS_TIMES_SEMIRING_T(
	GrB_Matrix C,
	const GrB_Matrix mask,
	const GrB_Matrix A,
	const GrB_Matrix B)
{
	assert(C->format_type == GrB_CSR);
	assert(mask->format_type == GrB_CSR);
	assert(A->format_type == GrB_CSR);
	assert(B->format_type == GrB_CSR);

	perfSpB_index C_nrows, C_ncols,
		mask_nrows, mask_ncols,
		A_nrows, A_ncols,
		B_nrows, B_ncols;
	GrB_Matrix_nrows(&C_nrows, C);
	GrB_Matrix_nrows(&mask_nrows, mask);
	GrB_Matrix_nrows(&A_nrows, A);
	GrB_Matrix_nrows(&B_nrows, B);

	GrB_Matrix_ncols(&C_ncols, C);
	GrB_Matrix_ncols(&mask_ncols, mask);
	GrB_Matrix_ncols(&A_ncols, A);
	GrB_Matrix_ncols(&B_ncols, B);

	assert(C_nrows == mask_nrows && C_ncols == mask_ncols);
	assert(C_nrows == A_nrows && A_ncols == B_nrows && B_ncols == C_ncols);

	GrB_Matrix_CSC_or_CSR *output = (GrB_Matrix_CSC_or_CSR *)C;
	GrB_Matrix_CSC_or_CSR *input_mask = (GrB_Matrix_CSC_or_CSR *)mask;
	GrB_Matrix_CSC_or_CSR *input_A = (GrB_Matrix_CSC_or_CSR *)A;
	GrB_Matrix_CSC_or_CSR *input_B = (GrB_Matrix_CSC_or_CSR *)B;

#pragma omp parallel
	{
		size_t output_ncol = output->matrix_base.col;
		value_t *spa_ = (value_t *)GrB_aligned_malloc(sizeof(value_t) * output_ncol);
		value_t *temp_row_slice_value = (value_t *)GrB_aligned_malloc(sizeof(value_t) * output_ncol);
		perfSpB_index *temp_row_slice_idx = (perfSpB_index *)GrB_aligned_malloc(sizeof(perfSpB_index) * output_ncol);
		size_t input_A_rows = input_A->matrix_base.row;

		// step 1
#pragma omp for schedule(dynamic, 128)
		for (size_t i = 0; i < input_A_rows; ++i)
		{
			for (size_t j = input_mask->ptr[i]; j < input_mask->ptr[i + 1]; j++)
			{
				const perfSpB_index col_C = input_mask->indices[j];
				spa_[col_C] = 0;
			}
			for (size_t j = input_A->ptr[i]; j < input_A->ptr[i + 1]; ++j)
			{
				const perfSpB_index col_A_i = input_A->indices[j];
				for (size_t k = input_B->ptr[col_A_i]; k < input_B->ptr[col_A_i + 1]; ++k)
				{
					const perfSpB_index col_B_j = input_B->indices[k];
					spa_[col_B_j] = 1;
				}
			}
			size_t output_nnz_one_row = 0;
			for (size_t j = input_mask->ptr[i]; j < input_mask->ptr[i + 1]; j++)
			{
				const perfSpB_index col_C = input_mask->indices[j];
				output_nnz_one_row += spa_[col_C];
			}
			output->ptr[i + 1] = output_nnz_one_row;
		}
#pragma omp single
		{
			output->ptr[0] = 0;
			for (size_t i = 0; i < input_A_rows; i++)
			{
				output->ptr[i + 1] += output->ptr[i];
			}
			size_t output_nnz = output->ptr[input_A_rows];
			if (output->val != NULL)
				free(output->val);
			if (output->indices != NULL)
				free(output->indices);
			output->indices = (perfSpB_index *)GrB_aligned_malloc(sizeof(perfSpB_index) * output_nnz);
			output->val = (void *)GrB_aligned_malloc(sizeof(value_t) * output_nnz);
			output->nnz = output->capacity = output_nnz;
		}
		// step 2
#pragma omp for schedule(dynamic, 128)
		for (size_t i = 0; i < input_A_rows; ++i)
		{
			for (size_t j = input_mask->ptr[i]; j < input_mask->ptr[i + 1]; j++)
			{
				const perfSpB_index col_C = input_mask->indices[j];
				spa_[col_C] = 0;
			}
			for (size_t j = input_A->ptr[i]; j < input_A->ptr[i + 1]; ++j)
			{
				const value_t value_A_i_j = ((value_t *)(input_A->val))[j];
				const perfSpB_index col_A_i = input_A->indices[j];
				for (size_t k = input_B->ptr[col_A_i]; k < input_B->ptr[col_A_i + 1]; ++k)
				{
					const value_t value_B_j_k = ((value_t *)input_B->val)[k];
					const perfSpB_index col_B_j = input_B->indices[k];

					spa_[col_B_j] += value_A_i_j * value_B_j_k;
				}
			}
			perfSpB_index output_nnz_one_row = 0;
			for (size_t j = input_mask->ptr[i]; j < input_mask->ptr[i + 1]; j++)
			{
				const perfSpB_index col_C = input_mask->indices[j];
				if (spa_[col_C])
				{
					temp_row_slice_idx[output_nnz_one_row] = col_C;
					temp_row_slice_value[output_nnz_one_row++] = spa_[col_C];
				}
			}
			memcpy(((value_t *)(output->val)) + output->ptr[i], temp_row_slice_value, sizeof(value_t) * output_nnz_one_row);
			memcpy(output->indices + output->ptr[i], temp_row_slice_idx, sizeof(perfSpB_index) * output_nnz_one_row);
		}
		free(spa_);
		free(temp_row_slice_value);
		free(temp_row_slice_idx);
	}
}

/**
 * @brief Matrix multiplication matrix
 * @param[out] C The result matrix
 * @param[in] mask_in The mask matrix
 * @param[in] accum The accumulate Binary Operator
 * @param[in] semiring  The semiring
 * @param[in] A The left input matrix
 * @param[in] B The right input matrix
 * @param[in] desc The descriptor
 */
template <typename value_t>
void Test_mxm(
	GrB_Matrix C,
	const GrB_Matrix mask,
	const GrB_BinaryOp accum,
	const GrB_Semiring op,
	const GrB_Matrix A,
	const GrB_Matrix B,
	const GrB_Descriptor desc)
{
	assert(mask != GrB_Matrix_NULL &&
		   accum == GrB_BINARYOP_NULL &&
		   (op == GrB_PLUS_TIMES_SEMIRING_INT32 ||
			op == GrB_PLUS_TIMES_SEMIRING_INT64 ||
			op == GrB_PLUS_TIMES_SEMIRING_FP32 ||
			op == GrB_PLUS_TIMES_SEMIRING_FP64) &&
		   desc == GrB_DESC_NULL);
	Test_mxm_NAccum_PLUS_TIMES_SEMIRING_T<value_t>(C, mask, A, B);
}

/**
 * @brief Test whether the matrices are equal
 * @param[in] A The left input matrix
 * @param[in] B The left right matrix
 * @return whether the matrices are equal
 */
template <typename value_t>
bool Test_Matrix_equal(GrB_Matrix A, GrB_Matrix B)
{
	perfSpB_index A_nrows, A_ncols, B_nrows, B_ncols;
	GrB_Matrix_nrows(&A_nrows, A);
	GrB_Matrix_nrows(&B_nrows, B);
	GrB_Matrix_ncols(&A_ncols, A);
	GrB_Matrix_ncols(&B_ncols, B);
	GrB_Matrix_CSC_or_CSR *input_A = (GrB_Matrix_CSC_or_CSR *)A;
	GrB_Matrix_CSC_or_CSR *input_B = (GrB_Matrix_CSC_or_CSR *)B;

	if (input_A->ptr_len != input_B->ptr_len)
	{
		std::cerr << "Error ptr_len" << std::endl;
		return false;
	}
	if (memcmp(input_A->ptr, input_B->ptr, input_A->ptr_len * sizeof(perfSpB_index)))
	{
		for (size_t i = 0; i < input_A->ptr_len; i++)
		{
			if (input_A->ptr[i] != input_B->ptr[i])
			{
				std::cerr << "Error ptr first find in ptr[" << i << "]" << std::endl;
				std::cerr << "except is " << input_A->ptr[i] << ", but get " << input_B->ptr[i] << std::endl;
				std::cerr << "cur line except";
				for (size_t j = 0; j < std::min(input_A->ptr[i], 50ul); j++)
				{
					std::cerr << " (" << input_A->indices[j] << "," << ((value_t *)input_A->val)[j] << ")";
				}
				std::cerr << std::endl;
				std::cerr << "but get";
				for (size_t j = 0; j < std::min(input_B->ptr[i], 50ul); j++)
				{
					std::cerr << " (" << input_B->indices[j] << "," << ((value_t *)input_B->val)[j] << ")";
				}
				std::cerr << std::endl;
				break;
			}
		}
		return false;
	}
	if (memcmp(input_A->indices, input_B->indices, input_A->nnz * sizeof(perfSpB_index)))
	{
		std::cerr << "Error indices" << std::endl;
		return false;
	}
	if (std::is_same<value_t, int>::value || std::is_same<value_t, long>::value)
	{
		for (size_t i = 0; i < input_A->ptr[input_A->ptr_len - 1]; i++)
		{
			if (((value_t *)input_A->val)[i] != ((value_t *)input_B->val)[i])
			{
				return false;
			}
		}
	}
	else
	{
		for (size_t i = 0; i < input_A->ptr[input_A->ptr_len - 1]; i++)
		{
			value_t va = ((value_t *)input_A->val)[i];
			value_t vb = ((value_t *)input_B->val)[i];
			if (std::fabs(va - vb) / std::max(std::fabs(va), std::fabs(vb)) > 1e-4)
			{
				return false;
			}
		}
	}
	return true;
}

template <typename value_t>
struct matrix_element
{
	perfSpB_index index;
	value_t val;
	bool operator<(const matrix_element &b) const
	{
		return index < b.index;
	}
};
/**
 * @brief Convert CSR matrix to CSC matrix
 * @param[in] A The matrix before convert
 * @param[out] B The matrix after convert
 */
template <typename value_t>
void Test_CSR2CSC(const GrB_Matrix A, GrB_Matrix B)
{
	perfSpB_index A_nrows, A_ncols;
	GrB_Matrix_nrows(&A_nrows, A);
	GrB_Matrix_ncols(&A_ncols, A);
	GrB_Matrix_CSC_or_CSR *input_A = (GrB_Matrix_CSC_or_CSR *)A;
	GrB_Matrix_CSC_or_CSR *output = (GrB_Matrix_CSC_or_CSR *)B;
	perfSpB_index tot_nnz = input_A->ptr[A_nrows];
	if (output->indices != NULL)
	{
		free(output->indices);
	}
	output->indices = (perfSpB_index *)GrB_aligned_malloc(sizeof(perfSpB_index) * tot_nnz);
	if (output->val != NULL)
	{
		free(output->val);
	}
	output->val = GrB_aligned_malloc(sizeof(value_t) * tot_nnz);
	output->nnz = output->capacity = tot_nnz;
	std::atomic_ulong *output_ptr = (std::atomic_ulong *)GrB_aligned_malloc(sizeof(std::atomic_ulong) * (A_ncols + 1));
	matrix_element<value_t> *temp_B = (matrix_element<value_t> *)GrB_aligned_malloc(sizeof(matrix_element<value_t>) * tot_nnz);
#pragma omp parallel for
	for (perfSpB_index i = 0; i <= A_ncols; i++)
	{
		atomic_init(output_ptr + i, 0ul);
	}
#pragma omp parallel for schedule(static, 128)
	for (perfSpB_index i = 0; i < A_nrows; i++)
	{
		for (perfSpB_index j = input_A->ptr[i]; j < input_A->ptr[i + 1]; j++)
		{
			perfSpB_index cur_col = input_A->indices[j];
			atomic_fetch_add(output_ptr + 1 + cur_col, 1ul);
		}
	}
	for (perfSpB_index i = 0; i < A_ncols; i++)
	{
		output->ptr[i] = output_ptr[i];
		output_ptr[i + 1] += output_ptr[i];
	}
	output->ptr[A_ncols] = output_ptr[A_ncols];
#pragma omp parallel for schedule(static, 128)
	for (perfSpB_index i = 0; i < A_nrows; i++)
	{
		for (perfSpB_index j = input_A->ptr[i]; j < input_A->ptr[i + 1]; j++)
		{
			perfSpB_index cur_col = input_A->indices[j];
			value_t cur_val = ((value_t *)input_A->val)[j];
			perfSpB_index cur_output_pos = atomic_fetch_add(output_ptr + cur_col, 1ul);
			temp_B[cur_output_pos].index = i;
			temp_B[cur_output_pos].val = cur_val;
		}
	}
#pragma omp parallel for schedule(static, 128)
	for (perfSpB_index i = 0; i < A_ncols; i++)
	{
		std::sort(temp_B + output->ptr[i], temp_B + output->ptr[i + 1]);
		for (perfSpB_index j = output->ptr[i]; j < output->ptr[i + 1]; j++)
		{
			output->indices[j] = temp_B[j].index;
			((value_t *)output->val)[j] = temp_B[j].val;
		}
	}
	free(temp_B);
	free(output_ptr);
}

/**
 * @brief Construct new matrix
 * @details Creates a new matrix with specified domain and dimensions.
 * @param[in,out] m On successful return, contains a handle to the newly created PerfSparseBLAS matrix.
 * @param[in] nrows The number of rows of the matrix being created.
 * @param[in] ncols The number of columns of the matrix being created.
 */
template <typename value_t>
GrB_Info Test_Matrix_new(GrB_Matrix *m, perfSpB_index row, perfSpB_index col)
{
	GrB_Info info;
	if (std::is_same<value_t, int>::value)
	{
		info = GrB_Matrix_new(m, GrB_INT32, row, col);
	}
	else if (std::is_same<value_t, long>::value)
	{
		info = GrB_Matrix_new(m, GrB_INT64, row, col);
	}
	else if (std::is_same<value_t, float>::value)
	{
		info = GrB_Matrix_new(m, GrB_FP32, row, col);
	}
	else if (std::is_same<value_t, double>::value)
	{
		info = GrB_Matrix_new(m, GrB_FP64, row, col);
	}
	return info;
}

/**
 * @brief Store elements from tuples into a matrix
 * @param[in,out] C An existing Matrix object to store the result.
 * @param[in] I Pointer to an array of row indices.
 * @param[in] J Pointer to an array of column indices.
 * @param[in] X Pointer to an array of scalars of a type that is compatible with the domain of matrix, C.
 * @param[in] nvals The number of entries contained in each array (the same for row_indices, col_indices and values).
 * @param[in] dup An associative and commutative binary operator to apply when duplicate values for the sam  location are present in the input arrays.
 */
template <typename value_t>
void Test_Matrix_build(
	GrB_Matrix C, const perfSpB_index *I, const perfSpB_index *J,
	const value_t *X, const perfSpB_index nvals, const GrB_BinaryOp dup)
{
	if (std::is_same<value_t, int>::value)
	{
		GrB_Matrix_build_INT32(C, I, J, (int *)X, nvals, dup);
	}
	else if (std::is_same<value_t, long>::value)
	{
		GrB_Matrix_build_INT64(C, I, J, (long *)X, nvals, dup);
	}
	else if (std::is_same<value_t, float>::value)
	{
		GrB_Matrix_build_FP32(C, I, J, (float *)X, nvals, dup);
	}
	else if (std::is_same<value_t, double>::value)
	{
		GrB_Matrix_build_FP64(C, I, J, (double *)X, nvals, dup);
	}
}

/**
 * @brief Generate a random square matrix
 * @param[in] N The size of matrix
 * @param[in] deg The average number of no zero elements per line
 * @param[out] values Pointer to an array of scalars of a type that is compatible with the domain of matrix.
 * @param[out] row_indices Pointer to an array of row indices.
 * @param[out] col_indices Pointer to an array of column indices.
 * @param[out] nrows The row of generate matrix
 * @param[out] ncols The col of generate matrix
 * @param[out] nvals The number of entries contained in each array (the same for row_indices, col_indices and values).
 */
template <typename value_t>
void genMatrix(int N, int deg, value_t *&values, perfSpB_index *&row_indices, perfSpB_index *&col_indices,
			   perfSpB_index &nrows, perfSpB_index &ncols, perfSpB_index &nvals)
{

	nrows = ncols = N;
	nvals = 0;
	perfSpB_index M = N * deg / 2;
	values = new value_t[M * 2];
	row_indices = new perfSpB_index[M * 2];
	col_indices = new perfSpB_index[M * 2];

	std::mt19937 generator(2048);

	std::vector<std::pair<perfSpB_index, perfSpB_index>> pairs(M * 2);
	for (perfSpB_index i = 0; i < M; i++)
	{
		perfSpB_index src = generator() % N;
		perfSpB_index dst = generator() % N;
		if (src != dst)
		{
			pairs[i] = {src, dst};
			pairs[i + M] = {dst, src};
		}
	}

	std::sort(pairs.begin(), pairs.end());
	pairs.erase(std::unique(pairs.begin(), pairs.end()), pairs.end());

	std::uniform_int_distribution<int> range1(1, 10);
	std::uniform_real_distribution<double> range2(0.0, 1.0);
	if (std::is_same<value_t, int>::value || std::is_same<value_t, long>::value)
	{
		for (const auto &pair : pairs)
		{
			perfSpB_index src = pair.first;
			perfSpB_index dst = pair.second;

			row_indices[nvals] = src;
			col_indices[nvals] = dst;
			values[nvals++] = range1(generator);
		}
	}
	else
	{
		for (const auto &pair : pairs)
		{
			perfSpB_index src = pair.first;
			perfSpB_index dst = pair.second;

			row_indices[nvals] = src;
			col_indices[nvals] = dst;
			values[nvals++] = range2(generator);
		}
	}
}
