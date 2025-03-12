/*
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, roadNet_CA)
{
    std::string input_file(MATRIX_FULL_PATH(roadNet-CA));
    std::string output_file(RESULT_FULL_PATH(roadNet-CA));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, amazon0312)
{
    std::string input_file(MATRIX_FULL_PATH(amazon0312));
    std::string output_file(RESULT_FULL_PATH(amazon0312));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP32_COMMON, com_Youtube)
{
    std::string input_file(MATRIX_FULL_PATH(com-Youtube));
    std::string output_file(RESULT_FULL_PATH(com-Youtube));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, web_Stanford)
{
    std::string input_file(MATRIX_FULL_PATH(web-Stanford));
    std::string output_file(RESULT_FULL_PATH(web-Stanford));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, as_Skitter)
{
    std::string input_file(MATRIX_FULL_PATH(as-Skitter));
    std::string output_file(RESULT_FULL_PATH(as-Skitter));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, road_usa)
{
    std::string input_file(MATRIX_FULL_PATH(road_usa));
    std::string output_file(RESULT_FULL_PATH(road_usa));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP32_COMMON, coAuthorsCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer));
    std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP32_COMMON, coAuthorsDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP));
    std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, web_Google)
{
    std::string input_file(MATRIX_FULL_PATH(web-Google));
    std::string output_file(RESULT_FULL_PATH(web-Google));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, com_Orkut)
{
    std::string input_file(MATRIX_FULL_PATH(com-Orkut));
    std::string output_file(RESULT_FULL_PATH(com-Orkut));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP32_COMMON, higgs_twitter)
{
    std::string input_file(MATRIX_FULL_PATH(higgs-twitter));
    std::string output_file(RESULT_FULL_PATH(higgs-twitter));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, wiki_topcats)
{
    std::string input_file(MATRIX_FULL_PATH(wiki-topcats));
    std::string output_file(RESULT_FULL_PATH(wiki-topcats));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, web_BerkStan)
{
    std::string input_file(MATRIX_FULL_PATH(web-BerkStan));
    std::string output_file(RESULT_FULL_PATH(web-BerkStan));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, com_Amazon)
{
    std::string input_file(MATRIX_FULL_PATH(com-Amazon));
    std::string output_file(RESULT_FULL_PATH(com-Amazon));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, com_DBLP)
{
    std::string input_file(MATRIX_FULL_PATH(com-DBLP));
    std::string output_file(RESULT_FULL_PATH(com-DBLP));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
*/
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, TSOPF_RS_b2383)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, coPapersCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer));
    std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, eu_2005)
{
    std::string input_file(MATRIX_FULL_PATH(eu-2005));
    std::string output_file(RESULT_FULL_PATH(eu-2005));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, crankseg_2)
{
    std::string input_file(MATRIX_FULL_PATH(crankseg_2));
    std::string output_file(RESULT_FULL_PATH(crankseg_2));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, nd12k)
{
    std::string input_file(MATRIX_FULL_PATH(nd12k));
    std::string output_file(RESULT_FULL_PATH(nd12k));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, coPapersDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coPapersDBLP));
    std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP32_COMMON, cnr_2000)
{
    std::string input_file(MATRIX_FULL_PATH(cnr-2000));
    std::string output_file(RESULT_FULL_PATH(cnr-2000));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, msdoor)
{
    std::string input_file(MATRIX_FULL_PATH(msdoor));
    std::string output_file(RESULT_FULL_PATH(msdoor));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, bundle_adj)
{
    std::string input_file(MATRIX_FULL_PATH(bundle_adj));
    std::string output_file(RESULT_FULL_PATH(bundle_adj));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, F1)
{
    std::string input_file(MATRIX_FULL_PATH(F1));
    std::string output_file(RESULT_FULL_PATH(F1));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, inline_1)
{
    std::string input_file(MATRIX_FULL_PATH(inline_1));
    std::string output_file(RESULT_FULL_PATH(inline_1));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, audikw_1)
{
    std::string input_file(MATRIX_FULL_PATH(audikw_1));
    std::string output_file(RESULT_FULL_PATH(audikw_1));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, ML_Laplace)
{
    std::string input_file(MATRIX_FULL_PATH(ML_Laplace));
    std::string output_file(RESULT_FULL_PATH(ML_Laplace));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, dielFilterV3real)
{
    std::string input_file(MATRIX_FULL_PATH(dielFilterV3real));
    std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, Flan_1565)
{
    std::string input_file(MATRIX_FULL_PATH(Flan_1565));
    std::string output_file(RESULT_FULL_PATH(Flan_1565));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, Long_Coup_dt0)
{
    std::string input_file(MATRIX_FULL_PATH(Long_Coup_dt0));
    std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}
TEST(cuda_test_spmv_LBNEC_FP32_COMMON, mip1)
{
    std::string input_file(MATRIX_FULL_PATH(mip1));
    std::string output_file(RESULT_FULL_PATH(mip1));
    test_SpMV_accu_perf<perfSpB_SpMV_LBNEC_FP32>(input_file, output_file, false);
}















// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, roadNet_CA)
// {
//     std::string input_file(MATRIX_FULL_PATH(roadNet-CA));
//     std::string output_file(RESULT_FULL_PATH(roadNet-CA));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, amazon0312)
// {
//     std::string input_file(MATRIX_FULL_PATH(amazon0312));
//     std::string output_file(RESULT_FULL_PATH(amazon0312));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, com_Youtube)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Youtube));
//     std::string output_file(RESULT_FULL_PATH(com-Youtube));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, web_Stanford)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Stanford));
//     std::string output_file(RESULT_FULL_PATH(web-Stanford));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, as_Skitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(as-Skitter));
//     std::string output_file(RESULT_FULL_PATH(as-Skitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, road_usa)
// {
//     std::string input_file(MATRIX_FULL_PATH(road_usa));
//     std::string output_file(RESULT_FULL_PATH(road_usa));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, coAuthorsCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, coAuthorsDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, web_Google)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Google));
//     std::string output_file(RESULT_FULL_PATH(web-Google));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, com_Orkut)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Orkut));
//     std::string output_file(RESULT_FULL_PATH(com-Orkut));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, higgs_twitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(higgs-twitter));
//     std::string output_file(RESULT_FULL_PATH(higgs-twitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, wiki_topcats)
// {
//     std::string input_file(MATRIX_FULL_PATH(wiki-topcats));
//     std::string output_file(RESULT_FULL_PATH(wiki-topcats));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, web_BerkStan)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-BerkStan));
//     std::string output_file(RESULT_FULL_PATH(web-BerkStan));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, com_Amazon)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Amazon));
//     std::string output_file(RESULT_FULL_PATH(com-Amazon));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, com_DBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-DBLP));
//     std::string output_file(RESULT_FULL_PATH(com-DBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, TSOPF_RS_b2383)
// {
//     std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383));
//     std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, coPapersCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, eu_2005)
// {
//     std::string input_file(MATRIX_FULL_PATH(eu-2005));
//     std::string output_file(RESULT_FULL_PATH(eu-2005));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, crankseg_2)
// {
//     std::string input_file(MATRIX_FULL_PATH(crankseg_2));
//     std::string output_file(RESULT_FULL_PATH(crankseg_2));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, nd12k)
// {
//     std::string input_file(MATRIX_FULL_PATH(nd12k));
//     std::string output_file(RESULT_FULL_PATH(nd12k));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, coPapersDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersDBLP));
//     std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, cnr_2000)
// {
//     std::string input_file(MATRIX_FULL_PATH(cnr-2000));
//     std::string output_file(RESULT_FULL_PATH(cnr-2000));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, msdoor)
// {
//     std::string input_file(MATRIX_FULL_PATH(msdoor));
//     std::string output_file(RESULT_FULL_PATH(msdoor));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, bundle_adj)
// {
//     std::string input_file(MATRIX_FULL_PATH(bundle_adj));
//     std::string output_file(RESULT_FULL_PATH(bundle_adj));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, F1)
// {
//     std::string input_file(MATRIX_FULL_PATH(F1));
//     std::string output_file(RESULT_FULL_PATH(F1));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, inline_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(inline_1));
//     std::string output_file(RESULT_FULL_PATH(inline_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, audikw_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(audikw_1));
//     std::string output_file(RESULT_FULL_PATH(audikw_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, ML_Laplace)
// {
//     std::string input_file(MATRIX_FULL_PATH(ML_Laplace));
//     std::string output_file(RESULT_FULL_PATH(ML_Laplace));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, dielFilterV3real)
// {
//     std::string input_file(MATRIX_FULL_PATH(dielFilterV3real));
//     std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, Flan_1565)
// {
//     std::string input_file(MATRIX_FULL_PATH(Flan_1565));
//     std::string output_file(RESULT_FULL_PATH(Flan_1565));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, Long_Coup_dt0)
// {
//     std::string input_file(MATRIX_FULL_PATH(Long_Coup_dt0));
//     std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_LIGHT_FP32_COMMON, mip1)
// {
//     std::string input_file(MATRIX_FULL_PATH(mip1));
//     std::string output_file(RESULT_FULL_PATH(mip1));
//     test_SpMV_accu_perf<perfSpB_SpMV_LIGHT_FP32>(input_file, output_file, false);
// }




// TEST(cuda_test_spmv_FP32_COMMON, roadNet_CA)
// {
//     std::string input_file(MATRIX_FULL_PATH(roadNet-CA));
//     std::string output_file(RESULT_FULL_PATH(roadNet-CA));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, amazon0312)
// {
//     std::string input_file(MATRIX_FULL_PATH(amazon0312));
//     std::string output_file(RESULT_FULL_PATH(amazon0312));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FP32_COMMON, com_Youtube)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Youtube));
//     std::string output_file(RESULT_FULL_PATH(com-Youtube));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, web_Stanford)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Stanford));
//     std::string output_file(RESULT_FULL_PATH(web-Stanford));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, as_Skitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(as-Skitter));
//     std::string output_file(RESULT_FULL_PATH(as-Skitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, road_usa)
// {
//     std::string input_file(MATRIX_FULL_PATH(road_usa));
//     std::string output_file(RESULT_FULL_PATH(road_usa));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FP32_COMMON, coAuthorsCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FP32_COMMON, coAuthorsDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, web_Google)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Google));
//     std::string output_file(RESULT_FULL_PATH(web-Google));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, com_Orkut)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Orkut));
//     std::string output_file(RESULT_FULL_PATH(com-Orkut));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FP32_COMMON, higgs_twitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(higgs-twitter));
//     std::string output_file(RESULT_FULL_PATH(higgs-twitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, wiki_topcats)
// {
//     std::string input_file(MATRIX_FULL_PATH(wiki-topcats));
//     std::string output_file(RESULT_FULL_PATH(wiki-topcats));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, web_BerkStan)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-BerkStan));
//     std::string output_file(RESULT_FULL_PATH(web-BerkStan));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, com_Amazon)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Amazon));
//     std::string output_file(RESULT_FULL_PATH(com-Amazon));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, com_DBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-DBLP));
//     std::string output_file(RESULT_FULL_PATH(com-DBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FP32_COMMON, TSOPF_RS_b2383)
// {
//     std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383));
//     std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, coPapersCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, eu_2005)
// {
//     std::string input_file(MATRIX_FULL_PATH(eu-2005));
//     std::string output_file(RESULT_FULL_PATH(eu-2005));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, crankseg_2)
// {
//     std::string input_file(MATRIX_FULL_PATH(crankseg_2));
//     std::string output_file(RESULT_FULL_PATH(crankseg_2));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, nd12k)
// {
//     std::string input_file(MATRIX_FULL_PATH(nd12k));
//     std::string output_file(RESULT_FULL_PATH(nd12k));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, coPapersDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersDBLP));
//     std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FP32_COMMON, cnr_2000)
// {
//     std::string input_file(MATRIX_FULL_PATH(cnr-2000));
//     std::string output_file(RESULT_FULL_PATH(cnr-2000));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, msdoor)
// {
//     std::string input_file(MATRIX_FULL_PATH(msdoor));
//     std::string output_file(RESULT_FULL_PATH(msdoor));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, bundle_adj)
// {
//     std::string input_file(MATRIX_FULL_PATH(bundle_adj));
//     std::string output_file(RESULT_FULL_PATH(bundle_adj));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, F1)
// {
//     std::string input_file(MATRIX_FULL_PATH(F1));
//     std::string output_file(RESULT_FULL_PATH(F1));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, inline_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(inline_1));
//     std::string output_file(RESULT_FULL_PATH(inline_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, audikw_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(audikw_1));
//     std::string output_file(RESULT_FULL_PATH(audikw_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, ML_Laplace)
// {
//     std::string input_file(MATRIX_FULL_PATH(ML_Laplace));
//     std::string output_file(RESULT_FULL_PATH(ML_Laplace));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, dielFilterV3real)
// {
//     std::string input_file(MATRIX_FULL_PATH(dielFilterV3real));
//     std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, Flan_1565)
// {
//     std::string input_file(MATRIX_FULL_PATH(Flan_1565));
//     std::string output_file(RESULT_FULL_PATH(Flan_1565));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, Long_Coup_dt0)
// {
//     std::string input_file(MATRIX_FULL_PATH(Long_Coup_dt0));
//     std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FP32_COMMON, mip1)
// {
//     std::string input_file(MATRIX_FULL_PATH(mip1));
//     std::string output_file(RESULT_FULL_PATH(mip1));
//     test_SpMV_accu_perf<perfSpB_SpMV_FP32>(input_file, output_file, false);
// }





// TEST(cuda_test_spmv_ADP_FP32_COMMON, roadNet_CA)
// {
//     std::string input_file(MATRIX_FULL_PATH(roadNet-CA));
//     std::string output_file(RESULT_FULL_PATH(roadNet-CA));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, amazon0312)
// {
//     std::string input_file(MATRIX_FULL_PATH(amazon0312));
//     std::string output_file(RESULT_FULL_PATH(amazon0312));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_ADP_FP32_COMMON, com_Youtube)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Youtube));
//     std::string output_file(RESULT_FULL_PATH(com-Youtube));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, web_Stanford)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Stanford));
//     std::string output_file(RESULT_FULL_PATH(web-Stanford));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, as_Skitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(as-Skitter));
//     std::string output_file(RESULT_FULL_PATH(as-Skitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, road_usa)
// {
//     std::string input_file(MATRIX_FULL_PATH(road_usa));
//     std::string output_file(RESULT_FULL_PATH(road_usa));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_ADP_FP32_COMMON, coAuthorsCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_ADP_FP32_COMMON, coAuthorsDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, web_Google)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Google));
//     std::string output_file(RESULT_FULL_PATH(web-Google));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, com_Orkut)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Orkut));
//     std::string output_file(RESULT_FULL_PATH(com-Orkut));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_ADP_FP32_COMMON, higgs_twitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(higgs-twitter));
//     std::string output_file(RESULT_FULL_PATH(higgs-twitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, wiki_topcats)
// {
//     std::string input_file(MATRIX_FULL_PATH(wiki-topcats));
//     std::string output_file(RESULT_FULL_PATH(wiki-topcats));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, web_BerkStan)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-BerkStan));
//     std::string output_file(RESULT_FULL_PATH(web-BerkStan));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, com_Amazon)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Amazon));
//     std::string output_file(RESULT_FULL_PATH(com-Amazon));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, com_DBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-DBLP));
//     std::string output_file(RESULT_FULL_PATH(com-DBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }

// // TEST(cuda_test_spmv_ADP_FP32_COMMON, TSOPF_RS_b2383)
// // {
// //     std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383));
// //     std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
// //     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// // }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, coPapersCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, eu_2005)
// {
//     std::string input_file(MATRIX_FULL_PATH(eu-2005));
//     std::string output_file(RESULT_FULL_PATH(eu-2005));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, crankseg_2)
// {
//     std::string input_file(MATRIX_FULL_PATH(crankseg_2));
//     std::string output_file(RESULT_FULL_PATH(crankseg_2));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// // TEST(cuda_test_spmv_ADP_FP32_COMMON, nd12k)
// // {
// //     std::string input_file(MATRIX_FULL_PATH(nd12k));
// //     std::string output_file(RESULT_FULL_PATH(nd12k));
// //     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// // }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, coPapersDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersDBLP));
//     std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_ADP_FP32_COMMON, cnr_2000)
// {
//     std::string input_file(MATRIX_FULL_PATH(cnr-2000));
//     std::string output_file(RESULT_FULL_PATH(cnr-2000));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, msdoor)
// {
//     std::string input_file(MATRIX_FULL_PATH(msdoor));
//     std::string output_file(RESULT_FULL_PATH(msdoor));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, bundle_adj)
// {
//     std::string input_file(MATRIX_FULL_PATH(bundle_adj));
//     std::string output_file(RESULT_FULL_PATH(bundle_adj));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, F1)
// {
//     std::string input_file(MATRIX_FULL_PATH(F1));
//     std::string output_file(RESULT_FULL_PATH(F1));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// // TEST(cuda_test_spmv_ADP_FP32_COMMON, inline_1)
// // {
// //     std::string input_file(MATRIX_FULL_PATH(inline_1));
// //     std::string output_file(RESULT_FULL_PATH(inline_1));
// //     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// // }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, audikw_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(audikw_1));
//     std::string output_file(RESULT_FULL_PATH(audikw_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, ML_Laplace)
// {
//     std::string input_file(MATRIX_FULL_PATH(ML_Laplace));
//     std::string output_file(RESULT_FULL_PATH(ML_Laplace));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, dielFilterV3real)
// {
//     std::string input_file(MATRIX_FULL_PATH(dielFilterV3real));
//     std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, Flan_1565)
// {
//     std::string input_file(MATRIX_FULL_PATH(Flan_1565));
//     std::string output_file(RESULT_FULL_PATH(Flan_1565));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, Long_Coup_dt0)
// {
//     std::string input_file(MATRIX_FULL_PATH(Long_Coup_dt0));
//     std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_ADP_FP32_COMMON, mip1)
// {
//     std::string input_file(MATRIX_FULL_PATH(mip1));
//     std::string output_file(RESULT_FULL_PATH(mip1));
//     test_SpMV_accu_perf<perfSpB_SpMV_Adaptive_FP32>(input_file, output_file, false);
// }


// TEST(cuda_test_spmv_PCSR_FP32_COMMON, roadNet_CA)
// {
//     std::string input_file(MATRIX_FULL_PATH(roadNet-CA));
//     std::string output_file(RESULT_FULL_PATH(roadNet-CA));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, amazon0312)
// {
//     std::string input_file(MATRIX_FULL_PATH(amazon0312));
//     std::string output_file(RESULT_FULL_PATH(amazon0312));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_PCSR_FP32_COMMON, com_Youtube)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Youtube));
//     std::string output_file(RESULT_FULL_PATH(com-Youtube));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, web_Stanford)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Stanford));
//     std::string output_file(RESULT_FULL_PATH(web-Stanford));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, as_Skitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(as-Skitter));
//     std::string output_file(RESULT_FULL_PATH(as-Skitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, road_usa)
// {
//     std::string input_file(MATRIX_FULL_PATH(road_usa));
//     std::string output_file(RESULT_FULL_PATH(road_usa));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_PCSR_FP32_COMMON, coAuthorsCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_PCSR_FP32_COMMON, coAuthorsDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, web_Google)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Google));
//     std::string output_file(RESULT_FULL_PATH(web-Google));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, com_Orkut)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Orkut));
//     std::string output_file(RESULT_FULL_PATH(com-Orkut));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_PCSR_FP32_COMMON, higgs_twitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(higgs-twitter));
//     std::string output_file(RESULT_FULL_PATH(higgs-twitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, wiki_topcats)
// {
//     std::string input_file(MATRIX_FULL_PATH(wiki-topcats));
//     std::string output_file(RESULT_FULL_PATH(wiki-topcats));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, web_BerkStan)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-BerkStan));
//     std::string output_file(RESULT_FULL_PATH(web-BerkStan));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, com_Amazon)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Amazon));
//     std::string output_file(RESULT_FULL_PATH(com-Amazon));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, com_DBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-DBLP));
//     std::string output_file(RESULT_FULL_PATH(com-DBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_PCSR_FP32_COMMON, TSOPF_RS_b2383)
// {
//     std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383));
//     std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, coPapersCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, eu_2005)
// {
//     std::string input_file(MATRIX_FULL_PATH(eu-2005));
//     std::string output_file(RESULT_FULL_PATH(eu-2005));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, crankseg_2)
// {
//     std::string input_file(MATRIX_FULL_PATH(crankseg_2));
//     std::string output_file(RESULT_FULL_PATH(crankseg_2));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, nd12k)
// {
//     std::string input_file(MATRIX_FULL_PATH(nd12k));
//     std::string output_file(RESULT_FULL_PATH(nd12k));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, coPapersDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersDBLP));
//     std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_PCSR_FP32_COMMON, cnr_2000)
// {
//     std::string input_file(MATRIX_FULL_PATH(cnr-2000));
//     std::string output_file(RESULT_FULL_PATH(cnr-2000));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, msdoor)
// {
//     std::string input_file(MATRIX_FULL_PATH(msdoor));
//     std::string output_file(RESULT_FULL_PATH(msdoor));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, bundle_adj)
// {
//     std::string input_file(MATRIX_FULL_PATH(bundle_adj));
//     std::string output_file(RESULT_FULL_PATH(bundle_adj));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, F1)
// {
//     std::string input_file(MATRIX_FULL_PATH(F1));
//     std::string output_file(RESULT_FULL_PATH(F1));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, inline_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(inline_1));
//     std::string output_file(RESULT_FULL_PATH(inline_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, audikw_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(audikw_1));
//     std::string output_file(RESULT_FULL_PATH(audikw_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, ML_Laplace)
// {
//     std::string input_file(MATRIX_FULL_PATH(ML_Laplace));
//     std::string output_file(RESULT_FULL_PATH(ML_Laplace));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, dielFilterV3real)
// {
//     std::string input_file(MATRIX_FULL_PATH(dielFilterV3real));
//     std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, Flan_1565)
// {
//     std::string input_file(MATRIX_FULL_PATH(Flan_1565));
//     std::string output_file(RESULT_FULL_PATH(Flan_1565));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, Long_Coup_dt0)
// {
//     std::string input_file(MATRIX_FULL_PATH(Long_Coup_dt0));
//     std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_PCSR_FP32_COMMON, mip1)
// {
//     std::string input_file(MATRIX_FULL_PATH(mip1));
//     std::string output_file(RESULT_FULL_PATH(mip1));
//     test_SpMV_accu_perf<perfSpB_SpMV_PCSR_FP32>(input_file, output_file, false);
// }



// TEST(cuda_test_spmv_FLAT_FP32_COMMON, roadNet_CA)
// {
//     std::string input_file(MATRIX_FULL_PATH(roadNet-CA));
//     std::string output_file(RESULT_FULL_PATH(roadNet-CA));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, amazon0312)
// {
//     std::string input_file(MATRIX_FULL_PATH(amazon0312));
//     std::string output_file(RESULT_FULL_PATH(amazon0312));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FLAT_FP32_COMMON, com_Youtube)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Youtube));
//     std::string output_file(RESULT_FULL_PATH(com-Youtube));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, web_Stanford)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Stanford));
//     std::string output_file(RESULT_FULL_PATH(web-Stanford));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, as_Skitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(as-Skitter));
//     std::string output_file(RESULT_FULL_PATH(as-Skitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, road_usa)
// {
//     std::string input_file(MATRIX_FULL_PATH(road_usa));
//     std::string output_file(RESULT_FULL_PATH(road_usa));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FLAT_FP32_COMMON, coAuthorsCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FLAT_FP32_COMMON, coAuthorsDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP));
//     std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, web_Google)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-Google));
//     std::string output_file(RESULT_FULL_PATH(web-Google));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, com_Orkut)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Orkut));
//     std::string output_file(RESULT_FULL_PATH(com-Orkut));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FLAT_FP32_COMMON, higgs_twitter)
// {
//     std::string input_file(MATRIX_FULL_PATH(higgs-twitter));
//     std::string output_file(RESULT_FULL_PATH(higgs-twitter));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, wiki_topcats)
// {
//     std::string input_file(MATRIX_FULL_PATH(wiki-topcats));
//     std::string output_file(RESULT_FULL_PATH(wiki-topcats));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, web_BerkStan)
// {
//     std::string input_file(MATRIX_FULL_PATH(web-BerkStan));
//     std::string output_file(RESULT_FULL_PATH(web-BerkStan));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, com_Amazon)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-Amazon));
//     std::string output_file(RESULT_FULL_PATH(com-Amazon));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, com_DBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(com-DBLP));
//     std::string output_file(RESULT_FULL_PATH(com-DBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FLAT_FP32_COMMON, TSOPF_RS_b2383)
// {
//     std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383));
//     std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, coPapersCiteseer)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer));
//     std::string output_file(RESULT_FULL_PATH(coPapersCiteseer));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, eu_2005)
// {
//     std::string input_file(MATRIX_FULL_PATH(eu-2005));
//     std::string output_file(RESULT_FULL_PATH(eu-2005));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, crankseg_2)
// {
//     std::string input_file(MATRIX_FULL_PATH(crankseg_2));
//     std::string output_file(RESULT_FULL_PATH(crankseg_2));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, nd12k)
// {
//     std::string input_file(MATRIX_FULL_PATH(nd12k));
//     std::string output_file(RESULT_FULL_PATH(nd12k));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, coPapersDBLP)
// {
//     std::string input_file(MATRIX_FULL_PATH(coPapersDBLP));
//     std::string output_file(RESULT_FULL_PATH(coPapersDBLP));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }

// TEST(cuda_test_spmv_FLAT_FP32_COMMON, cnr_2000)
// {
//     std::string input_file(MATRIX_FULL_PATH(cnr-2000));
//     std::string output_file(RESULT_FULL_PATH(cnr-2000));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, msdoor)
// {
//     std::string input_file(MATRIX_FULL_PATH(msdoor));
//     std::string output_file(RESULT_FULL_PATH(msdoor));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, bundle_adj)
// {
//     std::string input_file(MATRIX_FULL_PATH(bundle_adj));
//     std::string output_file(RESULT_FULL_PATH(bundle_adj));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, F1)
// {
//     std::string input_file(MATRIX_FULL_PATH(F1));
//     std::string output_file(RESULT_FULL_PATH(F1));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, inline_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(inline_1));
//     std::string output_file(RESULT_FULL_PATH(inline_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, audikw_1)
// {
//     std::string input_file(MATRIX_FULL_PATH(audikw_1));
//     std::string output_file(RESULT_FULL_PATH(audikw_1));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, ML_Laplace)
// {
//     std::string input_file(MATRIX_FULL_PATH(ML_Laplace));
//     std::string output_file(RESULT_FULL_PATH(ML_Laplace));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, dielFilterV3real)
// {
//     std::string input_file(MATRIX_FULL_PATH(dielFilterV3real));
//     std::string output_file(RESULT_FULL_PATH(dielFilterV3real));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, Flan_1565)
// {
//     std::string input_file(MATRIX_FULL_PATH(Flan_1565));
//     std::string output_file(RESULT_FULL_PATH(Flan_1565));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, Long_Coup_dt0)
// {
//     std::string input_file(MATRIX_FULL_PATH(Long_Coup_dt0));
//     std::string output_file(RESULT_FULL_PATH(Long_Coup_dt0));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }
// TEST(cuda_test_spmv_FLAT_FP32_COMMON, mip1)
// {
//     std::string input_file(MATRIX_FULL_PATH(mip1));
//     std::string output_file(RESULT_FULL_PATH(mip1));
//     test_SpMV_accu_perf<perfSpB_SpMV_flat_FP32>(input_file, output_file, false);
// }