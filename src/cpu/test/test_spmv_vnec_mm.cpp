#include "test_spmv_vnec.hpp"
#define ntest 2000
#define nwarm 1
inline void test_spmv_vnec_fp32_MM(const std::string &input_path, const std::string &result_path, bool iscsc)
{
    std::vector<perfSpB_index> row_indices;
    std::vector<perfSpB_index> col_indices;
    std::vector<float> values;
    perfSpB_index nrows, ncols, nvals;
    const char* mtx_path = input_path.c_str();

    readMtx<float>(mtx_path, &row_indices, &col_indices, &values, &nrows, &ncols, &nvals, 2, 1, false, 1);
    

    PerfSpB_init();
    perfSpB_object_format_ext format;
    format.matrix_format = perfSpB_csr;
    PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);
    perfSpB_matrix G = NULL;
    perfSpB_info info;
    SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_FP32, nrows, ncols));
    perfSpB_matrix_build_FP32(G, &row_indices[0], &col_indices[0], (float *)&values[0], nvals);
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
    if(nrows < 3000000)
    {
        PerfSpB_VNEC_type vnec_t = IRD_VNEC(G, perfSpB_FP32);
        if(vnec_t == PerfSpB_VNEC_D)
        {
            printf("-D is selected\n");
            VNEC_D_FP32 *mat_thd = Build_VNEC_D_FP32(G);
            //warm up
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
            //warm up
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
        //warm up
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
inline void test_spmv_vnec_fp64_MM(const std::string &input_path, const std::string &result_path, bool iscsc)
{
    std::vector<perfSpB_index> row_indices;
    std::vector<perfSpB_index> col_indices;
    std::vector<double> values;
    perfSpB_index nrows, ncols, nvals;
    const char* mtx_path = input_path.c_str();

    readMtx<double>(mtx_path, &row_indices, &col_indices, &values, &nrows, &ncols, &nvals, 2, 1, false, 1);
    

    PerfSpB_init();
    perfSpB_object_format_ext format;
    format.matrix_format = perfSpB_csr;
    PerfSpB_Global_Option_set_ext(perfSpB_matrix_format, format);
    perfSpB_matrix G = NULL;
    perfSpB_info info;
    SAFE_CALL(perfSpB_matrix_new(&G, perfSpB_FP64, nrows, ncols));
    perfSpB_matrix_build_FP64(G, &row_indices[0], &col_indices[0], (double *)&values[0], nvals);
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
    if(nrows < 3000000)
    {
        PerfSpB_VNEC_type vnec_t = IRD_VNEC(G, perfSpB_FP64);
        if(vnec_t == PerfSpB_VNEC_D)
        {
            printf("-D is selected\n");
            VNEC_D_FP64 *mat_thd = Build_VNEC_D_FP64(G);
            //warm up
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
            //warm up
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
        //warm up
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


TEST(mxv_test_VNEC_FP32_MM, roadNet_CA)
{
    std::string input_file(MATRIX_FULL_PATH(roadNet-CA));
    std::string output_file(RESULT_FULL_PATH(roadNet-CA));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, amazon0312)
{
    std::string input_file(MATRIX_FULL_PATH(amazon0312));
    std::string output_file(RESULT_FULL_PATH(amazon0312));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32_MM, com_Youtube)
{
    std::string input_file(MATRIX_FULL_PATH(com-Youtube));
    std::string output_file(RESULT_FULL_PATH(com-Youtube));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, web_Stanford)
{
    std::string input_file(MATRIX_FULL_PATH(web-Stanford));
    std::string output_file(RESULT_FULL_PATH(web-Stanford));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, as_Skitter)
{
    std::string input_file(MATRIX_FULL_PATH(as-Skitter));
    std::string output_file(RESULT_FULL_PATH(as-Skitter));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, road_usa)
{
    std::string input_file(MATRIX_FULL_PATH(road_usa));
    std::string output_file(RESULT_FULL_PATH(road_usa));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32_MM, coAuthorsCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer));
    std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32_MM, coAuthorsDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP));
    std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, web_Google)
{
    std::string input_file(MATRIX_FULL_PATH(web-Google));
    std::string output_file(RESULT_FULL_PATH(web-Google));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, com_Orkut)
{
    std::string input_file(MATRIX_FULL_PATH(com-Orkut));
    std::string output_file(RESULT_FULL_PATH(com-Orkut));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32_MM, higgs_twitter)
{
    std::string input_file(MATRIX_FULL_PATH(higgs-twitter));
    std::string output_file(RESULT_FULL_PATH(higgs-twitter));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, wiki_topcats)
{
    std::string input_file(MATRIX_FULL_PATH(wiki-topcats));
    std::string output_file(RESULT_FULL_PATH(wiki-topcats));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, web_BerkStan)
{
    std::string input_file(MATRIX_FULL_PATH(web-BerkStan));
    std::string output_file(RESULT_FULL_PATH(web-BerkStan));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, com_Amazon)
{
    std::string input_file(MATRIX_FULL_PATH(com-Amazon));
    std::string output_file(RESULT_FULL_PATH(wcom-Amazon));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, com_DBLP)
{
    std::string input_file(MATRIX_FULL_PATH(com-DBLP));
    std::string output_file(RESULT_FULL_PATH(com-DBLP));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32_MM, TSOPF_RS_b2383)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, coPapersCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer));
    std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, eu_2005)
{
    std::string input_file(MATRIX_FULL_PATH(eu-2005));
    std::string output_file(RESULT_FULL_PATH(eu-2005));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, crankseg_2)
{
    std::string input_file(MATRIX_FULL_PATH(crankseg_2));
    std::string output_file(RESULT_FULL_PATH(crankseg_2));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, nd12k)
{
    std::string input_file(MATRIX_FULL_PATH(nd12k));
    std::string output_file(RESULT_FULL_PATH(nd12k));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, coPapersDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coPapersDBLP));
    std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP32_MM, cnr_2000)
{
    std::string input_file(MATRIX_FULL_PATH(cnr-2000));
    std::string output_file(RESULT_FULL_PATH(cnr-2000));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, msdoor)
{
    std::string input_file(MATRIX_FULL_PATH(msdoor));
    std::string output_file(RESULT_FULL_PATH(msdoor));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, bundle_adj)
{
    std::string input_file(MATRIX_FULL_PATH(bundle_adj));
    std::string output_file(RESULT_FULL_PATH(bundle_adj));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, F1)
{
    std::string input_file(MATRIX_FULL_PATH(F1));
    std::string output_file(RESULT_FULL_PATH(F1));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, inline_1)
{
    std::string input_file(MATRIX_FULL_PATH(inline_1));
    std::string output_file(RESULT_FULL_PATH(inline_1));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, audikw_1)
{
    std::string input_file(MATRIX_FULL_PATH(audikw_1));
    std::string output_file(RESULT_FULL_PATH(audikw_1));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, ML_Laplace)
{
    std::string input_file(MATRIX_FULL_PATH(ML_Laplace));
    std::string output_file(RESULT_FULL_PATH(ML_Laplace));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, dielFilterV3real)
{
    std::string input_file(MATRIX_FULL_PATH(dielFilterV3real));
    std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, Flan_1565)
{
    std::string input_file(MATRIX_FULL_PATH(Flan_1565));
    std::string output_file(RESULT_FULL_PATH(Flan_1565));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, Long_Coup_dt0)
{
    std::string input_file(MATRIX_FULL_PATH(Long_Coup_dt0));
    std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP32_MM, mip1)
{
    std::string input_file(MATRIX_FULL_PATH(mip1));
    std::string output_file(RESULT_FULL_PATH(mip1));
    test_spmv_vnec_fp32_MM(input_file, output_file, false);
}



TEST(mxv_test_VNEC_FP64_MM, roadNet_CA)
{
    std::string input_file(MATRIX_FULL_PATH(roadNet-CA));
    std::string output_file(RESULT_FULL_PATH(roadNet-CA));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, amazon0312)
{
    std::string input_file(MATRIX_FULL_PATH(amazon0312));
    std::string output_file(RESULT_FULL_PATH(amazon0312));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64_MM, com_Youtube)
{
    std::string input_file(MATRIX_FULL_PATH(com-Youtube));
    std::string output_file(RESULT_FULL_PATH(com-Youtube));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, web_Stanford)
{
    std::string input_file(MATRIX_FULL_PATH(web-Stanford));
    std::string output_file(RESULT_FULL_PATH(web-Stanford));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, as_Skitter)
{
    std::string input_file(MATRIX_FULL_PATH(as-Skitter));
    std::string output_file(RESULT_FULL_PATH(as-Skitter));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, road_usa)
{
    std::string input_file(MATRIX_FULL_PATH(road_usa));
    std::string output_file(RESULT_FULL_PATH(road_usa));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64_MM, coAuthorsCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer));
    std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64_MM, coAuthorsDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP));
    std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, web_Google)
{
    std::string input_file(MATRIX_FULL_PATH(web-Google));
    std::string output_file(RESULT_FULL_PATH(web-Google));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, com_Orkut)
{
    std::string input_file(MATRIX_FULL_PATH(com-Orkut));
    std::string output_file(RESULT_FULL_PATH(com-Orkut));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64_MM, higgs_twitter)
{
    std::string input_file(MATRIX_FULL_PATH(higgs-twitter));
    std::string output_file(RESULT_FULL_PATH(higgs-twitter));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, wiki_topcats)
{
    std::string input_file(MATRIX_FULL_PATH(wiki-topcats));
    std::string output_file(RESULT_FULL_PATH(wiki-topcats));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, web_BerkStan)
{
    std::string input_file(MATRIX_FULL_PATH(web-BerkStan));
    std::string output_file(RESULT_FULL_PATH(web-BerkStan));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, com_Amazon)
{
    std::string input_file(MATRIX_FULL_PATH(com-Amazon));
    std::string output_file(RESULT_FULL_PATH(wcom-Amazon));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, com_DBLP)
{
    std::string input_file(MATRIX_FULL_PATH(com-DBLP));
    std::string output_file(RESULT_FULL_PATH(com-DBLP));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64_MM, TSOPF_RS_b2383)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, coPapersCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer));
    std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, eu_2005)
{
    std::string input_file(MATRIX_FULL_PATH(eu-2005));
    std::string output_file(RESULT_FULL_PATH(eu-2005));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, crankseg_2)
{
    std::string input_file(MATRIX_FULL_PATH(crankseg_2));
    std::string output_file(RESULT_FULL_PATH(crankseg_2));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, nd12k)
{
    std::string input_file(MATRIX_FULL_PATH(nd12k));
    std::string output_file(RESULT_FULL_PATH(nd12k));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, coPapersDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coPapersDBLP));
    std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}

TEST(mxv_test_VNEC_FP64_MM, cnr_2000)
{
    std::string input_file(MATRIX_FULL_PATH(cnr-2000));
    std::string output_file(RESULT_FULL_PATH(cnr-2000));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, msdoor)
{
    std::string input_file(MATRIX_FULL_PATH(msdoor));
    std::string output_file(RESULT_FULL_PATH(msdoor));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, bundle_adj)
{
    std::string input_file(MATRIX_FULL_PATH(bundle_adj));
    std::string output_file(RESULT_FULL_PATH(bundle_adj));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, F1)
{
    std::string input_file(MATRIX_FULL_PATH(F1));
    std::string output_file(RESULT_FULL_PATH(F1));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, inline_1)
{
    std::string input_file(MATRIX_FULL_PATH(inline_1));
    std::string output_file(RESULT_FULL_PATH(inline_1));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, audikw_1)
{
    std::string input_file(MATRIX_FULL_PATH(audikw_1));
    std::string output_file(RESULT_FULL_PATH(audikw_1));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, ML_Laplace)
{
    std::string input_file(MATRIX_FULL_PATH(ML_Laplace));
    std::string output_file(RESULT_FULL_PATH(ML_Laplace));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, dielFilterV3real)
{
    std::string input_file(MATRIX_FULL_PATH(dielFilterV3real));
    std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, Flan_1565)
{
    std::string input_file(MATRIX_FULL_PATH(Flan_1565));
    std::string output_file(RESULT_FULL_PATH(Flan_1565));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, Long_Coup_dt0)
{
    std::string input_file(MATRIX_FULL_PATH(Long_Coup_dt0));
    std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
TEST(mxv_test_VNEC_FP64_MM, mip1)
{
    std::string input_file(MATRIX_FULL_PATH(mip1));
    std::string output_file(RESULT_FULL_PATH(mip1));
    test_spmv_vnec_fp64_MM(input_file, output_file, false);
}
