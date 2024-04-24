#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "PerfSpB_MACRO.h"
#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"

/**
 * @ingroup perfSpB_vector
 * @brief A structure to represent vectors.
 * @details This class stores basic information about a vector, which is inherited by other concrete vector classes of various formats.
 */
struct perfSpB_vector_opaque
{
    perfSpB_type element_type;                   /**< Element data type */
    perfSpB_vector_format_value_ext format_type; /**<  Marker of vector format */
    perfSpB_index n;                             /**< Vector length.*/
    size_t element_size;                         /**< byte number of a single element.*/
};

/**
 * @ingroup perfSpB_vector
 * @defgroup perfSpB_vector_Dense
 * @brief A Dense vector class
 * @details The dense vector format uses a array to represent all elements(including zero elements) in a vector.
 * @{
 */

typedef struct
{
    struct perfSpB_vector_opaque vector_base;
    void *values;
} perfSpB_vector_Dense;

perfSpB_info perfSpB_vector_Dense_new(perfSpB_vector *v, perfSpB_type type, perfSpB_index n);

perfSpB_info perfSpB_vector_Dense_dup(perfSpB_vector *v1, perfSpB_vector v2);

#define PerfSpB_VECTOR_DENSE_SET(type, T)                                                     \
    perfSpB_info PerfSpB_TOKEN_PASTING2(perfSpB_vector_Dense_setElement_, T) /* w(row) = x */ \
        (                                                                                     \
            perfSpB_vector w, /* vector to modify           */                                \
            type x,           /* scalar to assign to w(row) */                                \
            perfSpB_index row /* row index                  */                                \
        )

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

#define PerfSpB_VECTOR_DENSE_EXTRACT(type, T)                                                   \
    perfSpB_info PerfSpB_TOKEN_PASTING2(perfSpB_vector_Dense_extractElement_, T) /* x = v(i) */ \
        (                                                                                       \
            type * x,               /* scalar to extract           */                           \
            const perfSpB_vector v, /* vector to extract a scalar from */                       \
            perfSpB_index i         /* index                  */                                \
        )

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
#undef PerfSpB_VECTOR_DENSE_EXTRACT

#define PerfSpB_VECTOR_DENSE_EXTRACT_TUPLES(type, T)                                                   \
    perfSpB_info PerfSpB_TOKEN_PASTING2(perfSpB_vector_Dense_extractTuples_, T) /*[I,~,X] = find (v)*/ \
        (                                                                                              \
            perfSpB_index * I,     /*array for returning row indices of tuples*/                       \
            type * X,              /*array for returning values of tuples*/                            \
            perfSpB_index * nvals, /*I, X size on input; # tuples on output*/                          \
            const perfSpB_vector v /*vector to extract tuples*/                                        \
        )

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

perfSpB_info perfSpB_vector_Dense_free(perfSpB_vector *v);

/**
 * @anchor perfSpB_vector_Dense_build
 * @name perfSpB_vector_Dense_build
 * @brief Store elements from tuples into a dense vetctor
 * @details
 *
 * @param[in,out] w An existing dense Vector object to store the result.
 * @param[in] indices Pointer to an array of indices.
 * @param[in] values Pointer to an array of scalars of a type that is compatible with the domain of vector **w**.
 * @param[in] n The number of entries contained in each array (the same for indices and values).
 * @return perfSpB_info
 */
///@{

#define PerfSpB_VECTOR_DENSE_BUILD(type, T)                                   \
    perfSpB_info perfSpB_vector_Dense_build_##T(perfSpB_vector_Dense *w,      \
                                                const perfSpB_index *indices, \
                                                const type *values,           \
                                                perfSpB_index n);
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
///@}
/**@}*/ // end for perfSpB_vector_Dense

/**
 * @ingroup perfSpB_vector
 * @defgroup perfSpB_vector_Sparse
 * @brief A sparse vector class
 * @details The sparse vector format uses a list approach to store only all non-zero elements of the vector, wherthe list can be indexed ordered and unordered.
 * @{
 */
typedef struct
{
    struct perfSpB_vector_opaque vector_base; /**< The base vector msg*/
    void *values;                             /**< The data array */
    perfSpB_index *indices;                   /**< The index array */
    perfSpB_index nnz;                        /**< The number of non zero; the size of array valuse and indices*/
    perfSpB_index capacity;                   /**< The size of the current array request.
                                               * When adding elements to make nnz larger than the capacity, it needs to be expanded*/
    bool is_sorted;                           /**< A notation for whether the array \link values \endlink and \link indices \endlink is ordered. */
} perfSpB_vector_Sparse;

/**
 * @ingroup perfSpB_vector_Sparse
 * @brief Create a perfSpB_vector_Sparse object
 * @param[out] v A Pointer to the newly created sparse vector
 * @param[in] type Type defines the data type of the vector elements
 * @param[in] n Vector length
 * @return perfSpB_info
 */
perfSpB_info perfSpB_vector_Sparse_new(perfSpB_vector *v, perfSpB_type type, perfSpB_index n);

/**
 * @ingroup perfSpB_vector_Sparse
 * @brief Create perfSpB_vector_Sparse_setElement_T functions with different data types
 * @param type Macro param: Data Type, e.g., bool, int8_t, int16_t...
 * @param T Macro param: Function Suffix, e.g., BOOL, INT8, INT16...
 * @param[in,out] w The input vector
 * @param[in] x The set value
 * @param[in] row The index of the input vector
 * @return perfSpB_info
 */
#define PerfSpB_VECTOR_SPARSE_SET(type, T)                                                     \
    perfSpB_info PerfSpB_TOKEN_PASTING2(perfSpB_vector_Sparse_setElement_, T) /* w(row) = x */ \
        (                                                                                      \
            perfSpB_vector w, /* vector to modify           */                                 \
            type x,           /* scalar to assign to w(row) */                                 \
            perfSpB_index row /* row index                  */                                 \
        )

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

/**
 * @ingroup perfSpB_vector_Sparse
 * @brief Create perfSpB_vector_Sparse_extractElement_T functions with different data types
 * @param type Macro param: Data Type, e.g., bool, int8_t, int16_t...
 * @param T Macro param: Function Suffix, e.g., BOOL, INT8, INT16...
 * @param[out] x The pointer to result
 * @param[in] v The input vector
 * @param[in] row The index of the input vector
 * @return perfSpB_info
 */
#define PerfSpB_VECTOR_SPARSE_EXTRACT(type, T)                                                   \
    perfSpB_info PerfSpB_TOKEN_PASTING2(perfSpB_vector_Sparse_extractElement_, T) /* x = v(i) */ \
        (                                                                                        \
            type * x,               /* scalar to extract           */                            \
            const perfSpB_vector v, /* vector to extract a scalar from */                        \
            perfSpB_index i         /* index                  */                                 \
        )

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
#undef PerfSpB_VECTOR_SPARSE_EXTRACT

perfSpB_info perfSpB_vector_Sparse_extractTuples(perfSpB_index *indices, int *values, perfSpB_index *n, const perfSpB_vector v);
/**
 * @ingroup perfSpB_vector_Sparse
 * @brief Create perfSpB_vector_Sparse_extractTuples_T functions with different data types
 * @param type Macro param: Data Type, e.g., bool, int8_t, int16_t...
 * @param T Macro param: Function Suffix, e.g., BOOL, INT8, INT16...
 * @param[in,out] I Array for returning row indices of tuples
 * @param[out] X array for returning values of tuples
 * @param[in] nvals Pointer to \link I \endlink and \link X \endlink size.
 * @param[in] v Vector to extract tuples
 * @return perfSpB_info
 */
#define PerfSpB_VECTOR_SPARSE_EXTRACT_TUPLES(type, T)                                                   \
    perfSpB_info PerfSpB_TOKEN_PASTING2(perfSpB_vector_Sparse_extractTuples_, T) /*[I,~,X] = find (v)*/ \
        (                                                                                               \
            perfSpB_index * I,     /*array for returning row indices of tuples*/                        \
            type * X,              /*array for returning values of tuples*/                             \
            perfSpB_index * nvals, /*I, X size on input; # tuples on output*/                           \
            const perfSpB_vector v /*vector to extract tuples*/                                         \
        )

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

/**
 * @ingroup perfSpB_vector_Sparse
 * @brief Frees the space of a sparse vector object
 * @param[in] v A Pointer to the sparse vector needed to be freed
 * @return perfSpB_info
 */
perfSpB_info perfSpB_vector_Sparse_free(perfSpB_vector *v);

/**
 * @ingroup perfSpB_vector_Sparse
 * @brief Growing the capacity of a sparse vector
 * @param[in] v A Pointer to the sparse vector needed to be freed
 * @param[in] capacity New capacity to be allocated
 * @return perfSpB_info
 */
perfSpB_info perfSpB_vector_Sparse_grow(perfSpB_vector_Sparse *v, perfSpB_index capacity);

/**
 * @anchor perfSpB_vector_Sparse_build
 * @name perfSpB_vector_Sparse_build
 * @ingroup perfSpB_vector_Sparse
 * @brief Store elements from tuples into a vector
 * @details
 * @param[in,out] w An existing Vector object to store the result.
 * @param [in] indices Pointer to an array of indices.
 * @param [in] values Pointer to an array of scalars of a type that is compatible with the domain of vector w.
 * @param [in] n The number of entries contained in each array (the same for indices and values).
 * @return perfSpB_info
 * @todo Support multiple **dup** operations
 */
///@{
#define PerfSpB_VECTOR_SPARSE_BUILD(type, T)                                   \
    perfSpB_info perfSpB_vector_Sparse_build_##T(perfSpB_vector_Sparse *w,     \
                                                 const perfSpB_index *indices, \
                                                 const type *values,           \
                                                 perfSpB_index n)

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
///@}
/**@}*/ // end for perfSpB_vector_Sparse