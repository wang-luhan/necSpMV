#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"

#define PerfSpB_VECTOR_EXTRACT_CPP(type, T)                                    \
    perfSpB_info perfSpB_vector_extract_element(type *x, const perfSpB_vector v, perfSpB_index i) \
    {                                                                      \
        return perfSpB_vector_extract_element_##T(x, v, i);                     \
    }

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

#define PerfSpB_VECTOR_EXTRACT_TUPLES_CPP(type, T)                                    \
    perfSpB_info perfSpB_vector_extract_tuples(perfSpB_index *I, type * X, perfSpB_index *p_nvals, const perfSpB_vector v) \
    {                                                                      \
        return perfSpB_vector_extract_tuples_##T(I, X, p_nvals, v);                     \
    }

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

#define PerfSpB_VECTOR_SET_CPP(type, T)                                   \
    perfSpB_info perfSpB_vector_set_element(perfSpB_vector v, type x, perfSpB_index i) \
    {                                                                 \
        return perfSpB_vector_set_element_##T(v, x, i);                    \
    }

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