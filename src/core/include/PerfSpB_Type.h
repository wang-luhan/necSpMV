#pragma once

#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include <stdlib.h>

#define PerfSpB_TYPE_CASE(type, object, SIZE) \
    case (type):                          \
        (*object)->element_size = SIZE;           \
        break;

#define PerfSpB_TYPE_CASES(object)            \
    PerfSpB_TYPE_CASE(perfSpB_BOOL, object, 1);   \
    PerfSpB_TYPE_CASE(perfSpB_INT8, object, 1);   \
    PerfSpB_TYPE_CASE(perfSpB_INT16, object, 2);  \
    PerfSpB_TYPE_CASE(perfSpB_INT32, object, 4);  \
    PerfSpB_TYPE_CASE(perfSpB_INT64, object, 8);  \
    PerfSpB_TYPE_CASE(perfSpB_UINT8, object, 1);  \
    PerfSpB_TYPE_CASE(perfSpB_UINT16, object, 2); \
    PerfSpB_TYPE_CASE(perfSpB_UINT32, object, 4); \
    PerfSpB_TYPE_CASE(perfSpB_UINT64, object, 8); \
    PerfSpB_TYPE_CASE(perfSpB_FP32, object, 4);   \
    PerfSpB_TYPE_CASE(perfSpB_FP64, object, 8);   \
    default:                              \
        return perfSpB_failure;

#define ZERO_BOOL false
#define ZERO_INT8 0
#define ZERO_INT16 0
#define ZERO_INT32 0
#define ZERO_INT64 0
#define ZERO_UINT8 0
#define ZERO_UINT16 0
#define ZERO_UINT32 0
#define ZERO_UINT64 0
#define ZERO_FP32 0.0f
#define ZERO_FP64 0.0f

#define ZERO_bool false
#define ZERO_int8_t 0
#define ZERO_int16_t 0
#define ZERO_int32_t 0
#define ZERO_int64_t 0
#define ZERO_uint8_t 0
#define ZERO_uint16_t 0
#define ZERO_uint32_t 0
#define ZERO_uint64_t 0
#define ZERO_float 0.0f
#define ZERO_double 0.0f