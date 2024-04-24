#pragma once
#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"

template <typename T>
class VectorGenerator
{

private:
    bool isComplement_;
    size_t vector_size_;
    std::vector<T> values_x_;
    std::vector<size_t> idxs_x_;
    std::vector<size_t> shuffle_idxs_x_;

    void generate_a_random_index()
    {
#pragma omp parallel for
        for (size_t i = 0; i < vector_size_; ++i)
        {
            idxs_x_[i] = ((size_t)i);
            shuffle_idxs_x_[i] = ((size_t)i);
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(shuffle_idxs_x_.begin(), shuffle_idxs_x_.end(), g);
    }

    GrB_Vector Build_Dense_Vector(
        const perfSpB_index *idx_x_,
        const T *values_x_,
        const perfSpB_index x_nnz) const
    {
        GrB_Vector x;
        if constexpr (std::is_same<T, int32_t>::value)
        {
            GrB_Vector_new_format_ext(&x, GrB_INT32, vector_size_, GrB_DENSE);
            GrB_Vector_build_INT32(x, idx_x_, values_x_, x_nnz, GrB_BINARYOP_NULL);
        }
        else if constexpr (std::is_same<T, double>::value)
        {
            GrB_Vector_new_format_ext(&x, GrB_FP64, vector_size_, GrB_DENSE);
            GrB_Vector_build_FP64(x, idx_x_, values_x_, x_nnz, GrB_BINARYOP_NULL);
        }
        else
        {
            throw std::invalid_argument("Unsupported type for Build_sparse_vector");
        }
        return x;
    }

    GrB_Vector Build_Sparse_Vector(
        const perfSpB_index *idx_x_,
        const T *values_x_,
        const perfSpB_index x_nnz) const
    {
        GrB_Vector x;
        if constexpr (std::is_same<T, int32_t>::value)
        {
            GrB_Vector_new_format_ext(&x, GrB_INT32, vector_size_, GrB_SPARSE);
            GrB_Vector_build_INT32(x, idx_x_, values_x_, x_nnz, GrB_BINARYOP_NULL);
        }
        else if constexpr (std::is_same<T, double>::value)
        {
            GrB_Vector_new_format_ext(&x, GrB_FP64, vector_size_, GrB_SPARSE);
            GrB_Vector_build_FP64(x, idx_x_, values_x_, x_nnz, GrB_BINARYOP_NULL);
        }
        else
        {
            throw std::invalid_argument("Unsupported type for Build_sparse_vector");
        }
        return x;
    }

public:
    VectorGenerator(size_t size, bool isComplement)
        : isComplement_(isComplement), vector_size_(size), values_x_(size), idxs_x_(size), shuffle_idxs_x_(size)
    {
#pragma omp parallel for
        for (size_t i = 0; i < size; i++)
        {
            values_x_[i] = generate_random_number<T>();
        }
        generate_a_random_index();
    }

    GrB_Vector Get_Sparse_Vector(double density) const
    {
        size_t x_nnz_ = 0;
        if (isComplement_)
        {
            x_nnz_ = (1.0 - density) * vector_size_;
        }
        else
        {
            x_nnz_ = density * vector_size_;
        }

        GrB_Vector ret;
        if (x_nnz_ < vector_size_)
        {
            std::vector<size_t> seg_idxs_x_(shuffle_idxs_x_.begin(), shuffle_idxs_x_.begin() + x_nnz_);
            std::sort(seg_idxs_x_.begin(), seg_idxs_x_.end());
            ret = Build_Sparse_Vector(seg_idxs_x_.data(), values_x_.data(), x_nnz_);
        }
        else
        {
            ret = Build_Sparse_Vector(idxs_x_.data(), values_x_.data(), x_nnz_);
        }
        return ret;
    }

    GrB_Vector Get_Dense_Vector(double density) const
    {
        size_t x_nnz_ = 0;
        if (isComplement_)
        {
            x_nnz_ = (1.0 - density) * vector_size_;
        }
        else
        {
            x_nnz_ = density * vector_size_;
        }

        GrB_Vector ret;
        if (x_nnz_ < vector_size_)
        {
            std::vector<size_t> seg_idxs_x_(shuffle_idxs_x_.begin(), shuffle_idxs_x_.begin() + x_nnz_);
            std::sort(seg_idxs_x_.begin(), seg_idxs_x_.end());
            ret = Build_Dense_Vector(seg_idxs_x_.data(), values_x_.data(), x_nnz_);
        }
        else
        {
            ret = Build_Dense_Vector(idxs_x_.data(), values_x_.data(), x_nnz_);
        }
        return ret;
    }
};