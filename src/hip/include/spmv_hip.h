#pragma once
#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include "PerfSpB_core.h"

#include <string.h>
#include <assert.h>

#include <stdio.h>
#include <omp.h>
#include <sys/time.h>

#define UNUSED(var) (void)((var) = (var))

template<typename T>
__host__ __device__ __forceinline__ T divup(T a, T b)
{
	return (a + b - 1) / b;
}

// void perfsparseSpMV(perfSpB_vector y, const perfSpB_matrix A, const perfSpB_vector x);
// void perfsparseSpMV__(perfSpB_vector y, const perfSpB_matrix A, const perfSpB_vector x);