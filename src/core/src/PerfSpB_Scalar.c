#include "PerfSpB_Alloc.h"
#include "PerfSpB_Type.h"
#include "PerfSpB_Scalar.h"
#include "PerfSpB_Error.h"

perfSpB_info perfSpB_scalar_new(
    perfSpB_scalar *scalar,
    perfSpB_type d)
{
    *scalar = (struct perfSpB_scalar_opaque *)
        PerfSpB_aligned_malloc(
            sizeof(struct perfSpB_scalar_opaque));
    if (*scalar == NULL)
    {
        return perfSpB_failure;
    }
    (*scalar)->element_type = d;
    return perfSpB_success;
}

perfSpB_info perfSpB_scalar_free(perfSpB_scalar *scalar)
{
    if (*scalar == NULL)
    {
        return perfSpB_failure;
    }
    else
    {
        free(*scalar);
        return perfSpB_success;
    }
}

#define CASE_SETZERO(type, T)          \
    case perfSpB_##T:                      \
        s->value.T##_value = ZERO_##T; \
        break;

#define CASES_SETZERO               \
    CASE_SETZERO(bool, BOOL);       \
    CASE_SETZERO(int8_t, INT8);     \
    CASE_SETZERO(int16_t, INT16);   \
    CASE_SETZERO(int32_t, INT32);   \
    CASE_SETZERO(int64_t, INT64);   \
    CASE_SETZERO(uint8_t, UINT8);   \
    CASE_SETZERO(uint16_t, UINT16); \
    CASE_SETZERO(uint32_t, UINT32); \
    CASE_SETZERO(uint64_t, UINT64); \
    CASE_SETZERO(float, FP32);      \
    CASE_SETZERO(double, FP64);

perfSpB_info perfSpB_scalar_setZero(perfSpB_scalar s)
{
    switch (s->element_type)
    {
        CASES_SETZERO;

    default:
        PerfSpB_Error("Unknown element type \
in the perfSpB_scalar_setZero!\n",
                  __FILE__, __LINE__);
        break;
    }
    return perfSpB_success;
}
#undef CASES_SETZERO
#undef CASE_SETZERO
