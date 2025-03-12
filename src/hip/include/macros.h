#include <bits/stdc++.h>
#include <hip/hip_runtime.h>
#include "device_launch_parameters.h"
#include <time.h>
#include <sys/time.h>
#include <hip/hip_runtime_api.h>
#include <hipsparse.h>
#define checkCudaErrors(func)                                                      \
    {                                                                              \
        hipError_t e = (func);                                                    \
        if (e != hipSuccess)                                                      \
            printf("%s %d CUDA: %s\n", __FILE__, __LINE__, hipGetErrorString(e)); \
    }

#define CHECK_CUDA(func)                                               \
    {                                                                  \
        hipError_t status = (func);                                   \
        if (status != hipSuccess)                                     \
        {                                                              \
            printf("CUDA API failed at line %d with error: %s (%d)\n", \
                   __LINE__, hipGetErrorString(status), status);      \
            return EXIT_FAILURE;                                       \
        }                                                              \
    }