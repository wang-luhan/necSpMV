#pragma once

#include <cassert>
#include <cstdio>
#include <climits>
#include <cfloat>

static cudaEvent_t start, stop;
static float elapsedTime;

static void cuda_time_test_start()
{
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start, 0);
    cudaEventQuery(start);
}

static void cuda_time_test_end()
{
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&elapsedTime, start, stop);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
}
/*
static void output_bandWidth_info(const long mem_size, const char *kernel_name)
{
    double bandwidth = (double)((mem_size) / (elapsedTime / 1000) / 1024 / 1024 / 1024);
    printf("perfcv %s: %10.6f ms \t bandwidth : %15.6lf GB/s\n", kernel_name, elapsedTime, bandwidth);
}
*/
// static double getElapsedTime()
// {
//     return (elapsedTime / 1000);
// }
