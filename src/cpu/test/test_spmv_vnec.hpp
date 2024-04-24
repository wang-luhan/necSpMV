
#include <gtest/gtest.h>
#include <sys/time.h>
#include <gtest/gtest.h>
#include <math.h>
#include <sys/time.h>
#include <algorithm>
#include <omp.h>

#include "utilities/util.hpp"
#include "utilities/graph.hpp"
#include "utilities/builder.hpp"
#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include "PerfSpB_core.h"
#ifdef ARM_NEON
#include <arm_neon.h>
#else
#include <immintrin.h>
#endif

#include <spmv_cpu_common.h>

// #define DATA_PATH "/data/wangluhan/open-graph-blas/data/performance/PageRank/"
// #define DATA_PATH "../../../../../disk/feature-SpMV/open-graph-blas/data/performance/PageRank/"
#define DATA_PATH "/data/wangluhan/SuiteSparse_Matrix_Collection/open-graph-blas/data/graph/"
#define MATRIX_FULL_PATH(file) DATA_PATH #file "/" #file ".mtx"
#define RESULT_FULL_PATH(file) DATA_PATH #file "/" #file "_result.mtx"

#define MATRIX_SG_FULL_PATH(file) DATA_PATH #file "/" #file ".sg"
#define always_inline __inline__ __attribute__((always_inline))

void PerfSpB_mxv_FP32_serial(perfSpB_vector w, const perfSpB_matrix A, const perfSpB_vector u);
void PerfSpB_mxv_FP64_serial(perfSpB_vector w, const perfSpB_matrix A, const perfSpB_vector u);

void VNEC_D_free_fp32(VNEC_D_FP32 *mat_thd);
void VNEC_S_free_fp32(VNEC_S_FP32 *mat_thd);

void VNEC_D_free_fp64(VNEC_D_FP64 *mat_thd);
void VNEC_S_free_fp64(VNEC_S_FP64 *mat_thd);