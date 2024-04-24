#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include "PerfSpB_Matrix.h"
#include <stdio.h>

void print_Vector_BOOL(perfSpB_vector v)
{
    printf("================================\n");
    perfSpB_index n;
    perfSpB_vector_nvals(&n, v);
    bool value;
    printf("The vector size is %lu\n", n);
    printf("The vector elements : \n");
    for (perfSpB_index i = 0; i < n; ++i)
    {
        value = false;
        perfSpB_vector_extract_element_BOOL(&value, v, i);
        printf("%d ", value);
    }
    printf("\n");
    printf("================================\n");
}

void print_Vector_INT32(perfSpB_vector v)
{
    printf("================================\n");
    perfSpB_index n;
    perfSpB_vector_nvals(&n, v);
    int value;
    printf("The vector size is %lu\n", n);
    printf("The vector elements : \n");
    for (perfSpB_index i = 0; i < n; ++i)
    {
        perfSpB_vector_extract_element_INT32(&value, v, i);
        printf("%d ", value);
    }
    printf("\n");
    printf("================================\n");
}

void print_Vector_FP32(perfSpB_vector v)
{
    printf("================================\n");
    perfSpB_index n;
    perfSpB_vector_nvals(&n, v);
    float value;
    printf("The vector size is %lu\n", n);
    printf("The vector elements : \n");
    for (perfSpB_index i = 0; i < n; ++i)
    {
        perfSpB_vector_extract_element_FP32(&value, v, i);
        printf("%f ", value);
    }
    printf("\n");
    printf("================================\n");
}

void print_Matrix_INT32(perfSpB_matrix m)
{
    perfSpB_index n_row, n_col;
    perfSpB_matrix_nrows(&n_row, m);
    perfSpB_matrix_ncols(&n_col, m);
    printf("================================\n");
    printf("The Matrix size is: %lux%lu\n", n_row, n_col);
    printf("The matrix elements:\n");

    for (perfSpB_index i = 0; i < n_row; ++i)
    {
        for (perfSpB_index j = 0; j < n_col; ++j)
        {
            int32_t value = 0;
            perfSpB_info info = perfSpB_matrix_extract_element_INT32(&value, m, i, j);
            if (info == perfSpB_no_value)
                value = 0;
            printf("%d ", value);
        }
        printf("\n");
    }
    printf("================================\n");
}

void print_Matrix_FP32(perfSpB_matrix m)
{
    perfSpB_index n_row, n_col;
    perfSpB_matrix_nrows(&n_row, m);
    perfSpB_matrix_ncols(&n_col, m);
    printf("================================\n");
    printf("The Matrix size is: %lux%lu\n", n_row, n_col);
    printf("The matrix elements:\n");

    for (perfSpB_index i = 0; i < n_row; ++i)
    {
        for (perfSpB_index j = 0; j < n_col; ++j)
        {
            float value = 0;
            perfSpB_info info = perfSpB_matrix_extract_element_FP32(&value, m, i, j);
            if (info == perfSpB_no_value)
                value = 0;
            printf("%f ", value);
        }
        printf("\n");
    }
    printf("================================\n");
}

void print_Matrix_BOOL(perfSpB_matrix m)
{
    perfSpB_index n_row, n_col;
    perfSpB_matrix_nrows(&n_row, m);
    perfSpB_matrix_ncols(&n_col, m);
    printf("================================\n");
    printf("The Matrix size is: %lux%lu\n", n_row, n_col);
    printf("The matrix elements:\n");

    for (perfSpB_index i = 0; i < n_row; ++i)
    {
        for (perfSpB_index j = 0; j < n_col; ++j)
        {
            bool value = 0;
            perfSpB_info info = perfSpB_matrix_extract_element_BOOL(&value, m, i, j);
            if (info == perfSpB_no_value)
                value = false;
            printf("%d ", value==0? 0 : 1);
        }
        printf("\n");
    }
    printf("================================\n");
}

// void print_Matrix_CSR(perfSpB_matrix_CSR *m, int n)
// {
//     printf("================================\n");
//     printf("val :");
//     for (perfSpB_index i = 0; i < n; i++)
//     {
//         printf("%c ", m->val[i]);
//     }
//     printf("\n");

//     printf("col :");
//     for (perfSpB_index i = 0; i < n; i++)
//     {
//         printf("%lu ", m->col[i]);
//     }
//     printf("\n");

//     printf("ptr :");
//     for (perfSpB_index i = 0; i <= n; i++)
//     {
//         printf("%lu ", m->ptr[i]);
//     }
//     printf("\n");

//     printf("================================\n");
// }