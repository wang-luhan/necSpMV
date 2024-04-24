#include "utilities/command_line.h"
#include "utilities/graph.hpp"
#include "utilities/builder.hpp"
#include <cstring>

template <typename T>
inline void CHECK_NULLPTR(T *ptr)
{
    if (ptr != nullptr)
    {
        delete[] ptr;
    }
}

/**
 * @ingroup utilities
 * @{
 */

/**
 * @brief Read the matrix data from the.sg file and store it in three arrays in COO format. The elements are arranged in row-first order (order in CSR format) .
 * @attention After calling this function, be careful to free up the values, row_indices and col_indices space to avoid memory leaks.
 *
 * @tparam T The datatype of values of Matrix.
 * @param[in] full_path The full path of the file to be read.
 * @param[out] values The values array of COO.
 * @param[out] row_indices The row_indices array of COO.
 * @param[out] col_indices The col_indices array of COO.
 * @param[out] nrows The number of rows.
 * @param[out] ncols The number of cols.
 * @param[out] nvals The number of non-zero values.
 */
template <typename T>
void Read_CSR_Matrix_SG(
    const std::string full_path,
    T *&values,
    perfSpB_index *&row_indices,
    perfSpB_index *&col_indices,
    perfSpB_index &nrows,
    perfSpB_index &ncols,
    perfSpB_index &nvals)
{
    // Read input graph from a .sg file.
    Builder<perfSpB_index, perfSpB_index> builder(full_path);
    CSRGraph<perfSpB_index, perfSpB_index> g = builder.MakeGraph();

    nrows = static_cast<perfSpB_index>(g.num_nodes());
    ncols = static_cast<perfSpB_index>(g.num_nodes());
    nvals = static_cast<perfSpB_index>(g.num_edges());

    CHECK_NULLPTR(values);
    CHECK_NULLPTR(row_indices);
    CHECK_NULLPTR(col_indices);

    values = new T[nvals];
    col_indices = new perfSpB_index[nvals];
    memcpy(col_indices, g.out_destValues(), nvals * sizeof(perfSpB_index));
    row_indices = new perfSpB_index[nvals];
    perfSpB_index *offsets = g.out_offsets();
    perfSpB_index index = 0;
    for (perfSpB_index i = 0; i < nrows; i++)
    {
        for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
        {
            if (index >= nvals)
            {
                std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                exit(-1);
            }
            values[index] = static_cast<T>(1);
            row_indices[index++] = i;
        }
    }
}

template <typename T>
void Read_CSR_and_CSC_Matrix_SG(
    const std::string full_path,
    T *&csr_values,
    perfSpB_index *&csr_row_indices,
    perfSpB_index *&csr_col_indices,
    T *&csc_values,
    perfSpB_index *&csc_row_indices,
    perfSpB_index *&csc_col_indices,
    perfSpB_index &nrows,
    perfSpB_index &ncols,
    perfSpB_index &nvals)
{
    // Read input graph from a .sg file.
    Builder<perfSpB_index, perfSpB_index> builder(full_path);
    CSRGraph<perfSpB_index, perfSpB_index> g = builder.MakeGraph();

    nrows = static_cast<perfSpB_index>(g.num_nodes());
    ncols = static_cast<perfSpB_index>(g.num_nodes());
    nvals = static_cast<perfSpB_index>(g.num_edges());

    CHECK_NULLPTR(csr_values);
    CHECK_NULLPTR(csr_row_indices);
    CHECK_NULLPTR(csr_col_indices);
    CHECK_NULLPTR(csc_values);
    CHECK_NULLPTR(csc_row_indices);
    CHECK_NULLPTR(csc_col_indices);

    csr_values = new T[nvals];
    csr_col_indices = new perfSpB_index[nvals];
    memcpy(csr_col_indices, g.out_destValues(), nvals * sizeof(perfSpB_index));
    csr_row_indices = new perfSpB_index[nvals];
    {
        perfSpB_index *offsets = g.out_offsets();
        perfSpB_index index = 0;
        for (perfSpB_index i = 0; i < nrows; i++)
        {
            for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
            {
                if (index >= nvals)
                {
                    std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                    exit(-1);
                }
                csr_values[index] = static_cast<T>(1);
                csr_row_indices[index++] = i;
            }
        }
    }

    csc_values = new T[nvals];
    csc_row_indices = new perfSpB_index[nvals];
    memcpy(csc_row_indices, g.in_destValues(), nvals * sizeof(perfSpB_index));
    csc_col_indices = new perfSpB_index[nvals];
    {
        perfSpB_index *offsets = g.in_offsets();
        perfSpB_index index = 0;
        for (perfSpB_index i = 0; i < ncols; i++)
        {
            for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
            {
                if (index >= nvals)
                {
                    std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                    exit(-1);
                }
                csc_values[index] = static_cast<T>(1);
                csc_col_indices[index++] = i;
            }
        }
    }
}

/**
 * @brief Read the matrix data from the.wsg file and store it in three arrays in COO format. The elements are arranged in row-first order (order in CSR format) .
 * @attention After calling this function, be careful to free up the values, row_indices and col_indices space to avoid memory leaks.
 *
 * @tparam T The datatype of values of Matrix.
 * @param[in] full_path The full path of the file to be read.
 * @param[out] values The values array of COO.
 * @param[out] row_indices The row_indices array of COO.
 * @param[out] col_indices The col_indices array of COO.
 * @param[out] nrows The number of rows.
 * @param[out] ncols The number of cols.
 * @param[out] nvals The number of non-zero values.
 */
template <typename T>
void Read_CSR_Matrix_WSG(
    const std::string full_path,
    T *&values,
    perfSpB_index *&row_indices,
    perfSpB_index *&col_indices,
    perfSpB_index &nrows,
    perfSpB_index &ncols,
    perfSpB_index &nvals)
{
    if (!std::is_same<T, int32_t>::value)
    {
        std::cout << "Read_CSR_Matrix_WSG only can read the int32_t weight." << std::endl;
        std::exit(-1);
    }
    // Read input graph from a .wsg file.
    Builder<perfSpB_index, NodeWeight<perfSpB_index, T>, T> builder(full_path);
    CSRGraph<perfSpB_index, NodeWeight<perfSpB_index, T>> g = builder.MakeGraph();

    nrows = static_cast<perfSpB_index>(g.num_nodes());
    ncols = static_cast<perfSpB_index>(g.num_nodes());
    nvals = static_cast<perfSpB_index>(g.num_edges());

    CHECK_NULLPTR(values);
    CHECK_NULLPTR(row_indices);
    CHECK_NULLPTR(col_indices);

    values = new T[nvals];
    col_indices = new perfSpB_index[nvals];
    row_indices = new perfSpB_index[nvals];
    perfSpB_index *offsets = g.out_offsets();
    perfSpB_index index = 0;
    for (perfSpB_index i = 0; i < nrows; i++)
    {
        for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
        {
            if (index >= nvals)
            {
                std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                exit(-1);
            }
            col_indices[index] = g.out_destValues()[index].v;
            values[index] = g.out_destValues()[index].w;
            row_indices[index++] = i;
        }
    }
}

/**
 * @brief Read the matrix data from the.sg file and store it in three arrays in COO format. The elements are arranged in col-first order (order in CSC format).
 * @attention After calling this function, be careful to free up the values, row_indices and col_indices space to avoid memory leaks.
 *
 * @tparam T The datatype of values of Matrix.
 * @param[in] full_path The full path of the file to be read.
 * @param[out] values The values array of COO.
 * @param[out] row_indices The row_indices array of COO.
 * @param[out] col_indices The col_indices array of COO.
 * @param[out] nrows The number of rows.
 * @param[out] ncols The number of cols.
 * @param[out] nvals The number of non-zero values.
 */
template <typename T>
void Read_CSC_Matrix_SG(
    const std::string full_path,
    T *&values,
    perfSpB_index *&row_indices,
    perfSpB_index *&col_indices,
    perfSpB_index &nrows,
    perfSpB_index &ncols,
    perfSpB_index &nvals)
{
    // Read input graph from a .sg file.
    Builder<perfSpB_index, perfSpB_index> builder(full_path);
    CSRGraph<perfSpB_index, perfSpB_index> g = builder.MakeGraph();

    nrows = static_cast<perfSpB_index>(g.num_nodes());
    ncols = static_cast<perfSpB_index>(g.num_nodes());
    nvals = static_cast<perfSpB_index>(g.num_edges());

    CHECK_NULLPTR(values);
    CHECK_NULLPTR(row_indices);
    CHECK_NULLPTR(col_indices);

    values = new T[nvals];
    row_indices = new perfSpB_index[nvals];
    memcpy(row_indices, g.in_destValues(), nvals * sizeof(perfSpB_index));
    col_indices = new perfSpB_index[nvals];
    perfSpB_index *offsets = g.in_offsets();
    perfSpB_index index = 0;
    for (perfSpB_index i = 0; i < ncols; i++)
    {
        for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
        {
            if (index >= nvals)
            {
                std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                exit(-1);
            }
            values[index] = static_cast<T>(1);
            col_indices[index++] = i;
        }
    }
}

/**
 * @brief Read the matrix data from the.wsg file and store it in three arrays in COO format. The elements are arranged in col-first order (order in CSC format) .
 * @attention After calling this function, be careful to free up the values, row_indices and col_indices space to avoid memory leaks.
 *
 * @tparam T The datatype of values of Matrix.
 * @param[in] full_path The full path of the file to be read.
 * @param[out] values The values array of COO.
 * @param[out] row_indices The row_indices array of COO.
 * @param[out] col_indices The col_indices array of COO.
 * @param[out] nrows The number of rows.
 * @param[out] ncols The number of cols.
 * @param[out] nvals The number of non-zero values.
 */
template <typename T>
void Read_CSC_Matrix_WSG(
    const std::string full_path,
    T *&values,
    perfSpB_index *&row_indices,
    perfSpB_index *&col_indices,
    perfSpB_index &nrows,
    perfSpB_index &ncols,
    perfSpB_index &nvals)
{
    if (!std::is_same<T, int32_t>::value)
    {
        std::cout << "Read_CSC_Matrix_WSG only can read the int32_t weight." << std::endl;
        std::exit(-1);
    }

    // Read input graph from a .wsg file.
    Builder<perfSpB_index, NodeWeight<perfSpB_index, T>, T> builder(full_path);
    CSRGraph<perfSpB_index, NodeWeight<perfSpB_index, T>> g = builder.MakeGraph();

    nrows = static_cast<perfSpB_index>(g.num_nodes());
    ncols = static_cast<perfSpB_index>(g.num_nodes());
    nvals = static_cast<perfSpB_index>(g.num_edges());

    CHECK_NULLPTR(values);
    CHECK_NULLPTR(row_indices);
    CHECK_NULLPTR(col_indices);

    values = new T[nvals];
    row_indices = new perfSpB_index[nvals];
    col_indices = new perfSpB_index[nvals];
    perfSpB_index *offsets = g.in_offsets();
    perfSpB_index index = 0;
    for (perfSpB_index i = 0; i < ncols; i++)
    {
        for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
        {
            if (index >= nvals)
            {
                std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                exit(-1);
            }
            row_indices[index] = g.in_destValues()[index].v;
            values[index] = g.in_destValues()[index].w;
            col_indices[index++] = i;
        }
    }
}

/**
 * @}
 */