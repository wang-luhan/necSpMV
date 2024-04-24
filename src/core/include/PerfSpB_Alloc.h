#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

#define PerfSpB_MALLOC_ALIGN 64

#define OK_ALLOC(info) \
    if (!(info))       \
        return perfSpB_failure;

#include <stddef.h>

    void *PerfSpB_aligned_malloc(size_t size);

    void *PerfSpB_aligned_calloc(size_t size);

    void *PerfSpB_aligned_realloc(void *ptr, size_t size);
#ifdef __cplusplus
}
#endif
