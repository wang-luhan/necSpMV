// #include <iostream>
// #include <fstream>
// #include <algorithm>
// #include <vector>
// #include <math.h>

// using namespace std;

// struct CSR
// {
//     vector<float> val;
//     vector<int64_t> col_ind;
//     vector<int64_t> row_ptr;
//     int64_t nnzs, cols, rows;
// };

// void printArray(vector<int64_t> v)
// {
//     for (int64_t i = 0; i < (int64_t)v.size(); i++)
//         cout << v[i] << ' ';
//     cout << '\n';
// }

// void printArray(vector<float> v)
// {
//     for (int64_t i = 0; i < (int64_t)v.size(); i++)
//         cout << v[i] << ' ';
//     cout << '\n';
// }

// void printMatrix(CSR csr)
// {

//     int64_t cont = 0;
//     for (int64_t i = 1; i < (int64_t)csr.row_ptr.size(); i++)
//     {
//         int64_t row_start = csr.row_ptr[i - 1] - 1;
//         int64_t row_end = csr.row_ptr[i] - 1;
//         vector<int64_t>::const_iterator first = csr.col_ind.begin() + row_start;
//         vector<int64_t>::const_iterator last = csr.col_ind.begin() + row_end;
//         vector<int64_t> row(first, last);
//         for (int64_t j = 1; j < (int64_t)csr.row_ptr.size(); j++)
//         {
//             if (std::count(row.begin(), row.end(), j) == 0)
//                 cout << '0' << ' ';
//             else
//             {
//                 cout << csr.val[cont] << ' ';
//                 cont++;
//             }
//         }
//         std::cout << std::endl;
//     }
// }

// int64_t getDegree(vector<int64_t> row_ptr, int64_t vertex)
// {
//     return row_ptr[vertex] - row_ptr[vertex - 1];
// }

// vector<int64_t> getAdjVertices(vector<int64_t> col_ind, vector<int64_t> row_ptr, int64_t vertex)
// {
//     int64_t row_start = row_ptr[vertex - 1];
//     int64_t row_end = row_ptr[vertex];
//     vector<int64_t>::const_iterator first = col_ind.begin() + row_start;
//     vector<int64_t>::const_iterator last = col_ind.begin() + row_end;
//     vector<int64_t> adjVertices(first, last);
//     return adjVertices;
// }

// int64_t getBandwidth(CSR csr)
// {
//     int64_t bandwidth = std::numeric_limits<int64_t>::min();
//     for (int64_t i = 1; i < (int64_t)csr.row_ptr.size() - 1; i++)
//     { // i = current row id
//         int64_t row_start = csr.row_ptr[i - 1];
//         int64_t row_end = csr.row_ptr[i];
//         if (row_end - row_start == 1)
//             continue;
//         for (int64_t j = row_start; j < row_end; j++)
//         {
//             if (abs(csr.col_ind[j] - i) > bandwidth)
//             {
//                 bandwidth = abs(csr.col_ind[j] - i);
//             }
//         }
//     }
//     return bandwidth;
// }

// CSR assemble_csr_matrix(std::string filePath)
// {
//     int64_t M, N, L;
//     CSR matrix;
//     std::ifstream fin(filePath);
//     // Ignore headers and comments:
//     while (fin.peek() == '%')
//         fin.ignore(2048, '\n');
//     // Read defining parameters:
//     fin >> M >> N >> L;
//     matrix.rows = M;
//     matrix.cols = N;
//     matrix.nnzs = L;
//     printf("nrows = %ld", matrix.rows);
//     printf("ncols = %ld", matrix.cols);
//     printf("nvals = %ld", matrix.nnzs);
    
//     int64_t last_row = 1;
//     matrix.row_ptr.push_back(1);
//     for (int64_t l = 0; l < L; l++)
//     {
//         int64_t row, col;
//         float data = 6.6;
//         fin >> row >> col;
//         matrix.col_ind.push_back(col);
//         matrix.val.push_back(data);
//         if (row > last_row)
//         {
//             last_row = row;
//             matrix.row_ptr.push_back(matrix.col_ind.size());
//         }
//     }
//     matrix.row_ptr.push_back(matrix.col_ind.size() + 1);
//     fin.close();
//     return matrix;
// }

// CSR assemble_simetric_csr_matrix(std::string filePath)
// {
//     int64_t M, N, L;
//     vector<int64_t> rows, cols;
//     vector<float> data;
//     CSR matrix;
//     std::ifstream fin(filePath);
//     // Ignore headers and comments:
//     while (fin.peek() == '%')
//         fin.ignore(2048, '\n');
//     // Read defining parameters:
//     fin >> M >> N >> L;
//     matrix.row_ptr.push_back(0);
//     for (int64_t l = 0; l < L; l++)
//     {
//         int64_t row, col;
//         float d;
//         fin >> row >> col >> d;
//         rows.push_back(row);
//         cols.push_back(col);
//         data.push_back(d);
//     }
//     fin.close();
//     for (int64_t l = 1; l <= M; l++)
//     {
//         for (int64_t k = 0; k < L; k++)
//         {
//             if (cols[k] == l)
//             {
//                 matrix.col_ind.push_back(rows[k]);
//                 matrix.val.push_back(data[k]);
//             }
//             else if (rows[k] == l)
//             {
//                 matrix.col_ind.push_back(cols[k]);
//                 matrix.val.push_back(data[k]);
//             }
//         }
//         matrix.row_ptr.push_back(matrix.col_ind.size());
//     }

//     matrix.row_ptr.push_back(matrix.col_ind.size() + 1);

//     return matrix;
// }
