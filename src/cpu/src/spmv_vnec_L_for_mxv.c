#include "spmv_cpu_common.h"

struct VNEC_L *Build_VNEC_L(const perfSpB_matrix A)
{
    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(A);
    perfSpB_index nrows = A->row;
    perfSpB_index nvals = a->nnz;
    VNEC_L *mat_thd = (VNEC_L *)malloc(sizeof(VNEC_L));
    if (mat_thd != NULL)
    {
        mat_thd->num_merge_items = nvals + nrows;
        mat_thd->items_per_thread = (mat_thd->num_merge_items + NUM_THREADS - 1) / NUM_THREADS;
        mat_thd->nz_indices = (int *)malloc((nvals) * sizeof(int));
        mat_thd->diagonal_start = (int *)malloc((NUM_THREADS) * sizeof(int));
        mat_thd->diagonal_end = (int *)malloc((NUM_THREADS) * sizeof(int));
        mat_thd->thread_coord_start = (perfSpB_coord *)malloc((NUM_THREADS) * sizeof(perfSpB_coord));
        mat_thd->thread_coord_end = (perfSpB_coord *)malloc((NUM_THREADS) * sizeof(perfSpB_coord));
    }
    else
    {
        fprintf(stderr, "Memory allocation failure!\n");
        exit(EXIT_FAILURE);
    }
    for (perfSpB_index i = 0; i < nvals; i++)
    {
        mat_thd->nz_indices[i] = i;
    }
    for (int tid = 0; tid < NUM_THREADS; tid++)
    {
        mat_thd->diagonal_start[tid] = min(mat_thd->items_per_thread * tid, mat_thd->num_merge_items);
        mat_thd->diagonal_end[tid] = min(mat_thd->diagonal_start[tid] + mat_thd->items_per_thread, mat_thd->num_merge_items);
        MergePathDivide(mat_thd->diagonal_start[tid], (a->ptr + 1), mat_thd->nz_indices, nrows, nvals, mat_thd->thread_coord_start + tid);
        MergePathDivide(mat_thd->diagonal_end[tid], (a->ptr + 1), mat_thd->nz_indices, nrows, nvals, mat_thd->thread_coord_end + tid);
    }
    return mat_thd;
}
void SpMV_VNEC_L_FP32(perfSpB_vector y, const perfSpB_matrix A, const perfSpB_vector x, VNEC_L *mat_thd)
{
    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(A);
    perfSpB_vector_Dense *yy = (perfSpB_vector_Dense *)(y);
    perfSpB_vector_Dense *xx = (perfSpB_vector_Dense *)(x);
    perfSpB_index *row_end_offsets = a->ptr + 1; // Merge list A
    // int nz_indices[a->nnz];           // Merge list B
    int row_carry_out[256];
    float value_carry_out[256];
#pragma omp parallel for schedule(static) num_threads(NUM_THREADS)
    for (int tid = 0; tid < NUM_THREADS; tid++)
    {
        perfSpB_coord thread_coord_start = mat_thd->thread_coord_start[tid];
        perfSpB_coord thread_coord_end = mat_thd->thread_coord_end[tid];
        for (; thread_coord_start.x < thread_coord_end.x; ++thread_coord_start.x)
        {
            float running_total = 0.0;
#ifdef ARM_NEON
            float32x4_t v_running_total = {0.0, 0.0, 0.0, 0.0};
            for (; thread_coord_start.y < (int)row_end_offsets[thread_coord_start.x] - 4; thread_coord_start.y += 4)
            {
                float32x4_t v_xtmp;
                float32x4_t v_atmp = vld1q_f32((float *)a->val + thread_coord_start.y);
                v_xtmp[0] = ((float *)xx->values)[a->indices[thread_coord_start.y + 0]];
                v_xtmp[1] = ((float *)xx->values)[a->indices[thread_coord_start.y + 1]];
                v_xtmp[2] = ((float *)xx->values)[a->indices[thread_coord_start.y + 2]];
                v_xtmp[3] = ((float *)xx->values)[a->indices[thread_coord_start.y + 3]];
                v_running_total = vmlaq_f32(v_running_total, v_xtmp, v_atmp);
            } // End of this line
            running_total = vaddvq_f32(v_running_total);
#endif
#ifdef X86_SIMD
            __m512 v_running_total = _mm512_setzero_ps();
            int loop_end = (int)row_end_offsets[thread_coord_start.x] - 16;
            for (; thread_coord_start.y < loop_end; thread_coord_start.y += 16)
            {
                __m512i v_indices = _mm512_set_epi32(
                    (int)a->indices[thread_coord_start.y + 15],
                    (int)a->indices[thread_coord_start.y + 14],
                    (int)a->indices[thread_coord_start.y + 13],
                    (int)a->indices[thread_coord_start.y + 12],
                    (int)a->indices[thread_coord_start.y + 11],
                    (int)a->indices[thread_coord_start.y + 10],
                    (int)a->indices[thread_coord_start.y + 9],
                    (int)a->indices[thread_coord_start.y + 8],
                    (int)a->indices[thread_coord_start.y + 7],
                    (int)a->indices[thread_coord_start.y + 6],
                    (int)a->indices[thread_coord_start.y + 5],
                    (int)a->indices[thread_coord_start.y + 4],
                    (int)a->indices[thread_coord_start.y + 3],
                    (int)a->indices[thread_coord_start.y + 2],
                    (int)a->indices[thread_coord_start.y + 1],
                    (int)a->indices[thread_coord_start.y + 0]);
                __m512 v_xtmp = _mm512_i32gather_ps(v_indices, (float *)xx->values, 4);

                __m512 v_atmp = _mm512_loadu_ps((float *)(a->val) + thread_coord_start.y);
                v_running_total = _mm512_fmadd_ps(v_xtmp, v_atmp, v_running_total);
            }
            running_total = _mm512_reduce_add_ps(v_running_total);
#endif
            for (; thread_coord_start.y < (int)row_end_offsets[thread_coord_start.x]; ++thread_coord_start.y)
            {
                running_total += ((float *)a->val)[thread_coord_start.y] * ((float *)xx->values)[a->indices[thread_coord_start.y]];
            } // End of this line

            ((float *)yy->values)[thread_coord_start.x] = running_total;
        }

        //  finish one row, calculate the partial sum of the next row
        //  Consume partial portion of thread's last row (accumulate any nonzeros for a partial row shared with the next thread)
        float running_total = 0.0;
        for (; thread_coord_start.y < thread_coord_end.y; ++thread_coord_start.y) // 4 5
        {
            running_total += ((float *)a->val)[thread_coord_start.y] * ((float *)xx->values)[a->indices[thread_coord_start.y]];
        }
        // save the thread's running total and row-id for subsequent fix-up
        row_carry_out[tid] = thread_coord_end.x; // The value of this row is incomplete
        value_carry_out[tid] = running_total;    // This row would be a little bit more complete with this. Each thread might have one of these
    }
// update the values in y for rows that span multiple threads
#pragma omp parallel for schedule(static) num_threads(NUM_THREADS)
    for (int tid = 0; tid < NUM_THREADS - 1; ++tid)
    {
        // if (row_carry_out[tid] < (int)y->n)
        ((float *)yy->values)[row_carry_out[tid]] += value_carry_out[tid];
    }
}

void SpMV_VNEC_L_FP64(perfSpB_vector y, const perfSpB_matrix A, const perfSpB_vector x, VNEC_L *mat_thd)
{
    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(A);
    perfSpB_vector_Dense *yy = (perfSpB_vector_Dense *)(y);
    perfSpB_vector_Dense *xx = (perfSpB_vector_Dense *)(x);
    perfSpB_index *row_end_offsets = a->ptr + 1; // Merge list A
    // int nz_indices[a->nnz];           // Merge list B
    int row_carry_out[256];
    double value_carry_out[256];
#pragma omp parallel for schedule(static) num_threads(NUM_THREADS)
    for (int tid = 0; tid < NUM_THREADS; tid++)
    {
        perfSpB_coord thread_coord_start = mat_thd->thread_coord_start[tid];
        perfSpB_coord thread_coord_end = mat_thd->thread_coord_end[tid];
        for (; thread_coord_start.x < thread_coord_end.x; ++thread_coord_start.x)
        {
            double running_total = 0.0;
            for (; thread_coord_start.y < (int)row_end_offsets[thread_coord_start.x]; ++thread_coord_start.y)
            {
                running_total += ((double *)a->val)[thread_coord_start.y] * ((double *)xx->values)[a->indices[thread_coord_start.y]];
            } // End of this line
            ((double *)yy->values)[thread_coord_start.x] = running_total;
        }

        //  finish one row, calculate the partial sum of the next row
        //  Consume partial portion of thread's last row (accumulate any nonzeros for a partial row shared with the next thread)
        double running_total = 0.0;
        for (; thread_coord_start.y < thread_coord_end.y; ++thread_coord_start.y) // 4 5
        {
            running_total += ((double *)a->val)[thread_coord_start.y] * ((double *)xx->values)[a->indices[thread_coord_start.y]];
        }
        // save the thread's running total and row-id for subsequent fix-up
        row_carry_out[tid] = thread_coord_end.x; // The value of this row is incomplete
        value_carry_out[tid] = running_total;    // This row would be a little bit more complete with this. Each thread might have one of these
    }
// update the values in y for rows that span multiple threads
#pragma omp parallel for schedule(static) num_threads(NUM_THREADS)
    for (int tid = 0; tid < NUM_THREADS - 1; ++tid)
    {
        ((double *)yy->values)[row_carry_out[tid]] += value_carry_out[tid];
    }
}
