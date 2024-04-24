#include "test_spmv_vnec.hpp"
#define ntest 2000
#define nwarm 1

inline void test_spmv_vnec_fp32(const std::string &input_path, const std::string &result_path, bool iscsc)
{
    Builder<perfSpB_index, perfSpB_index> builder(input_path);
    CSRGraph<perfSpB_index, perfSpB_index> g = builder.MakeGraph();

    perfSpB_index nrows, ncols, nvals;

    nrows = static_cast<perfSpB_index>(g.num_nodes());
    ncols = static_cast<perfSpB_index>(g.num_nodes());
    nvals = static_cast<perfSpB_index>(g.num_edges());

    perfSpB_index *row_indices;
    perfSpB_index *col_indices;
    float *values = new float[nvals];

    row_indices = new perfSpB_index[nvals];
    col_indices = g.out_destValues();
    perfSpB_index *offsets = g.out_offsets();
    perfSpB_index index = 0;
    for (perfSpB_index i = 0; i < nrows; i++)
    {

        for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
        {
            if (index >= nvals)
            {
                std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                exit(-1);
            }
            values[index] = i;
            row_indices[index++] = static_cast<perfSpB_index>(i);
        }
    }

    PerfSpB_init();
    perfSpB_object_format_ext format;
    format.matrix_format = perfSpB_csr;
    PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);
    perfSpB_matrix G = NULL;
    perfSpB_info info;
    SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_FP32, nrows, ncols));
    perfSpB_matrix_build_FP32(G, row_indices, col_indices, values, nvals);
    perfSpB_vector x;
    SAFE_CALL(perfSpB_vector_new(&x, perfSpB_FP32, ncols));
    for (perfSpB_index j = 0; j < ncols; j++)
    {
        perfSpB_vector_set_element_FP32(x, j, j);
    }
    perfSpB_vector result_benchmark;
    SAFE_CALL(perfSpB_vector_new(&result_benchmark, perfSpB_FP32, nrows));
    perfSpB_vector result_opt;
    SAFE_CALL(perfSpB_vector_new(&result_opt, perfSpB_FP32, nrows));
    struct timeval opt_start, opt_end;
    for (perfSpB_index i = 0; i < 1; i++)
    {
        PerfSpB_mxv_FP32_serial(result_benchmark, G, x);
    }
    //---------------------------------------------------------------------------------------------------------------------------
    if (nrows < 3000000)
    {
        PerfSpB_VNEC_type vnec_t = IRD_VNEC(G, perfSpB_FP32);
        if (vnec_t == PerfSpB_VNEC_D)
        {
            printf("-D is selected\n");
            VNEC_D_FP32 *mat_thd = Build_VNEC_D_FP32(G);
            // warm up
            for (perfSpB_index i = 0; i < nwarm; i++)
            {
                SpMV_VNEC_D_FP32(result_opt, G, x, mat_thd);
            }
            gettimeofday(&opt_start, NULL);
            for (perfSpB_index i = 0; i < ntest; i++)
            {
                SpMV_VNEC_D_FP32(result_opt, G, x, mat_thd);
            }
            gettimeofday(&opt_end, NULL);
            VNEC_D_free_fp32(mat_thd);
        }
        else
        {
            printf("-S is selected\n");
            VNEC_S_FP32 *mat_thd = Build_VNEC_S_FP32(G);
            // warm up
            for (perfSpB_index i = 0; i < nwarm; i++)
            {
                SpMV_VNEC_S_FP32(result_opt, G, x, mat_thd);
            }
            gettimeofday(&opt_start, NULL);
            for (perfSpB_index i = 0; i < ntest; i++)
            {
                SpMV_VNEC_S_FP32(result_opt, G, x, mat_thd);
            }
            gettimeofday(&opt_end, NULL);
            VNEC_S_free_fp32(mat_thd);
        }
    }
    else
    {
        printf("-L is selected\n");
        VNEC_L *mat_thd = Build_VNEC_L(G);
        // warm up
        for (perfSpB_index i = 0; i < nwarm; i++)
        {
            SpMV_VNEC_L_FP32(result_opt, G, x, mat_thd);
        }
        gettimeofday(&opt_start, NULL);
        for (perfSpB_index i = 0; i < ntest; i++)
        {
            SpMV_VNEC_L_FP32(result_opt, G, x, mat_thd);
        }
        gettimeofday(&opt_end, NULL);
        free(mat_thd->diagonal_start);
        free(mat_thd->diagonal_end);
        free(mat_thd->nz_indices);
        free(mat_thd->thread_coord_start);
        free(mat_thd->thread_coord_end);
        free(mat_thd);
    }
    long opt_timeuse = 1000000 * (opt_end.tv_sec - opt_start.tv_sec) + opt_end.tv_usec - opt_start.tv_usec;
    printf("\n ------------------------------------------------------------------------------");
    printf("\n SpMV overall time elapsed: %f ms\n", opt_timeuse / 1000.0 / ntest);
    printf(" ------------------------------------------------------------------------------ \n");
    float diff = 0.0;
    for (perfSpB_index i = 0; i < nrows; ++i)
    {
        float value_benchmark, value_opt;
        perfSpB_vector_extract_element_FP32(&value_benchmark, result_benchmark, i);
        perfSpB_vector_extract_element_FP32(&value_opt, result_opt, i);
        diff = fabs(value_benchmark - value_opt);
        ASSERT_LE(diff, value_benchmark * 1e-4);
    }

    perfSpB_matrix_free(&G);
    perfSpB_vector_free(&x);
    perfSpB_vector_free(&result_opt);
    perfSpB_vector_free(&result_benchmark);
}

inline void test_spmv_vnec_fp64(const std::string &input_path, const std::string &result_path, bool iscsc)
{
    Builder<perfSpB_index, perfSpB_index> builder(input_path);
    CSRGraph<perfSpB_index, perfSpB_index> g = builder.MakeGraph();

    perfSpB_index nrows, ncols, nvals;

    nrows = static_cast<perfSpB_index>(g.num_nodes());
    ncols = static_cast<perfSpB_index>(g.num_nodes());
    nvals = static_cast<perfSpB_index>(g.num_edges());

    perfSpB_index *row_indices;
    perfSpB_index *col_indices;
    double *values = new double[nvals];

    row_indices = new perfSpB_index[nvals];
    col_indices = g.out_destValues();
    perfSpB_index *offsets = g.out_offsets();
    perfSpB_index index = 0;
    for (perfSpB_index i = 0; i < nrows; i++)
    {

        for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
        {
            if (index >= nvals)
            {
                std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                exit(-1);
            }
            values[index] = i;
            row_indices[index++] = static_cast<perfSpB_index>(i);
        }
    }
    PerfSpB_init();
    perfSpB_object_format_ext format;
    format.matrix_format = perfSpB_csr;
    PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);
    perfSpB_matrix G = NULL;
    perfSpB_info info;
    SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_FP64, nrows, ncols));
    perfSpB_matrix_build_FP64(G, row_indices, col_indices, values, nvals);
    perfSpB_vector x;
    SAFE_CALL(perfSpB_vector_new(&x, perfSpB_FP64, ncols));
    for (perfSpB_index j = 0; j < ncols; j++)
    {
        perfSpB_vector_set_element_FP64(x, j, j);
    }
    perfSpB_vector result_benchmark;
    SAFE_CALL(perfSpB_vector_new(&result_benchmark, perfSpB_FP64, nrows));
    perfSpB_vector result_opt;
    SAFE_CALL(perfSpB_vector_new(&result_opt, perfSpB_FP64, nrows));
    struct timeval opt_start, opt_end;
    for (perfSpB_index i = 0; i < 1; i++)
    {
        PerfSpB_mxv_FP64_serial(result_benchmark, G, x);
    }
    //---------------------------------------------------------------------------------------------------------------------------
    if (nrows < 3000000)
    {
        PerfSpB_VNEC_type vnec_t = IRD_VNEC(G, perfSpB_FP64);
        if (vnec_t == PerfSpB_VNEC_D)
        {
            printf("-D is selected\n");
            VNEC_D_FP64 *mat_thd = Build_VNEC_D_FP64(G);
            // warm up
            for (perfSpB_index i = 0; i < nwarm; i++)
            {
                SpMV_VNEC_D_FP64(result_opt, G, x, mat_thd);
            }
            gettimeofday(&opt_start, NULL);
            for (perfSpB_index i = 0; i < ntest; i++)
            {
                SpMV_VNEC_D_FP64(result_opt, G, x, mat_thd);
            }
            gettimeofday(&opt_end, NULL);
            VNEC_D_free_fp64(mat_thd);
        }
        else
        {
            printf("-S is selected\n");
            VNEC_S_FP64 *mat_thd = Build_VNEC_S_FP64(G);
            // warm up
            for (perfSpB_index i = 0; i < nwarm; i++)
            {
                SpMV_VNEC_S_FP64(result_opt, G, x, mat_thd);
            }
            gettimeofday(&opt_start, NULL);
            for (perfSpB_index i = 0; i < ntest; i++)
            {
                SpMV_VNEC_S_FP64(result_opt, G, x, mat_thd);
            }
            gettimeofday(&opt_end, NULL);
            VNEC_S_free_fp64(mat_thd);
        }
    }
    else
    {
        printf("-L is selected\n");
        VNEC_L *mat_thd = Build_VNEC_L(G);
        // warm up
        for (perfSpB_index i = 0; i < nwarm; i++)
        {
            SpMV_VNEC_L_FP64(result_opt, G, x, mat_thd);
        }
        gettimeofday(&opt_start, NULL);
        for (perfSpB_index i = 0; i < ntest; i++)
        {
            SpMV_VNEC_L_FP64(result_opt, G, x, mat_thd);
        }
        gettimeofday(&opt_end, NULL);
        free(mat_thd->diagonal_start);
        free(mat_thd->diagonal_end);
        free(mat_thd->nz_indices);
        free(mat_thd->thread_coord_start);
        free(mat_thd->thread_coord_end);
        free(mat_thd);
    }
    long opt_timeuse = 1000000 * (opt_end.tv_sec - opt_start.tv_sec) + opt_end.tv_usec - opt_start.tv_usec;
    printf("\n ------------------------------------------------------------------------------");
    printf("\n VNEC_FP64 mxv overall time elapsed: %f ms\n", opt_timeuse / 1000.0 / ntest);
    printf(" ------------------------------------------------------------------------------ \n");
    double diff = 0.0;
    for (perfSpB_index i = 0; i < nrows; ++i)
    {
        double value_benchmark, value_opt;
        perfSpB_vector_extract_element_FP64(&value_benchmark, result_benchmark, i);
        perfSpB_vector_extract_element_FP64(&value_opt, result_opt, i);
        diff = fabs(value_benchmark - value_opt);
        ASSERT_LE(diff, value_benchmark * 1e-8);
    }

    perfSpB_matrix_free(&G);
    perfSpB_vector_free(&x);
    perfSpB_vector_free(&result_opt);
    perfSpB_vector_free(&result_benchmark);
}

inline void test_read_fp32(const std::string &sg_path, const std::string &m_path)
{
    Builder<perfSpB_index, perfSpB_index> builder(sg_path);
    CSRGraph<perfSpB_index, perfSpB_index> g = builder.MakeGraph();
    perfSpB_index nrows, ncols, nvals;
    nrows = static_cast<perfSpB_index>(g.num_nodes());
    ncols = static_cast<perfSpB_index>(g.num_nodes());
    nvals = static_cast<perfSpB_index>(g.num_edges());

    perfSpB_index *row_indices;
    perfSpB_index *col_indices;
    float *values = new float[nvals];

    row_indices = new perfSpB_index[nvals];
    col_indices = g.out_destValues();
    perfSpB_index *offsets = g.out_offsets();
    perfSpB_index index = 0;
    for (perfSpB_index i = 0; i < nrows; i++)
    {

        for (perfSpB_index j = 0; j < offsets[i + 1] - offsets[i]; j++)
        {
            if (index >= nvals)
            {
                std::cerr << "Error index >= nvals" << index << " " << nvals << std::endl;
                exit(-1);
            }
            values[index] = 1;
            row_indices[index++] = static_cast<perfSpB_index>(i);
        }
    }

    PerfSpB_init();
    perfSpB_object_format_ext format;
    format.matrix_format = perfSpB_csr;
    PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);
    perfSpB_matrix G = NULL;
    perfSpB_info info;
    SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_FP32, nrows, ncols));
    perfSpB_matrix_build_FP32(G, row_indices, col_indices, values, nvals);

    std::vector<perfSpB_index> row_indices_;
    std::vector<perfSpB_index> col_indices_;
    std::vector<float> values_;
    perfSpB_index nrows_, ncols_, nvals_;
    const char *mtx_path = m_path.c_str();

    readMtx_coo<float>(mtx_path, &row_indices_, &col_indices_, &values_, &nrows_, &ncols_, &nvals_, 1, false);

    perfSpB_matrix G_ = NULL;
    SAFE_CALL(perfSpB_matrix_new(&G_, perfSpB_FP32, nrows_, ncols_));
    perfSpB_matrix_build_FP32(G_, &row_indices_[0], &col_indices_[0], (float *)&values_[0], nvals_);

    perfSpB_vector x;
    SAFE_CALL(perfSpB_vector_new(&x, perfSpB_FP32, ncols));
    for (perfSpB_index j = 0; j < ncols; j++)
    {
        perfSpB_vector_set_element_FP32(x, 1, j);
    }
    perfSpB_vector result_mm;
    SAFE_CALL(perfSpB_vector_new(&result_mm, perfSpB_FP32, nrows));
    perfSpB_vector result_sg;
    SAFE_CALL(perfSpB_vector_new(&result_sg, perfSpB_FP32, nrows));

    PerfSpB_mxv_FP32_serial(result_sg, G, x);
    PerfSpB_mxv_FP32_serial(result_mm, G_, x);
    float diff = 0.0;
    float sum_mm = 0.0;
    float sum_sg = 0.0;
    for (perfSpB_index i = 1; i < nrows; ++i)
    {
        float value_sg, value_mm;
        perfSpB_vector_extract_element_FP32(&value_sg, result_sg, i);
        perfSpB_vector_extract_element_FP32(&value_mm, result_mm, i);
        // diff = fabs(value_sg - value_mm);
        // ASSERT_LE(diff, value_mm * 1e-4);
        sum_mm += value_mm;
        sum_sg += value_sg;
        if(value_mm != value_sg)
        {
            printf("\n (%ld)  mm=%f sg = %f  \n",i,value_mm,value_sg);
        }
        ASSERT_EQ(value_mm, value_sg);
    }
    // printf("\n mm=%f sg = %f  \n",sum_mm,sum_sg);

    perfSpB_matrix_free(&G);
    perfSpB_vector_free(&x);
    perfSpB_vector_free(&result_sg);
    perfSpB_vector_free(&result_mm);

    // float diff = 0.0;
    // float sum_mm = 0.0;
    // float sum_sg = 0.0;
    // for (perfSpB_index i = 0; i < 1; ++i)
    // {
    //     for (perfSpB_index j = 0; j < 1; ++j)
    //     {
    //         float value_mm, value_sg;
    //         perfSpB_matrix_extract_element_FP32(&value_mm, G_, i, j);
    //         perfSpB_matrix_extract_element_FP32(&value_sg, G, i, j);
    //         sum_mm += value_mm;
    //         sum_sg += value_sg;
    //         // diff = fabs(value_mm - value_sg);
    //         // ASSERT_LE(diff, value_mm * 1e-4);
    //         // if(value_mm != value_sg)
    //         // {
    //         //     printf("\n (%ld,%ld)  mm=%f sg = %f  \n",i,j,value_mm,value_sg);
    //         // }
    //     }
    // }
    // printf("\n mm=%f sg = %f  \n",sum_mm,sum_sg);

    // perfSpB_matrix_free(&G);
    perfSpB_matrix_free(&G_);

}

TEST(mxv_test_read_FP32, roadNet_CA)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(roadNet-CA));
    std::string input_file2(MATRIX_FULL_PATH(roadNet-CA));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, amazon0312)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(amazon0312));
    std::string input_file2(MATRIX_FULL_PATH(amazon0312));
    test_read_fp32(input_file1, input_file2);
}

TEST(mxv_test_read_FP32, com_Youtube)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(com-Youtube));
    std::string input_file2(MATRIX_FULL_PATH(com-Youtube));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, web_Stanford)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(web-Stanford));
    std::string input_file2(MATRIX_FULL_PATH(web-Stanford));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, as_Skitter)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(as-Skitter));
    std::string input_file2(MATRIX_FULL_PATH(as-Skitter));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, road_usa)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(road_usa));
    std::string input_file2(MATRIX_FULL_PATH(road_usa));
    test_read_fp32(input_file1, input_file2);
}

TEST(mxv_test_read_FP32, coAuthorsCiteseer)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(coAuthorsCiteseer));
    std::string input_file2(MATRIX_FULL_PATH(coAuthorsCiteseer));
    test_read_fp32(input_file1, input_file2);
}

TEST(mxv_test_read_FP32, coAuthorsDBLP)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(coAuthorsDBLP));
    std::string input_file2(MATRIX_FULL_PATH(coAuthorsDBLP));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, web_Google)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(web-Google));
    std::string input_file2(MATRIX_FULL_PATH(web-Google));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, com_Orkut)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(com-Orkut));
    std::string input_file2(MATRIX_FULL_PATH(com-Orkut));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, higgs_twitter)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(higgs-twitter));
    std::string input_file2(MATRIX_FULL_PATH(higgs-twitter));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, wiki_topcats)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(wiki-topcats));
    std::string input_file2(MATRIX_FULL_PATH(wiki-topcats));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, web_BerkStan)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(web-BerkStan));
    std::string input_file2(MATRIX_FULL_PATH(web-BerkStan));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, com_Amazon)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(com-Amazon));
    std::string input_file2(MATRIX_FULL_PATH(wcom-Amazon));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, com_DBLP)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(com-DBLP));
    std::string input_file2(MATRIX_FULL_PATH(com-DBLP));
    test_read_fp32(input_file1, input_file2);
}

TEST(mxv_test_read_FP32, TSOPF_RS_b2383)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(TSOPF_RS_b2383));
    std::string input_file2(MATRIX_FULL_PATH(TSOPF_RS_b2383));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, coPapersCiteseer)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(coPapersCiteseer));
    std::string input_file2(MATRIX_FULL_PATH(coPapersCiteseer));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, eu_2005)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(eu-2005));
    std::string input_file2(MATRIX_FULL_PATH(eu-2005));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, crankseg_2)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(crankseg_2));
    std::string input_file2(MATRIX_FULL_PATH(crankseg_2));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, nd12k)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(nd12k));
    std::string input_file2(MATRIX_FULL_PATH(nd12k));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, coPapersDBLP)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(coPapersDBLP));
    std::string input_file2(MATRIX_FULL_PATH(coPapersDBLP));
    test_read_fp32(input_file1, input_file2);
}

TEST(mxv_test_read_FP32, cnr_2000)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(cnr-2000));
    std::string input_file2(MATRIX_FULL_PATH(cnr-2000));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, msdoor)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(msdoor));
    std::string input_file2(MATRIX_FULL_PATH(msdoor));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, bundle_adj)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(bundle_adj));
    std::string input_file2(MATRIX_FULL_PATH(bundle_adj));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, F1)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(F1));
    std::string input_file2(MATRIX_FULL_PATH(F1));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, inline_1)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(inline_1));
    std::string input_file2(MATRIX_FULL_PATH(inline_1));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, audikw_1)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(audikw_1));
    std::string input_file2(MATRIX_FULL_PATH(audikw_1));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, ML_Laplace)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(ML_Laplace));
    std::string input_file2(MATRIX_FULL_PATH(ML_Laplace));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, dielFilterV3real)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(dielFilterV3real));
    std::string input_file2(MATRIX_FULL_PATH(dielFilterV3real));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, Flan_1565)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(Flan_1565));
    std::string input_file2(MATRIX_FULL_PATH(Flan_1565));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, Long_Coup_dt0)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(Long_Coup_dt0));
    std::string input_file2(MATRIX_FULL_PATH(Long_Coup_dt0));
    test_read_fp32(input_file1, input_file2);
}
TEST(mxv_test_read_FP32, mip1)
{
    std::string input_file1(MATRIX_SG_FULL_PATH(mip1));
    std::string input_file2(MATRIX_FULL_PATH(mip1));
    test_read_fp32(input_file1, input_file2);
}


TEST(mxv_test_VNEC_FP32, roadNet_CA)
{
    std::string input_file(MATRIX_SG_FULL_PATH(roadNet-CA));
    std::string output_file(RESULT_FULL_PATH(roadNet-CA));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, amazon0312)
{
    std::string input_file(MATRIX_SG_FULL_PATH(amazon0312));
    std::string output_file(RESULT_FULL_PATH(amazon0312));
    test_spmv_vnec_fp32(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32, com_Youtube)
{
    std::string input_file(MATRIX_SG_FULL_PATH(com-Youtube));
    std::string output_file(RESULT_FULL_PATH(com-Youtube));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, web_Stanford)
{
    std::string input_file(MATRIX_SG_FULL_PATH(web-Stanford));
    std::string output_file(RESULT_FULL_PATH(web-Stanford));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, as_Skitter)
{
    std::string input_file(MATRIX_SG_FULL_PATH(as-Skitter));
    std::string output_file(RESULT_FULL_PATH(as-Skitter));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, road_usa)
{
    std::string input_file(MATRIX_SG_FULL_PATH(road_usa));
    std::string output_file(RESULT_FULL_PATH(road_usa));
    test_spmv_vnec_fp32(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32, coAuthorsCiteseer)
{
    std::string input_file(MATRIX_SG_FULL_PATH(coAuthorsCiteseer));
    std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
    test_spmv_vnec_fp32(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32, coAuthorsDBLP)
{
    std::string input_file(MATRIX_SG_FULL_PATH(coAuthorsDBLP));
    std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, web_Google)
{
    std::string input_file(MATRIX_SG_FULL_PATH(web-Google));
    std::string output_file(RESULT_FULL_PATH(web-Google));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, com_Orkut)
{
    std::string input_file(MATRIX_SG_FULL_PATH(com-Orkut));
    std::string output_file(RESULT_FULL_PATH(com-Orkut));
    test_spmv_vnec_fp32(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32, higgs_twitter)
{
    std::string input_file(MATRIX_SG_FULL_PATH(higgs-twitter));
    std::string output_file(RESULT_FULL_PATH(higgs-twitter));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, wiki_topcats)
{
    std::string input_file(MATRIX_SG_FULL_PATH(wiki-topcats));
    std::string output_file(RESULT_FULL_PATH(wiki-topcats));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, web_BerkStan)
{
    std::string input_file(MATRIX_SG_FULL_PATH(web-BerkStan));
    std::string output_file(RESULT_FULL_PATH(web-BerkStan));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, com_Amazon)
{
    std::string input_file(MATRIX_SG_FULL_PATH(com-Amazon));
    std::string output_file(RESULT_FULL_PATH(wcom-Amazon));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, com_DBLP)
{
    std::string input_file(MATRIX_SG_FULL_PATH(com-DBLP));
    std::string output_file(RESULT_FULL_PATH(com-DBLP));
    test_spmv_vnec_fp32(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32, TSOPF_RS_b2383)
{
    std::string input_file(MATRIX_SG_FULL_PATH(TSOPF_RS_b2383));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, coPapersCiteseer)
{
    std::string input_file(MATRIX_SG_FULL_PATH(coPapersCiteseer));
    std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, eu_2005)
{
    std::string input_file(MATRIX_SG_FULL_PATH(eu-2005));
    std::string output_file(RESULT_FULL_PATH(eu-2005));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, crankseg_2)
{
    std::string input_file(MATRIX_SG_FULL_PATH(crankseg_2));
    std::string output_file(RESULT_FULL_PATH(crankseg_2));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, nd12k)
{
    std::string input_file(MATRIX_SG_FULL_PATH(nd12k));
    std::string output_file(RESULT_FULL_PATH(nd12k));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, coPapersDBLP)
{
    std::string input_file(MATRIX_SG_FULL_PATH(coPapersDBLP));
    std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
    test_spmv_vnec_fp32(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32, cnr_2000)
{
    std::string input_file(MATRIX_SG_FULL_PATH(cnr-2000));
    std::string output_file(RESULT_FULL_PATH(cnr-2000));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, msdoor)
{
    std::string input_file(MATRIX_SG_FULL_PATH(msdoor));
    std::string output_file(RESULT_FULL_PATH(msdoor));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, bundle_adj)
{
    std::string input_file(MATRIX_SG_FULL_PATH(bundle_adj));
    std::string output_file(RESULT_FULL_PATH(bundle_adj));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, F1)
{
    std::string input_file(MATRIX_SG_FULL_PATH(F1));
    std::string output_file(RESULT_FULL_PATH(F1));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, inline_1)
{
    std::string input_file(MATRIX_SG_FULL_PATH(inline_1));
    std::string output_file(RESULT_FULL_PATH(inline_1));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, audikw_1)
{
    std::string input_file(MATRIX_SG_FULL_PATH(audikw_1));
    std::string output_file(RESULT_FULL_PATH(audikw_1));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, ML_Laplace)
{
    std::string input_file(MATRIX_SG_FULL_PATH(ML_Laplace));
    std::string output_file(RESULT_FULL_PATH(ML_Laplace));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, dielFilterV3real)
{
    std::string input_file(MATRIX_SG_FULL_PATH(dielFilterV3real));
    std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, Flan_1565)
{
    std::string input_file(MATRIX_SG_FULL_PATH(Flan_1565));
    std::string output_file(RESULT_FULL_PATH(Flan_1565));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, Long_Coup_dt0)
{
    std::string input_file(MATRIX_SG_FULL_PATH(Long_Coup_dt0));
    std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
    test_spmv_vnec_fp32(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32, mip1)
{
    std::string input_file(MATRIX_SG_FULL_PATH(mip1));
    std::string output_file(RESULT_FULL_PATH(mip1));
    test_spmv_vnec_fp32(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64, roadNet_CA)
{
    std::string input_file(MATRIX_SG_FULL_PATH(roadNet-CA));
    std::string output_file(RESULT_FULL_PATH(roadNet-CA));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, amazon0312)
{
    std::string input_file(MATRIX_SG_FULL_PATH(amazon0312));
    std::string output_file(RESULT_FULL_PATH(amazon0312));
    test_spmv_vnec_fp64(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64, com_Youtube)
{
    std::string input_file(MATRIX_SG_FULL_PATH(com-Youtube));
    std::string output_file(RESULT_FULL_PATH(com-Youtube));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, web_Stanford)
{
    std::string input_file(MATRIX_SG_FULL_PATH(web-Stanford));
    std::string output_file(RESULT_FULL_PATH(web-Stanford));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, as_Skitter)
{
    std::string input_file(MATRIX_SG_FULL_PATH(as-Skitter));
    std::string output_file(RESULT_FULL_PATH(as-Skitter));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, road_usa)
{
    std::string input_file(MATRIX_SG_FULL_PATH(road_usa));
    std::string output_file(RESULT_FULL_PATH(road_usa));
    test_spmv_vnec_fp64(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64, coAuthorsCiteseer)
{
    std::string input_file(MATRIX_SG_FULL_PATH(coAuthorsCiteseer));
    std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
    test_spmv_vnec_fp64(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64, coAuthorsDBLP)
{
    std::string input_file(MATRIX_SG_FULL_PATH(coAuthorsDBLP));
    std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, web_Google)
{
    std::string input_file(MATRIX_SG_FULL_PATH(web-Google));
    std::string output_file(RESULT_FULL_PATH(web-Google));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, com_Orkut)
{
    std::string input_file(MATRIX_SG_FULL_PATH(com-Orkut));
    std::string output_file(RESULT_FULL_PATH(com-Orkut));
    test_spmv_vnec_fp64(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64, higgs_twitter)
{
    std::string input_file(MATRIX_SG_FULL_PATH(higgs-twitter));
    std::string output_file(RESULT_FULL_PATH(higgs-twitter));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, wiki_topcats)
{
    std::string input_file(MATRIX_SG_FULL_PATH(wiki-topcats));
    std::string output_file(RESULT_FULL_PATH(wiki-topcats));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, web_BerkStan)
{
    std::string input_file(MATRIX_SG_FULL_PATH(web-BerkStan));
    std::string output_file(RESULT_FULL_PATH(web-BerkStan));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, com_Amazon)
{
    std::string input_file(MATRIX_SG_FULL_PATH(com-Amazon));
    std::string output_file(RESULT_FULL_PATH(wcom-Amazon));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, com_DBLP)
{
    std::string input_file(MATRIX_SG_FULL_PATH(com-DBLP));
    std::string output_file(RESULT_FULL_PATH(com-DBLP));
    test_spmv_vnec_fp64(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64, TSOPF_RS_b2383)
{
    std::string input_file(MATRIX_SG_FULL_PATH(TSOPF_RS_b2383));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, coPapersCiteseer)
{
    std::string input_file(MATRIX_SG_FULL_PATH(coPapersCiteseer));
    std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, eu_2005)
{
    std::string input_file(MATRIX_SG_FULL_PATH(eu-2005));
    std::string output_file(RESULT_FULL_PATH(eu-2005));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, crankseg_2)
{
    std::string input_file(MATRIX_SG_FULL_PATH(crankseg_2));
    std::string output_file(RESULT_FULL_PATH(crankseg_2));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, nd12k)
{
    std::string input_file(MATRIX_SG_FULL_PATH(nd12k));
    std::string output_file(RESULT_FULL_PATH(nd12k));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, coPapersDBLP)
{
    std::string input_file(MATRIX_SG_FULL_PATH(coPapersDBLP));
    std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
    test_spmv_vnec_fp64(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64, cnr_2000)
{
    std::string input_file(MATRIX_SG_FULL_PATH(cnr-2000));
    std::string output_file(RESULT_FULL_PATH(cnr-2000));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, msdoor)
{
    std::string input_file(MATRIX_SG_FULL_PATH(msdoor));
    std::string output_file(RESULT_FULL_PATH(msdoor));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, bundle_adj)
{
    std::string input_file(MATRIX_SG_FULL_PATH(bundle_adj));
    std::string output_file(RESULT_FULL_PATH(bundle_adj));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, F1)
{
    std::string input_file(MATRIX_SG_FULL_PATH(F1));
    std::string output_file(RESULT_FULL_PATH(F1));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, inline_1)
{
    std::string input_file(MATRIX_SG_FULL_PATH(inline_1));
    std::string output_file(RESULT_FULL_PATH(inline_1));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, audikw_1)
{
    std::string input_file(MATRIX_SG_FULL_PATH(audikw_1));
    std::string output_file(RESULT_FULL_PATH(audikw_1));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, ML_Laplace)
{
    std::string input_file(MATRIX_SG_FULL_PATH(ML_Laplace));
    std::string output_file(RESULT_FULL_PATH(ML_Laplace));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, dielFilterV3real)
{
    std::string input_file(MATRIX_SG_FULL_PATH(dielFilterV3real));
    std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, Flan_1565)
{
    std::string input_file(MATRIX_SG_FULL_PATH(Flan_1565));
    std::string output_file(RESULT_FULL_PATH(Flan_1565));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, Long_Coup_dt0)
{
    std::string input_file(MATRIX_SG_FULL_PATH(Long_Coup_dt0));
    std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64, mip1)
{
    std::string input_file(MATRIX_SG_FULL_PATH(mip1));
    std::string output_file(RESULT_FULL_PATH(mip1));
    test_spmv_vnec_fp64(input_file, output_file, false);
}
