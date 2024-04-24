#pragma once
#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include <stdlib.h>

/**
 * @ingroup perfSpB_matrix
 * @brief A structure to represent matirixs
 * @details This class stores basic information about a matrix, which is inherited by other concrete matrix classes of various formats.
 */
struct perfSpB_matrix_opaque
{
    perfSpB_type element_type;                   /**< Element data type */
    perfSpB_matrix_format_value_ext format_type; /**<  Marker of matrix format */
    perfSpB_index row;                           /**< Number of rows*/
    perfSpB_index col;                           /**< Number of rows */
    size_t element_size;                         /**< byte number of a single element.*/
};

/**
 * @ingroup perfSpB_matrix
 * @defgroup perfSpB_matrix_CSC_or_CSR
 * @brief A CSC/CSR format matrix class
 * @details Sparse matrix stored in traditional CSC (Compressed sparse column) or CSR (compressed sparse row) format. Since these two formats have symmetry, a class is reused to manage both formats.
 * @{
 */

typedef struct
{
    struct perfSpB_matrix_opaque matrix_base;
    void *val;              ///< Value of each non-zero element.
    perfSpB_index *indices; ///< Row coordinate for CSC, and col coordinate for CSR.
    perfSpB_index *ptr;     ///< Col initial position for CSC, and row initial position for CSR.
    perfSpB_index ptr_len;  ///< Length of ptr array.
    perfSpB_index nnz;      ///< Total non-zero elements.
    perfSpB_index capacity; ///< the capacity of val, indices array.
} perfSpB_matrix_CSC_or_CSR;

perfSpB_index perfSpB_matrix_CSC_or_CSR_nnz(perfSpB_matrix_CSC_or_CSR *m);

perfSpB_info perfSpB_matrix_CSC_or_CSR_new(perfSpB_matrix *m_in,
                                           perfSpB_type type,
                                           perfSpB_index row,
                                           perfSpB_index col,
                                           perfSpB_matrix_format_value_ext format_type);

/**
 * @anchor perfSpB_matrix_CSC_or_CSR_build
 * @name perfSpB_matrix_CSC_or_CSR_build
 * @brief Store elements from tuples into a CSC/CSR matrix.
 * @param[in,out] m_in An existing CSC/CSR Matrix object to store the result.
 * @param[in] row_indices Pointer to an array of row indices.
 * @param[in] col_indices Pointer to an array of column indices.
 * @param[in] values Pointer to an array of scalars of a type that is compatible with the domain of matrix, m_in.
 * @param[in] n The number of entries contained in each array (the same for row_indices, col_indices, and values).
 * @return perfSpB_info
 */
///@{
#define GRB_MATRIX_CSC_OR_CSR_FAST_BUILD_EXT(type, T)            \
    perfSpB_info perfSpB_matrix_CSC_or_CSR_fast_build_##T##_ext( \
        perfSpB_matrix m_in,                                     \
        const perfSpB_index *row_indices,                        \
        const perfSpB_index *col_indices,                        \
        const type *values,                                      \
        const perfSpB_index n);
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

#define PerfSpB_MATRIX_CSC_OR_CSR_BUILD(type, T)      \
    perfSpB_info perfSpB_matrix_CSC_or_CSR_build_##T( \
        perfSpB_matrix m_in,                          \
        const perfSpB_index *row_indices,             \
        const perfSpB_index *col_indices,             \
        const type *values,                           \
        const perfSpB_index n);
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

///@}

/**
 * @anchor perfSpB_matrix_CSC_or_CSR_setElement
 * @name perfSpB_matrix_CSC_or_CSR_setElement
 * @brief Set a single element in a CSC/CSR matrix
 * @param[in,out] m_in An existing CSC/CSR matrix for which an element is to be assigned
 * @param[in] value Scalar to assign. Its domain (type) must be compatible with the domain of m_in.
 * @param[in] row_index Row index of element to be assigned.
 * @param[in] col_index Column index of element to be assigned.
 * @return perfSpB_info
 */
///@{
#define PerfSpB_MATRIX_CSC_OR_CSR_SETELEMENT(type, T)                              \
    perfSpB_info perfSpB_matrix_CSC_or_CSR_setElement_##T(perfSpB_matrix m_in,     \
                                                          type value,              \
                                                          perfSpB_index row_index, \
                                                          perfSpB_index col_index)
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
///@}

/**
 * @anchor perfSpB_matrix_CSC_or_CSR_extractElement
 * @name perfSpB_matrix_CSC_or_CSR_extractElement
 * @brief Extract a single element from a CSC/CSR matrix
 * @param[in,out] val An existing scalar whose domain is compatible with the domain of matrix **m_in**. On successful return, this scalar holds the result of the extract. Any previous value stored in **val** is overwritten.
 * @param[in] m_in The CSC/CSR matrix from which an element is extracted.
 * @param[in] row_index The row index of location in **m_in** to extract.
 * @param[in] col_index The row index of location in **m_in** to extract.
 * @return perfSpB_info
 */
///@{
#define PerfSpB_MATRIX_CSC_OR_CSR_EXTRACTELEMENT(type, T)                                \
    perfSpB_info perfSpB_matrix_CSC_or_CSR_extractElement_##T(type *val,                 \
                                                              const perfSpB_matrix m_in, \
                                                              perfSpB_index row_index,   \
                                                              perfSpB_index col_index)

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
///@}

perfSpB_info perfSpB_matrix_CSC_or_CSR_free(perfSpB_matrix *m_in);

/**@}*/
