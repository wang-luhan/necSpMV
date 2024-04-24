#pragma once
#include "PerfSparseBLAS_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup core
     * @brief PerfSparseBLAS objects
     * @details Definition and basic operation of PerfSparseBLAS objects.
     * @{
     */

    /**
     * @brief perfSparseBLAS initialization function
     * @details An instance of the SparseBLAS C API implementation as seen by an application. An application can have only one context between the start and end of the application. A context begins with the first thread that calls \link PerfSpB_init \endlink and ends with the first thread to call \link PerfSpB_finalize \endlink. It is an error for \link PerfSpB_init \endlink or \link PerfSpB_finalize \endlink to be called more than one time within an application.
     */
    void PerfSpB_init();
    /**
     * @brief perfSparseBLAS finalization  function
     * @details An instance of the SparseBLAS C API implementation as seen by an application. An application can have only one context between the start and end of the application. A context begins with the first thread that calls \link PerfSpB_init \endlink and ends with the first thread to call \link PerfSpB_finalize \endlink. It is an error for \link PerfSpB_init \endlink or \link PerfSpB_finalize \endlink to be called more than one time within an application.
     */
    void PerfSpB_finalize();

    /**
     * @defgroup perfSpB_scalar
     * @brief perfSpB_scalar class
     * @{
     */

    /**
     * @brief Creates a new empty scalar with specified domain.
     * @param[in,out] s On successful return, contains a handle to the newly created PerfSparseBLAS scalar.
     * @param[in] d The type corresponding to the domain of the scalar being created.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_scalar_new(perfSpB_scalar *s, perfSpB_type type);

    /**
     * @brief Destroys a previously created perfSpB_scalar object and releases any resources associated with the object.
     *
     * @param[in,out] s An existing perfSpB_vector object to be destroyed. The object must have been created by an explicit call to a \link perfSpB_scalar_new \endlink constructor. On successful completion of perfSpB_scalar_free, obj behaves as an uninitialized object.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_scalar_free(perfSpB_scalar *s);

    ///@}

    /**
     * @defgroup perfSpB_vector
     * @brief perfSpB_vector class
     * @details perfSpB_vector is inherited as a base class by \link perfSpB_vector_Sparse \endlink and \link perfSpB_vector_Dense \endlink. They represent the storage of vector elements in sparse and dense formats, respectively.
     * @{
     */

    /**
     * @brief Creates a new vector with specified domain and size
     * @param[in,out] v On successful return, contains a handle to the newly created PerfSparseBLAS vector
     * @param[in] type The type corresponding to the domain of the vector being created. Can be one of the predefined SparseBLAS types in \link perfSpB_type \endlink.
     * @param[in] n The size of the vector being created.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_vector_new(perfSpB_vector *v, perfSpB_type type, perfSpB_index n);

    /**
     * @brief Destroys a previously created perfSpB_vector object and releases any resources associated with the object.
     *
     * @param[in,out] v An existing perfSpB_vector object to be destroyed. The object must have been created by an explicit call to a \link perfSpB_vector_new \endlink constructor. On successful completion of perfSpB_vector_free, obj behaves as an uninitialized object.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_vector_free(perfSpB_vector *v);

    /**
     * @brief Creates a new vector with the same domain, size, and contents as another vector
     * @param[in,out] v1 successful return, contains a handle to the newly created PerfSparseBLAS vector.
     * @param[in] v2 The PerfSparseBLAS vector to be duplicated.
     */
    perfSpB_info perfSpB_vector_dup(perfSpB_vector *v1, perfSpB_vector v2);

    /**
     * @brief Retrieve the number of stored elements (tuples) in a vector.
     * @param[out] nvals On successful return, this is set to the number of stored elements (tuples) in the vector.
     * @param[in] v An existing SparseBLAS vector being queried.
     */
    perfSpB_info perfSpB_vector_nvals(perfSpB_index *nvals, perfSpB_vector v);

    //------------------------------------------------------------------------------
    // perfSpB_vector_build
    //------------------------------------------------------------------------------

    // perfSpB_vector_build:  C = sparse (I,X), but using any
    // associative operator to assemble duplicate entries.

    /**
     * @anchor perfSpB_vector_build
     * @name perfSpB_vector_build
     * @brief Store elements from tuples into a vetctor
     * @details
     * @brief Store elements from tuples into a vetctor
     *
     * @param[in,out] w An existing Vector object to store the result.
     * @param[in] indices Pointer to an array of indices.
     * @param[in] values Pointer to an array of scalars of a type that is compatible with the domain of vector **w**.
     * @param[in] n The number of entries contained in each array (the same for indices and values).
     * @return perfSpB_info
     */
    ///@{
    /**
     * @brief Store BOOL elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_vector_build for function introduction details
     */
    // TODO: rename?
    perfSpB_info perfSpB_vector_build_BOOL(
        perfSpB_vector w,
        const perfSpB_index *indices,
        const bool *values,
        perfSpB_index n);

    /**
     * @brief Store INT32 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_vector_build for function introduction details
     */
    perfSpB_info perfSpB_vector_build_INT32(
        perfSpB_vector w,
        const perfSpB_index *indices,
        const int32_t *values,
        perfSpB_index n);
    ///@}

    //------------------------------------------------------------------------------
    // perfSpB_vector_set_element
    //------------------------------------------------------------------------------

    // Set a single scalar in a vector, w(i) = x, typecasting from the type of x to
    // the type of w as needed.

    /**
     * @anchor perfSpB_vector_set_element
     * @name perfSpB_vector_set_element
     * @brief Set one element of a vector to a given value.
     * @param[in,out] w An existing SparseBLAS vector for which an element is to be assigned.
     * @param[in] x Scalar assign. Its domain (type) must be compatible with the domain of w.
     * @param[in] i The location of the element to be assigned.
     * @return perfSpB_info
     */
    ///@{
    /**
     * @brief Set a single perfSpB_scalar element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_Scalar // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            perfSpB_scalar s, // scalar to assign to w(i)
            perfSpB_index i   // row index
        );
    /**
     * @brief Set a single BOOL element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_BOOL // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            bool x,           // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single INT8 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_INT8 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            int8_t x,         // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single UINT8 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_UINT8 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            uint8_t x,        // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single INT16 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_INT16 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            int16_t x,        // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single UINT16 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_UINT16 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            uint16_t x,       // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single INT32element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_INT32 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            int32_t x,        // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single UINT32 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_UINT32 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            uint32_t x,       // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single INT64 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_INT64 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            int64_t x,        // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single UINT64 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_UINT64 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            uint64_t x,       // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single FP32 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_FP32 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            float x,          // scalar to assign to w(i)
            perfSpB_index i   // row index
        );

    /**
     * @brief Set a single FP64 element in a vector
     * @details Please refer to \ref perfSpB_vector_set_element for function introduction details
     */
    perfSpB_info perfSpB_vector_set_element_FP64 // w(i) = x
        (
            perfSpB_vector w, // vector to modify
            double x,         // scalar to assign to w(i)
            perfSpB_index i   // row index
        );
    ///@}
    // Type-generic version:  x can be any supported C type or void * for a
    // user-defined type.

    //------------------------------------------------------------------------------
    // perfSpB_vector_extract_element
    //------------------------------------------------------------------------------

    // Extract a single entry from a vector, x = v(i), typecasting from the type of
    // v to the type of x as needed.

    /**
     * @anchor perfSpB_vector_extract_element
     * @name perfSpB_vector_extract_element
     * @brief Extract a single element from a vector.
     * @param[in,out] x An existing scalar of whose domain is compatible with the domain of vector v. On successful return, this scalar holds the result of the extract.
     * @param[in] v The PerfSparseBLAS vector from which an element is extracted.
     * @param[in] i The location in v to extract.
     * @return perfSpB_info
     */
    ///@{

    /**
     * @brief Extract a single perfSpB_scalar element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_Scalar // x = v(i)
        (
            perfSpB_scalar x,       // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single BOOL element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_BOOL // x = v(i)
        (
            bool *x,                // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single INT8 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_INT8 // x = v(i)
        (
            int8_t *x,              // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single UINT8 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_UINT8 // x = v(i)
        (
            uint8_t *x,             // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single INT16 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_INT16 // x = v(i)
        (
            int16_t *x,             // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single UINT16 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_UINT16 // x = v(i)
        (
            uint16_t *x,            // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single INT32 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_INT32 // x = v(i)
        (
            int32_t *x,             // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single UINT32 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_UINT32 // x = v(i)
        (
            uint32_t *x,            // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single INT64 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_INT64 // x = v(i)
        (
            int64_t *x,             // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single UINT64 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_UINT64 // x = v(i)
        (
            uint64_t *x,            // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single FP32 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_FP32 // x = v(i)
        (
            float *x,               // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    /**
     * @brief Extract a single FP64 element from a vector.
     * @details Please refer to \ref perfSpB_vector_extract_element for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_element_FP64 // x = v(i)
        (
            double *x,              // scalar extracted
            const perfSpB_vector v, // vector to extract an entry from
            perfSpB_index i         // row index
        );

    ///@}
    // Type-generic version:  x can be a pointer to any supported C type or void *
    // for a user-defined type.

    //------------------------------------------------------------------------------
    // perfSpB_vector_extract_tuples
    //------------------------------------------------------------------------------

    // Extracts all tuples from a vector, like [I,~,X] = find (v).  If
    // any parameter I and/or X is NULL, then that component is not extracted.  For
    // example, to extract just the row indices, pass I as non-NULL, and X as NULL.
    // This is like [I,~,~] = find (v).

    /**
     * @anchor perfSpB_vector_extract_tuples
     * @name perfSpB_vector_extract_tuples
     * @brief Extract tuples from a vector
     * @param[out] RowInd Pointer to an array of indices that is large enough to hold all of the stored values’ indices.
     * @param[out] Vals Pointer to an array of scalars of a type that is large enough to hold all of the stored values whose type is compatible with D(v).
     * @param[in] nvals Pointer to a value indicating (on input) the number of elements the values and indices arrays can hold. Upon return, it will contain the number of values written to the arrays.
     * @param[in] v An existing PerfSparseBLAS vector.
     * @return perfSpB_info
     */
    ///@{
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_BOOL // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            bool *Vals,               // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );

    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_INT8 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            int8_t *Vals,             // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_UINT8 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            uint8_t *Vals,            // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_INT16 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            int16_t *Vals,            // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_UINT16 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            uint16_t *Vals,           // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_INT32 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            int32_t *Vals,            // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_UINT32 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            uint32_t *Vals,           // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_INT64 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            int64_t *Vals,            // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_UINT64 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            uint64_t *Vals,           // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_FP32 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            float *Vals,              // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    /**
     * @brief Extract the contents of a PerfSparseBLAS vector into non-opaque data structures.
     * @details Please refer to \ref perfSpB_vector_extract_tuples for function introduction details
     */
    perfSpB_info perfSpB_vector_extract_tuples_FP64 // [I,~,X] = find (v)
        (
            perfSpB_index *RowInd,      // array for returning row indices of tuples
            double *Vals,             // array for returning values of tuples
            perfSpB_index *nvals,  // I, X size on input; # tuples on output
            const perfSpB_vector v // vector to extract tuples from
        );
    ///@}
    // Type-generic version:  X can be a pointer to any supported C type or void *
    // for a user-defined type.

    /**@}*/ // end for perfSpB_vector

    /**
     * @defgroup perfSpB_matrix
     * @brief perfSpB_matrix class
     * @{
     */

    /**
     * @brief Get the data type of a matrix
     *
     * @param[out] t On successful return, contains the result type of the input matrix.
     * @param[in] m An existing PerfSparseBLAS matrix being queried.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_matrix_type(perfSpB_type *t, perfSpB_matrix m);
    /**
     * @brief Number of rows in a matrix
     * @details Retrieve the number of rows in a matrix.
     * @param[out] n On successful return, contains the number of rows in the matrix.
     * @param[in] m An existing PerfSparseBLAS matrix being queried.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_matrix_nrows(perfSpB_index *n, perfSpB_matrix m);

    /**
     * @brief Number of columns in a matrix
     * @details Retrieve the number of columns in a matrix
     *
     * @param n On successful return, contains the number of columns in the matrix.
     * @param m An existing PerfSparseBLAS matrix being queried.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_matrix_ncols(perfSpB_index *n, perfSpB_matrix m);

    /**
     * @brief Construct new matrix
     * @details Creates a new matrix with specified domain and dimensions.
     * @param[in,out] m On successful return, contains a handle to the newly created PerfSparseBLAS matrix.
     * @param[in] type The type corresponding to the domain of the matrix being created. Can be one of the predefined \link perfSpB_type \endlink.
     * @param[in] nrows The number of rows of the matrix being created.
     * @param[in] ncols The number of columns of the matrix being created.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_matrix_new(perfSpB_matrix *m, perfSpB_type type, perfSpB_index nrows, perfSpB_index ncols);

    /**
     * @brief Destroy a matrix and release its resources
     * @details Destroys a previously created PerfSparseBLAS matrix object and releases any resources associated with the matrix.
     * @param[in,out] A An existing SparseBLAS matrix to be destroyed. The object must have been created by an explicit call to a PerfSparseBLAS matrix constructor. On successful completion, matrix A behaves as an uninitialized matrix object.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_matrix_free(perfSpB_matrix *A);

    //------------------------------------------------------------------------------
    // perfSpB_matrix_build
    //------------------------------------------------------------------------------

    /**
     * @anchor perfSpB_matrix_build
     * @name perfSpB_matrix_build
     * @brief Store elements from tuples into a matrix
     * @details
     * @brief Store elements from tuples into a matrix
     *
     * @param[in,out] C An existing Matrix object to store the result.
     * @param[in] RowInd Pointer to an array of row indices.
     * @param[in] ColInd Pointer to an array of column indices.
     * @param[in] X Pointer to an array of scalars of a type that is compatible with the domain of matrix, C.
     * @param[in] nvals The number of entries contained in each array (the same for row_indices, col_indices and values).
     * @param[in] dup An associative and commutative binary operator to apply when duplicate values for the sam  location are present in the input arrays.
     * @return perfSpB_info
     */
    ///@{
    /**
     * @brief Store BOOL elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_BOOL // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const bool *Vals,          // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store INT8 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_INT8 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const int8_t *Vals,        // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store UINT8 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_UINT8 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const uint8_t *Vals,       // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store INT16 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_INT16 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const int16_t *Vals,       // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store UINT16 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_UINT16 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const uint16_t *Vals,      // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store INT32 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_INT32 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const int32_t *Vals,       // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store UINT32 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_UINT32 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const uint32_t *Vals,      // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store INT64 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_INT64 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const int64_t *Vals,       // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store UINT64 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_UINT64 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const uint64_t *Vals,      // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store FP32 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_FP32 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const float *Vals,         // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store FP64 elements from tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_build for function introduction details
     */
    perfSpB_info perfSpB_matrix_build_FP64 // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const double *Vals,        // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );
    ///@}

    /**
       * @anchor perfSpB_matrix_fast_build_ext
       * @name perfSpB_matrix_fast_build_ext
       * @brief Store elements from sorted tuples into a matrix
       * @details If the incoming tuples are ordered (in order of CSC or CSR format), the matrix created by calling this interface can be created more quickly. This is because the interface can make direct copies of ordered tuples, eliminating the need to sort incoming tuples. \n <b>However, it is worth noting that the sorting rules must be consistent with the format of the SparseBLAS matrix, otherwise it will lead to undefined errors. Passing in unsorted tuples will also result in undefined errors. Therefore, it is recommended to call this interface with caution.</b>

       *
       * @param[in,out] C An existing Matrix object to store the result.
       * @param[in] RowInd Pointer to an array of sorted row indices.
       * @param[in] ColInd Pointer to an array of sorted column indices.
       * @param[in] X Pointer to an array of sorted scalars of a type that is compatible with the domain of matrix, C.
       * @param[in] nvals The number of entries contained in each array (the same for row_indices, col_indices and values).
       * @param[in] dup An associative and commutative binary operator to apply when duplicate values for the sam  location are present in the input arrays.
       * @return perfSpB_info
       */
    ///@{
    /**
     * @brief Store BOOL elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_BOOL_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const bool *Vals,          // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store INT8 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_INT8_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const int8_t *Vals,        // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store UINT8 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_UINT8_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const uint8_t *Vals,       // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store INT16 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_INT16_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const int16_t *Vals,       // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store UINT16 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_UINT16_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const uint16_t *Vals,      // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store INT32 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_INT32_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const int32_t *Vals,       // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store UINT32 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_UINT32_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const uint32_t *Vals,      // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store INT64 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_INT64_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const int64_t *Vals,       // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store UINT64 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_UINT64_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const uint64_t *Vals,      // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store FP32 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_FP32_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const float *Vals,         // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );

    /**
     * @brief Store FP64 elements from sorted tuples into a matrix
     * @details Please refer to \ref perfSpB_matrix_fast_build_ext for function introduction details
     */
    perfSpB_info perfSpB_matrix_fast_build_FP64_ext // build a matrix from (RowInd,ColInd,Vals) tuples
        (
            perfSpB_matrix Mat,       // matrix to build
            const perfSpB_index *RowInd, // array of row indices of tuples
            const perfSpB_index *ColInd, // array of column indices of tuples
            const double *Vals,        // array of values of tuples
            perfSpB_index nvals     // number of tuples
        );
    ///@}

    //------------------------------------------------------------------------------
    // perfSpB_matrix_set_element
    //------------------------------------------------------------------------------

    // Set a single entry in a matrix, Mat(i,j) = x, typecasting
    // from the type of x to the type of C, as needed.

    /**
     * @anchor perfSpB_matrix_set_element
     * @name  perfSpB_matrix_set_element
     * @brief Set a single element in matrix
     * @details Set one element of a matrix to a given value.
     * @param[in,out] Mat An existing PerfSparseBLAS matrix for which an element is to be assigned.
     * @param[in] x Scalar to assign. Its domain (type) must be compatible with the domain of C.
     * @param[in] i Row index of element to be assigned
     * @param[in] j Column index of element to be assigned
     * @return perfSpB_info
     */

    ///@{

    /**
     * @brief Set a single BOOL element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_BOOL // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            bool x,           // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );

    /**
     * @brief Set a single INT8 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_INT8 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            int8_t x,         // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );

    /**
     * @brief Set a single UINT8 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_UINT8 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            uint8_t x,        // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );

    /**
     * @brief Set a single INT16 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_INT16 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            int16_t x,        // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );

    /**
     * @brief Set a single UINT16 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_UINT16 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            uint16_t x,       // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );

    /**
     * @brief Set a single INT32 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_INT32 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            int32_t x,        // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );
    /**
     * @brief Set a single UINT32 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_UINT32 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            uint32_t x,       // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );
    /**
     * @brief Set a single INT64 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_INT64 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            int64_t x,        // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );
    /**
     * @brief Set a single UINT64 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_UINT64 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            uint64_t x,       // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );

    /**
     * @brief Set a single FP32 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_FP32 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            float x,          // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );

    /**
     * @brief Set a single FP64 element in matrix
     * @details Please refer to \ref perfSpB_matrix_set_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_set_element_FP64 // Mat (i,j) = x
        (
            perfSpB_matrix Mat, // matrix to modify
            double x,         // scalar to assign to Mat(i,j)
            perfSpB_index i,  // row index
            perfSpB_index j   // column index
        );
    ///@}
    // Type-generic version:  x can be any supported C type or void * for a
    // user-defined type.

#if PerfSpB_STDC_VERSION >= 201112L
#define perfSpB_matrix_set_element(C, x, i, j) \
    _Generic(                                 \
        (x),                                  \
        PerfSpB_CASES(, PerfSpB, Matrix_setElement))(C, x, i, j)
#endif

    //------------------------------------------------------------------------------
    // perfSpB_matrix_extract_element
    //------------------------------------------------------------------------------

    // Extract a single entry from a matrix, x = A(i,j), typecasting from the type
    // of A to the type of x, as needed.

    /**
     * @anchor perfSpB_matrix_extract_element
     * @name perfSpB_matrix_extract_element
     * @brief Extract a single element from a matrix
     * @details Extract one element of a matrix into a scalar.
     * @param[in,out] x An existing scalar whose domain is compatible with the domain of matrix A. On successful return, this scalar holds the result of the extract. Any previous value stored in val or s is overwritten.
     * @param[in] A The PerfSparseBLAS matrix from which an element is extracted.
     * @param[in] i The row index of location in A to extract.
     * @param[in] j The column index of location in A to extract.
     * @return perfSpB_info
     */

    ///@{

    /**
     * @brief Extract a single perfSpB_scalar element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_Scalar // x = A(i,j)
        (
            perfSpB_scalar x,       // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );

    /**
     * @brief Extract a single BOOL element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_BOOL // x = A(i,j)
        (
            bool *x,                // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );

    /**
     * @brief Extract a single INT8 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_INT8 // x = A(i,j)
        (
            int8_t *x,              // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single UINT8 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_UINT8 // x = A(i,j)
        (
            uint8_t *x,             // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single INT16 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_INT16 // x = A(i,j)
        (
            int16_t *x,             // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single UINT16 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_UINT16 // x = A(i,j)
        (
            uint16_t *x,            // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single INT32 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_INT32 // x = A(i,j)
        (
            int32_t *x,             // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single UINT32 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_UINT32 // x = A(i,j)
        (
            uint32_t *x,            // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single INT64 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_INT64 // x = A(i,j)
        (
            int64_t *x,             // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single UINT64 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_UINT64 // x = A(i,j)
        (
            uint64_t *x,            // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single FP32 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_FP32 // x = A(i,j)
        (
            float *x,               // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    /**
     * @brief Extract a single FP64 element from a matrix
     * @details Please refer to \ref perfSpB_matrix_extract_element for function introduction details
     */
    perfSpB_info perfSpB_matrix_extract_element_FP64 // x = A(i,j)
        (
            double *x,              // extracted scalar
            const perfSpB_matrix A, // matrix to extract a scalar from
            perfSpB_index i,        // row index
            perfSpB_index j         // column index
        );
    ///@} //end for perfSpB_matrix_extract_element
    // Type-generic version:  x can be a pointer to any supported C type or void *
    // for a user-defined type.

    /**@}*/ // end for perfSpB_matrix
    /**@}*/ // end for core

    /**
     * @defgroup operator
     * @brief The basic operations of PerfSparseBLAS
     * @details This module contains the basic operations of PerfSparseBLAS
     * @{
     */

    /**
     * @defgroup PerfSpB_mxv
     * @brief Matrix-Vector multiplication module
     * @details This module mainly implements PerfSpB_mxv, whose core operators are SpMSpV and SpMV, both of which are very important for graph algorithms to achieve Pull/Push optimization \cite yang2018implementing.
     * @{
     */
    perfSpB_info perfSpB_SpMV_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_VNEC_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_EDA_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_PCSR_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_PCSR_W_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);
    perfSpB_info perfSpB_SpMV_Adaptive_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_MERGE_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_LBNEC_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_Nec_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_LIGHT_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_LINE_ENHANCE_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);


    perfSpB_info perfSpB_SpMV_ACSR_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_flat_FP32(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

                        
    perfSpB_info perfSpB_SpMV_FP64(perfSpB_operation_t op,
                                     const void *alpha,
                                     const perfSpB_matrix matA,
                                     const perfSpB_vector vecX,
                                     const void *beta,
                                     perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_PCSR_FP64(perfSpB_operation_t op,
                                        const void *alpha,
                                        const perfSpB_matrix matA,
                                        const perfSpB_vector vecX,
                                        const void *beta,
                                        perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_Adaptive_FP64(perfSpB_operation_t op,
                                        const void *alpha,
                                        const perfSpB_matrix matA,
                                        const perfSpB_vector vecX,
                                        const void *beta,
                                        perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_LBNEC_FP64(perfSpB_operation_t op,
                                        const void *alpha,
                                        const perfSpB_matrix matA,
                                        const perfSpB_vector vecX,
                                        const void *beta,
                                        perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_LIGHT_FP64(perfSpB_operation_t op,
                                        const void *alpha,
                                        const perfSpB_matrix matA,
                                        const perfSpB_vector vecX,
                                        const void *beta,
                                        perfSpB_vector vecY);

    perfSpB_info perfSpB_SpMV_flat_FP64(perfSpB_operation_t op,
                                        const void *alpha,
                                        const perfSpB_matrix matA,
                                        const perfSpB_vector vecX,
                                        const void *beta,
                                        perfSpB_vector vecY);

    perfSpB_info PerfSpB_mxv(perfSpB_vector y, const perfSpB_matrix A, const perfSpB_vector x, void *VNEC);

    /////////////////////////////////////////CPU kernel////////////////////////////////////////////
    // TODO: user APIs?
    void SpMV_VNEC_D_FP32(perfSpB_vector y,
                          const perfSpB_matrix A,
                          const perfSpB_vector x,
                          VNEC_D_FP32 *mat_thd);

    struct VNEC_D_FP32 *Build_VNEC_D_FP32(const perfSpB_matrix A);
    PerfSpB_VNEC_type IRD_VNEC(const perfSpB_matrix A, perfSpB_type type);

    void SpMV_VNEC_S_FP32(perfSpB_vector y,
                          const perfSpB_matrix A,
                          const perfSpB_vector x,
                          VNEC_S_FP32 *mat_thd);

    struct VNEC_S_FP32 *Build_VNEC_S_FP32(const perfSpB_matrix A);

    struct VNEC_L *Build_VNEC_L(const perfSpB_matrix A);
    void SpMV_VNEC_L_FP32(perfSpB_vector y, const perfSpB_matrix A, const perfSpB_vector x, VNEC_L *mat_thd);

    void SpMV_VNEC_D_FP64(perfSpB_vector y,
                          const perfSpB_matrix A,
                          const perfSpB_vector x,
                          VNEC_D_FP64 *mat_thd);

    struct VNEC_D_FP64 *Build_VNEC_D_FP64(const perfSpB_matrix A);

    void SpMV_VNEC_S_FP64(perfSpB_vector y,
                          const perfSpB_matrix A,
                          const perfSpB_vector x,
                          VNEC_S_FP64 *mat_thd);

    struct VNEC_S_FP64 *Build_VNEC_S_FP64(const perfSpB_matrix A);

    void SpMV_VNEC_L_FP64(perfSpB_vector y, const perfSpB_matrix A, const perfSpB_vector x, VNEC_L *mat_thd);
    /**@}*/ // end for PerfSpB_mxv

    /**
     * @defgroup PerfSpB_mxm
     * @brief Matrix-Matrix multiplication module
     * @details This module mainly implements matrix and matrix multiplication operations. Since in the initial design, we only consider the matrix to be stored using sparse format, its core operator is SpGEMM.
     * @{
     */
    perfSpB_info PerfSpB_mxm(perfSpB_matrix Mat, const perfSpB_matrix A, const perfSpB_matrix B);
    /**@}*/ // end for PerfSpB_mxm

    /**
     * @defgroup perfSpB_transpose
     * @brief Transpose rows and columns of a matrix.
     * @details This version computes a new matrix that is the transpose of the source matrix.
     * @{
     */

    /**
     * @brief Computes the transformation of the values of the elements of a vector using a unary function.
     *
     * @param[in,out] C An existing SparseBLAS matrix. On input, the matrix provides values that may be accumulated with the result of the transpose operation. On output, the matrix holds the results of the operation.
     * @param[in] A     The SparseBLAS matrix on which transposition will be performed.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_transpose(perfSpB_matrix Mat, const perfSpB_matrix A);
    /**@} */ // end for perfSpB_transpose

    /**@}*/ // end for operator

    /**
     * @defgroup Extension
     * @brief Extend the SparseBLAS API with some functions that control the underlying runtime methods.
     * @{
     */

    /**
     * @defgroup ObjectFormat
     * @brief Object format control module
     * @details The following code shows the default format for setting the matrix construction:
     * \code
     * perfSpB_object_format_ext format;
     * format.matrix_format = perfSpB_csr;
     * PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);
     * \endcode
     * @{
     */

    /**
     * @brief Function to set the global default object format
     *
     * @param[in] field The field needs to be set
     * @param[in] value The value will be set for this field
     * @return perfSpB_info
     */
    perfSpB_info PerfSpB_Global_Option_set_ext // set a global default option
        (
            perfSpB_option_field_ext field, // option to change
            perfSpB_object_format_ext value // value to change it to
        );

    /**
     * @brief Creates a new vector with specified domain, size and format.
     *
     * @param[in,out] v On successful return, contains a handle to the newly created PerfSparseBLAS vector.
     * @param[in] type The type corresponding to the domain of the vector being created. Can be one of the predefined \link perfSpB_type \enlink.
     * @param[in] n The size of the vector being created.
     * @param[in] format The format of the vector being created.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_vector_new_format_ext(perfSpB_vector *v,
                                               perfSpB_type type,
                                               perfSpB_index n,
                                               perfSpB_vector_format_value_ext format);

    /**
     * @brief Get the format of the given vector
     *
     * @param[in] v The PerfSparseBLAS vector which format will be retured
     * @return perfSpB_vector_format_value_ext
     */
    perfSpB_vector_format_value_ext perfSpB_vector_format_ext(const perfSpB_vector v);

    /**
     * @brief Creates a new vector in a way that copies the format of a given vector.
     * @details The new vector format will be the same as the format of the given vector, but will not copy its value.
     * @param out The new vector
     * @param in The given vector
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_vector_copy_format_ext(perfSpB_vector *out, const perfSpB_vector in);

    /**
     * @brief Creates a new matrix with specified domain, size and format.
     *
     * @param[in,out] v On successful return, contains a handle to the newly created PerfSparseBLAS matrix.
     * @param[in] type The type corresponding to the domain of the matrix being created. Can be one of the predefined \link perfSpB_type \enlink.
     * @param[in] row The row number of the matrix being created.
     * @param[in] col The col number of the matrix being created.
     * @param[in] format The format of the matrix being created.
     * @return perfSpB_info
     */
    perfSpB_info perfSpB_matrix_new_format_ext(perfSpB_matrix *m,
                                               perfSpB_type type,
                                               perfSpB_index row,
                                               perfSpB_index col,
                                               perfSpB_matrix_format_value_ext format);

    /**
     * @brief Get the format of the given matrix
     *
     * @param[in] m The PerfSparseBLAS matrix which format will be retured
     * @return perfSpB_matrix_format_value_ext
     */
    perfSpB_matrix_format_value_ext perfSpB_matrix_format_ext(const perfSpB_matrix m);
    /**@}*/ // end for ObjectFormat

    /**
     * @brief Decide whether to print warning message.
     *
     */
    perfSpB_info PerfSpB_Warning_switch_set_ext(bool val);
    /**@}*/ // end for Extension

#ifdef __cplusplus
}
#endif

// The declaration of C++ code
#ifdef __cplusplus

#define PerfSpB_VECTOR_EXTRACT_CPP(type, T) \
    perfSpB_info perfSpB_vector_extract_element(type *x, const perfSpB_vector v, perfSpB_index i);

PerfSpB_VECTOR_EXTRACT_CPP(bool, BOOL);
PerfSpB_VECTOR_EXTRACT_CPP(int8_t, INT8);
PerfSpB_VECTOR_EXTRACT_CPP(int16_t, INT16);
PerfSpB_VECTOR_EXTRACT_CPP(int32_t, INT32);
PerfSpB_VECTOR_EXTRACT_CPP(int64_t, INT64);
PerfSpB_VECTOR_EXTRACT_CPP(uint8_t, UINT8);
PerfSpB_VECTOR_EXTRACT_CPP(uint16_t, UINT16);
PerfSpB_VECTOR_EXTRACT_CPP(uint32_t, UINT32);
PerfSpB_VECTOR_EXTRACT_CPP(uint64_t, UINT64);
PerfSpB_VECTOR_EXTRACT_CPP(float, FP32);
PerfSpB_VECTOR_EXTRACT_CPP(double, FP64);
#undef PerfSpB_VECTOR_EXTRACT_CPP

#define PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(type, T) \
    perfSpB_info perfSpB_vector_extract_tuples(perfSpB_index *RowInd, type *Vals, perfSpB_index *p_nvals, const perfSpB_vector v);

PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(bool, BOOL);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(int8_t, INT8);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(int16_t, INT16);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(int32_t, INT32);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(int64_t, INT64);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(uint8_t, UINT8);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(uint16_t, UINT16);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(uint32_t, UINT32);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(uint64_t, UINT64);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(float, FP32);
PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(double, FP64);
#undef PerfSpB_VECTOR_EXTRACT_TUPLES_CPP

#define PerfSpB_VECTOR_SET_CPP(type, T) \
    perfSpB_info perfSpB_vector_set_element(perfSpB_vector v, type x, perfSpB_index i);

PerfSpB_VECTOR_SET_CPP(bool, BOOL);
PerfSpB_VECTOR_SET_CPP(int8_t, INT8);
PerfSpB_VECTOR_SET_CPP(int16_t, INT16);
PerfSpB_VECTOR_SET_CPP(int32_t, INT32);
PerfSpB_VECTOR_SET_CPP(int64_t, INT64);
PerfSpB_VECTOR_SET_CPP(uint8_t, UINT8);
PerfSpB_VECTOR_SET_CPP(uint16_t, UINT16);
PerfSpB_VECTOR_SET_CPP(uint32_t, UINT32);
PerfSpB_VECTOR_SET_CPP(uint64_t, UINT64);
PerfSpB_VECTOR_SET_CPP(float, FP32);
PerfSpB_VECTOR_SET_CPP(double, FP64);
#undef PerfSpB_VECTOR_SET_CPP

#endif

/**
 * @defgroup algorithm
 * @brief The basic graph algorithms
 * @details This module contains a series of basic graph algorithms implemented using PerfSparseBLAS.
 *
 */
