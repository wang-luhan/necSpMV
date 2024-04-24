#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "PerfSpB_Global.h"
#include "PerfSpB_Scalar.h"
#include "PerfSpB_Matrix.h"
#include "PerfSpB_Error.h"
#include "PerfSpB_Type.h"
#include "PerfSpB_Alloc.h"

struct perfSpB_matrix_opaque perfSpB_matrix_null_opaque;
perfSpB_matrix perfSpB_matrix_null = &perfSpB_matrix_null_opaque;

perfSpB_info perfSpB_matrix_new(
    perfSpB_matrix *m,
    perfSpB_type type,
    perfSpB_index row,
    perfSpB_index col)
{
    perfSpB_matrix_format_value_ext format_type;
    if (PerfSpB_Global_is_csc_get())
        format_type = perfSpB_csc;
    else
        format_type = perfSpB_csr;
    switch (format_type)
    {
    case (perfSpB_csr):
        return perfSpB_matrix_CSC_or_CSR_new(
            m, type, row, col, format_type);
        break;
    case (perfSpB_csc):
        return perfSpB_matrix_CSC_or_CSR_new(
            m, type, row, col, format_type);
        break;
    default:
        PerfSpB_Error("Unknown Matrix Format \
in the perfSpB_matrix_new!\n",
                      __FILE__, __LINE__);
        break;
    }
    return perfSpB_failure;
}

perfSpB_info perfSpB_matrix_new_format_ext(
    perfSpB_matrix *m, perfSpB_type type,
    perfSpB_index row, perfSpB_index col,
    perfSpB_matrix_format_value_ext format)
{
    perfSpB_info info;

    switch (format)
    {
    case (perfSpB_csr):
        info = perfSpB_matrix_CSC_or_CSR_new(
            m, type, row, col, format);
        return info;
        break;
    case (perfSpB_csc):
        info = perfSpB_matrix_CSC_or_CSR_new(
            m, type, row, col, format);
        return info;
        break;
    default:
        PerfSpB_Error("Unknown Matrix Format \
in the perfSpB_matrix_new!\n",
                      __FILE__, __LINE__);
        break;
    }
    return perfSpB_failure;
}

perfSpB_matrix_format_value_ext perfSpB_matrix_format_ext(
    const perfSpB_matrix m)
{
    return m->format_type;
}

perfSpB_info perfSpB_matrix_type(
    perfSpB_type *type, perfSpB_matrix m)
{
    *type = m->element_type;
    return perfSpB_success;
}

perfSpB_info perfSpB_matrix_nrows(
    perfSpB_index *n, perfSpB_matrix m)
{
    *n = m->row;
    return perfSpB_success;
}
perfSpB_info perfSpB_matrix_ncols(
    perfSpB_index *n, perfSpB_matrix m)
{
    *n = m->col;
    return perfSpB_success;
}

#define PerfSpB_MATRIX_FAST_BUILD_EXT(type, T)                     \
    perfSpB_info perfSpB_matrix_fast_build_##T##_ext(              \
        perfSpB_matrix m_in,                                       \
        const perfSpB_index *row_indices,                          \
        const perfSpB_index *col_indices,                          \
        const type *values,                                        \
        const perfSpB_index n)                                     \
    {                                                              \
        perfSpB_matrix_format_value_ext format =                   \
            m_in->format_type;                                     \
        switch (format)                                            \
        {                                                          \
        case (perfSpB_csr):                                        \
            return perfSpB_matrix_CSC_or_CSR_fast_build_##T##_ext( \
                m_in,                                              \
                row_indices,                                       \
                col_indices,                                       \
                values,                                            \
                n);                                                \
            break;                                                 \
        case (perfSpB_csc):                                        \
            return perfSpB_matrix_CSC_or_CSR_fast_build_##T##_ext( \
                m_in,                                              \
                row_indices,                                       \
                col_indices,                                       \
                values,                                            \
                n);                                                \
            break;                                                 \
        default:                                                   \
            PerfSpB_Error("Unknown Matrix Format \
in perfSpB_matrix_build!\n",                                       \
                          __FILE__, __LINE__);                     \
            break;                                                 \
        }                                                          \
        return perfSpB_failure;                                    \
    }

PerfSpB_MATRIX_FAST_BUILD_EXT(bool, BOOL);
PerfSpB_MATRIX_FAST_BUILD_EXT(int8_t, INT8);
PerfSpB_MATRIX_FAST_BUILD_EXT(int16_t, INT16);
PerfSpB_MATRIX_FAST_BUILD_EXT(int32_t, INT32);
PerfSpB_MATRIX_FAST_BUILD_EXT(int64_t, INT64);
PerfSpB_MATRIX_FAST_BUILD_EXT(uint8_t, UINT8);
PerfSpB_MATRIX_FAST_BUILD_EXT(uint16_t, UINT16);
PerfSpB_MATRIX_FAST_BUILD_EXT(uint32_t, UINT32);
PerfSpB_MATRIX_FAST_BUILD_EXT(uint64_t, UINT64);
PerfSpB_MATRIX_FAST_BUILD_EXT(float, FP32);
PerfSpB_MATRIX_FAST_BUILD_EXT(double, FP64);
#undef PerfSpB_MATRIX_BUILD_EXT

#define PerfSpB_MATRIX_BUILD(type, T)                   \
    perfSpB_info perfSpB_matrix_build_##T(              \
        perfSpB_matrix m_in,                            \
        const perfSpB_index *row_indices,               \
        const perfSpB_index *col_indices,               \
        const type *values,                             \
        const perfSpB_index n)                          \
    {                                                   \
        perfSpB_matrix_format_value_ext format =        \
            m_in->format_type;                          \
        switch (format)                                 \
        {                                               \
        case (perfSpB_csr):                             \
            return perfSpB_matrix_CSC_or_CSR_build_##T( \
                m_in,                                   \
                row_indices,                            \
                col_indices,                            \
                values,                                 \
                n);                                     \
            break;                                      \
        case (perfSpB_csc):                             \
            return perfSpB_matrix_CSC_or_CSR_build_##T( \
                m_in,                                   \
                row_indices,                            \
                col_indices,                            \
                values,                                 \
                n);                                     \
            break;                                      \
        default:                                        \
            PerfSpB_Error("Unknown Matrix Format \
in perfSpB_matrix_build!\n",                            \
                          __FILE__, __LINE__);          \
            break;                                      \
        }                                               \
        return perfSpB_failure;                         \
    }

PerfSpB_MATRIX_BUILD(bool, BOOL);
PerfSpB_MATRIX_BUILD(int8_t, INT8);
PerfSpB_MATRIX_BUILD(int16_t, INT16);
PerfSpB_MATRIX_BUILD(int32_t, INT32);
PerfSpB_MATRIX_BUILD(int64_t, INT64);
PerfSpB_MATRIX_BUILD(uint8_t, UINT8);
PerfSpB_MATRIX_BUILD(uint16_t, UINT16);
PerfSpB_MATRIX_BUILD(uint32_t, UINT32);
PerfSpB_MATRIX_BUILD(uint64_t, UINT64);
PerfSpB_MATRIX_BUILD(float, FP32);
PerfSpB_MATRIX_BUILD(double, FP64);
#undef PerfSpB_MATRIX_BUILD

#define PerfSpB_MATRIX_SETELEMENT(type, T)                   \
    perfSpB_info perfSpB_matrix_set_element_##T(              \
        perfSpB_matrix m,                                    \
        type value,                                          \
        perfSpB_index row,                                   \
        perfSpB_index col)                                   \
    {                                                        \
        perfSpB_matrix_format_value_ext format =             \
            m->format_type;                                  \
        switch (format)                                      \
        {                                                    \
        case (perfSpB_csr):                                  \
            return perfSpB_matrix_CSC_or_CSR_setElement_##T( \
                m, value, row, col);                         \
            break;                                           \
        case (perfSpB_csc):                                  \
            return perfSpB_matrix_CSC_or_CSR_setElement_##T( \
                m, value, row, col);                         \
            break;                                           \
        default:                                             \
            PerfSpB_Error("Unknown Matrix Format \
in the perfSpB_matrix_set_element!\n",                        \
                          __FILE__, __LINE__);               \
            break;                                           \
        }                                                    \
        return perfSpB_failure;                              \
    }

PerfSpB_MATRIX_SETELEMENT(bool, BOOL);
PerfSpB_MATRIX_SETELEMENT(int8_t, INT8);
PerfSpB_MATRIX_SETELEMENT(int16_t, INT16);
PerfSpB_MATRIX_SETELEMENT(int32_t, INT32);
PerfSpB_MATRIX_SETELEMENT(int64_t, INT64);
PerfSpB_MATRIX_SETELEMENT(uint8_t, UINT8);
PerfSpB_MATRIX_SETELEMENT(uint16_t, UINT16);
PerfSpB_MATRIX_SETELEMENT(uint32_t, UINT32);
PerfSpB_MATRIX_SETELEMENT(uint64_t, UINT64);
PerfSpB_MATRIX_SETELEMENT(float, FP32);
PerfSpB_MATRIX_SETELEMENT(double, FP64);
#undef PerfSpB_MATRIX_SETELEMENT

#define PerfSpB_MATRIX_EXTRACTELEMENT(type, T)                   \
    perfSpB_info perfSpB_matrix_extract_element_##T(              \
        type *p,                                                 \
        perfSpB_matrix m,                                        \
        perfSpB_index row,                                       \
        perfSpB_index col)                                       \
    {                                                            \
        perfSpB_matrix_format_value_ext format =                 \
            m->format_type;                                      \
        switch (format)                                          \
        {                                                        \
        case (perfSpB_csr):                                      \
            return perfSpB_matrix_CSC_or_CSR_extractElement_##T( \
                p, m, row, col);                                 \
            break;                                               \
        case (perfSpB_csc):                                      \
            return perfSpB_matrix_CSC_or_CSR_extractElement_##T( \
                p, m, row, col);                                 \
            break;                                               \
        default:                                                 \
            PerfSpB_Error("Unknown Matrix Format \
in the perfSpB_matrix_extract_element!\n",                        \
                          __FILE__, __LINE__);                   \
            break;                                               \
        }                                                        \
        return perfSpB_failure;                                  \
    }
PerfSpB_MATRIX_EXTRACTELEMENT(bool, BOOL);
PerfSpB_MATRIX_EXTRACTELEMENT(int8_t, INT8);
PerfSpB_MATRIX_EXTRACTELEMENT(int16_t, INT16);
PerfSpB_MATRIX_EXTRACTELEMENT(int32_t, INT32);
PerfSpB_MATRIX_EXTRACTELEMENT(int64_t, INT64);
PerfSpB_MATRIX_EXTRACTELEMENT(uint8_t, UINT8);
PerfSpB_MATRIX_EXTRACTELEMENT(uint16_t, UINT16);
PerfSpB_MATRIX_EXTRACTELEMENT(uint32_t, UINT32);
PerfSpB_MATRIX_EXTRACTELEMENT(uint64_t, UINT64);
PerfSpB_MATRIX_EXTRACTELEMENT(float, FP32);
PerfSpB_MATRIX_EXTRACTELEMENT(double, FP64);
#undef PerfSpB_MATRIX_EXTRACTELEMENT

#define CASE_SWICTH_DATA_TYPE_A_TO_B(   \
    type_A, T_A, type_B, T_B)           \
    case perfSpB_##T_B:                 \
        s->value.T_B##_value =          \
            (type_B)(temp.T_A##_value); \
        break;

#define CASES_SWICTH_DATA_TYPE_A_TO_B(type_A, T_A) \
    switch (s->element_type)                       \
    {                                              \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, bool, BOOL);              \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, int8_t, INT8);            \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, int16_t, INT16);          \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, int32_t, INT32);          \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, int64_t, INT64);          \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, uint8_t, UINT8);          \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, uint16_t, UINT16);        \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, uint32_t, UINT32);        \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, uint64_t, UINT64);        \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, float, FP32);             \
        CASE_SWICTH_DATA_TYPE_A_TO_B(              \
            type_A, T_A, double, FP64);            \
    default:                                       \
        PerfSpB_Error("unknown element type \
of the scalar !\n",                                \
                      __FILE__, __LINE__);         \
        break;                                     \
    }

#define CASE_EXTRACTELEMENT_SCALAR(type_A, T_A)         \
    case perfSpB_##T_A:                                 \
        info = perfSpB_matrix_extract_element_##T_A(     \
            &(temp.T_A##_value), m, row, col);          \
        if (info == perfSpB_success)                    \
            CASES_SWICTH_DATA_TYPE_A_TO_B(type_A, T_A); \
        break;

#define CASES_EXTRACTELEMENT_SCALAR               \
    CASE_EXTRACTELEMENT_SCALAR(bool, BOOL);       \
    CASE_EXTRACTELEMENT_SCALAR(int8_t, INT8);     \
    CASE_EXTRACTELEMENT_SCALAR(int16_t, INT16);   \
    CASE_EXTRACTELEMENT_SCALAR(int32_t, INT32);   \
    CASE_EXTRACTELEMENT_SCALAR(int64_t, INT64);   \
    CASE_EXTRACTELEMENT_SCALAR(uint8_t, UINT8);   \
    CASE_EXTRACTELEMENT_SCALAR(uint16_t, UINT16); \
    CASE_EXTRACTELEMENT_SCALAR(uint32_t, UINT32); \
    CASE_EXTRACTELEMENT_SCALAR(uint64_t, UINT64); \
    CASE_EXTRACTELEMENT_SCALAR(float, FP32);      \
    CASE_EXTRACTELEMENT_SCALAR(double, FP64);

perfSpB_info perfSpB_matrix_extract_element_Scalar(
    perfSpB_scalar s,
    const perfSpB_matrix m,
    const perfSpB_index row,
    const perfSpB_index col)
{
    perfSpB_info info;
    perfSpB_type m_tpye = m->element_type;
    Scalar_Value temp;
    switch (m_tpye)
    {
        CASES_EXTRACTELEMENT_SCALAR;
    default:
        PerfSpB_Error("Unknown the scalar element type\
of the input Matrix \
in the perfSpB_matrix_extract_element_Scalar\n",
                      __FILE__, __LINE__);
        info = perfSpB_failure;
        break;
    }
    return info;
}
#undef CASES_EXTRACTELEMENT_SCALAR
#undef CASE_EXTRACTELEMENT_SCALAR
#undef CASES_SWICTH_DATA_TYPE_A_TO_B
#undef CASE_SWICTH_DATA_TYPE_A_TO_B

perfSpB_info perfSpB_matrix_free(perfSpB_matrix *m)
{
    perfSpB_matrix_format_value_ext format =
        (*m)->format_type;
    switch (format)
    {
    case (perfSpB_csr):
        return perfSpB_matrix_CSC_or_CSR_free(m);
        break;
    case (perfSpB_csc):
        return perfSpB_matrix_CSC_or_CSR_free(m);
        break;
    default:
        PerfSpB_Error("Unknown Matrix Format in \
perfSpB_matrix_free!\n",
                      __FILE__, __LINE__);
        break;
    }
    return perfSpB_failure;
}

///////////////////////////////////Build CSC or CSR////////////////////////////////

#define Matrix_compute_next_grow(size) \
    ((size) ? ((size) << 1) : 1)

static perfSpB_info perfSpB_matrix_CSC_or_CSR_grow(
    perfSpB_matrix_CSC_or_CSR *m,
    perfSpB_index capacity)
{
    size_t size = m->matrix_base.element_size;
    if (m->val)
        m->val = PerfSpB_aligned_realloc(
            m->val, size * capacity);
    else
        m->val = PerfSpB_aligned_malloc(
            size * capacity);
    assert(m->val);
    if (m->indices)
        m->indices =
            (perfSpB_index *)PerfSpB_aligned_realloc(
                m->indices, sizeof(perfSpB_index) * capacity);
    else
        m->indices = (perfSpB_index *)PerfSpB_aligned_malloc(
            sizeof(perfSpB_index) * capacity);
    assert(m->indices);
    m->capacity = capacity;
    return perfSpB_success;
}

/**
 * @brief Create a matrix of CSC/CSR format.
 * @param[out] m_in the pointer to a matrix
 */
perfSpB_info perfSpB_matrix_CSC_or_CSR_new(
    perfSpB_matrix *m_in,
    perfSpB_type type,
    perfSpB_index row,
    perfSpB_index col,
    perfSpB_matrix_format_value_ext format_type)
{
    assert(format_type == perfSpB_csc ||
           format_type == perfSpB_csr);
    perfSpB_matrix_CSC_or_CSR **m =
        (perfSpB_matrix_CSC_or_CSR **)m_in;
    OK_ALLOC(*m = (perfSpB_matrix_CSC_or_CSR *)PerfSpB_aligned_malloc(
                 sizeof(perfSpB_matrix_CSC_or_CSR)));
    (*m_in)->element_type = type;
    (*m_in)->format_type = format_type;
    (*m)->matrix_base.row = row;
    (*m)->matrix_base.col = col;
    (*m)->ptr_len =
        format_type == perfSpB_csc
            ? (col + 1)
            : (row + 1);
    (*m)->nnz = 0;
    switch (type)
    {
        PerfSpB_TYPE_CASES(m_in);
    }
    (*m)->capacity = 0;
    (*m)->val = NULL;
    (*m)->indices = NULL;
    perfSpB_index p_len =
        (*m)->matrix_base.format_type == perfSpB_csc
            ? (row + 1)
            : (col + 1);
    OK_ALLOC((*m)->ptr = (perfSpB_index *)PerfSpB_aligned_calloc(
                 p_len * sizeof(perfSpB_index)));

    return perfSpB_success;
}

#define GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(type, T)            \
    perfSpB_info perfSpB_matrix_CSC_or_CSR_fast_build_##T##_ext( \
        perfSpB_matrix m_in,                                     \
        const perfSpB_index *row_indices,                        \
        const perfSpB_index *col_indices,                        \
        const type *values,                                      \
        const perfSpB_index n)                                   \
    {                                                            \
        perfSpB_matrix_CSC_or_CSR *m =                           \
            (perfSpB_matrix_CSC_or_CSR *)m_in;                   \
        perfSpB_matrix_CSC_or_CSR_grow(m, n);                    \
                                                                 \
        m->nnz = n;                                              \
                                                                 \
        m->ptr[0] = 0;                                           \
        perfSpB_index ptr_index = 0;                             \
                                                                 \
        const perfSpB_index *p1_indices =                        \
            m_in->format_type == perfSpB_csc                     \
                ? row_indices                                    \
                : col_indices;                                   \
        const perfSpB_index *p2_indices =                        \
            m_in->format_type == perfSpB_csc                     \
                ? col_indices                                    \
                : row_indices;                                   \
        for (perfSpB_index i = 0; i < n; ++i)                    \
        {                                                        \
            m->indices[i] = p1_indices[i];                       \
            ((type *)(m->val))[i] = values[i];                   \
            while (ptr_index != p2_indices[i])                   \
            {                                                    \
                m->ptr[++ptr_index] = i;                         \
            }                                                    \
        }                                                        \
        m->ptr[m->ptr_len - 1] = n;                              \
        return perfSpB_success;                                  \
    }
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(bool, BOOL);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(int8_t, INT8);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(int16_t, INT16);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(int32_t, INT32);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(int64_t, INT64);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(uint8_t, UINT8);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(uint16_t, UINT16);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(uint32_t, UINT32);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(uint64_t, UINT64);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(float, FP32);
GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(double, FP64);
#undef GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT

typedef union
{
    bool VAL_BOOL;
    int8_t VAL_INT8;
    int16_t VAL_INT16;
    int32_t VAL_INT32;
    int64_t VAL_INT64;
    uint8_t VAL_UINT8;
    uint16_t VAL_UINT16;
    uint32_t VAL_UINT32;
    uint64_t VAL_UINT64;
    float VAL_FP32;
    double VAL_FP64;
} PerfSpB_Build_Object_Format_ext;

typedef struct triple
{
    perfSpB_index row;
    perfSpB_index col;
    PerfSpB_Build_Object_Format_ext val;
} triple;

int tri_cmp_csr(const void *a, const void *b)
{
    triple *a1 = (triple *)a;
    triple *a2 = (triple *)b;
    if ((*a1).row > (*a2).row)
        return 1;
    else if ((*a1).row < (*a2).row)
        return -1;
    else if ((*a1).row == (*a2).row && (*a1).col > (*a2).col)
        return 1;
    else if ((*a1).row == (*a2).row && (*a1).col < (*a2).col)
        return -1;
    return 0;
}
int tri_cmp_csc(const void *a, const void *b)
{
    triple *a1 = (triple *)a;
    triple *a2 = (triple *)b;
    if ((*a1).col > (*a2).col)
        return 1;
    else if ((*a1).col < (*a2).col)
        return -1;
    else if ((*a1).col == (*a2).col && (*a1).row > (*a2).row)
        return 1;
    else if ((*a1).col == (*a2).col && (*a1).row < (*a2).row)
        return -1;
    return 0;
}

#define PerfSpB_MATRIX_CSC_OR_CSR_BUILD(type, T)                          \
    perfSpB_info perfSpB_matrix_CSC_or_CSR_build_##T(                     \
        perfSpB_matrix m_in,                                              \
        const perfSpB_index *row_indices,                                 \
        const perfSpB_index *col_indices,                                 \
        const type *values,                                               \
        const perfSpB_index n)                                            \
    {                                                                     \
        perfSpB_matrix_CSC_or_CSR *m = (perfSpB_matrix_CSC_or_CSR *)m_in; \
        perfSpB_matrix_CSC_or_CSR_grow(m, n);                             \
                                                                          \
        m->nnz = n;                                                       \
        triple *NNZ_TRIPLE = (triple *)malloc(n * sizeof(triple));        \
        memset(NNZ_TRIPLE, 0, sizeof(triple) * n);                        \
        for (perfSpB_index i = 0; i < n; i++)                             \
        {                                                                 \
            NNZ_TRIPLE[i].row = row_indices[i];                           \
            NNZ_TRIPLE[i].col = col_indices[i];                           \
            NNZ_TRIPLE[i].val.VAL_##T = values[i];                        \
        }                                                                 \
        if (m_in->format_type == perfSpB_csc)                             \
        {                                                                 \
            qsort(NNZ_TRIPLE, n, sizeof(NNZ_TRIPLE[0]), tri_cmp_csc);     \
        }                                                                 \
        else                                                              \
        {                                                                 \
            qsort(NNZ_TRIPLE, n, sizeof(NNZ_TRIPLE[0]), tri_cmp_csr);     \
        }                                                                 \
                                                                          \
        m->ptr[0] = 0;                                                    \
        perfSpB_index ptr_index = 0;                                      \
                                                                          \
        if (m_in->format_type == perfSpB_csc)                             \
        {                                                                 \
            for (perfSpB_index i = 0; i < n; ++i)                         \
            {                                                             \
                m->indices[i] = NNZ_TRIPLE[i].row;                        \
                ((type *)(m->val))[i] = NNZ_TRIPLE[i].val.VAL_##T;        \
                while (ptr_index != NNZ_TRIPLE[i].col)                    \
                {                                                         \
                    m->ptr[++ptr_index] = i;                              \
                }                                                         \
            }                                                             \
            m->ptr[m->ptr_len - 1] = n;                                   \
            return perfSpB_success;                                       \
        }                                                                 \
        else                                                              \
        {                                                                 \
            for (perfSpB_index i = 0; i < n; ++i)                         \
            {                                                             \
                m->indices[i] = NNZ_TRIPLE[i].col;                        \
                ((type *)(m->val))[i] = NNZ_TRIPLE[i].val.VAL_##T;        \
                while (ptr_index != NNZ_TRIPLE[i].row)                    \
                {                                                         \
                    m->ptr[++ptr_index] = i;                              \
                }                                                         \
            }                                                             \
            m->ptr[m->ptr_len - 1] = n;                                   \
            return perfSpB_success;                                       \
        }                                                                 \
    }
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(bool, BOOL);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(int8_t, INT8);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(int16_t, INT16);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(int32_t, INT32);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(int64_t, INT64);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(uint8_t, UINT8);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(uint16_t, UINT16);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(uint32_t, UINT32);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(uint64_t, UINT64);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(float, FP32);
PerfSpB_MATRIX_CSC_OR_CSR_BUILD(double, FP64);
#undef PerfSpB_MATRIX_CSC_OR_CSR_BUILD

perfSpB_index perfSpB_matrix_CSC_or_CSR_capacity(perfSpB_matrix_CSC_or_CSR *m)
{
    return m->capacity;
}

// This function is created by xulei!
// It is designed for the perfSpB_matrix_set_element.
// It includes many meanings and needs to be decomposed.
// It will check if the element(row, col) is stored in the CSC matrix(m).
// If true, it provides the address of the element through the pointer p.
// If false, it provides the index of the element to be added to the CSC matrix soon, and returns the perfSpB_no_value.
static perfSpB_info perfSpB_matrix_CSC_or_CSR_findElement(
    void **p,
    perfSpB_matrix_CSC_or_CSR *m,
    perfSpB_index row,
    perfSpB_index col,
    perfSpB_index *index)
{
    perfSpB_index index1 =
        m->matrix_base.format_type == perfSpB_csc ? col : row;
    perfSpB_index index2 =
        m->matrix_base.format_type == perfSpB_csc ? row : col;

    perfSpB_index ptr_start = m->ptr[index1];
    *index = ptr_start;
    perfSpB_index n_one_line = m->ptr[index1 + 1] - ptr_start;
    size_t size = m->matrix_base.element_size;
    for (perfSpB_index i = 0; i < n_one_line; ++i)
    {
        perfSpB_index iter = i + ptr_start;
        perfSpB_index index2_temp = m->indices[iter];
        if (index2 == index2_temp)
        {
            *p = m->val + size * iter;
            return perfSpB_success;
        }
        else if (index2 < index2_temp)
        {
            *index = iter;
            break;
        }
        else
        {
            *index = iter + 1;
        }
    }
    return perfSpB_no_value;
}

// This function is a binarySearch version of a perfSpB_matrix_findElement.
// TODO The binarySearch for the Index of val/row array in a perfSpB_matrix_Contents with a column number(target), where the start and end locate a specific line in a CSC sparse matrix and the number of elements in this row is greater than 1.
// perfSpB_index binarySearch(perfSpB_index *list, perfSpB_index start, perfSpB_index end, perfSpB_index target)
// {
//     end = end - 1;
//     assert(list[start] <= list[end]);
//     while (start <= end)
//     {
//         perfSpB_index middle = (start + end) / 2;
//     }
//     return perfSpB_success;
// }

#define PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(type, T)                  \
    perfSpB_info perfSpB_matrix_CSC_or_CSR_setElement_##T(             \
        perfSpB_matrix m_in,                                           \
        type value,                                                    \
        perfSpB_index row,                                             \
        perfSpB_index col)                                             \
    {                                                                  \
        perfSpB_matrix_CSC_or_CSR *m =                                 \
            (perfSpB_matrix_CSC_or_CSR *)m_in;                         \
        size_t size = m_in->element_size;                              \
        perfSpB_index index1 =                                         \
            m->matrix_base.format_type == perfSpB_csc                  \
                ? col                                                  \
                : row;                                                 \
        perfSpB_index index2 =                                         \
            m->matrix_base.format_type == perfSpB_csc                  \
                ? row                                                  \
                : col;                                                 \
        if (value)                                                     \
        {                                                              \
            void *p = 0;                                               \
            assert(row <= m->matrix_base.row ||                        \
                   col <= m->matrix_base.col);                         \
                                                                       \
            perfSpB_index index;                                       \
                                                                       \
            if (perfSpB_matrix_CSC_or_CSR_findElement(                 \
                    &p, m, row, col, &index))                          \
            {                                                          \
                perfSpB_index m_capacity =                             \
                    perfSpB_matrix_CSC_or_CSR_capacity(m);             \
                perfSpB_index m_size =                                 \
                    perfSpB_matrix_CSC_or_CSR_nnz(m);                  \
                if (m_capacity <= m_size)                              \
                {                                                      \
                    perfSpB_matrix_CSC_or_CSR_grow(                    \
                        m,                                             \
                        Matrix_compute_next_grow((m_capacity)));       \
                }                                                      \
                if (index < m_size)                                    \
                {                                                      \
                    memmove(m->val + (index + 1) * size,               \
                            m->val + index * size,                     \
                            size * (m_size - index));                  \
                                                                       \
                    memmove(m->indices + index + 1,                    \
                            m->indices + index,                        \
                            sizeof(perfSpB_index) * (m_size - index)); \
                }                                                      \
                ((type *)m->val)[index] = value;                       \
                m->indices[index] = index2;                            \
                for (                                                  \
                    perfSpB_index i = index1 + 1;                      \
                    i < m->ptr_len;                                    \
                    i++)                                               \
                {                                                      \
                    m->ptr[i]++;                                       \
                }                                                      \
                m->nnz++;                                              \
            }                                                          \
            else                                                       \
            {                                                          \
                *((type *)p) = value;                                  \
            }                                                          \
            return perfSpB_success;                                    \
        }                                                              \
        else                                                           \
        {                                                              \
            return perfSpB_failure;                                    \
        }                                                              \
    }

PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(bool, BOOL);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(int8_t, INT8);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(int16_t, INT16);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(int32_t, INT32);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(int64_t, INT64);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(uint8_t, UINT8);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(uint16_t, UINT16);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(uint32_t, UINT32);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(uint64_t, UINT64);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(float, FP32);
PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(double, FP64);
#undef PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT

#define PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(type, T)          \
    perfSpB_info perfSpB_matrix_CSC_or_CSR_extractElement_##T(     \
        type *p,                                                   \
        perfSpB_matrix m_in,                                       \
        perfSpB_index row,                                         \
        perfSpB_index col)                                         \
    {                                                              \
        if (m_in->element_type != perfSpB_##T)                     \
            PerfSpB_Error("The data types of the matrix elements and the target do not match \
in perfSpB_matrix_CSC_or_CSR_extractElement!\n",                   \
                          __FILE__, __LINE__);                     \
        perfSpB_matrix_CSC_or_CSR *m =                             \
            (perfSpB_matrix_CSC_or_CSR *)(m_in);                   \
                                                                   \
        perfSpB_index index1 =                                     \
            m_in->format_type == perfSpB_csc ? col : row;          \
        perfSpB_index index2 =                                     \
            m_in->format_type == perfSpB_csc ? row : col;          \
                                                                   \
        perfSpB_index ptr_start = m->ptr[index1];                  \
        perfSpB_index n_one_line =                                 \
            m->ptr[index1 + 1] - ptr_start;                        \
                                                                   \
        for (perfSpB_index i = 0; i < n_one_line; ++i)             \
        {                                                          \
            perfSpB_index index2_temp = m->indices[i + ptr_start]; \
            if (index2 == index2_temp)                             \
            {                                                      \
                *p = ((type *)m->val)[i + ptr_start];              \
                return perfSpB_success;                            \
            }                                                      \
            else if (index2 < index2_temp)                         \
                break;                                             \
        }                                                          \
        return perfSpB_no_value;                                   \
    }

PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(bool, BOOL);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(int8_t, INT8);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(int16_t, INT16);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(int32_t, INT32);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(int64_t, INT64);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(uint8_t, UINT8);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(uint16_t, UINT16);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(uint32_t, UINT32);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(uint64_t, UINT64);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(float, FP32);
PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(double, FP64);
#undef PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT

perfSpB_index perfSpB_matrix_CSC_or_CSR_nnz(perfSpB_matrix_CSC_or_CSR *m)
{
    return m->nnz;
}

perfSpB_info perfSpB_matrix_CSC_or_CSR_free(perfSpB_matrix *m_in)
{
    perfSpB_matrix_CSC_or_CSR **m = (perfSpB_matrix_CSC_or_CSR **)m_in;
    if ((*m)->val)
    {
        free((*m)->val);
        free((*m)->indices);
        free((*m)->ptr);

        free(*m);
        return perfSpB_success;
    }
    else
    {
        return perfSpB_failure;
    }
}