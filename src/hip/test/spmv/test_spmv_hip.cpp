#include <gtest/gtest.h>
#include <sys/time.h>
#include <math.h>
#include <algorithm>
// #include <omp.h>

#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include "PerfSpB_core.h"
#include "utilities/util.hpp"
#include "utilities/graph.hpp"
#include "utilities/builder.hpp"
// #include "mmio.h"

#include <thread> // 引入线程库
#include <chrono> // 引入计时库

// #define DATA_PATH "/data/wangluhan/SuiteSparse_Matrix_Collection/open-graph-blas/data/graph/"
#define DATA_PATH "/public/home/zzs000156/wangluhan/graph_mtx/graph/"
#define MATRIX_FULL_PATH(file) DATA_PATH #file "/" #file ".mtx"
#define RESULT_FULL_PATH(file) DATA_PATH #file "/" #file "_result.mtx"

#define MATRIX_SG_FULL_PATH(file) DATA_PATH #file "/" #file ".sg"

#define ntest 1
#define nwarm 1
void PerfSpB_mxv_FP32_serial(perfSpB_vector w, const perfSpB_matrix A, const perfSpB_vector u)
{
    perfSpB_vector_Dense *ww = (perfSpB_vector_Dense *)(w);
    perfSpB_vector_Dense *uu = (perfSpB_vector_Dense *)(u);

    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(A);
    float t1, t2, t3;
    for (perfSpB_index i = 0; i < w->n; i++)
    {
        t1 = 0.0f;
        perfSpB_index ptr_start = a->ptr[i];
        perfSpB_index n_one_line = a->ptr[i + 1] - ptr_start;
        for (perfSpB_index j = 0; j < n_one_line; j++)
        {
            t2 = ((float *)a->val)[j + ptr_start];
            t3 = 0.0f;
            perfSpB_index v_idx = a->indices[j + ptr_start];
            t3 = ((float *)uu->values)[v_idx];
            t1 += t2 * t3;
        }
        ((float *)ww->values)[i] = t1;
    }
}
void PerfSpB_mxv_FP64_serial(perfSpB_vector w, const perfSpB_matrix A, const perfSpB_vector u)
{
    perfSpB_vector_Dense *ww = (perfSpB_vector_Dense *)(w);
    perfSpB_vector_Dense *uu = (perfSpB_vector_Dense *)(u);

    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(A);
    double t1, t2, t3;
    for (perfSpB_index i = 0; i < w->n; i++)
    {
        t1 = 0.0f;
        perfSpB_index ptr_start = a->ptr[i];
        perfSpB_index n_one_line = a->ptr[i + 1] - ptr_start;
        for (perfSpB_index j = 0; j < n_one_line; j++)
        {
            t2 = ((double *)a->val)[j + ptr_start];
            t3 = 0.0f;
            perfSpB_index v_idx = a->indices[j + ptr_start];
            t3 = ((double *)uu->values)[v_idx];
            t1 += t2 * t3;
        }
        ((double *)ww->values)[i] = t1;
    }
}
template <perfSpB_info (*perf_spmv)(perfSpB_operation_t, const void *, const perfSpB_matrix, const perfSpB_vector, const void *, perfSpB_vector)>
inline void test_SpMV_accu_perf(const std::string &input_path, const std::string &result_path, bool iscsc)
{
    // printf("\n aaaaaaaaaaaaaaaaaaa \n");
    std::vector<perfSpB_index> row_indices;
    std::vector<perfSpB_index> col_indices;
    std::vector<float> values;
    perfSpB_index nrows, ncols, nvals;
    const char *mtx_path = input_path.c_str();

    readMtx_coo<float>(mtx_path, &row_indices, &col_indices, &values, &nrows, &ncols, &nvals, 1, false);
    // printf("\n bbbbbbbbbbbbbbbbbbbbbbb \n");

    PerfSpB_init();
    perfSpB_object_format_ext format;
    format.matrix_format = perfSpB_csr;
    PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);
    perfSpB_matrix G = NULL;
    perfSpB_info info;
    SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_FP32, nrows, ncols));
    // perfSpB_matrix_build_FP32(G, row_indices, col_indices, values, nvals);
    perfSpB_matrix_build_FP32(G, &row_indices[0], &col_indices[0], (float *)&values[0], nvals);
    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(G);

    for (int i = 0; i < nrows; i++)
    {
        if ((a->ptr[i + 1] - a->ptr[i]) < 0)
        {
            printf("\n !!!  row offset error !!!\n");
            return;
        }
    }

    perfSpB_vector x;
    SAFE_CALL(perfSpB_vector_new(&x, perfSpB_FP32, ncols));
    for (perfSpB_index j = 0; j < ncols; j++)
    {
        perfSpB_vector_set_element_FP32(x, j + (j % 66), j);
    }
    perfSpB_vector result_benchmark;
    SAFE_CALL(perfSpB_vector_new(&result_benchmark, perfSpB_FP32, nrows));
    perfSpB_vector result_opt;
    SAFE_CALL(perfSpB_vector_new(&result_opt, perfSpB_FP32, nrows));
    for (perfSpB_index j = 0; j < ncols; j++)
    {
        perfSpB_vector_set_element_FP32(result_benchmark, 0, j);
        perfSpB_vector_set_element_FP32(result_opt, 0, j);
    }
    // struct timeval opt_start, opt_end;
    for (perfSpB_index i = 0; i < 1; i++)
    {
        PerfSpB_mxv_FP32_serial(result_benchmark, G, x);
    }
    // printf("\n cccccccccccccccccccccc \n");

    float alpha = 1.0f;
    float beta = 0.0f;
    //---------------------------------------------------------------------------------------------------------------------------
    // gettimeofday(&opt_start, NULL);
    for (perfSpB_index i = 0; i < ntest; i++)
    {
        perf_spmv(perfSpB_operation_non_transpose, &alpha, G, x, &beta, result_opt);
        // perfSpB_SpMV_VNEC_FP32(perfSpB_operation_non_transpose, &alpha, G, x, &beta, result_opt);
    }
    // gettimeofday(&opt_end, NULL);
    printf("\nmatrix has %ld nnz \n", nvals);

    // long opt_timeuse = 1000000 * (opt_end.tv_sec - opt_start.tv_sec) + opt_end.tv_usec - opt_start.tv_usec;
    // printf("\n ------------------------------------------------------------------------------");
    // printf("\n SpMV overall time elapsed: %f ms\n", opt_timeuse / 1000.0 / ntest);
    // printf(" ------------------------------------------------------------------------------ \n");

    // float diff = 0.0;
    // for (perfSpB_index i = 0; i < nrows; ++i)
    // {
    //     float value_benchmark, value_opt;
    //     perfSpB_vector_extract_element_FP32(&value_benchmark, result_benchmark, i);
    //     perfSpB_vector_extract_element_FP32(&value_opt, result_opt, i);
    //     diff = fabs(value_benchmark - value_opt);
    //     if (diff > value_benchmark * 1e-4)
    //     {
    //         printf("\ncuda[%ld]=%f", i, value_opt);
    //         printf("\ncpu_[%ld]=%f", i, value_benchmark);
    //         printf("\n");
    //     }

    //     ASSERT_LE(diff, value_benchmark * 1e-4); // TODO: Accuracy test
    // }

    perfSpB_matrix_free(&G);
    perfSpB_vector_free(&x);
    perfSpB_vector_free(&result_opt);
    perfSpB_vector_free(&result_benchmark);
}

template <perfSpB_info (*perf_spmv)(perfSpB_operation_t, const void *, const perfSpB_matrix, const perfSpB_vector, const void *, perfSpB_vector)>
inline void test_SpMV_accu_perf_FP64(const std::string &input_path, const std::string &result_path, bool iscsc)
{

    std::vector<perfSpB_index> row_indices;
    std::vector<perfSpB_index> col_indices;
    std::vector<double> values;
    perfSpB_index nrows, ncols, nvals;
    const char *mtx_path = input_path.c_str();

    readMtx_coo<double>(mtx_path, &row_indices, &col_indices, &values, &nrows, &ncols, &nvals, 1, false);

    PerfSpB_init();
    perfSpB_object_format_ext format;
    format.matrix_format = perfSpB_csr;
    PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);
    perfSpB_matrix G = NULL;
    perfSpB_info info;
    SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_FP64, nrows, ncols));
    // perfSpB_matrix_build_FP64(G, row_indices, col_indices, values, nvals);
    perfSpB_matrix_build_FP64(G, &row_indices[0], &col_indices[0], (double *)&values[0], nvals);
    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(G);

    for (int i = 0; i < nrows; i++)
    {
        if ((a->ptr[i + 1] - a->ptr[i]) < 0)
        {
            printf("\n !!!  row offset error !!!\n");
            return;
        }
    }

    perfSpB_vector x;
    SAFE_CALL(perfSpB_vector_new(&x, perfSpB_FP64, ncols));
    for (perfSpB_index j = 0; j < ncols; j++)
    {
        perfSpB_vector_set_element_FP64(x, j + (j % 66), j);
    }
    perfSpB_vector result_benchmark;
    SAFE_CALL(perfSpB_vector_new(&result_benchmark, perfSpB_FP64, nrows));
    perfSpB_vector result_opt;
    SAFE_CALL(perfSpB_vector_new(&result_opt, perfSpB_FP64, nrows));
    for (perfSpB_index j = 0; j < ncols; j++)
    {
        perfSpB_vector_set_element_FP64(result_benchmark, 0, j);
        perfSpB_vector_set_element_FP64(result_opt, 0, j);
    }
    // struct timeval opt_start, opt_end;
    for (perfSpB_index i = 0; i < 1; i++)
    {
        PerfSpB_mxv_FP64_serial(result_benchmark, G, x);
    }

    double alpha = 1.0f;
    double beta = 0.0f;
    //---------------------------------------------------------------------------------------------------------------------------
    // gettimeofday(&opt_start, NULL);
    for (perfSpB_index i = 0; i < ntest; i++)
    {
        perf_spmv(perfSpB_operation_non_transpose, &alpha, G, x, &beta, result_opt);
        // perfSpB_SpMV_VNEC_FP64(perfSpB_operation_non_transpose, &alpha, G, x, &beta, result_opt);
    }
    // gettimeofday(&opt_end, NULL);
    printf("\nmatrix has %ld nnz \n", nvals);

    // long opt_timeuse = 1000000 * (opt_end.tv_sec - opt_start.tv_sec) + opt_end.tv_usec - opt_start.tv_usec;
    // printf("\n ------------------------------------------------------------------------------");
    // printf("\n SpMV overall time elapsed: %f ms\n", opt_timeuse / 1000.0 / ntest);
    // printf(" ------------------------------------------------------------------------------ \n");

    // double diff = 0.0;
    // for (perfSpB_index i = 0; i < nrows; ++i)
    // {
    //     double value_benchmark, value_opt;
    //     perfSpB_vector_extract_element_FP64(&value_benchmark, result_benchmark, i);
    //     perfSpB_vector_extract_element_FP64(&value_opt, result_opt, i);
    //     diff = fabs(value_benchmark - value_opt);
    //     if (diff > value_benchmark * 1e-4)
    //     {
    //         printf("\ncuda[%ld]=%f", i, value_opt);
    //         printf("\ncpu_[%ld]=%f", i, value_benchmark);
    //         printf("\n");
    //     }

    //     ASSERT_LE(diff, value_benchmark * 1e-4); // TODO: Accuracy test
    // }

    perfSpB_matrix_free(&G);
    perfSpB_vector_free(&x);
    perfSpB_vector_free(&result_opt);
    perfSpB_vector_free(&result_benchmark);
}

// #include "commontest_fp32.hpp"
// #include "commontest_fp64.hpp"
// #include "lbnec_fp32.hpp"
// #include "flat_fp32.hpp"
// #include "lbnec_fp64.hpp"
/*
TEST(cuda_test_spmv_LBNEC_FP32, roadNet_CA)
{
    std::string input_file(MATRIX_FULL_PATH(roadNet-CA ));
    std::string output_file(RESULT_FULL_PATH(roadNet-CA ));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP32, amazon0312)
{
    std::string input_file(MATRIX_FULL_PATH(amazon0312 ));
    std::string output_file(RESULT_FULL_PATH(amazon0312 ));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32, web_Google)
{
    std::string input_file(MATRIX_FULL_PATH(web-Google ));
    std::string output_file(RESULT_FULL_PATH(web-Google ));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32, web_Stanford)
{
    std::string input_file(MATRIX_FULL_PATH(web-Stanford ));
    std::string output_file(RESULT_FULL_PATH(web-Stanford ));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32, coAuthorsCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer ));
    std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer ));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32, coAuthorsDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP ));
    std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP ));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32, com_Amazon)
{
    std::string input_file(MATRIX_FULL_PATH(com-Amazon ));
    std::string output_file(RESULT_FULL_PATH(com-Amazon ));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32, web_BerkStan)
{
    std::string input_file(MATRIX_FULL_PATH(web-BerkStan ));
    std::string output_file(RESULT_FULL_PATH(web-BerkStan ));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
*/
// TEST(cuda_test_spmv_CUSP_FP32, roadNet_CA)
// {
//     std::string input_file(MATRIX_FULL_PATH(roadNet-CA ));
//     std::string output_file(RESULT_FULL_PATH(roadNet-CA ));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_CUSP_FP32, amazon0312)
// {
//     std::string input_file(MATRIX_FULL_PATH(amazon0312 ));
//     std::string output_file(RESULT_FULL_PATH(amazon0312 ));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_CUSP_FP32, web_Google)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Google ));
//     std::string output_file(RESULT_FULL_PATH(web-Google ));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_CUSP_FP32, web_Stanford)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Stanford ));
//     std::string output_file(RESULT_FULL_PATH(web-Stanford ));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_CUSP_FP32, coAuthorsCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer ));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer ));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_CUSP_FP32, coAuthorsDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP ));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP ));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_CUSP_FP32, com_Amazon)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Amazon ));
//     std::string output_file(RESULT_FULL_PATH(com-Amazon ));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_CUSP_FP32, web_BerkStan)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-BerkStan ));
//     std::string output_file(RESULT_FULL_PATH(web-BerkStan ));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LBNEC_FP32, web_Google)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Google ));
//     std::string output_file(RESULT_FULL_PATH(web-Google ));
//     test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LBNEC_FP32, coAuthorsDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP ));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP ));
//     test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LBNEC_FP64, roadNet_CA)
// {
//     std::string input_file(MATRIX_FULL_PATH(roadNet-CA ));
//     std::string output_file(RESULT_FULL_PATH(roadNet-CA ));
//     test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LBNEC_FP64, web_Google)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Google ));
//     std::string output_file(RESULT_FULL_PATH(web-Google ));
//     test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LBNEC_FP64, coAuthorsDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP ));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP ));
//     test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
// }
