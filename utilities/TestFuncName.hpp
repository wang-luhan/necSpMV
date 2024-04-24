#pragma once
#include "GrB_vxm.h"

template <void (*TestFunc)(GrB_Vector, GrB_Vector, GrB_Vector, GrB_Matrix)>
struct TestFuncName{
    static const std::string value() { return "Unknown_function"; }
};

template <>
struct TestFuncName<MaskedSpMV4vxm_naive_CUDA_PLUS_TIMES_FP64> {
    static const std::string value() { return "Cuda_Masked_SpMV"; }
};

template <>
struct TestFuncName<MaskedSpMV4vxm_naive_CUDA_PLUS_TIMES_FP64_v2> {
    static const std::string value() { return "Cuda_Masked_SpMV_v2"; }
};

template <>
struct TestFuncName<SpMaskedSpMV4vxm_naive_CUDA_PLUS_TIMES_FP64> {
    static const std::string value() { return "Cuda_SpMasked_SpMV"; }
};

template <>
struct TestFuncName<SpMV4vxm_naive_CUDA_PLUS_TIMES_FP64> {
    static const std::string value() { return "Cuda_SpMV"; }
};

template <>
struct TestFuncName<MaskedSpMSpV4vxm_naive_CUDA_PLUS_TIMES_FP64> {
    static const std::string value() { return "Cuda_Masked_SpMSpV"; }
};

template <>
struct TestFuncName<SpMSpV4vxm_naive_CUDA_PLUS_TIMES_FP64> {
    static const std::string value() { return "Cuda_SpMSpV"; }
};

template <void (*TestFunc)(GrB_Vector, GrB_Vector, GrB_Vector, GrB_Matrix)>
std::string getTestFuncName() {
    return TestFuncName<TestFunc>::value();
}