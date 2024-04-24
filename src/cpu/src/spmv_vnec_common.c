#include "spmv_cpu_common.h"

void MergePathDivide(
    int diagonal,
    perfSpB_index *a,
    int *b,
    int a_len,
    int b_len,
    perfSpB_coord *path_coordinate)
{
    // Diagonal search range (in x coordinate space)
    int x_min = max(diagonal - b_len, 0);
    int x_max = min(diagonal, a_len);
    // printf("\n x_min = %d and x_max = %d \n", x_min, x_max);

    // 2D binary-search along the diagonal search range
    while (x_min < x_max)
    {
        int pivot = (x_min + x_max) >> 1;
        if ((int)a[pivot] <= b[diagonal - pivot - 1])
        {
            // Keep top-right half of diagonal range
            x_min = pivot + 1;
        }
        else
        {
            // Keep bottom-left half of diagonal range
            x_max = pivot;
        }
    }
    path_coordinate->x = min(x_min, a_len);
    path_coordinate->y = diagonal - x_min;
}
