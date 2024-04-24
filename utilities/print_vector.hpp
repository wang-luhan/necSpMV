#include <iostream>

template <typename T>
void print_Vector(const GrB_Vector v)
{
    std::cout << "================================" << std::endl;
    perfSpB_index n;
    GrB_Vector_size(&n, v);
    T value;
    printf("The vector size is %lu\n", n);
    printf("The vector elements : \n");
    for (perfSpB_index i = 0; i < n; ++i)
    {
        value = static_cast<T>(0);
        GrB_Vector_extractElement(&value, v, i);
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "================================\n"
              << std::endl;
}

template <typename T>
void print_Matrix(const GrB_Matrix m)
{
    perfSpB_index n_row, n_col;
    GrB_Matrix_nrows(&n_row, m);
    GrB_Matrix_ncols(&n_col, m);
    std::cout << "================================"<<std::endl;
    std::cout << "The Matrix size is: "<<n_row<<"x"<<n_col<<std::endl;
    std::cout<<"The matrix elements:"<<std::endl;
    for (perfSpB_index i = 0; i < n_row; ++i)
    {
        for (perfSpB_index j = 0; j < n_col; ++j)
        {
            T value = static_cast<T>(0);
           GrB_Matrix_extractElement(&value, m, i, j);
            std::cout<<value<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"================================"<<std::endl;
}