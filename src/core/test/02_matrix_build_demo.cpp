// #include "PerfSparseBLAS_func.h"
// #include "PerfSparseBLAS_type.h"
// #include "utilities/util.hpp"
// #include <gtest/gtest.h>
// #include <vector>
// #include <stdio.h>
// #include <string>
// #include "PerfSpB_core.h"

// inline void test_method_of_Matrix_build(const char *mtx_path, bool iscsc)
// {

//     std::vector<perfSpB_index> row_indices;
//     std::vector<perfSpB_index> col_indices;

//     std::vector<float> values;
//     perfSpB_index nrows, ncols, nvals;

//     perfSpB_object_format_ext format;
//     if (iscsc)
//         format.matrix_format = perfSpB_csc;
//     else
//         format.matrix_format = perfSpB_csr;

//     PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);

//     readMtx<float>(mtx_path, &row_indices, &col_indices, &values, &nrows, &ncols, &nvals, 2, 1, iscsc, 1);

//     PerfSpB_init();
//     perfSpB_matrix G = NULL;
//     perfSpB_info info;
//     SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_FP32, nrows, ncols));

//     perfSpB_matrix_build_FP32(G, &row_indices[0], &col_indices[0], (float *)&values[0], nvals);

//     float temp_val;
//     bool flag_debug = false;
//     for (perfSpB_index i = 0; i < nvals; i++)
//     {
//         if (perfSpB_matrix_extract_element_FP32(&temp_val, G, row_indices[i], col_indices[i]) == perfSpB_no_value)
//         {
//             temp_val = 0.0;
//         }
//         if (values[i] != temp_val)
//             flag_debug = true;
//         if (flag_debug)
//             exit(1);
//         ASSERT_EQ(values[i], temp_val);
//     }

//     perfSpB_matrix_free(&G);
//     PerfSpB_finalize();
// }

// inline void test_method_of_Matrix_build_ext(const char *mtx_path, bool iscsc)
// {

//     std::vector<perfSpB_index> row_indices;
//     std::vector<perfSpB_index> col_indices;

//     std::vector<char> values;
//     perfSpB_index nrows, ncols, nvals;

//     perfSpB_object_format_ext format;
//     if (iscsc)
//         format.matrix_format = perfSpB_csc;
//     else
//         format.matrix_format = perfSpB_csr;

//     PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);

//     readMtx<char>(mtx_path, &row_indices, &col_indices, &values, &nrows, &ncols, &nvals, 2, 1, iscsc, 1);

//     PerfSpB_init();
//     perfSpB_matrix G = NULL;
//     perfSpB_info info;
//     SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_BOOL, nrows, ncols));
//     perfSpB_matrix_fast_build_BOOL_ext(G, &row_indices[0], &col_indices[0], (bool *)&values[0], nvals);

//     bool temp_val;
//     bool flag_debug = false;
//     for (perfSpB_index i = 0; i < nvals; i++)
//     {
//         if (perfSpB_matrix_extract_element_BOOL(&temp_val, G, row_indices[i], col_indices[i]) == perfSpB_no_value)
//         {
//             temp_val = 0;
//         }
//         if (values[i] != temp_val)
//             flag_debug = true;
//         if (flag_debug)
//             exit(1);
//         ASSERT_EQ(values[i], temp_val);
//     }

//     perfSpB_matrix_free(&G);
//     PerfSpB_finalize();
// }

// #define DATA_PATH "../data/correctness/common/"
// #define DATA_FULL_PATH(file) DATA_PATH file "/" file ".mtx"

// // CSC tests
// TEST(MATRIX_BUILD, ak2010_CSC)
// {
//     std::string input_file(DATA_FULL_PATH("ak2010"));
//     test_method_of_Matrix_build(input_file.c_str(), true);
// }

// TEST(MATRIX_BUILD, coAuthorsDBLP_CSC)
// {
//     std::string input_file(DATA_FULL_PATH("coAuthorsDBLP"));
//     test_method_of_Matrix_build(input_file.c_str(), true);
// }

// TEST(MATRIX_BUILD, amazon0302_CSC)
// {
//     std::string input_file(DATA_FULL_PATH("delaunay_n13"));
//     test_method_of_Matrix_build(input_file.c_str(), true);
// }

// TEST(MATRIX_BUILD, ak2010_CSC_fast_build)
// {
//     std::string input_file(DATA_FULL_PATH("ak2010"));
//     test_method_of_Matrix_build_ext(input_file.c_str(), true);
// }

// TEST(MATRIX_BUILD, coAuthorsDBLP_CSC_fast_build)
// {
//     std::string input_file(DATA_FULL_PATH("coAuthorsDBLP"));
//     test_method_of_Matrix_build_ext(input_file.c_str(), true);
// }

// TEST(MATRIX_BUILD, amazon0302_CSC_fast_build)
// {
//     std::string input_file(DATA_FULL_PATH("delaunay_n13"));
//     test_method_of_Matrix_build_ext(input_file.c_str(), true);
// }

// // CSR tests
// TEST(MATRIX_BUILD, ak2010_CSR)
// {
//     std::string input_file(DATA_FULL_PATH("ak2010"));
//     test_method_of_Matrix_build(input_file.c_str(), false);
// }

// TEST(MATRIX_BUILD, coAuthorsDBLP_CSR)
// {
//     std::string input_file(DATA_FULL_PATH("coAuthorsDBLP"));
//     test_method_of_Matrix_build(input_file.c_str(), false);
// }

// TEST(MATRIX_BUILD, delaunay_n13_CSR)
// {
//     std::string input_file(DATA_FULL_PATH("delaunay_n13"));
//     test_method_of_Matrix_build(input_file.c_str(), false);
// }

// TEST(MATRIX_BUILD, amazon0302_CSR_fast_build)
// {
//     std::string input_file(DATA_FULL_PATH("ak2010"));
//     test_method_of_Matrix_build_ext(input_file.c_str(), false);
// }

// TEST(MATRIX_BUILD, coAuthorsDBLP_CSR_fast_build)
// {
//     std::string input_file(DATA_FULL_PATH("coAuthorsDBLP"));
//     test_method_of_Matrix_build_ext(input_file.c_str(), false);
// }

// TEST(MATRIX_BUILD, delaunay_n13_CSR_fast_build)
// {
//     std::string input_file(DATA_FULL_PATH("delaunay_n13"));
//     test_method_of_Matrix_build_ext(input_file.c_str(), false);
// }
