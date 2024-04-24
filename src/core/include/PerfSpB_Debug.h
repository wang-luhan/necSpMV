#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"

#ifdef __cplusplus
extern "C"
{
#endif
    void print_Vector_BOOL(perfSpB_vector v);
    void print_Vector_INT32(perfSpB_vector v);
    void print_Vector_FP32(perfSpB_vector v);
    void print_Matrix_INT32(perfSpB_matrix m);
    void print_Matrix_FP32(perfSpB_matrix m);
    void print_Matrix_BOOL(perfSpB_matrix m);
#ifdef __cplusplus
}
#endif

#include <stdlib.h>
#define SAFE_CALL(method)    \
    info = method;           \
    if (info != perfSpB_success) \
    {                        \
        exit(9);             \
    }


#define CHECK_CUDA(func)                                               \
    {                                                                  \
        cudaError_t status = (func);                                   \
        if (status != cudaSuccess)                                     \
        {                                                              \
            printf("CUDA API failed at line %d with error: %s (%d)\n", \
                   __LINE__, cudaGetErrorString(status), status);      \
            return EXIT_FAILURE;                                       \
        }                                                              \
    }
