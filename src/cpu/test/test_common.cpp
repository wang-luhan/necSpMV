#include "test_spmv_vnec.hpp"

void PerfSpB_mxv_FP32_serial(perfSpB_vector w, const perfSpB_matrix A, const perfSpB_vector u)
{
    perfSpB_vector_Dense *ww = (perfSpB_vector_Dense *)(w);
    perfSpB_vector_Dense *uu = (perfSpB_vector_Dense *)(u);

    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(A);
    float t1, t2, t3;
    for (perfSpB_index i = 0; i < w->n; i++)
    {
        t1 = 0.0f;
        perfSpB_index ptr_start = a->ptr[i];
        perfSpB_index n_one_line = a->ptr[i + 1] - ptr_start;
        for (perfSpB_index j = 0; j < n_one_line; j++)
        {
            t2 = ((float *)a->val)[j + ptr_start];
            t3 = 0.0f;
            perfSpB_index v_idx = a->indices[j + ptr_start];
            t3 = ((float *)uu->values)[v_idx];
            t1 += t2 * t3;
        }
        ((float *)ww->values)[i] = t1;
    }
}
void PerfSpB_mxv_FP64_serial(perfSpB_vector w, const perfSpB_matrix A, const perfSpB_vector u)
{
    perfSpB_vector_Dense *ww = (perfSpB_vector_Dense *)(w);
    perfSpB_vector_Dense *uu = (perfSpB_vector_Dense *)(u);

    perfSpB_matrix_CSC_or_CSR *a = (perfSpB_matrix_CSC_or_CSR *)(A);
    double t1, t2, t3;
    for (perfSpB_index i = 0; i < w->n; i++)
    {
        t1 = 0.0f;
        perfSpB_index ptr_start = a->ptr[i];
        perfSpB_index n_one_line = a->ptr[i + 1] - ptr_start;
        for (perfSpB_index j = 0; j < n_one_line; j++)
        {
            t2 = ((double *)a->val)[j + ptr_start];
            t3 = 0.0f;
            perfSpB_index v_idx = a->indices[j + ptr_start];
            t3 = ((double *)uu->values)[v_idx];
            t1 += t2 * t3;
        }
        ((double *)ww->values)[i] = t1;
    }
}

void VNEC_D_free_fp32(VNEC_D_FP32 *mat_thd)
{
    free(mat_thd->thread_coord_start);
    free(mat_thd->thread_coord_end);
    free(mat_thd->ecr_indices);
    free(mat_thd->NEC_NUM);
    for (int i = 0; i < NUM_THREADS; i++)
    {
        free(mat_thd->use_x_indices[i]);
#ifdef X86_SIMD
        _mm_free(mat_thd->ecr_xx_val[i]);
#else
        free(mat_thd->ecr_xx_val[i]);
#endif
    }
    free(mat_thd->use_x_indices);
    free(mat_thd->ecr_xx_val);
    free(mat_thd->col_start);
    free(mat_thd->v_row_ptr);
#ifdef X86_SIMD
    _mm_free(mat_thd->val_align);
#else
    free(mat_thd->val_align);
#endif
    free(mat_thd);
}
void VNEC_S_free_fp32(VNEC_S_FP32 *mat_thd)
{
    free(mat_thd->NEC_NUM);
    free(mat_thd->spvv16_len);
    for (int i = 0; i < NUM_THREADS; i++)
    {
        free(mat_thd->use_x_indices[i]);
        free(mat_thd->ecr_xx_val[i]);
        free(mat_thd->tasks[i]);
    }
    free(mat_thd->use_x_indices);
    free(mat_thd->ecr_xx_val);
    free(mat_thd->tasks);
    free(mat_thd->reorder_mat.nnz);
    free(mat_thd->reorder_mat.col);
    free(mat_thd->reorder_mat.row_begin);
    free(mat_thd->reorder_mat.row_end);
    free(mat_thd->reorder_mat.task_start);
    free(mat_thd->reorder_mat.task_end);
    free(mat_thd);
}

void VNEC_D_free_fp64(VNEC_D_FP64 *mat_thd)
{
    free(mat_thd->thread_coord_start);
    free(mat_thd->thread_coord_end);
    free(mat_thd->ecr_indices);
    free(mat_thd->NEC_NUM);
    for (int i = 0; i < NUM_THREADS; i++)
    {
        free(mat_thd->use_x_indices[i]);
#ifdef X86_SIMD
        _mm_free(mat_thd->ecr_xx_val[i]);
#else
        free(mat_thd->ecr_xx_val[i]);
#endif
    }
    free(mat_thd->use_x_indices);
    free(mat_thd->ecr_xx_val);
    free(mat_thd->col_start);
    free(mat_thd->v_row_ptr);
#ifdef X86_SIMD
    _mm_free(mat_thd->val_align);
#else
    free(mat_thd->val_align);
#endif
    free(mat_thd);
}
void VNEC_S_free_fp64(VNEC_S_FP64 *mat_thd)
{
    free(mat_thd->NEC_NUM);
    free(mat_thd->spvv8_len);
    for (int i = 0; i < NUM_THREADS; i++)
    {
        free(mat_thd->use_x_indices[i]);
        free(mat_thd->ecr_xx_val[i]);
        free(mat_thd->tasks[i]);
    }
    free(mat_thd->use_x_indices);
    free(mat_thd->ecr_xx_val);
    free(mat_thd->tasks);
    free(mat_thd->reorder_mat.nnz);
    free(mat_thd->reorder_mat.col);
    free(mat_thd->reorder_mat.row_begin);
    free(mat_thd->reorder_mat.row_end);
    free(mat_thd->reorder_mat.task_start);
    free(mat_thd->reorder_mat.task_end);
    free(mat_thd);
}