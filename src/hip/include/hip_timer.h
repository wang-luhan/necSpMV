#pragma once

#include <cassert>
#include <cstdio>
#include <climits>
#include <cfloat>

static hipEvent_t start, stop;
static float elapsedTime;

static void hip_time_test_start()
{
    hipEventCreate(&start);
    hipEventCreate(&stop);
    hipEventRecord(start, 0);
    hipEventQuery(start);
}

static void hip_time_test_end()
{
    hipEventRecord(stop, 0);
    hipEventSynchronize(stop);
    hipEventElapsedTime(&elapsedTime, start, stop);
    hipEventDestroy(start);
    hipEventDestroy(stop);
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
