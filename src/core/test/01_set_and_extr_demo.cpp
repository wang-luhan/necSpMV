// #include "SparseBLAS.h"
#include <gtest/gtest.h>
#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include "stdio.h"
#include "PerfSpB_Debug.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void generate_a_random_index(std::vector<perfSpB_index> &a, perfSpB_index n)
{
    for (perfSpB_index i = 0; i < n; ++i)
    {
        a.push_back((perfSpB_index)i);
    }
    std::random_shuffle(a.begin(), a.end());
}

#define TEST_VECTOR_SET_EXTRACT_CPP_TEST(type, T, size)      \
    TEST(Vector_Set_Extract_Test, CPP_##T)                   \
    {                                                        \
        int val_space_size = size;                           \
        std::vector<perfSpB_index> random_a;                     \
        generate_a_random_index(random_a, 1000);             \
        type value_array[1000];                              \
        PerfSpB_init();                                          \
        perfSpB_vector v;                                        \
        perfSpB_vector_new(&v, perfSpB_##T, 1000);                   \
        for (int i = 0; i < 1000; i++)                       \
        {                                                    \
            type value = mrand48() % val_space_size;         \
            value_array[i] = value;                          \
            perfSpB_vector_set_element(v, value, random_a[i]);    \
        }                                                    \
        for (int i = 0; i < 1000; i++)                       \
        {                                                    \
            type value;                                      \
            if (perfSpB_vector_extract_element(                   \
                    &value, v, random_a[i]) == perfSpB_no_value) \
                value = false;                               \
            ASSERT_EQ(value_array[i], value);                \
        }                                                    \
        perfSpB_vector_free(&v);                                 \
        PerfSpB_finalize();                                      \
    }

TEST_VECTOR_SET_EXTRACT_CPP_TEST(bool, BOOL, 2)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(int8_t, INT8, 128)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(int16_t, INT16, 32768)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(int32_t, INT32, 2147483648)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(int64_t, INT64, 2147483648)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(uint8_t, UINT8, 128)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(uint16_t, UINT16, 32768)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(uint32_t, UINT32, 2147483648)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(uint64_t, UINT64, 2147483648)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(float, FP32, 2147483648)
TEST_VECTOR_SET_EXTRACT_CPP_TEST(double, FP64, 2147483648)
#undef TEST_VECTOR_SET_EXTRACT_CPP_TEST

#define TEST_VECTOR_SET_EXTRACT_C_TEST(type, T, size)        \
    TEST(Vector_Set_Extract_Test, C_##T)                     \
    {                                                        \
        int val_space_size = size;                           \
        std::vector<perfSpB_index> random_a;                     \
        generate_a_random_index(random_a, 1000);             \
        type value_array[1000];                              \
        PerfSpB_init();                                          \
        perfSpB_vector v;                                        \
        perfSpB_vector_new(&v, perfSpB_##T, 1000);                   \
        for (int i = 0; i < 1000; i++)                       \
        {                                                    \
            type value = mrand48() % val_space_size;         \
            value_array[i] = value;                          \
            perfSpB_vector_set_element_##T(                       \
                v, value, random_a[i]);                      \
        }                                                    \
        for (int i = 0; i < 1000; i++)                       \
        {                                                    \
            type value;                                      \
            if (perfSpB_vector_extract_element_##T(               \
                    &value, v, random_a[i]) == perfSpB_no_value) \
                value = false;                               \
            ASSERT_EQ(value_array[i], value);                \
        }                                                    \
        perfSpB_vector_free(&v);                                 \
        PerfSpB_finalize();                                      \
    }

TEST_VECTOR_SET_EXTRACT_C_TEST(bool, BOOL, 2)
TEST_VECTOR_SET_EXTRACT_C_TEST(int8_t, INT8, 128)
TEST_VECTOR_SET_EXTRACT_C_TEST(int16_t, INT16, 32768)
TEST_VECTOR_SET_EXTRACT_C_TEST(int32_t, INT32, 2147483648)
TEST_VECTOR_SET_EXTRACT_C_TEST(int64_t, INT64, 2147483648)
TEST_VECTOR_SET_EXTRACT_C_TEST(uint8_t, UINT8, 128)
TEST_VECTOR_SET_EXTRACT_C_TEST(uint16_t, UINT16, 32768)
TEST_VECTOR_SET_EXTRACT_C_TEST(uint32_t, UINT32, 2147483648)
TEST_VECTOR_SET_EXTRACT_C_TEST(uint64_t, UINT64, 2147483648)
TEST_VECTOR_SET_EXTRACT_C_TEST(float, FP32, 2147483648)
TEST_VECTOR_SET_EXTRACT_C_TEST(double, FP64, 2147483648)
#undef TEST_VECTOR_SET_EXTRACT_C_TEST

#define TEST_MATRIX_SET_EXTRACT_C_TEST(type, T, size)     \
    TEST(Matrix_Set_Extract_Test, C_##T)                  \
    {                                                     \
        int val_space_size = size;                        \
        std::vector<perfSpB_index> random_a;                  \
        std::vector<perfSpB_index> random_b;                  \
        generate_a_random_index(random_a, 1000);          \
        generate_a_random_index(random_b, 1000);          \
        type validation_m[1000][1000];                    \
        memset(validation_m, 0,                           \
               sizeof(type) * 1000 * 1000);               \
        PerfSpB_init();                                       \
        perfSpB_matrix m;                                     \
        perfSpB_matrix_new(&m, perfSpB_##T, 1000, 1000);          \
        for (int i = 0; i < 1000; i++)                    \
        {                                                 \
            type value = mrand48() % val_space_size;      \
            perfSpB_matrix_set_element_##T(                    \
                m, value, random_a[i], random_b[i]);      \
            validation_m[random_a[i]][random_b[i]] =      \
                value;                                    \
        }                                                 \
        for (int i = 0; i < 1000; i++)                    \
        {                                                 \
            for (int j = 0; j < 1000; j++)                \
            {                                             \
                type value;                               \
                if (perfSpB_matrix_extract_element_##T(        \
                        &value, m, i, j) == perfSpB_no_value) \
                {                                         \
                    value = (type)0;                      \
                }                                         \
                ASSERT_EQ(validation_m[i][j], value);     \
            }                                             \
        }                                                 \
        perfSpB_matrix_free(&m);                              \
        PerfSpB_finalize();                                   \
    }
TEST_MATRIX_SET_EXTRACT_C_TEST(bool, BOOL, 2)
TEST_MATRIX_SET_EXTRACT_C_TEST(int8_t, INT8, 128)
TEST_MATRIX_SET_EXTRACT_C_TEST(int16_t, INT16, 32768)
TEST_MATRIX_SET_EXTRACT_C_TEST(int32_t, INT32, 2147483648)
TEST_MATRIX_SET_EXTRACT_C_TEST(int64_t, INT64, 2147483648)
TEST_MATRIX_SET_EXTRACT_C_TEST(uint8_t, UINT8, 128)
TEST_MATRIX_SET_EXTRACT_C_TEST(uint16_t, UINT16, 32768)
TEST_MATRIX_SET_EXTRACT_C_TEST(uint32_t, UINT32, 2147483648)
TEST_MATRIX_SET_EXTRACT_C_TEST(uint64_t, UINT64, 2147483648)
TEST_MATRIX_SET_EXTRACT_C_TEST(float, FP32, 2147483648)
TEST_MATRIX_SET_EXTRACT_C_TEST(double, FP64, 2147483648)
#undef TEST_MATRIX_SET_EXTRACT_C_TEST