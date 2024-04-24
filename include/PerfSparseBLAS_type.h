#pragma once

#include "stdint.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define PerfSpB_MAX_NAME_LENGTH 128

    /**
     * @brief The usual return value of the PerfSparseBLAS methods
     */
    typedef enum
    {
        perfSpB_success = 0,  ///< Indicates successful method execution
        perfSpB_failure = 1,  ///< Indicates method execution failure
        perfSpB_no_value = -1 ///< Using the extract related method, the zero element is not stored in the object and the value is returned.
    } perfSpB_info;

    /**
     * @brief Built-in data types supported by PerfSparseBLAS
     */
    typedef enum
    {
        perfSpB_null_type,
        perfSpB_BOOL,   ///< in C: bool
        perfSpB_INT8,   ///< in C: int8_t
        perfSpB_INT16,  ///< in C: int16_t
        perfSpB_INT32,  ///< in C: int32_t
        perfSpB_INT64,  ///< in C: int64_t
        perfSpB_UINT8,  ///< in C: uint8_t
        perfSpB_UINT16, ///< in C: uint16_t
        perfSpB_UINT32, ///< in C: uint32_t
        perfSpB_UINT64, ///< in C: uint64_t
        perfSpB_FP32,   ///< in C: float
        perfSpB_FP64,   ///< in C: double
        perfSpB_type_n
    } perfSpB_type;

    /**
     * @brief Type of index objects used in PerfSparseBLAS
     * @details It define by :
     * @code{.c}
     * typedef unsigned long int perfSpB_index;
     * @endcode
     * The range of valid values for a variable of type perfSpB_index is [0, perfSpB_index_max] where the largest index value permissible is defined with a macro, perfSpB_index_max.
     */
    typedef int64_t perfSpB_index;
    /**
     * @brief A method argument literal to indicate that all indices of an input array should be used.
     *
     */
    extern perfSpB_index *perfSpB_all;

/**
 * @brief The largest perfSpB_index value permissible
 */
#define perfSpB_index_max ((perfSpB_index)0x0fffffffffffffff)

    /**
     * @brief perfSpB_scalar_opaque
     */
    struct perfSpB_scalar_opaque;

    /**
     * @brief One scalar which can store any perfSpB_type element.
     */
    typedef struct perfSpB_scalar_opaque *perfSpB_scalar;

    /**
     * @brief perfSpB_vector_opaque
     */
    struct perfSpB_vector_opaque;

    /**
     * @brief One-dimensional collection of elements; can be sparse.
     */
    typedef struct perfSpB_vector_opaque *perfSpB_vector;

    /**
     * @brief A Null perfSpB_vector
     * @details It is used for the mask argument to call a none-mask vxm or mxv operation.
     */
    extern perfSpB_vector perfSpB_vector_null;

    struct perfSpB_matrix_opaque;
    /**
     * @brief Two-dimensional collection of elements; typically sparse.
     */
    typedef struct perfSpB_matrix_opaque *perfSpB_matrix;
    /**
     * @brief A Null perfSpB_matrix
     * @details It is used for the mask argument to call a none-mask vxm, mxv or mxm operation.
     */
    extern perfSpB_matrix perfSpB_matrix_null;

    // TODO: Needs be called by users?
    typedef enum
    {
        PerfSpB_VNEC_D = 0,
        PerfSpB_VNEC_S = 1,
    } PerfSpB_VNEC_type;

    typedef struct perfSpB_coord
    {
        int x;
        int y;
    } perfSpB_coord;

    // TODO: Needs be called by users?
    typedef struct VNEC_D_FP32
    {
        perfSpB_coord *thread_coord_start;
        perfSpB_coord *thread_coord_end;
        int *ecr_indices;
        int *NEC_NUM;
        int **use_x_indices;
        float **ecr_xx_val;
        int *v_row_ptr;
        int *col_start;
        float *val_align;
    } VNEC_D_FP32;

    typedef struct csr_f32
    {
        float *nnz;
        int *col, *row_begin, *row_end;
        int *task_start;
        int *task_end;
    } csr_f32;
    typedef struct VNEC_S_FP32
    {
        /*
            ECR
        */
        int *NEC_NUM;
        int **use_x_indices;
        float **ecr_xx_val;
        /*
            vectorization
        */
        int *spvv16_len;
        int **tasks;
        struct csr_f32 reorder_mat;
    } VNEC_S_FP32;

    typedef struct VNEC_L
    {
        int num_merge_items;
        int items_per_thread;
        int *diagonal_start;
        int *diagonal_end;
        perfSpB_coord *thread_coord_start;
        perfSpB_coord *thread_coord_end;
        int *nz_indices;
    } VNEC_L;

    typedef struct VNEC_D_FP64
    {
        perfSpB_coord *thread_coord_start;
        perfSpB_coord *thread_coord_end;
        int *ecr_indices;
        int *NEC_NUM;
        int **use_x_indices;
        double **ecr_xx_val;
        int *v_row_ptr;
        int *col_start;
        double *val_align;
    } VNEC_D_FP64;

    typedef struct csr_f64
    {
        double *nnz;
        int *col, *row_begin, *row_end;
        int *task_start;
        int *task_end;
    } csr_f64;
    typedef struct VNEC_S_FP64
    {
        /*
            ECR
        */
        int *NEC_NUM;
        int **use_x_indices;
        double **ecr_xx_val;
        /*
            vectorization
        */
        int *spvv8_len;
        int **tasks;
        struct csr_f64 reorder_mat;
    } VNEC_S_FP64;

    /**
     * @brief Object options available for format setting
     *
     */
    typedef enum
    {
        perfSpB_vector_format, ///< You can set the format of the vector
        perfSpB_matrix_format  ///< You can set the format of the matrix
    } perfSpB_option_field_ext;

    /**
     * @Available vector formats
     *
     */
    typedef enum
    {
        perfSpB_dense = 0,            ///< Dense Format: All elements of the vector including the zero element are represented
        perfSpB_sparse = 1,           ///< Sparse Format: The non-zero elements of the vector are represented
        perfSpB_vector_no_format = -1 ///< format not defined (Now useless)
    } perfSpB_vector_format_value_ext;

    /**
     * @Available matrix formats
     *
     */
    typedef enum
    {
        perfSpB_csc = 0,              ///< CSR: compressed sparse row format
        perfSpB_csr = 1,              ///< CSC: compressed sparse column format
        perfSpB_matrix_no_format = -1 ///< format not defined (Now useless)
    } perfSpB_matrix_format_value_ext;

    /**
     * @brief The argument of \link PerfSpB_Global_Option_set_ext \endlink
     *
     */
    typedef union
    {
        perfSpB_vector_format_value_ext vector_format;
        perfSpB_matrix_format_value_ext matrix_format;
    } perfSpB_object_format_ext;

    typedef enum
    {
        perfSpB_operation_transpose = 0,           ///< The transpose operation is selected.
        perfSpB_operation_conjugate_transpose = 1, ///< The conjugate transpose operation is selected.
        perfSpB_operation_non_transpose = -1       ///< The non-transpose operation is selected.
    } perfSpB_operation_t;

#ifdef __cplusplus
}
#endif
