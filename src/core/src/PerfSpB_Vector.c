/**
 * @file perfSpB_vector.c
 * @xulei (xulei19b@ict.ac.com)
 * @brief Member functions of perfSpB_vector
 * @version 0.1
 * @date 2022-08-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "PerfSpB_core.h"
#include "PerfSpB_Global.h"
#define max(x, y) (x > y) ? x : y;
#define Vector_compute_next_grow(size) \
    ((size) ? ((size) << 1) : 1)

struct perfSpB_vector_opaque perfSpB_vector_null_opaque =
    {perfSpB_null_type,
     perfSpB_vector_no_format,
     0,
     0};
perfSpB_vector perfSpB_vector_null = &perfSpB_vector_null_opaque;

perfSpB_info perfSpB_vector_nvals(perfSpB_index *n, perfSpB_vector v)
{
    *n = v->n;
    return perfSpB_success;
}

perfSpB_info perfSpB_vector_new(
    perfSpB_vector *v,
    perfSpB_type type,
    perfSpB_index n)
{

    perfSpB_vector_format_value_ext format_type =
        PerfSpB_Global_get_Vector_Format();
    perfSpB_info info;

    switch (format_type)
    {
    case (perfSpB_dense):
        info = perfSpB_vector_Dense_new(v, type, n);
        return info;
    case (perfSpB_sparse):
        info = perfSpB_vector_Sparse_new(v, type, n);
        return info;
    default:
        PerfSpB_Error("Unknown Vector Format \
in the perfSpB_vector_new!\n",
                      __FILE__, __LINE__);
        break;
    }
    return perfSpB_failure;
}

// Todo : This is a very slow implementation.
perfSpB_info perfSpB_vector_dup(perfSpB_vector *v1, perfSpB_vector v2)
{
    perfSpB_vector_format_value_ext format_type = v2->format_type;
    perfSpB_info info;

    switch (format_type)
    {
    case (perfSpB_dense):
        info = perfSpB_vector_Dense_dup(v1, v2);
        return info;
    case (perfSpB_sparse):
        PerfSpB_Error("GxB_SPARSE is not supported \
for Vector Format in the perfSpB_vector_dup!\n",
                      __FILE__, __LINE__);
        return perfSpB_failure;
    default:
        PerfSpB_Error("Unknown vector format_type \
in the perfSpB_vector_dup!\n",
                      __FILE__, __LINE__);
        return perfSpB_failure;
    }
}

perfSpB_info perfSpB_vector_copy_format_ext(
    perfSpB_vector *out,
    const perfSpB_vector in)
{
    perfSpB_info info;
    if (*out != NULL)
    {
        SAFE_CALL(perfSpB_vector_free(out));
    }

    const perfSpB_type type = in->element_type;
    const perfSpB_index n = in->n;
    const perfSpB_vector_format_value_ext format =
        in->format_type;

    info = perfSpB_vector_new_format_ext(
        out, type, n, format);

    return info;
}

perfSpB_info perfSpB_vector_new_format_ext(
    perfSpB_vector *v,
    perfSpB_type type,
    perfSpB_index n,
    perfSpB_vector_format_value_ext format)
{
    perfSpB_info info;

    switch (format)
    {
    case (perfSpB_dense):
        info = perfSpB_vector_Dense_new(v, type, n);
        return info;
        break;
    case (perfSpB_sparse):
        info = perfSpB_vector_Sparse_new(v, type, n);
        return info;
        break;
    default:
        PerfSpB_Error("Unknown Vector Format \
in the perfSpB_vector_new!\n",
                      __FILE__, __LINE__);
        break;
    }
    return perfSpB_failure;
}

perfSpB_vector_format_value_ext perfSpB_vector_format_ext(const perfSpB_vector v)
{
    return v->format_type;
}

#ifdef _OPENMP
#define GRB_VECTOR_SET(type, T)                              \
    perfSpB_info perfSpB_vector_set_element_##T(              \
        perfSpB_vector v,                                    \
        type value,                                          \
        perfSpB_index index)                                 \
    {                                                        \
        perfSpB_vector_format_value_ext format =             \
            v->format_type;                                  \
        perfSpB_info info;                                   \
        switch (format)                                      \
        {                                                    \
        case (perfSpB_dense):                                \
            return perfSpB_vector_Dense_setElement_##T(      \
                v, value, index);                            \
        case (perfSpB_sparse):                               \
        {                                                    \
            _Pragma("omp critical")                          \
            {                                                \
                info = perfSpB_vector_Sparse_setElement_##T( \
                    v, value, index);                        \
            }                                                \
            return info;                                     \
        }                                                    \
        default:                                             \
            PerfSpB_Error("Unknown Vector Format \
in the perfSpB_vector_set_element_##T !\n",                   \
                          __FILE__, __LINE__);               \
            break;                                           \
        }                                                    \
        return perfSpB_failure;                              \
    }
#else
#define GRB_VECTOR_SET(type, T)                          \
    perfSpB_info perfSpB_vector_set_element_##T(          \
        perfSpB_vector v,                                \
        type value,                                      \
        perfSpB_index index)                             \
    {                                                    \
        perfSpB_vector_format_value_ext format =         \
            v->format_type;                              \
        perfSpB_info info;                               \
        switch (format)                                  \
        {                                                \
        case (perfSpB_dense):                            \
        {                                                \
            info = perfSpB_vector_Dense_setElement_##T(  \
                v, value, index);                        \
            return info;                                 \
        }                                                \
        case (perfSpB_sparse):                           \
        {                                                \
            info = perfSpB_vector_Sparse_setElement_##T( \
                v, value, index);                        \
            return info;                                 \
        }                                                \
        default:                                         \
            PerfSpB_error("Unknown Vector Format \
in the perfSpB_vector_set_element_##T !\n");              \
            break;                                       \
        }                                                \
        return perfSpB_failure;                          \
    }
#endif
GRB_VECTOR_SET(bool, BOOL);
GRB_VECTOR_SET(int8_t, INT8);
GRB_VECTOR_SET(int16_t, INT16);
GRB_VECTOR_SET(int32_t, INT32);
GRB_VECTOR_SET(int64_t, INT64);
GRB_VECTOR_SET(uint8_t, UINT8);
GRB_VECTOR_SET(uint16_t, UINT16);
GRB_VECTOR_SET(uint32_t, UINT32);
GRB_VECTOR_SET(uint64_t, UINT64);
GRB_VECTOR_SET(float, FP32);
GRB_VECTOR_SET(double, FP64);
#undef GRB_VECTOR_SET

#define CASE_SWICTH_DATA_TYPE_A_TO_B(                  \
    type_A, T_A, type_B, T_B)                          \
    case perfSpB_##T_B:                                \
        info = perfSpB_vector_set_element_##T_B(        \
            v, (type_B)(s->value.T_A##_value), index); \
        break;

#define CASES_SWICTH_DATA_TYPE_A_TO_B(type_A, T_A) \
    switch (v->element_type)                       \
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

#define CASE_SETELEMENT_SCALAR(type_A, T_A) \
    case perfSpB_##T_A:                     \
        CASES_SWICTH_DATA_TYPE_A_TO_B(      \
            type_A, T_A);                   \
        break;

#define CASES_SETELEMENT_SCALAR               \
    CASE_SETELEMENT_SCALAR(bool, BOOL);       \
    CASE_SETELEMENT_SCALAR(int8_t, INT8);     \
    CASE_SETELEMENT_SCALAR(int16_t, INT16);   \
    CASE_SETELEMENT_SCALAR(int32_t, INT32);   \
    CASE_SETELEMENT_SCALAR(int64_t, INT64);   \
    CASE_SETELEMENT_SCALAR(uint8_t, UINT8);   \
    CASE_SETELEMENT_SCALAR(uint16_t, UINT16); \
    CASE_SETELEMENT_SCALAR(uint32_t, UINT32); \
    CASE_SETELEMENT_SCALAR(uint64_t, UINT64); \
    CASE_SETELEMENT_SCALAR(float, FP32);      \
    CASE_SETELEMENT_SCALAR(double, FP64);

perfSpB_info perfSpB_vector_set_element_Scalar(
    perfSpB_vector v,
    perfSpB_scalar s,
    perfSpB_index index)
{
    perfSpB_info info = perfSpB_failure;
    switch (s->element_type)
    {
        CASES_SETELEMENT_SCALAR;
    default:
        PerfSpB_Error("unknown element type of scalar \
in the perfSpB_vector_set_element_Scalar!\n",
                      __FILE__, __LINE__);
        break;
    }
    return info;
}
#undef CASES_SETELEMENT_SCALAR
#undef CASE_SETELEMENT_SCALAR
#undef CASES_SWICTH_DATA_TYPE_A_TO_B
#undef CASE_SWICTH_DATA_TYPE_A_TO_B

#define GRB_VECTOR_EXTRACT(type, T)                          \
    perfSpB_info perfSpB_vector_extract_element_##T(          \
        type *value,                                         \
        perfSpB_vector v,                                    \
        perfSpB_index index)                                 \
    {                                                        \
        perfSpB_vector_format_value_ext format =             \
            v->format_type;                                  \
        switch (format)                                      \
        {                                                    \
        case (perfSpB_dense):                                \
            return perfSpB_vector_Dense_extractElement_##T(  \
                value, v, index);                            \
        case (perfSpB_sparse):                               \
            return perfSpB_vector_Sparse_extractElement_##T( \
                value, v, index);                            \
            break;                                           \
        default:                                             \
            PerfSpB_Error("Unknown Vector Format \
in the perfSpB_vector_extract_element_" #T " !\n",            \
                          __FILE__, __LINE__);               \
            break;                                           \
        }                                                    \
        return perfSpB_failure;                              \
    }

GRB_VECTOR_EXTRACT(bool, BOOL);
GRB_VECTOR_EXTRACT(int8_t, INT8);
GRB_VECTOR_EXTRACT(int16_t, INT16);
GRB_VECTOR_EXTRACT(int32_t, INT32);
GRB_VECTOR_EXTRACT(int64_t, INT64);
GRB_VECTOR_EXTRACT(uint8_t, UINT8);
GRB_VECTOR_EXTRACT(uint16_t, UINT16);
GRB_VECTOR_EXTRACT(uint32_t, UINT32);
GRB_VECTOR_EXTRACT(uint64_t, UINT64);
GRB_VECTOR_EXTRACT(float, FP32);
GRB_VECTOR_EXTRACT(double, FP64);
#undef GRB_VECTOR_EXTRACT

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

#define CASE_EXTRACTELEMENT_SCALAR(type_A, T_A)     \
    case perfSpB_##T_A:                             \
        info = perfSpB_vector_extract_element_##T_A( \
            &(temp.T_A##_value), v, index);         \
        if (info == perfSpB_success)                \
            CASES_SWICTH_DATA_TYPE_A_TO_B(          \
                type_A, T_A);                       \
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

perfSpB_info perfSpB_vector_extract_element_Scalar(
    perfSpB_scalar s,
    const perfSpB_vector v,
    const perfSpB_index index)
{
    perfSpB_info info;
    perfSpB_type v_tpye = v->element_type;
    Scalar_Value temp;
    switch (v_tpye)
    {
        CASES_EXTRACTELEMENT_SCALAR;
    default:
        PerfSpB_Error("Unknown the scalar element type\
of the input vector \
in the perfSpB_vector_extract_element_Scalar\n",
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

#define PerfSpB_VECTOR_EXTRACT_TUPLES(type, T)              \
    perfSpB_info perfSpB_vector_extract_tuples_##T(          \
        perfSpB_index *indices,                             \
        type *values,                                       \
        perfSpB_index *n,                                   \
        const perfSpB_vector v)                             \
    {                                                       \
        perfSpB_vector_format_value_ext format =            \
            v->format_type;                                 \
        switch (format)                                     \
        {                                                   \
        case (perfSpB_dense):                               \
            return perfSpB_vector_Dense_extractTuples_##T(  \
                indices, values, n, v);                     \
        case (perfSpB_sparse):                              \
            return perfSpB_vector_Sparse_extractTuples_##T( \
                indices, values, n, v);                     \
        default:                                            \
            PerfSpB_Error("Unknown Vector Format \
in perfSpB_vector_extract_tuples_" #T " !\n",                \
                          __FILE__, __LINE__);              \
            break;                                          \
        }                                                   \
        return perfSpB_failure;                             \
    }
PerfSpB_VECTOR_EXTRACT_TUPLES(bool, BOOL);
PerfSpB_VECTOR_EXTRACT_TUPLES(int8_t, INT8);
PerfSpB_VECTOR_EXTRACT_TUPLES(int16_t, INT16);
PerfSpB_VECTOR_EXTRACT_TUPLES(int32_t, INT32);
PerfSpB_VECTOR_EXTRACT_TUPLES(int64_t, INT64);
PerfSpB_VECTOR_EXTRACT_TUPLES(uint8_t, UINT8);
PerfSpB_VECTOR_EXTRACT_TUPLES(uint16_t, UINT16);
PerfSpB_VECTOR_EXTRACT_TUPLES(uint32_t, UINT32);
PerfSpB_VECTOR_EXTRACT_TUPLES(uint64_t, UINT64);
PerfSpB_VECTOR_EXTRACT_TUPLES(float, FP32);
PerfSpB_VECTOR_EXTRACT_TUPLES(double, FP64);
#undef PerfSpB_VECTOR_EXTRACT_TUPLES

/**
 * @callgraph
 */
perfSpB_info perfSpB_vector_free(perfSpB_vector *v)
{
    perfSpB_vector_format_value_ext format =
        (*v)->format_type;
    switch (format)
    {
    case (perfSpB_dense):
        return perfSpB_vector_Dense_free(v);
    case (perfSpB_sparse):
        return perfSpB_vector_Sparse_free(v);
    default:
        PerfSpB_Error("Unknown Vector Format \
in the perfSpB_vector_free !\n",
                      __FILE__, __LINE__);
        break;
    }
    return perfSpB_failure;
}

#define PerfSpB_VECTOR_BUILD(type, T)               \
    perfSpB_info perfSpB_vector_build_##T(          \
        perfSpB_vector v,                           \
        const perfSpB_index *indices,               \
        const type *values,                         \
        perfSpB_index n)                            \
    {                                               \
        perfSpB_vector_format_value_ext format =    \
            v->format_type;                         \
        switch (format)                             \
        {                                           \
        case (perfSpB_dense):                       \
            return perfSpB_vector_Dense_build_##T(  \
                (perfSpB_vector_Dense *)v,          \
                indices, values, n);                \
        case (perfSpB_sparse):                      \
            return perfSpB_vector_Sparse_build_##T( \
                (perfSpB_vector_Sparse *)v,         \
                indices, values, n);                \
        default:                                    \
            PerfSpB_Error("Unknown Vector Format \
in the perfSpB_vector_build_" #T " !\n",            \
                          __FILE__, __LINE__);      \
            break;                                  \
        }                                           \
        return perfSpB_failure;                     \
    }
PerfSpB_VECTOR_BUILD(bool, BOOL);
PerfSpB_VECTOR_BUILD(int8_t, INT8);
PerfSpB_VECTOR_BUILD(int16_t, INT16);
PerfSpB_VECTOR_BUILD(int32_t, INT32);
PerfSpB_VECTOR_BUILD(int64_t, INT64);
PerfSpB_VECTOR_BUILD(uint8_t, UINT8);
PerfSpB_VECTOR_BUILD(uint16_t, UINT16);
PerfSpB_VECTOR_BUILD(uint32_t, UINT32);
PerfSpB_VECTOR_BUILD(uint64_t, UINT64);
PerfSpB_VECTOR_BUILD(float, FP32);
PerfSpB_VECTOR_BUILD(double, FP64);
#undef PerfSpB_VECTOR_BUILD

/////////////////////////////////////////Dense Vector////////////////////////////////////
perfSpB_info perfSpB_vector_Dense_new(
    perfSpB_vector *v_in,
    perfSpB_type type,
    perfSpB_index n)
{
    perfSpB_vector_Dense **v =
        (perfSpB_vector_Dense **)v_in;

    *v = (perfSpB_vector_Dense *)
        PerfSpB_aligned_malloc(
            sizeof(perfSpB_vector_Dense));
    (*v)->vector_base.format_type = perfSpB_dense;
    (*v)->vector_base.element_type = type;
    switch (type)
    {
        PerfSpB_TYPE_CASES(v_in);
    }
    size_t size = (*v_in)->element_size;
    if (!(*v))
        return perfSpB_failure;
    (*v)->values = PerfSpB_aligned_malloc(n * size);
    if (!(*v)->values)
        return perfSpB_failure;
    // The entire vector is initialized to zero.
    memset((*v)->values, 0, n * size);
    // Set the vector length.
    (*v)->vector_base.n = n;
    return perfSpB_success;
}

perfSpB_info perfSpB_vector_Dense_dup(
    perfSpB_vector *v1,
    perfSpB_vector v2)
{
    perfSpB_vector_Dense **v = (perfSpB_vector_Dense **)v1;
    *v = (perfSpB_vector_Dense *)
        PerfSpB_aligned_malloc(
            sizeof(perfSpB_vector_Dense));
    (*v)->vector_base.format_type = perfSpB_dense;
    perfSpB_type type = v2->element_type;
    (*v)->vector_base.element_type = type;
    switch (type)
    {
        PerfSpB_TYPE_CASES(v1);
    }
    size_t size = (*v1)->element_size;
    perfSpB_index n = v2->n;
    (*v1)->n = n;
    (*v1)->element_size = size;

    if (!(*v))
        return perfSpB_failure;

    (*v)->values = PerfSpB_aligned_malloc(n * size);
    if (!(*v)->values)
        return perfSpB_failure;

    memcpy((*v)->values,
           ((perfSpB_vector_Dense *)v2)->values, n * size);
    return perfSpB_success;
}

//------------------------------------------------------------------------------
// perfSpB_vector_set_element: set an entry in a vector, w (row) = x
//------------------------------------------------------------------------------
// Set a single scalar, w(row) = x, typecasting from the type of x to
// the type of w as needed.
#define PerfSpB_VECTOR_DENSE_SET(type, T)                      \
    perfSpB_info PerfSpB_TOKEN_PASTING2(                       \
        perfSpB_vector_Dense_setElement_, T)(                  \
        perfSpB_vector w,                                      \
        type x,                                                \
        perfSpB_index row)                                     \
    {                                                          \
        ((type *)(((perfSpB_vector_Dense *)w)->values))[row] = \
            x;                                                 \
        return perfSpB_success;                                \
    }

PerfSpB_VECTOR_DENSE_SET(bool, BOOL);
PerfSpB_VECTOR_DENSE_SET(int8_t, INT8);
PerfSpB_VECTOR_DENSE_SET(int16_t, INT16);
PerfSpB_VECTOR_DENSE_SET(int32_t, INT32);
PerfSpB_VECTOR_DENSE_SET(int64_t, INT64);
PerfSpB_VECTOR_DENSE_SET(uint8_t, UINT8);
PerfSpB_VECTOR_DENSE_SET(uint16_t, UINT16);
PerfSpB_VECTOR_DENSE_SET(uint32_t, UINT32);
PerfSpB_VECTOR_DENSE_SET(uint64_t, UINT64);
PerfSpB_VECTOR_DENSE_SET(float, FP32);
PerfSpB_VECTOR_DENSE_SET(double, FP64);

#undef PerfSpB_VECTOR_DENSE_SET

//------------------------------------------------------------------------------
// perfSpB_vector_extract_element: extract a single entry from a vector
//------------------------------------------------------------------------------
// Extract a single entry, x = v(i), typecasting from the type of v to the type
// of x, as needed.

// Returns perfSpB_success if v(i) is present, and sets x to its value.

#define PerfSpB_VECTOR_DENSE_EXTRACT(type, T)                   \
    perfSpB_info PerfSpB_TOKEN_PASTING2(                        \
        perfSpB_vector_Dense_extractElement_, T)(               \
        type * x,                                               \
        const perfSpB_vector v,                                 \
        perfSpB_index i)                                        \
    {                                                           \
        if (v->element_type != perfSpB_##T)                     \
            PerfSpB_Error("The data types of the vector \
elements and the target do not match \
in perfSpB_vector_Dense_extractElement_" #T "!\n",              \
                          __FILE__, __LINE__);                  \
        (*x) =                                                  \
            ((type *)(((perfSpB_vector_Dense *)v)->values))[i]; \
        return perfSpB_success;                                 \
    }

PerfSpB_VECTOR_DENSE_EXTRACT(bool, BOOL);
PerfSpB_VECTOR_DENSE_EXTRACT(int8_t, INT8);
PerfSpB_VECTOR_DENSE_EXTRACT(int16_t, INT16);
PerfSpB_VECTOR_DENSE_EXTRACT(int32_t, INT32);
PerfSpB_VECTOR_DENSE_EXTRACT(int64_t, INT64);
PerfSpB_VECTOR_DENSE_EXTRACT(uint8_t, UINT8);
PerfSpB_VECTOR_DENSE_EXTRACT(uint16_t, UINT16);
PerfSpB_VECTOR_DENSE_EXTRACT(uint32_t, UINT32);
PerfSpB_VECTOR_DENSE_EXTRACT(uint64_t, UINT64);
PerfSpB_VECTOR_DENSE_EXTRACT(float, FP32);
PerfSpB_VECTOR_DENSE_EXTRACT(double, FP64);

#undef PerfSpB_VECTOR_DENSE_SET

//------------------------------------------------------------------------------
// perfSpB_vector_extract_tuples: extract all tuples from a vector
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2022, All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

//------------------------------------------------------------------------------

// Extracts all tuples from a column, like [I,~,X] = find (v).  If
// any parameter I and/or X is NULL, then that component is not extracted.  The
// size of the I and X arrays (those that are not NULL) is given by nvals,
// which must be at least as large as PerfSpB_nvals (&nvals, v).  The values in the
// typecasted to the type of X, as needed.

// If any parameter I and/or X is NULL, that component is not extracted.  So to
// extract just the row indices, pass I as non-NULL, and X as NULL.  This is
// like [I,~,~] = find (v).

// If v is iso and X is not NULL, the iso scalar vx [0] is expanded into X.

#define PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(type, T)                    \
    perfSpB_info PerfSpB_TOKEN_PASTING2(                                \
        perfSpB_vector_Dense_extractTuples_, T)(                        \
        perfSpB_index * I,                                              \
        type * X,                                                       \
        perfSpB_index * p_nvals,                                        \
        const perfSpB_vector v)                                         \
    {                                                                   \
        if (*p_nvals != v->n)                                           \
        {                                                               \
            return perfSpB_failure;                                     \
        }                                                               \
        else                                                            \
        {                                                               \
            for (perfSpB_index i = 0; i < *p_nvals; i++)                \
            {                                                           \
                I[i] = i;                                               \
                X[i] =                                                  \
                    ((type *)(((perfSpB_vector_Dense *)v)->values))[i]; \
            }                                                           \
            return perfSpB_success;                                     \
        }                                                               \
    }

PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(bool, BOOL);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(int8_t, INT8);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(int16_t, INT16);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(int32_t, INT32);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(int64_t, INT64);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(uint8_t, UINT8);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(uint16_t, UINT16);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(uint32_t, UINT32);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(uint64_t, UINT64);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(float, FP32);
PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(double, FP64);

#undef PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES

perfSpB_info perfSpB_vector_Dense_free(perfSpB_vector *v_in)
{
    perfSpB_vector_Dense **v =
        (perfSpB_vector_Dense **)v_in;
    if ((*v)->values)
    {
        free((*v)->values);
        free(*v);
        return perfSpB_success;
    }
    else
    {
        return perfSpB_failure;
    }
}

#define PerfSpB_VECTOR_DENSE_BUILD(type, T)      \
    perfSpB_info perfSpB_vector_Dense_build_##T( \
        perfSpB_vector_Dense *w,                 \
        const perfSpB_index *indices,            \
        const type *values,                      \
        perfSpB_index n)                         \
    {                                            \
        perfSpB_index n_w = w->vector_base.n;    \
        perfSpB_index element_size =             \
            w->vector_base.element_size;         \
        memset(w->values, 0,                     \
               n_w *element_size);               \
                                                 \
        for (perfSpB_index i = 0; i < n; ++i)    \
        {                                        \
            ((type *)w->values)[indices[i]] =    \
                values[i];                       \
        }                                        \
                                                 \
        return perfSpB_success;                  \
    }

PerfSpB_VECTOR_DENSE_BUILD(bool, BOOL);
PerfSpB_VECTOR_DENSE_BUILD(int8_t, INT8);
PerfSpB_VECTOR_DENSE_BUILD(int16_t, INT16);
PerfSpB_VECTOR_DENSE_BUILD(int32_t, INT32);
PerfSpB_VECTOR_DENSE_BUILD(int64_t, INT64);
PerfSpB_VECTOR_DENSE_BUILD(uint8_t, UINT8);
PerfSpB_VECTOR_DENSE_BUILD(uint16_t, UINT16);
PerfSpB_VECTOR_DENSE_BUILD(uint32_t, UINT32);
PerfSpB_VECTOR_DENSE_BUILD(uint64_t, UINT64);
PerfSpB_VECTOR_DENSE_BUILD(float, FP32);
PerfSpB_VECTOR_DENSE_BUILD(double, FP64);
#undef PerfSpB_VECTOR_DENSE_BUILD

/////////////////////////////////////////Sparse Vector////////////////////////////////////
perfSpB_info perfSpB_vector_Sparse_grow(
    perfSpB_vector_Sparse *v,
    perfSpB_index capacity)
{
    if (capacity > v->capacity)
    {
        size_t size =
            v->vector_base.element_size;
        if (v->values)
            v->values =
                PerfSpB_aligned_realloc(
                    v->values, size * capacity);
        else
            v->values =
                PerfSpB_aligned_malloc(
                    size * capacity);
        assert(v->values);
        if (v->indices)
            v->indices = (perfSpB_index *)
                PerfSpB_aligned_realloc(
                    v->indices,
                    sizeof(perfSpB_index) * capacity);
        else
            v->indices = (perfSpB_index *)
                PerfSpB_aligned_malloc(
                    sizeof(perfSpB_index) * capacity);
        assert(v->indices);
        v->capacity = capacity;
    }
    return perfSpB_success;
}

perfSpB_info perfSpB_vector_Sparse_new(
    perfSpB_vector *v_in,
    perfSpB_type type,
    perfSpB_index n)
{
    perfSpB_vector_Sparse **v =
        (perfSpB_vector_Sparse **)v_in;

    *v = (perfSpB_vector_Sparse *)
        PerfSpB_aligned_malloc(
            sizeof(perfSpB_vector_Sparse));
    (*v)->vector_base.format_type =
        perfSpB_sparse;
    (*v)->vector_base.element_type =
        type;
    (*v)->vector_base.n = n;
    (*v)->values = NULL;
    (*v)->indices = NULL;
    (*v)->nnz = 0;
    (*v)->capacity = 0;
    (*v)->is_sorted = true;
    switch (type)
    {
        PerfSpB_TYPE_CASES(v_in);
    }
    return perfSpB_success;
}

static perfSpB_index perfSpB_vector_Sparse_capacity(
    perfSpB_vector_Sparse *v)
{
    return v->capacity;
}

static perfSpB_index perfSpB_vector_Sparse_nnz(
    perfSpB_vector_Sparse *v)
{
    return v->nnz;
}

static bool perfSpB_vector_Sparse_findElement(
    perfSpB_vector_Sparse *v,
    perfSpB_index target,
    perfSpB_index *ans)
{
    if (v->nnz)
    {
        perfSpB_index left = 1;
        perfSpB_index right = v->nnz;

        while (left <= right)
        {
            perfSpB_index mid = ((right - left) >> 1) + left;
            perfSpB_index val = v->indices[mid - 1];
            if (target == val)
            {
                *ans = mid - 1;
                return true;
            }
            else if (target < val)
            {
                *ans = mid - 1;
                right = mid - 1;
            }
            else
            {
                *ans = mid;
                left = mid + 1;
            }
        }
    }
    return false;
}

//------------------------------------------------------------------------------
// perfSpB_vector_set_element: set an entry in a vector, w (row) = x
//------------------------------------------------------------------------------
// Set a single scalar, w(row) = x, typecasting from the type of x to
// the type of w as needed.
#define PerfSpB_VECTOR_SPARSE_SET(type, T)                           \
    perfSpB_info perfSpB_vector_Sparse_setElement_##T /* w(i) = x */ \
        (                                                            \
            perfSpB_vector w, /* vector to modify           */       \
            type x,           /* scalar to assign to w(i) */         \
            perfSpB_index i   /* index                  */           \
        )                                                            \
    {                                                                \
        perfSpB_vector_Sparse *v = (perfSpB_vector_Sparse *)w;       \
        size_t size = w->element_size;                               \
                                                                     \
        assert(i < w->n);                                            \
        perfSpB_index index = 0;                                     \
        if (perfSpB_vector_Sparse_findElement(v, i, &index))         \
        {                                                            \
            if (x)                                                   \
                ((type *)v->values)[index] = x;                      \
            else                                                     \
            {                                                        \
                v->nnz--;                                            \
                memmove(v->values + index * size,                    \
                        v->values + (index + 1) * size,              \
                        size * (v->nnz - index));                    \
                memmove(v->indices + index,                          \
                        v->indices + index + 1,                      \
                        sizeof(perfSpB_index) * (v->nnz - index));   \
            }                                                        \
        }                                                            \
        else if (x)                                                  \
        {                                                            \
            perfSpB_index v_capacity =                               \
                perfSpB_vector_Sparse_capacity(v);                   \
            perfSpB_index v_size = perfSpB_vector_Sparse_nnz(v);     \
            if (v_capacity <= v_size)                                \
            {                                                        \
                perfSpB_vector_Sparse_grow(                          \
                    v,                                               \
                    Vector_compute_next_grow((v_capacity)));         \
            }                                                        \
            if (index < v_size)                                      \
            {                                                        \
                memmove(v->values + (index + 1) * size,              \
                        v->values + index * size,                    \
                        size * (v_size - index));                    \
                memmove(v->indices + index + 1,                      \
                        v->indices + index,                          \
                        sizeof(perfSpB_index) * (v_size - index));   \
            }                                                        \
            ((type *)v->values)[index] = x;                          \
            v->indices[index] = i;                                   \
            v->nnz++;                                                \
        }                                                            \
        return perfSpB_success;                                      \
    }
PerfSpB_VECTOR_SPARSE_SET(bool, BOOL);
PerfSpB_VECTOR_SPARSE_SET(int8_t, INT8);
PerfSpB_VECTOR_SPARSE_SET(int16_t, INT16);
PerfSpB_VECTOR_SPARSE_SET(int32_t, INT32);
PerfSpB_VECTOR_SPARSE_SET(int64_t, INT64);
PerfSpB_VECTOR_SPARSE_SET(uint8_t, UINT8);
PerfSpB_VECTOR_SPARSE_SET(uint16_t, UINT16);
PerfSpB_VECTOR_SPARSE_SET(uint32_t, UINT32);
PerfSpB_VECTOR_SPARSE_SET(uint64_t, UINT64);
PerfSpB_VECTOR_SPARSE_SET(float, FP32);
PerfSpB_VECTOR_SPARSE_SET(double, FP64);

#undef PerfSpB_VECTOR_SPARSE_SET

//------------------------------------------------------------------------------
// perfSpB_vector_extract_element: extract a single entry from a vector
//------------------------------------------------------------------------------
// Extract a single entry, x = v(i), typecasting from the type of v to the type
// of x, as needed.

// Returns perfSpB_success if v(i) is present, and sets x to its value.

#define PerfSpB_VECTOR_SPARSE_EXTRACT(type, T)             \
    perfSpB_info perfSpB_vector_Sparse_extractElement_##T( \
        type *x,                                           \
        const perfSpB_vector v_in,                         \
        perfSpB_index i)                                   \
    {                                                      \
        if (v_in->element_type != perfSpB_##T)             \
            PerfSpB_Error("The data types of the vector elements \
and the target do not match in \
perfSpB_vector_Sparse_extractElement!\n",                  \
                          __FILE__, __LINE__);             \
                                                           \
        perfSpB_vector_Sparse *v =                         \
            (perfSpB_vector_Sparse *)v_in;                 \
                                                           \
        perfSpB_index index = 0;                           \
        if (perfSpB_vector_Sparse_findElement(             \
                v, i, &index))                             \
        {                                                  \
            *x = ((type *)v->values)[index];               \
            return perfSpB_success;                        \
        }                                                  \
        else                                               \
        {                                                  \
            return perfSpB_no_value;                       \
        }                                                  \
    }
PerfSpB_VECTOR_SPARSE_EXTRACT(bool, BOOL);
PerfSpB_VECTOR_SPARSE_EXTRACT(int8_t, INT8);
PerfSpB_VECTOR_SPARSE_EXTRACT(int16_t, INT16);
PerfSpB_VECTOR_SPARSE_EXTRACT(int32_t, INT32);
PerfSpB_VECTOR_SPARSE_EXTRACT(int64_t, INT64);
PerfSpB_VECTOR_SPARSE_EXTRACT(uint8_t, UINT8);
PerfSpB_VECTOR_SPARSE_EXTRACT(uint16_t, UINT16);
PerfSpB_VECTOR_SPARSE_EXTRACT(uint32_t, UINT32);
PerfSpB_VECTOR_SPARSE_EXTRACT(uint64_t, UINT64);
PerfSpB_VECTOR_SPARSE_EXTRACT(float, FP32);
PerfSpB_VECTOR_SPARSE_EXTRACT(double, FP64);

#undef PerfSpB_VECTOR_SPARSE_SET

//------------------------------------------------------------------------------
// perfSpB_vector_extract_tuples: extract all tuples from a vector
//------------------------------------------------------------------------------

#define PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(type, T)     \
    perfSpB_info PerfSpB_TOKEN_PASTING2(                  \
        perfSpB_vector_Sparse_extractTuples_, T)(         \
        perfSpB_index * I,                                \
        type * X,                                         \
        perfSpB_index * p_nvals,                          \
        const perfSpB_vector v)                           \
    {                                                     \
        if (*p_nvals != v->n)                             \
        {                                                 \
            return perfSpB_failure;                       \
        }                                                 \
        else                                              \
        {                                                 \
            for (perfSpB_index i = 0; i < *p_nvals; i++)  \
            {                                             \
                I[i] = i;                                 \
                type value = (type)0;                     \
                perfSpB_vector_Sparse_extractElement_##T( \
                    &value, v, i);                        \
                X[i] = value;                             \
            }                                             \
            return perfSpB_success;                       \
        }                                                 \
    }

PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(bool, BOOL);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(int8_t, INT8);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(int16_t, INT16);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(int32_t, INT32);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(int64_t, INT64);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(uint8_t, UINT8);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(uint16_t, UINT16);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(uint32_t, UINT32);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(uint64_t, UINT64);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(float, FP32);
PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(double, FP64);

#undef PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES

perfSpB_info perfSpB_vector_Sparse_free(perfSpB_vector *v_in)
{
    perfSpB_vector_Sparse **v = (perfSpB_vector_Sparse **)v_in;
    if ((*v)->values)
    {
        free((*v)->values);
    }
    else
    {
        return perfSpB_failure;
    }
    if ((*v)->indices)
    {
        free((*v)->indices);
    }
    else
    {
        return perfSpB_failure;
    }
    if ((*v))
    {
        free(*v);
    }
    else
    {
        return perfSpB_failure;
    }

    return perfSpB_success;
}

#define PerfSpB_VECTOR_SPARSE_BUILD(type, T)           \
    perfSpB_info perfSpB_vector_Sparse_build_##T(      \
        perfSpB_vector_Sparse *v,                      \
        const perfSpB_index *indices,                  \
        const type *values,                            \
        perfSpB_index n)                               \
    {                                                  \
        perfSpB_index v_capacity = v->capacity;        \
        perfSpB_info info;                             \
        if (v_capacity <= n)                           \
        {                                              \
            SAFE_CALL(                                 \
                perfSpB_vector_Sparse_grow(v, n + 1)); \
            v->capacity = n + 1;                       \
        }                                              \
        memcpy(v->values,                              \
               values, n * sizeof(type));              \
        memcpy(v->indices,                             \
               indices, n * sizeof(perfSpB_index));    \
        v->nnz = n;                                    \
        return perfSpB_success;                        \
    }
PerfSpB_VECTOR_SPARSE_BUILD(bool, BOOL);
PerfSpB_VECTOR_SPARSE_BUILD(int8_t, INT8);
PerfSpB_VECTOR_SPARSE_BUILD(int16_t, INT16);
PerfSpB_VECTOR_SPARSE_BUILD(int32_t, INT32);
PerfSpB_VECTOR_SPARSE_BUILD(int64_t, INT64);
PerfSpB_VECTOR_SPARSE_BUILD(uint8_t, UINT8);
PerfSpB_VECTOR_SPARSE_BUILD(uint16_t, UINT16);
PerfSpB_VECTOR_SPARSE_BUILD(uint32_t, UINT32);
PerfSpB_VECTOR_SPARSE_BUILD(uint64_t, UINT64);
PerfSpB_VECTOR_SPARSE_BUILD(float, FP32);
PerfSpB_VECTOR_SPARSE_BUILD(double, FP64);
#undef PerfSpB_VECTOR_SPARSE_BUILD