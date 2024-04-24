TEST(cuda_test_spmv_LBNEC_FP64, 3Dspectralwave)
{
    std::string input_file(MATRIX_FULL_PATH(3Dspectralwave ));
    std::string output_file(RESULT_FULL_PATH(3Dspectralwave ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adaptive)
{
    std::string input_file(MATRIX_FULL_PATH(adaptive ));
    std::string output_file(RESULT_FULL_PATH(adaptive ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell10)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell10 ));
    std::string output_file(RESULT_FULL_PATH(af_shell10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, amazon_2008)
{
    std::string input_file(MATRIX_FULL_PATH(amazon-2008 ));
    std::string output_file(RESULT_FULL_PATH(amazon-2008 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, apache2)
{
    std::string input_file(MATRIX_FULL_PATH(apache2 ));
    std::string output_file(RESULT_FULL_PATH(apache2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, asia_osm)
{
    std::string input_file(MATRIX_FULL_PATH(asia_osm ));
    std::string output_file(RESULT_FULL_PATH(asia_osm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ASIC_680ks)
{
    std::string input_file(MATRIX_FULL_PATH(ASIC_680ks ));
    std::string output_file(RESULT_FULL_PATH(ASIC_680ks ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ASIC_680k)
{
    std::string input_file(MATRIX_FULL_PATH(ASIC_680k ));
    std::string output_file(RESULT_FULL_PATH(ASIC_680k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, as_Skitter)
{
    std::string input_file(MATRIX_FULL_PATH(as-Skitter ));
    std::string output_file(RESULT_FULL_PATH(as-Skitter ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, atmosmodd)
{
    std::string input_file(MATRIX_FULL_PATH(atmosmodd ));
    std::string output_file(RESULT_FULL_PATH(atmosmodd ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, atmosmodj)
{
    std::string input_file(MATRIX_FULL_PATH(atmosmodj ));
    std::string output_file(RESULT_FULL_PATH(atmosmodj ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, atmosmodl)
{
    std::string input_file(MATRIX_FULL_PATH(atmosmodl ));
    std::string output_file(RESULT_FULL_PATH(atmosmodl ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, atmosmodm)
{
    std::string input_file(MATRIX_FULL_PATH(atmosmodm ));
    std::string output_file(RESULT_FULL_PATH(atmosmodm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, audikw_1)
{
    std::string input_file(MATRIX_FULL_PATH(audikw_1 ));
    std::string output_file(RESULT_FULL_PATH(audikw_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, belgium_osm)
{
    std::string input_file(MATRIX_FULL_PATH(belgium_osm ));
    std::string output_file(RESULT_FULL_PATH(belgium_osm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bone010)
{
    std::string input_file(MATRIX_FULL_PATH(bone010 ));
    std::string output_file(RESULT_FULL_PATH(bone010 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, boneS10)
{
    std::string input_file(MATRIX_FULL_PATH(boneS10 ));
    std::string output_file(RESULT_FULL_PATH(boneS10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage14)
{
    std::string input_file(MATRIX_FULL_PATH(cage14 ));
    std::string output_file(RESULT_FULL_PATH(cage14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage15)
{
    std::string input_file(MATRIX_FULL_PATH(cage15 ));
    std::string output_file(RESULT_FULL_PATH(cage15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, channel_500x100x100_b050)
{
    std::string input_file(MATRIX_FULL_PATH(channel-500x100x100-b050 ));
    std::string output_file(RESULT_FULL_PATH(channel-500x100x100-b050 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, circuit5M_dc)
{
    std::string input_file(MATRIX_FULL_PATH(circuit5M_dc ));
    std::string output_file(RESULT_FULL_PATH(circuit5M_dc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, circuit5M)
{
    std::string input_file(MATRIX_FULL_PATH(circuit5M ));
    std::string output_file(RESULT_FULL_PATH(circuit5M ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cit_Patents)
{
    std::string input_file(MATRIX_FULL_PATH(cit-Patents ));
    std::string output_file(RESULT_FULL_PATH(cit-Patents ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, coPapersDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coPapersDBLP ));
    std::string output_file(RESULT_FULL_PATH(coPapersDBLP ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, debr)
{
    std::string input_file(MATRIX_FULL_PATH(debr ));
    std::string output_file(RESULT_FULL_PATH(debr ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n20)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n20 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n21)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n21 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n22)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n22 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n23)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n23 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dielFilterV2clx)
{
    std::string input_file(MATRIX_FULL_PATH(dielFilterV2clx ));
    std::string output_file(RESULT_FULL_PATH(dielFilterV2clx ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dielFilterV2real)
{
    std::string input_file(MATRIX_FULL_PATH(dielFilterV2real ));
    std::string output_file(RESULT_FULL_PATH(dielFilterV2real ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dielFilterV3real)
{
    std::string input_file(MATRIX_FULL_PATH(dielFilterV3real ));
    std::string output_file(RESULT_FULL_PATH(dielFilterV3real ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ecology1)
{
    std::string input_file(MATRIX_FULL_PATH(ecology1 ));
    std::string output_file(RESULT_FULL_PATH(ecology1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ecology2)
{
    std::string input_file(MATRIX_FULL_PATH(ecology2 ));
    std::string output_file(RESULT_FULL_PATH(ecology2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Emilia_923)
{
    std::string input_file(MATRIX_FULL_PATH(Emilia_923 ));
    std::string output_file(RESULT_FULL_PATH(Emilia_923 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, eu_2005)
{
    std::string input_file(MATRIX_FULL_PATH(eu-2005 ));
    std::string output_file(RESULT_FULL_PATH(eu-2005 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Fault_639)
{
    std::string input_file(MATRIX_FULL_PATH(Fault_639 ));
    std::string output_file(RESULT_FULL_PATH(Fault_639 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, flickr)
{
    std::string input_file(MATRIX_FULL_PATH(flickr ));
    std::string output_file(RESULT_FULL_PATH(flickr ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Freescale1)
{
    std::string input_file(MATRIX_FULL_PATH(Freescale1 ));
    std::string output_file(RESULT_FULL_PATH(Freescale1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, FullChip)
{
    std::string input_file(MATRIX_FULL_PATH(FullChip ));
    std::string output_file(RESULT_FULL_PATH(FullChip ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G3_circuit)
{
    std::string input_file(MATRIX_FULL_PATH(G3_circuit ));
    std::string output_file(RESULT_FULL_PATH(G3_circuit ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Geo_1438)
{
    std::string input_file(MATRIX_FULL_PATH(Geo_1438 ));
    std::string output_file(RESULT_FULL_PATH(Geo_1438 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, germany_osm)
{
    std::string input_file(MATRIX_FULL_PATH(germany_osm ));
    std::string output_file(RESULT_FULL_PATH(germany_osm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, great_britain_osm)
{
    std::string input_file(MATRIX_FULL_PATH(great-britain_osm ));
    std::string output_file(RESULT_FULL_PATH(great-britain_osm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gsm_106857)
{
    std::string input_file(MATRIX_FULL_PATH(gsm_106857 ));
    std::string output_file(RESULT_FULL_PATH(gsm_106857 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Hamrle3)
{
    std::string input_file(MATRIX_FULL_PATH(Hamrle3 ));
    std::string output_file(RESULT_FULL_PATH(Hamrle3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Hook_1498)
{
    std::string input_file(MATRIX_FULL_PATH(Hook_1498 ));
    std::string output_file(RESULT_FULL_PATH(Hook_1498 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugebubbles_00000)
{
    std::string input_file(MATRIX_FULL_PATH(hugebubbles-00000 ));
    std::string output_file(RESULT_FULL_PATH(hugebubbles-00000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugebubbles_00010)
{
    std::string input_file(MATRIX_FULL_PATH(hugebubbles-00010 ));
    std::string output_file(RESULT_FULL_PATH(hugebubbles-00010 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugebubbles_00020)
{
    std::string input_file(MATRIX_FULL_PATH(hugebubbles-00020 ));
    std::string output_file(RESULT_FULL_PATH(hugebubbles-00020 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugetrace_00000)
{
    std::string input_file(MATRIX_FULL_PATH(hugetrace-00000 ));
    std::string output_file(RESULT_FULL_PATH(hugetrace-00000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugetrace_00010)
{
    std::string input_file(MATRIX_FULL_PATH(hugetrace-00010 ));
    std::string output_file(RESULT_FULL_PATH(hugetrace-00010 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugetrace_00020)
{
    std::string input_file(MATRIX_FULL_PATH(hugetrace-00020 ));
    std::string output_file(RESULT_FULL_PATH(hugetrace-00020 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugetric_00000)
{
    std::string input_file(MATRIX_FULL_PATH(hugetric-00000 ));
    std::string output_file(RESULT_FULL_PATH(hugetric-00000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugetric_00010)
{
    std::string input_file(MATRIX_FULL_PATH(hugetric-00010 ));
    std::string output_file(RESULT_FULL_PATH(hugetric-00010 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hugetric_00020)
{
    std::string input_file(MATRIX_FULL_PATH(hugetric-00020 ));
    std::string output_file(RESULT_FULL_PATH(hugetric-00020 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, in_2004)
{
    std::string input_file(MATRIX_FULL_PATH(in-2004 ));
    std::string output_file(RESULT_FULL_PATH(in-2004 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, italy_osm)
{
    std::string input_file(MATRIX_FULL_PATH(italy_osm ));
    std::string output_file(RESULT_FULL_PATH(italy_osm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, kkt_power)
{
    std::string input_file(MATRIX_FULL_PATH(kkt_power ));
    std::string output_file(RESULT_FULL_PATH(kkt_power ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, kron_g500_logn20)
{
    std::string input_file(MATRIX_FULL_PATH(kron_g500-logn20 ));
    std::string output_file(RESULT_FULL_PATH(kron_g500-logn20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ldoor)
{
    std::string input_file(MATRIX_FULL_PATH(ldoor ));
    std::string output_file(RESULT_FULL_PATH(ldoor ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ljournal_2008)
{
    std::string input_file(MATRIX_FULL_PATH(ljournal-2008 ));
    std::string output_file(RESULT_FULL_PATH(ljournal-2008 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lp1)
{
    std::string input_file(MATRIX_FULL_PATH(lp1 ));
    std::string output_file(RESULT_FULL_PATH(lp1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, memchip)
{
    std::string input_file(MATRIX_FULL_PATH(memchip ));
    std::string output_file(RESULT_FULL_PATH(memchip ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, netherlands_osm)
{
    std::string input_file(MATRIX_FULL_PATH(netherlands_osm ));
    std::string output_file(RESULT_FULL_PATH(netherlands_osm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nlpkkt120)
{
    std::string input_file(MATRIX_FULL_PATH(nlpkkt120 ));
    std::string output_file(RESULT_FULL_PATH(nlpkkt120 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nlpkkt80)
{
    std::string input_file(MATRIX_FULL_PATH(nlpkkt80 ));
    std::string output_file(RESULT_FULL_PATH(nlpkkt80 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, packing_500x100x100_b050)
{
    std::string input_file(MATRIX_FULL_PATH(packing-500x100x100-b050 ));
    std::string output_file(RESULT_FULL_PATH(packing-500x100x100-b050 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, parabolic_fem)
{
    std::string input_file(MATRIX_FULL_PATH(parabolic_fem ));
    std::string output_file(RESULT_FULL_PATH(parabolic_fem ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, patents)
{
    std::string input_file(MATRIX_FULL_PATH(patents ));
    std::string output_file(RESULT_FULL_PATH(patents ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pre2)
{
    std::string input_file(MATRIX_FULL_PATH(pre2 ));
    std::string output_file(RESULT_FULL_PATH(pre2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat29)
{
    std::string input_file(MATRIX_FULL_PATH(rajat29 ));
    std::string output_file(RESULT_FULL_PATH(rajat29 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat30)
{
    std::string input_file(MATRIX_FULL_PATH(rajat30 ));
    std::string output_file(RESULT_FULL_PATH(rajat30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat31)
{
    std::string input_file(MATRIX_FULL_PATH(rajat31 ));
    std::string output_file(RESULT_FULL_PATH(rajat31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rgg_n_2_20_s0)
{
    std::string input_file(MATRIX_FULL_PATH(rgg_n_2_20_s0 ));
    std::string output_file(RESULT_FULL_PATH(rgg_n_2_20_s0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rgg_n_2_21_s0)
{
    std::string input_file(MATRIX_FULL_PATH(rgg_n_2_21_s0 ));
    std::string output_file(RESULT_FULL_PATH(rgg_n_2_21_s0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rgg_n_2_22_s0)
{
    std::string input_file(MATRIX_FULL_PATH(rgg_n_2_22_s0 ));
    std::string output_file(RESULT_FULL_PATH(rgg_n_2_22_s0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, road_central)
{
    std::string input_file(MATRIX_FULL_PATH(road_central ));
    std::string output_file(RESULT_FULL_PATH(road_central ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, roadNet_CA)
{
    std::string input_file(MATRIX_FULL_PATH(roadNet-CA ));
    std::string output_file(RESULT_FULL_PATH(roadNet-CA ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, roadNet_PA)
{
    std::string input_file(MATRIX_FULL_PATH(roadNet-PA ));
    std::string output_file(RESULT_FULL_PATH(roadNet-PA ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, roadNet_TX)
{
    std::string input_file(MATRIX_FULL_PATH(roadNet-TX ));
    std::string output_file(RESULT_FULL_PATH(roadNet-TX ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, road_usa)
{
    std::string input_file(MATRIX_FULL_PATH(road_usa ));
    std::string output_file(RESULT_FULL_PATH(road_usa ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Serena)
{
    std::string input_file(MATRIX_FULL_PATH(Serena ));
    std::string output_file(RESULT_FULL_PATH(Serena ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, soc_LiveJournal1)
{
    std::string input_file(MATRIX_FULL_PATH(soc-LiveJournal1 ));
    std::string output_file(RESULT_FULL_PATH(soc-LiveJournal1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Stanford_Berkeley)
{
    std::string input_file(MATRIX_FULL_PATH(Stanford_Berkeley ));
    std::string output_file(RESULT_FULL_PATH(Stanford_Berkeley ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, StocF_1465)
{
    std::string input_file(MATRIX_FULL_PATH(StocF-1465 ));
    std::string output_file(RESULT_FULL_PATH(StocF-1465 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2em)
{
    std::string input_file(MATRIX_FULL_PATH(t2em ));
    std::string output_file(RESULT_FULL_PATH(t2em ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, thermal2)
{
    std::string input_file(MATRIX_FULL_PATH(thermal2 ));
    std::string output_file(RESULT_FULL_PATH(thermal2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tmt_sym)
{
    std::string input_file(MATRIX_FULL_PATH(tmt_sym ));
    std::string output_file(RESULT_FULL_PATH(tmt_sym ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tmt_unsym)
{
    std::string input_file(MATRIX_FULL_PATH(tmt_unsym ));
    std::string output_file(RESULT_FULL_PATH(tmt_unsym ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, venturiLevel3)
{
    std::string input_file(MATRIX_FULL_PATH(venturiLevel3 ));
    std::string output_file(RESULT_FULL_PATH(venturiLevel3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wb_edu)
{
    std::string input_file(MATRIX_FULL_PATH(wb-edu ));
    std::string output_file(RESULT_FULL_PATH(wb-edu ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, webbase_1M)
{
    std::string input_file(MATRIX_FULL_PATH(webbase-1M ));
    std::string output_file(RESULT_FULL_PATH(webbase-1M ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, web_BerkStan)
{
    std::string input_file(MATRIX_FULL_PATH(web-BerkStan ));
    std::string output_file(RESULT_FULL_PATH(web-BerkStan ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, web_Google)
{
    std::string input_file(MATRIX_FULL_PATH(web-Google ));
    std::string output_file(RESULT_FULL_PATH(web-Google ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wikipedia_20051105)
{
    std::string input_file(MATRIX_FULL_PATH(wikipedia-20051105 ));
    std::string output_file(RESULT_FULL_PATH(wikipedia-20051105 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wikipedia_20060925)
{
    std::string input_file(MATRIX_FULL_PATH(wikipedia-20060925 ));
    std::string output_file(RESULT_FULL_PATH(wikipedia-20060925 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wikipedia_20061104)
{
    std::string input_file(MATRIX_FULL_PATH(wikipedia-20061104 ));
    std::string output_file(RESULT_FULL_PATH(wikipedia-20061104 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wikipedia_20070206)
{
    std::string input_file(MATRIX_FULL_PATH(wikipedia-20070206 ));
    std::string output_file(RESULT_FULL_PATH(wikipedia-20070206 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wiki_Talk)
{
    std::string input_file(MATRIX_FULL_PATH(wiki-Talk ));
    std::string output_file(RESULT_FULL_PATH(wiki-Talk ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 1138_bus)
{
    std::string input_file(MATRIX_FULL_PATH(1138_bus ));
    std::string output_file(RESULT_FULL_PATH(1138_bus ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 144)
{
    std::string input_file(MATRIX_FULL_PATH(144 ));
    std::string output_file(RESULT_FULL_PATH(144 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 2cubes_sphere)
{
    std::string input_file(MATRIX_FULL_PATH(2cubes_sphere ));
    std::string output_file(RESULT_FULL_PATH(2cubes_sphere ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 2D_27628_bjtcai)
{
    std::string input_file(MATRIX_FULL_PATH(2D_27628_bjtcai ));
    std::string output_file(RESULT_FULL_PATH(2D_27628_bjtcai ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 2D_54019_highK)
{
    std::string input_file(MATRIX_FULL_PATH(2D_54019_highK ));
    std::string output_file(RESULT_FULL_PATH(2D_54019_highK ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 3D_28984_Tetra)
{
    std::string input_file(MATRIX_FULL_PATH(3D_28984_Tetra ));
    std::string output_file(RESULT_FULL_PATH(3D_28984_Tetra ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 3D_51448_3D)
{
    std::string input_file(MATRIX_FULL_PATH(3D_51448_3D ));
    std::string output_file(RESULT_FULL_PATH(3D_51448_3D ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 3Dspectralwave2)
{
    std::string input_file(MATRIX_FULL_PATH(3Dspectralwave2 ));
    std::string output_file(RESULT_FULL_PATH(3Dspectralwave2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 3dtube)
{
    std::string input_file(MATRIX_FULL_PATH(3dtube ));
    std::string output_file(RESULT_FULL_PATH(3dtube ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 3elt_dual)
{
    std::string input_file(MATRIX_FULL_PATH(3elt_dual ));
    std::string output_file(RESULT_FULL_PATH(3elt_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 3elt)
{
    std::string input_file(MATRIX_FULL_PATH(3elt ));
    std::string output_file(RESULT_FULL_PATH(3elt ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 494_bus)
{
    std::string input_file(MATRIX_FULL_PATH(494_bus ));
    std::string output_file(RESULT_FULL_PATH(494_bus ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 598a)
{
    std::string input_file(MATRIX_FULL_PATH(598a ));
    std::string output_file(RESULT_FULL_PATH(598a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 662_bus)
{
    std::string input_file(MATRIX_FULL_PATH(662_bus ));
    std::string output_file(RESULT_FULL_PATH(662_bus ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, 685_bus)
{
    std::string input_file(MATRIX_FULL_PATH(685_bus ));
    std::string output_file(RESULT_FULL_PATH(685_bus ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, a0nsdsil)
{
    std::string input_file(MATRIX_FULL_PATH(a0nsdsil ));
    std::string output_file(RESULT_FULL_PATH(a0nsdsil ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, a2nnsnsl)
{
    std::string input_file(MATRIX_FULL_PATH(a2nnsnsl ));
    std::string output_file(RESULT_FULL_PATH(a2nnsnsl ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, a5esindl)
{
    std::string input_file(MATRIX_FULL_PATH(a5esindl ));
    std::string output_file(RESULT_FULL_PATH(a5esindl ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ABACUS_shell_hd)
{
    std::string input_file(MATRIX_FULL_PATH(ABACUS_shell_hd ));
    std::string output_file(RESULT_FULL_PATH(ABACUS_shell_hd ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ABACUS_shell_ld)
{
    std::string input_file(MATRIX_FULL_PATH(ABACUS_shell_ld ));
    std::string output_file(RESULT_FULL_PATH(ABACUS_shell_ld ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ABACUS_shell_md)
{
    std::string input_file(MATRIX_FULL_PATH(ABACUS_shell_md ));
    std::string output_file(RESULT_FULL_PATH(ABACUS_shell_md ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ABACUS_shell_ud)
{
    std::string input_file(MATRIX_FULL_PATH(ABACUS_shell_ud ));
    std::string output_file(RESULT_FULL_PATH(ABACUS_shell_ud ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, add20)
{
    std::string input_file(MATRIX_FULL_PATH(add20 ));
    std::string output_file(RESULT_FULL_PATH(add20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, add32)
{
    std::string input_file(MATRIX_FULL_PATH(add32 ));
    std::string output_file(RESULT_FULL_PATH(add32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_01)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_01 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_02)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_02 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_03)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_03 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_04)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_04 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_05)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_05 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_06)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_06 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_07)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_07 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_08)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_08 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_09)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_09 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_10)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_10 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_11)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_11 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_12)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_12 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_13)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_13 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_14)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_14 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_15)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_15 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_16)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_16 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_17)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_17 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_18)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_18 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_19)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_19 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_20)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_20 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_21)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_21 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_22)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_22 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_23)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_23 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_24)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_24 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_25)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_25 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_26)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_26 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_27)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_27 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_28)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_28 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_29)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_29 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_29 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_30)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_30 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_31)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_31 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_32)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_32 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_33)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_33 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_33 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_34)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_34 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_34 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_35)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_35 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_35 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_36)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_36 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_37)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_37 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_37 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_38)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_38 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_38 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_39)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_39 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_39 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_40)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_40 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_40 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_41)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_41 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_41 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_42)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_42 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_42 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_43)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_43 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_43 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_44)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_44 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_44 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_45)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_45 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_45 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_46)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_46 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_46 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_47)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_47 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_47 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_48)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_48 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_48 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_49)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_49 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_49 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_50)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_50 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_50 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_51)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_51 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_51 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_52)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_52 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_52 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_53)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_53 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_53 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_54)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_54 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_54 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_55)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_55 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_55 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_56)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_56 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_56 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_57)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_57 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_57 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_58)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_58 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_58 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_59)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_59 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_59 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_60)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_60 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_60 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_61)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_61 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_61 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_62)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_62 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_62 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_63)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_63 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_63 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_64)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_64 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_64 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_65)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_65 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_65 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_66)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_66 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_66 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_67)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_67 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_67 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_68)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_68 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_68 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_dcop_69)
{
    std::string input_file(MATRIX_FULL_PATH(adder_dcop_69 ));
    std::string output_file(RESULT_FULL_PATH(adder_dcop_69 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_trans_01)
{
    std::string input_file(MATRIX_FULL_PATH(adder_trans_01 ));
    std::string output_file(RESULT_FULL_PATH(adder_trans_01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, adder_trans_02)
{
    std::string input_file(MATRIX_FULL_PATH(adder_trans_02 ));
    std::string output_file(RESULT_FULL_PATH(adder_trans_02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_0_k101)
{
    std::string input_file(MATRIX_FULL_PATH(af_0_k101 ));
    std::string output_file(RESULT_FULL_PATH(af_0_k101 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_1_k101)
{
    std::string input_file(MATRIX_FULL_PATH(af_1_k101 ));
    std::string output_file(RESULT_FULL_PATH(af_1_k101 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af23560)
{
    std::string input_file(MATRIX_FULL_PATH(af23560 ));
    std::string output_file(RESULT_FULL_PATH(af23560 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_2_k101)
{
    std::string input_file(MATRIX_FULL_PATH(af_2_k101 ));
    std::string output_file(RESULT_FULL_PATH(af_2_k101 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_3_k101)
{
    std::string input_file(MATRIX_FULL_PATH(af_3_k101 ));
    std::string output_file(RESULT_FULL_PATH(af_3_k101 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_4_k101)
{
    std::string input_file(MATRIX_FULL_PATH(af_4_k101 ));
    std::string output_file(RESULT_FULL_PATH(af_4_k101 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_5_k101)
{
    std::string input_file(MATRIX_FULL_PATH(af_5_k101 ));
    std::string output_file(RESULT_FULL_PATH(af_5_k101 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell1)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell1 ));
    std::string output_file(RESULT_FULL_PATH(af_shell1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell2)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell2 ));
    std::string output_file(RESULT_FULL_PATH(af_shell2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell3)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell3 ));
    std::string output_file(RESULT_FULL_PATH(af_shell3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell4)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell4 ));
    std::string output_file(RESULT_FULL_PATH(af_shell4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell5)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell5 ));
    std::string output_file(RESULT_FULL_PATH(af_shell5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell6)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell6 ));
    std::string output_file(RESULT_FULL_PATH(af_shell6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell7)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell7 ));
    std::string output_file(RESULT_FULL_PATH(af_shell7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell8)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell8 ));
    std::string output_file(RESULT_FULL_PATH(af_shell8 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, af_shell9)
{
    std::string input_file(MATRIX_FULL_PATH(af_shell9 ));
    std::string output_file(RESULT_FULL_PATH(af_shell9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, aft01)
{
    std::string input_file(MATRIX_FULL_PATH(aft01 ));
    std::string output_file(RESULT_FULL_PATH(aft01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, aft02)
{
    std::string input_file(MATRIX_FULL_PATH(aft02 ));
    std::string output_file(RESULT_FULL_PATH(aft02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, airfoil1_dual)
{
    std::string input_file(MATRIX_FULL_PATH(airfoil1_dual ));
    std::string output_file(RESULT_FULL_PATH(airfoil1_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, airfoil1)
{
    std::string input_file(MATRIX_FULL_PATH(airfoil1 ));
    std::string output_file(RESULT_FULL_PATH(airfoil1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, airfoil_2d)
{
    std::string input_file(MATRIX_FULL_PATH(airfoil_2d ));
    std::string output_file(RESULT_FULL_PATH(airfoil_2d ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Alemdar)
{
    std::string input_file(MATRIX_FULL_PATH(Alemdar ));
    std::string output_file(RESULT_FULL_PATH(Alemdar ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, amazon0302)
{
    std::string input_file(MATRIX_FULL_PATH(amazon0302 ));
    std::string output_file(RESULT_FULL_PATH(amazon0302 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, amazon0312)
{
    std::string input_file(MATRIX_FULL_PATH(amazon0312 ));
    std::string output_file(RESULT_FULL_PATH(amazon0312 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, amazon0505)
{
    std::string input_file(MATRIX_FULL_PATH(amazon0505 ));
    std::string output_file(RESULT_FULL_PATH(amazon0505 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, amazon0601)
{
    std::string input_file(MATRIX_FULL_PATH(amazon0601 ));
    std::string output_file(RESULT_FULL_PATH(amazon0601 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Andrews)
{
    std::string input_file(MATRIX_FULL_PATH(Andrews ));
    std::string output_file(RESULT_FULL_PATH(Andrews ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, apache1)
{
    std::string input_file(MATRIX_FULL_PATH(apache1 ));
    std::string output_file(RESULT_FULL_PATH(apache1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, appu)
{
    std::string input_file(MATRIX_FULL_PATH(appu ));
    std::string output_file(RESULT_FULL_PATH(appu ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, as_22july06)
{
    std::string input_file(MATRIX_FULL_PATH(as-22july06 ));
    std::string output_file(RESULT_FULL_PATH(as-22july06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, as_735)
{
    std::string input_file(MATRIX_FULL_PATH(as-735 ));
    std::string output_file(RESULT_FULL_PATH(as-735 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, as_caida)
{
    std::string input_file(MATRIX_FULL_PATH(as-caida ));
    std::string output_file(RESULT_FULL_PATH(as-caida ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ash292)
{
    std::string input_file(MATRIX_FULL_PATH(ash292 ));
    std::string output_file(RESULT_FULL_PATH(ash292 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ASIC_100ks)
{
    std::string input_file(MATRIX_FULL_PATH(ASIC_100ks ));
    std::string output_file(RESULT_FULL_PATH(ASIC_100ks ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ASIC_100k)
{
    std::string input_file(MATRIX_FULL_PATH(ASIC_100k ));
    std::string output_file(RESULT_FULL_PATH(ASIC_100k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ASIC_320ks)
{
    std::string input_file(MATRIX_FULL_PATH(ASIC_320ks ));
    std::string output_file(RESULT_FULL_PATH(ASIC_320ks ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ASIC_320k)
{
    std::string input_file(MATRIX_FULL_PATH(ASIC_320k ));
    std::string output_file(RESULT_FULL_PATH(ASIC_320k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, astro_ph)
{
    std::string input_file(MATRIX_FULL_PATH(astro-ph ));
    std::string output_file(RESULT_FULL_PATH(astro-ph ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, aug2dc)
{
    std::string input_file(MATRIX_FULL_PATH(aug2dc ));
    std::string output_file(RESULT_FULL_PATH(aug2dc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, aug2d)
{
    std::string input_file(MATRIX_FULL_PATH(aug2d ));
    std::string output_file(RESULT_FULL_PATH(aug2d ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, aug3dcqp)
{
    std::string input_file(MATRIX_FULL_PATH(aug3dcqp ));
    std::string output_file(RESULT_FULL_PATH(aug3dcqp ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, aug3d)
{
    std::string input_file(MATRIX_FULL_PATH(aug3d ));
    std::string output_file(RESULT_FULL_PATH(aug3d ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, auto)
{
    std::string input_file(MATRIX_FULL_PATH(auto ));
    std::string output_file(RESULT_FULL_PATH(auto ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, av41092)
{
    std::string input_file(MATRIX_FULL_PATH(av41092 ));
    std::string output_file(RESULT_FULL_PATH(av41092 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, b2_ss)
{
    std::string input_file(MATRIX_FULL_PATH(b2_ss ));
    std::string output_file(RESULT_FULL_PATH(b2_ss ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barrier2_10)
{
    std::string input_file(MATRIX_FULL_PATH(barrier2-10 ));
    std::string output_file(RESULT_FULL_PATH(barrier2-10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barrier2_11)
{
    std::string input_file(MATRIX_FULL_PATH(barrier2-11 ));
    std::string output_file(RESULT_FULL_PATH(barrier2-11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barrier2_12)
{
    std::string input_file(MATRIX_FULL_PATH(barrier2-12 ));
    std::string output_file(RESULT_FULL_PATH(barrier2-12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barrier2_1)
{
    std::string input_file(MATRIX_FULL_PATH(barrier2-1 ));
    std::string output_file(RESULT_FULL_PATH(barrier2-1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barrier2_2)
{
    std::string input_file(MATRIX_FULL_PATH(barrier2-2 ));
    std::string output_file(RESULT_FULL_PATH(barrier2-2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barrier2_3)
{
    std::string input_file(MATRIX_FULL_PATH(barrier2-3 ));
    std::string output_file(RESULT_FULL_PATH(barrier2-3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barrier2_4)
{
    std::string input_file(MATRIX_FULL_PATH(barrier2-4 ));
    std::string output_file(RESULT_FULL_PATH(barrier2-4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barrier2_9)
{
    std::string input_file(MATRIX_FULL_PATH(barrier2-9 ));
    std::string output_file(RESULT_FULL_PATH(barrier2-9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barth4)
{
    std::string input_file(MATRIX_FULL_PATH(barth4 ));
    std::string output_file(RESULT_FULL_PATH(barth4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barth5)
{
    std::string input_file(MATRIX_FULL_PATH(barth5 ));
    std::string output_file(RESULT_FULL_PATH(barth5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, barth)
{
    std::string input_file(MATRIX_FULL_PATH(barth ));
    std::string output_file(RESULT_FULL_PATH(barth ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Baumann)
{
    std::string input_file(MATRIX_FULL_PATH(Baumann ));
    std::string output_file(RESULT_FULL_PATH(Baumann ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bauru5727)
{
    std::string input_file(MATRIX_FULL_PATH(bauru5727 ));
    std::string output_file(RESULT_FULL_PATH(bauru5727 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer01)
{
    std::string input_file(MATRIX_FULL_PATH(bayer01 ));
    std::string output_file(RESULT_FULL_PATH(bayer01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer02)
{
    std::string input_file(MATRIX_FULL_PATH(bayer02 ));
    std::string output_file(RESULT_FULL_PATH(bayer02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer03)
{
    std::string input_file(MATRIX_FULL_PATH(bayer03 ));
    std::string output_file(RESULT_FULL_PATH(bayer03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer04)
{
    std::string input_file(MATRIX_FULL_PATH(bayer04 ));
    std::string output_file(RESULT_FULL_PATH(bayer04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer05)
{
    std::string input_file(MATRIX_FULL_PATH(bayer05 ));
    std::string output_file(RESULT_FULL_PATH(bayer05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer06)
{
    std::string input_file(MATRIX_FULL_PATH(bayer06 ));
    std::string output_file(RESULT_FULL_PATH(bayer06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer07)
{
    std::string input_file(MATRIX_FULL_PATH(bayer07 ));
    std::string output_file(RESULT_FULL_PATH(bayer07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer08)
{
    std::string input_file(MATRIX_FULL_PATH(bayer08 ));
    std::string output_file(RESULT_FULL_PATH(bayer08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer09)
{
    std::string input_file(MATRIX_FULL_PATH(bayer09 ));
    std::string output_file(RESULT_FULL_PATH(bayer09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bayer10)
{
    std::string input_file(MATRIX_FULL_PATH(bayer10 ));
    std::string output_file(RESULT_FULL_PATH(bayer10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bbmat)
{
    std::string input_file(MATRIX_FULL_PATH(bbmat ));
    std::string output_file(RESULT_FULL_PATH(bbmat ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcircuit)
{
    std::string input_file(MATRIX_FULL_PATH(bcircuit ));
    std::string output_file(RESULT_FULL_PATH(bcircuit ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcspwr04)
{
    std::string input_file(MATRIX_FULL_PATH(bcspwr04 ));
    std::string output_file(RESULT_FULL_PATH(bcspwr04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcspwr05)
{
    std::string input_file(MATRIX_FULL_PATH(bcspwr05 ));
    std::string output_file(RESULT_FULL_PATH(bcspwr05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcspwr06)
{
    std::string input_file(MATRIX_FULL_PATH(bcspwr06 ));
    std::string output_file(RESULT_FULL_PATH(bcspwr06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcspwr07)
{
    std::string input_file(MATRIX_FULL_PATH(bcspwr07 ));
    std::string output_file(RESULT_FULL_PATH(bcspwr07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcspwr08)
{
    std::string input_file(MATRIX_FULL_PATH(bcspwr08 ));
    std::string output_file(RESULT_FULL_PATH(bcspwr08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcspwr09)
{
    std::string input_file(MATRIX_FULL_PATH(bcspwr09 ));
    std::string output_file(RESULT_FULL_PATH(bcspwr09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcspwr10)
{
    std::string input_file(MATRIX_FULL_PATH(bcspwr10 ));
    std::string output_file(RESULT_FULL_PATH(bcspwr10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk04)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk04 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk05)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk05 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk06)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk06 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk07)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk07 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk08)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk08 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk09)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk09 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk10)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk10 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk11)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk11 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk12)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk12 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk13)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk13 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk14)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk14 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk15)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk15 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk16)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk16 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk17)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk17 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk18)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk18 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk19)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk19 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk20)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk20 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk21)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk21 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk23)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk23 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk24)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk24 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk25)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk25 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk26)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk26 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk27)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk27 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk28)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk28 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk29)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk29 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk29 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk30)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk30 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk31)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk31 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk32)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk32 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk33)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk33 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk33 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk34)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk34 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk34 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk35)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk35 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk35 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk36)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk36 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk37)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk37 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk37 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk38)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk38 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk38 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstk39)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstk39 ));
    std::string output_file(RESULT_FULL_PATH(bcsstk39 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm07)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm07 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm08)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm08 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm09)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm09 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm10)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm10 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm11)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm11 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm12)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm12 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm13)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm13 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm21)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm21 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm22)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm22 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm23)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm23 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm24)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm24 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm25)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm25 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm26)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm26 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm27)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm27 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm34)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm34 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm34 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm35)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm35 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm35 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm36)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm36 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm37)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm37 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm37 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm38)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm38 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm38 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bcsstm39)
{
    std::string input_file(MATRIX_FULL_PATH(bcsstm39 ));
    std::string output_file(RESULT_FULL_PATH(bcsstm39 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, b_dyn)
{
    std::string input_file(MATRIX_FULL_PATH(b_dyn ));
    std::string output_file(RESULT_FULL_PATH(b_dyn ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, BenElechi1)
{
    std::string input_file(MATRIX_FULL_PATH(BenElechi1 ));
    std::string output_file(RESULT_FULL_PATH(BenElechi1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, benzene)
{
    std::string input_file(MATRIX_FULL_PATH(benzene ));
    std::string output_file(RESULT_FULL_PATH(benzene ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bfly)
{
    std::string input_file(MATRIX_FULL_PATH(bfly ));
    std::string output_file(RESULT_FULL_PATH(bfly ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bfwa398)
{
    std::string input_file(MATRIX_FULL_PATH(bfwa398 ));
    std::string output_file(RESULT_FULL_PATH(bfwa398 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bfwa782)
{
    std::string input_file(MATRIX_FULL_PATH(bfwa782 ));
    std::string output_file(RESULT_FULL_PATH(bfwa782 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bfwb398)
{
    std::string input_file(MATRIX_FULL_PATH(bfwb398 ));
    std::string output_file(RESULT_FULL_PATH(bfwb398 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bfwb782)
{
    std::string input_file(MATRIX_FULL_PATH(bfwb782 ));
    std::string output_file(RESULT_FULL_PATH(bfwb782 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bibd_81_2)
{
    std::string input_file(MATRIX_FULL_PATH(bibd_81_2 ));
    std::string output_file(RESULT_FULL_PATH(bibd_81_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, big_dual)
{
    std::string input_file(MATRIX_FULL_PATH(big_dual ));
    std::string output_file(RESULT_FULL_PATH(big_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, big)
{
    std::string input_file(MATRIX_FULL_PATH(big ));
    std::string output_file(RESULT_FULL_PATH(big ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, biplane_9)
{
    std::string input_file(MATRIX_FULL_PATH(biplane-9 ));
    std::string output_file(RESULT_FULL_PATH(biplane-9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bips07_1693)
{
    std::string input_file(MATRIX_FULL_PATH(bips07_1693 ));
    std::string output_file(RESULT_FULL_PATH(bips07_1693 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bips07_1998)
{
    std::string input_file(MATRIX_FULL_PATH(bips07_1998 ));
    std::string output_file(RESULT_FULL_PATH(bips07_1998 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bips07_2476)
{
    std::string input_file(MATRIX_FULL_PATH(bips07_2476 ));
    std::string output_file(RESULT_FULL_PATH(bips07_2476 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bips07_3078)
{
    std::string input_file(MATRIX_FULL_PATH(bips07_3078 ));
    std::string output_file(RESULT_FULL_PATH(bips07_3078 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bips98_1142)
{
    std::string input_file(MATRIX_FULL_PATH(bips98_1142 ));
    std::string output_file(RESULT_FULL_PATH(bips98_1142 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bips98_1450)
{
    std::string input_file(MATRIX_FULL_PATH(bips98_1450 ));
    std::string output_file(RESULT_FULL_PATH(bips98_1450 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bips98_606)
{
    std::string input_file(MATRIX_FULL_PATH(bips98_606 ));
    std::string output_file(RESULT_FULL_PATH(bips98_606 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, blckhole)
{
    std::string input_file(MATRIX_FULL_PATH(blckhole ));
    std::string output_file(RESULT_FULL_PATH(blckhole ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, blockqp1)
{
    std::string input_file(MATRIX_FULL_PATH(blockqp1 ));
    std::string output_file(RESULT_FULL_PATH(blockqp1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bloweya)
{
    std::string input_file(MATRIX_FULL_PATH(bloweya ));
    std::string output_file(RESULT_FULL_PATH(bloweya ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bloweybl)
{
    std::string input_file(MATRIX_FULL_PATH(bloweybl ));
    std::string output_file(RESULT_FULL_PATH(bloweybl ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bloweybq)
{
    std::string input_file(MATRIX_FULL_PATH(bloweybq ));
    std::string output_file(RESULT_FULL_PATH(bloweybq ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bmw3_2)
{
    std::string input_file(MATRIX_FULL_PATH(bmw3_2 ));
    std::string output_file(RESULT_FULL_PATH(bmw3_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bmw7st_1)
{
    std::string input_file(MATRIX_FULL_PATH(bmw7st_1 ));
    std::string output_file(RESULT_FULL_PATH(bmw7st_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bmwcra_1)
{
    std::string input_file(MATRIX_FULL_PATH(bmwcra_1 ));
    std::string output_file(RESULT_FULL_PATH(bmwcra_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bodyy4)
{
    std::string input_file(MATRIX_FULL_PATH(bodyy4 ));
    std::string output_file(RESULT_FULL_PATH(bodyy4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bodyy5)
{
    std::string input_file(MATRIX_FULL_PATH(bodyy5 ));
    std::string output_file(RESULT_FULL_PATH(bodyy5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bodyy6)
{
    std::string input_file(MATRIX_FULL_PATH(bodyy6 ));
    std::string output_file(RESULT_FULL_PATH(bodyy6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, boneS01)
{
    std::string input_file(MATRIX_FULL_PATH(boneS01 ));
    std::string output_file(RESULT_FULL_PATH(boneS01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, boyd1)
{
    std::string input_file(MATRIX_FULL_PATH(boyd1 ));
    std::string output_file(RESULT_FULL_PATH(boyd1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, boyd2)
{
    std::string input_file(MATRIX_FULL_PATH(boyd2 ));
    std::string output_file(RESULT_FULL_PATH(boyd2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_0)
{
    std::string input_file(MATRIX_FULL_PATH(bp_0 ));
    std::string output_file(RESULT_FULL_PATH(bp_0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_1000)
{
    std::string input_file(MATRIX_FULL_PATH(bp_1000 ));
    std::string output_file(RESULT_FULL_PATH(bp_1000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_1200)
{
    std::string input_file(MATRIX_FULL_PATH(bp_1200 ));
    std::string output_file(RESULT_FULL_PATH(bp_1200 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_1400)
{
    std::string input_file(MATRIX_FULL_PATH(bp_1400 ));
    std::string output_file(RESULT_FULL_PATH(bp_1400 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_1600)
{
    std::string input_file(MATRIX_FULL_PATH(bp_1600 ));
    std::string output_file(RESULT_FULL_PATH(bp_1600 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_200)
{
    std::string input_file(MATRIX_FULL_PATH(bp_200 ));
    std::string output_file(RESULT_FULL_PATH(bp_200 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_400)
{
    std::string input_file(MATRIX_FULL_PATH(bp_400 ));
    std::string output_file(RESULT_FULL_PATH(bp_400 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_600)
{
    std::string input_file(MATRIX_FULL_PATH(bp_600 ));
    std::string output_file(RESULT_FULL_PATH(bp_600 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bp_800)
{
    std::string input_file(MATRIX_FULL_PATH(bp_800 ));
    std::string output_file(RESULT_FULL_PATH(bp_800 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, brack2)
{
    std::string input_file(MATRIX_FULL_PATH(brack2 ));
    std::string output_file(RESULT_FULL_PATH(brack2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, brainpc2)
{
    std::string input_file(MATRIX_FULL_PATH(brainpc2 ));
    std::string output_file(RESULT_FULL_PATH(brainpc2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bratu3d)
{
    std::string input_file(MATRIX_FULL_PATH(bratu3d ));
    std::string output_file(RESULT_FULL_PATH(bratu3d ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bundle1)
{
    std::string input_file(MATRIX_FULL_PATH(bundle1 ));
    std::string output_file(RESULT_FULL_PATH(bundle1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, bwm2000)
{
    std::string input_file(MATRIX_FULL_PATH(bwm2000 ));
    std::string output_file(RESULT_FULL_PATH(bwm2000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_18)
{
    std::string input_file(MATRIX_FULL_PATH(c-18 ));
    std::string output_file(RESULT_FULL_PATH(c-18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_19)
{
    std::string input_file(MATRIX_FULL_PATH(c-19 ));
    std::string output_file(RESULT_FULL_PATH(c-19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_20)
{
    std::string input_file(MATRIX_FULL_PATH(c-20 ));
    std::string output_file(RESULT_FULL_PATH(c-20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_21)
{
    std::string input_file(MATRIX_FULL_PATH(c-21 ));
    std::string output_file(RESULT_FULL_PATH(c-21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_22)
{
    std::string input_file(MATRIX_FULL_PATH(c-22 ));
    std::string output_file(RESULT_FULL_PATH(c-22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_23)
{
    std::string input_file(MATRIX_FULL_PATH(c-23 ));
    std::string output_file(RESULT_FULL_PATH(c-23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_24)
{
    std::string input_file(MATRIX_FULL_PATH(c-24 ));
    std::string output_file(RESULT_FULL_PATH(c-24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_25)
{
    std::string input_file(MATRIX_FULL_PATH(c-25 ));
    std::string output_file(RESULT_FULL_PATH(c-25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_26)
{
    std::string input_file(MATRIX_FULL_PATH(c-26 ));
    std::string output_file(RESULT_FULL_PATH(c-26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_27)
{
    std::string input_file(MATRIX_FULL_PATH(c-27 ));
    std::string output_file(RESULT_FULL_PATH(c-27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_28)
{
    std::string input_file(MATRIX_FULL_PATH(c-28 ));
    std::string output_file(RESULT_FULL_PATH(c-28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_29)
{
    std::string input_file(MATRIX_FULL_PATH(c-29 ));
    std::string output_file(RESULT_FULL_PATH(c-29 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_30)
{
    std::string input_file(MATRIX_FULL_PATH(c-30 ));
    std::string output_file(RESULT_FULL_PATH(c-30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_31)
{
    std::string input_file(MATRIX_FULL_PATH(c-31 ));
    std::string output_file(RESULT_FULL_PATH(c-31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_32)
{
    std::string input_file(MATRIX_FULL_PATH(c-32 ));
    std::string output_file(RESULT_FULL_PATH(c-32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_33)
{
    std::string input_file(MATRIX_FULL_PATH(c-33 ));
    std::string output_file(RESULT_FULL_PATH(c-33 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_34)
{
    std::string input_file(MATRIX_FULL_PATH(c-34 ));
    std::string output_file(RESULT_FULL_PATH(c-34 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_35)
{
    std::string input_file(MATRIX_FULL_PATH(c-35 ));
    std::string output_file(RESULT_FULL_PATH(c-35 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_36)
{
    std::string input_file(MATRIX_FULL_PATH(c-36 ));
    std::string output_file(RESULT_FULL_PATH(c-36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_37)
{
    std::string input_file(MATRIX_FULL_PATH(c-37 ));
    std::string output_file(RESULT_FULL_PATH(c-37 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_38)
{
    std::string input_file(MATRIX_FULL_PATH(c-38 ));
    std::string output_file(RESULT_FULL_PATH(c-38 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_39)
{
    std::string input_file(MATRIX_FULL_PATH(c-39 ));
    std::string output_file(RESULT_FULL_PATH(c-39 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_40)
{
    std::string input_file(MATRIX_FULL_PATH(c-40 ));
    std::string output_file(RESULT_FULL_PATH(c-40 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_41)
{
    std::string input_file(MATRIX_FULL_PATH(c-41 ));
    std::string output_file(RESULT_FULL_PATH(c-41 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_42)
{
    std::string input_file(MATRIX_FULL_PATH(c-42 ));
    std::string output_file(RESULT_FULL_PATH(c-42 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_43)
{
    std::string input_file(MATRIX_FULL_PATH(c-43 ));
    std::string output_file(RESULT_FULL_PATH(c-43 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_44)
{
    std::string input_file(MATRIX_FULL_PATH(c-44 ));
    std::string output_file(RESULT_FULL_PATH(c-44 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_45)
{
    std::string input_file(MATRIX_FULL_PATH(c-45 ));
    std::string output_file(RESULT_FULL_PATH(c-45 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_46)
{
    std::string input_file(MATRIX_FULL_PATH(c-46 ));
    std::string output_file(RESULT_FULL_PATH(c-46 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_47)
{
    std::string input_file(MATRIX_FULL_PATH(c-47 ));
    std::string output_file(RESULT_FULL_PATH(c-47 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_48)
{
    std::string input_file(MATRIX_FULL_PATH(c-48 ));
    std::string output_file(RESULT_FULL_PATH(c-48 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_49)
{
    std::string input_file(MATRIX_FULL_PATH(c-49 ));
    std::string output_file(RESULT_FULL_PATH(c-49 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_50)
{
    std::string input_file(MATRIX_FULL_PATH(c-50 ));
    std::string output_file(RESULT_FULL_PATH(c-50 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_51)
{
    std::string input_file(MATRIX_FULL_PATH(c-51 ));
    std::string output_file(RESULT_FULL_PATH(c-51 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_52)
{
    std::string input_file(MATRIX_FULL_PATH(c-52 ));
    std::string output_file(RESULT_FULL_PATH(c-52 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_53)
{
    std::string input_file(MATRIX_FULL_PATH(c-53 ));
    std::string output_file(RESULT_FULL_PATH(c-53 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_54)
{
    std::string input_file(MATRIX_FULL_PATH(c-54 ));
    std::string output_file(RESULT_FULL_PATH(c-54 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_55)
{
    std::string input_file(MATRIX_FULL_PATH(c-55 ));
    std::string output_file(RESULT_FULL_PATH(c-55 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_56)
{
    std::string input_file(MATRIX_FULL_PATH(c-56 ));
    std::string output_file(RESULT_FULL_PATH(c-56 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_57)
{
    std::string input_file(MATRIX_FULL_PATH(c-57 ));
    std::string output_file(RESULT_FULL_PATH(c-57 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_58)
{
    std::string input_file(MATRIX_FULL_PATH(c-58 ));
    std::string output_file(RESULT_FULL_PATH(c-58 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_59)
{
    std::string input_file(MATRIX_FULL_PATH(c-59 ));
    std::string output_file(RESULT_FULL_PATH(c-59 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_60)
{
    std::string input_file(MATRIX_FULL_PATH(c-60 ));
    std::string output_file(RESULT_FULL_PATH(c-60 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_61)
{
    std::string input_file(MATRIX_FULL_PATH(c-61 ));
    std::string output_file(RESULT_FULL_PATH(c-61 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_62ghs)
{
    std::string input_file(MATRIX_FULL_PATH(c-62ghs ));
    std::string output_file(RESULT_FULL_PATH(c-62ghs ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_62)
{
    std::string input_file(MATRIX_FULL_PATH(c-62 ));
    std::string output_file(RESULT_FULL_PATH(c-62 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_63)
{
    std::string input_file(MATRIX_FULL_PATH(c-63 ));
    std::string output_file(RESULT_FULL_PATH(c-63 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_64b)
{
    std::string input_file(MATRIX_FULL_PATH(c-64b ));
    std::string output_file(RESULT_FULL_PATH(c-64b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_64)
{
    std::string input_file(MATRIX_FULL_PATH(c-64 ));
    std::string output_file(RESULT_FULL_PATH(c-64 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_65)
{
    std::string input_file(MATRIX_FULL_PATH(c-65 ));
    std::string output_file(RESULT_FULL_PATH(c-65 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_66b)
{
    std::string input_file(MATRIX_FULL_PATH(c-66b ));
    std::string output_file(RESULT_FULL_PATH(c-66b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_66)
{
    std::string input_file(MATRIX_FULL_PATH(c-66 ));
    std::string output_file(RESULT_FULL_PATH(c-66 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_67b)
{
    std::string input_file(MATRIX_FULL_PATH(c-67b ));
    std::string output_file(RESULT_FULL_PATH(c-67b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_67)
{
    std::string input_file(MATRIX_FULL_PATH(c-67 ));
    std::string output_file(RESULT_FULL_PATH(c-67 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_68)
{
    std::string input_file(MATRIX_FULL_PATH(c-68 ));
    std::string output_file(RESULT_FULL_PATH(c-68 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_69)
{
    std::string input_file(MATRIX_FULL_PATH(c-69 ));
    std::string output_file(RESULT_FULL_PATH(c-69 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_70)
{
    std::string input_file(MATRIX_FULL_PATH(c-70 ));
    std::string output_file(RESULT_FULL_PATH(c-70 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_71)
{
    std::string input_file(MATRIX_FULL_PATH(c-71 ));
    std::string output_file(RESULT_FULL_PATH(c-71 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_72)
{
    std::string input_file(MATRIX_FULL_PATH(c-72 ));
    std::string output_file(RESULT_FULL_PATH(c-72 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_73b)
{
    std::string input_file(MATRIX_FULL_PATH(c-73b ));
    std::string output_file(RESULT_FULL_PATH(c-73b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_73)
{
    std::string input_file(MATRIX_FULL_PATH(c-73 ));
    std::string output_file(RESULT_FULL_PATH(c-73 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ca_AstroPh)
{
    std::string input_file(MATRIX_FULL_PATH(ca-AstroPh ));
    std::string output_file(RESULT_FULL_PATH(ca-AstroPh ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ca_CondMat)
{
    std::string input_file(MATRIX_FULL_PATH(ca-CondMat ));
    std::string output_file(RESULT_FULL_PATH(ca-CondMat ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage10)
{
    std::string input_file(MATRIX_FULL_PATH(cage10 ));
    std::string output_file(RESULT_FULL_PATH(cage10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage11)
{
    std::string input_file(MATRIX_FULL_PATH(cage11 ));
    std::string output_file(RESULT_FULL_PATH(cage11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage12)
{
    std::string input_file(MATRIX_FULL_PATH(cage12 ));
    std::string output_file(RESULT_FULL_PATH(cage12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage13)
{
    std::string input_file(MATRIX_FULL_PATH(cage13 ));
    std::string output_file(RESULT_FULL_PATH(cage13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage7)
{
    std::string input_file(MATRIX_FULL_PATH(cage7 ));
    std::string output_file(RESULT_FULL_PATH(cage7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage8)
{
    std::string input_file(MATRIX_FULL_PATH(cage8 ));
    std::string output_file(RESULT_FULL_PATH(cage8 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage9)
{
    std::string input_file(MATRIX_FULL_PATH(cage9 ));
    std::string output_file(RESULT_FULL_PATH(cage9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cage)
{
    std::string input_file(MATRIX_FULL_PATH(cage ));
    std::string output_file(RESULT_FULL_PATH(cage ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, CAG_mat1916)
{
    std::string input_file(MATRIX_FULL_PATH(CAG_mat1916 ));
    std::string output_file(RESULT_FULL_PATH(CAG_mat1916 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, CAG_mat364)
{
    std::string input_file(MATRIX_FULL_PATH(CAG_mat364 ));
    std::string output_file(RESULT_FULL_PATH(CAG_mat364 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ca_GrQc)
{
    std::string input_file(MATRIX_FULL_PATH(ca-GrQc ));
    std::string output_file(RESULT_FULL_PATH(ca-GrQc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ca_HepPh)
{
    std::string input_file(MATRIX_FULL_PATH(ca-HepPh ));
    std::string output_file(RESULT_FULL_PATH(ca-HepPh ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ca_HepTh)
{
    std::string input_file(MATRIX_FULL_PATH(ca-HepTh ));
    std::string output_file(RESULT_FULL_PATH(ca-HepTh ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, caidaRouterLevel)
{
    std::string input_file(MATRIX_FULL_PATH(caidaRouterLevel ));
    std::string output_file(RESULT_FULL_PATH(caidaRouterLevel ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, California)
{
    std::string input_file(MATRIX_FULL_PATH(California ));
    std::string output_file(RESULT_FULL_PATH(California ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_1054)
{
    std::string input_file(MATRIX_FULL_PATH(can_1054 ));
    std::string output_file(RESULT_FULL_PATH(can_1054 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_1072)
{
    std::string input_file(MATRIX_FULL_PATH(can_1072 ));
    std::string output_file(RESULT_FULL_PATH(can_1072 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_144)
{
    std::string input_file(MATRIX_FULL_PATH(can_144 ));
    std::string output_file(RESULT_FULL_PATH(can_144 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_161)
{
    std::string input_file(MATRIX_FULL_PATH(can_161 ));
    std::string output_file(RESULT_FULL_PATH(can_161 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_187)
{
    std::string input_file(MATRIX_FULL_PATH(can_187 ));
    std::string output_file(RESULT_FULL_PATH(can_187 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_229)
{
    std::string input_file(MATRIX_FULL_PATH(can_229 ));
    std::string output_file(RESULT_FULL_PATH(can_229 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_256)
{
    std::string input_file(MATRIX_FULL_PATH(can_256 ));
    std::string output_file(RESULT_FULL_PATH(can_256 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_268)
{
    std::string input_file(MATRIX_FULL_PATH(can_268 ));
    std::string output_file(RESULT_FULL_PATH(can_268 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_292)
{
    std::string input_file(MATRIX_FULL_PATH(can_292 ));
    std::string output_file(RESULT_FULL_PATH(can_292 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_445)
{
    std::string input_file(MATRIX_FULL_PATH(can_445 ));
    std::string output_file(RESULT_FULL_PATH(can_445 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_634)
{
    std::string input_file(MATRIX_FULL_PATH(can_634 ));
    std::string output_file(RESULT_FULL_PATH(can_634 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_715)
{
    std::string input_file(MATRIX_FULL_PATH(can_715 ));
    std::string output_file(RESULT_FULL_PATH(can_715 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, can_838)
{
    std::string input_file(MATRIX_FULL_PATH(can_838 ));
    std::string output_file(RESULT_FULL_PATH(can_838 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cant)
{
    std::string input_file(MATRIX_FULL_PATH(cant ));
    std::string output_file(RESULT_FULL_PATH(cant ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, case39)
{
    std::string input_file(MATRIX_FULL_PATH(case39 ));
    std::string output_file(RESULT_FULL_PATH(case39 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, case9)
{
    std::string input_file(MATRIX_FULL_PATH(case9 ));
    std::string output_file(RESULT_FULL_PATH(case9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity01)
{
    std::string input_file(MATRIX_FULL_PATH(cavity01 ));
    std::string output_file(RESULT_FULL_PATH(cavity01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity02)
{
    std::string input_file(MATRIX_FULL_PATH(cavity02 ));
    std::string output_file(RESULT_FULL_PATH(cavity02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity03)
{
    std::string input_file(MATRIX_FULL_PATH(cavity03 ));
    std::string output_file(RESULT_FULL_PATH(cavity03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity04)
{
    std::string input_file(MATRIX_FULL_PATH(cavity04 ));
    std::string output_file(RESULT_FULL_PATH(cavity04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity05)
{
    std::string input_file(MATRIX_FULL_PATH(cavity05 ));
    std::string output_file(RESULT_FULL_PATH(cavity05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity06)
{
    std::string input_file(MATRIX_FULL_PATH(cavity06 ));
    std::string output_file(RESULT_FULL_PATH(cavity06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity07)
{
    std::string input_file(MATRIX_FULL_PATH(cavity07 ));
    std::string output_file(RESULT_FULL_PATH(cavity07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity08)
{
    std::string input_file(MATRIX_FULL_PATH(cavity08 ));
    std::string output_file(RESULT_FULL_PATH(cavity08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity09)
{
    std::string input_file(MATRIX_FULL_PATH(cavity09 ));
    std::string output_file(RESULT_FULL_PATH(cavity09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity10)
{
    std::string input_file(MATRIX_FULL_PATH(cavity10 ));
    std::string output_file(RESULT_FULL_PATH(cavity10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity11)
{
    std::string input_file(MATRIX_FULL_PATH(cavity11 ));
    std::string output_file(RESULT_FULL_PATH(cavity11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity12)
{
    std::string input_file(MATRIX_FULL_PATH(cavity12 ));
    std::string output_file(RESULT_FULL_PATH(cavity12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity13)
{
    std::string input_file(MATRIX_FULL_PATH(cavity13 ));
    std::string output_file(RESULT_FULL_PATH(cavity13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity14)
{
    std::string input_file(MATRIX_FULL_PATH(cavity14 ));
    std::string output_file(RESULT_FULL_PATH(cavity14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity15)
{
    std::string input_file(MATRIX_FULL_PATH(cavity15 ));
    std::string output_file(RESULT_FULL_PATH(cavity15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity16)
{
    std::string input_file(MATRIX_FULL_PATH(cavity16 ));
    std::string output_file(RESULT_FULL_PATH(cavity16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity17)
{
    std::string input_file(MATRIX_FULL_PATH(cavity17 ));
    std::string output_file(RESULT_FULL_PATH(cavity17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity18)
{
    std::string input_file(MATRIX_FULL_PATH(cavity18 ));
    std::string output_file(RESULT_FULL_PATH(cavity18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity19)
{
    std::string input_file(MATRIX_FULL_PATH(cavity19 ));
    std::string output_file(RESULT_FULL_PATH(cavity19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity20)
{
    std::string input_file(MATRIX_FULL_PATH(cavity20 ));
    std::string output_file(RESULT_FULL_PATH(cavity20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity21)
{
    std::string input_file(MATRIX_FULL_PATH(cavity21 ));
    std::string output_file(RESULT_FULL_PATH(cavity21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity22)
{
    std::string input_file(MATRIX_FULL_PATH(cavity22 ));
    std::string output_file(RESULT_FULL_PATH(cavity22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity23)
{
    std::string input_file(MATRIX_FULL_PATH(cavity23 ));
    std::string output_file(RESULT_FULL_PATH(cavity23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity24)
{
    std::string input_file(MATRIX_FULL_PATH(cavity24 ));
    std::string output_file(RESULT_FULL_PATH(cavity24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity25)
{
    std::string input_file(MATRIX_FULL_PATH(cavity25 ));
    std::string output_file(RESULT_FULL_PATH(cavity25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cavity26)
{
    std::string input_file(MATRIX_FULL_PATH(cavity26 ));
    std::string output_file(RESULT_FULL_PATH(cavity26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, c_big)
{
    std::string input_file(MATRIX_FULL_PATH(c-big ));
    std::string output_file(RESULT_FULL_PATH(c-big ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cbuckle)
{
    std::string input_file(MATRIX_FULL_PATH(cbuckle ));
    std::string output_file(RESULT_FULL_PATH(cbuckle ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cca)
{
    std::string input_file(MATRIX_FULL_PATH(cca ));
    std::string output_file(RESULT_FULL_PATH(cca ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ccc)
{
    std::string input_file(MATRIX_FULL_PATH(ccc ));
    std::string output_file(RESULT_FULL_PATH(ccc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cdde1)
{
    std::string input_file(MATRIX_FULL_PATH(cdde1 ));
    std::string output_file(RESULT_FULL_PATH(cdde1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cdde2)
{
    std::string input_file(MATRIX_FULL_PATH(cdde2 ));
    std::string output_file(RESULT_FULL_PATH(cdde2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cdde3)
{
    std::string input_file(MATRIX_FULL_PATH(cdde3 ));
    std::string output_file(RESULT_FULL_PATH(cdde3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cdde4)
{
    std::string input_file(MATRIX_FULL_PATH(cdde4 ));
    std::string output_file(RESULT_FULL_PATH(cdde4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cdde5)
{
    std::string input_file(MATRIX_FULL_PATH(cdde5 ));
    std::string output_file(RESULT_FULL_PATH(cdde5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cdde6)
{
    std::string input_file(MATRIX_FULL_PATH(cdde6 ));
    std::string output_file(RESULT_FULL_PATH(cdde6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cegb2802)
{
    std::string input_file(MATRIX_FULL_PATH(cegb2802 ));
    std::string output_file(RESULT_FULL_PATH(cegb2802 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cegb2919)
{
    std::string input_file(MATRIX_FULL_PATH(cegb2919 ));
    std::string output_file(RESULT_FULL_PATH(cegb2919 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cegb3024)
{
    std::string input_file(MATRIX_FULL_PATH(cegb3024 ));
    std::string output_file(RESULT_FULL_PATH(cegb3024 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cegb3306)
{
    std::string input_file(MATRIX_FULL_PATH(cegb3306 ));
    std::string output_file(RESULT_FULL_PATH(cegb3306 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, celegans_metabolic)
{
    std::string input_file(MATRIX_FULL_PATH(celegans_metabolic ));
    std::string output_file(RESULT_FULL_PATH(celegans_metabolic ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, celegansneural)
{
    std::string input_file(MATRIX_FULL_PATH(celegansneural ));
    std::string output_file(RESULT_FULL_PATH(celegansneural ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cell1)
{
    std::string input_file(MATRIX_FULL_PATH(cell1 ));
    std::string output_file(RESULT_FULL_PATH(cell1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cell2)
{
    std::string input_file(MATRIX_FULL_PATH(cell2 ));
    std::string output_file(RESULT_FULL_PATH(cell2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cfd1)
{
    std::string input_file(MATRIX_FULL_PATH(cfd1 ));
    std::string output_file(RESULT_FULL_PATH(cfd1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cfd2)
{
    std::string input_file(MATRIX_FULL_PATH(cfd2 ));
    std::string output_file(RESULT_FULL_PATH(cfd2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ch5_5_b3)
{
    std::string input_file(MATRIX_FULL_PATH(ch5-5-b3 ));
    std::string output_file(RESULT_FULL_PATH(ch5-5-b3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ch7_8_b5)
{
    std::string input_file(MATRIX_FULL_PATH(ch7-8-b5 ));
    std::string output_file(RESULT_FULL_PATH(ch7-8-b5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Chebyshev1)
{
    std::string input_file(MATRIX_FULL_PATH(Chebyshev1 ));
    std::string output_file(RESULT_FULL_PATH(Chebyshev1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Chebyshev2)
{
    std::string input_file(MATRIX_FULL_PATH(Chebyshev2 ));
    std::string output_file(RESULT_FULL_PATH(Chebyshev2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Chebyshev3)
{
    std::string input_file(MATRIX_FULL_PATH(Chebyshev3 ));
    std::string output_file(RESULT_FULL_PATH(Chebyshev3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Chebyshev4)
{
    std::string input_file(MATRIX_FULL_PATH(Chebyshev4 ));
    std::string output_file(RESULT_FULL_PATH(Chebyshev4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Chem97ZtZ)
{
    std::string input_file(MATRIX_FULL_PATH(Chem97ZtZ ));
    std::string output_file(RESULT_FULL_PATH(Chem97ZtZ ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, chem_master1)
{
    std::string input_file(MATRIX_FULL_PATH(chem_master1 ));
    std::string output_file(RESULT_FULL_PATH(chem_master1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, chipcool0)
{
    std::string input_file(MATRIX_FULL_PATH(chipcool0 ));
    std::string output_file(RESULT_FULL_PATH(chipcool0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, chipcool1)
{
    std::string input_file(MATRIX_FULL_PATH(chipcool1 ));
    std::string output_file(RESULT_FULL_PATH(chipcool1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, circuit_1)
{
    std::string input_file(MATRIX_FULL_PATH(circuit_1 ));
    std::string output_file(RESULT_FULL_PATH(circuit_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, circuit204)
{
    std::string input_file(MATRIX_FULL_PATH(circuit204 ));
    std::string output_file(RESULT_FULL_PATH(circuit204 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, circuit_2)
{
    std::string input_file(MATRIX_FULL_PATH(circuit_2 ));
    std::string output_file(RESULT_FULL_PATH(circuit_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, circuit_3)
{
    std::string input_file(MATRIX_FULL_PATH(circuit_3 ));
    std::string output_file(RESULT_FULL_PATH(circuit_3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, circuit_4)
{
    std::string input_file(MATRIX_FULL_PATH(circuit_4 ));
    std::string output_file(RESULT_FULL_PATH(circuit_4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, citationCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(citationCiteseer ));
    std::string output_file(RESULT_FULL_PATH(citationCiteseer ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cit_HepPh)
{
    std::string input_file(MATRIX_FULL_PATH(cit-HepPh ));
    std::string output_file(RESULT_FULL_PATH(cit-HepPh ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cit_HepTh)
{
    std::string input_file(MATRIX_FULL_PATH(cit-HepTh ));
    std::string output_file(RESULT_FULL_PATH(cit-HepTh ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ck400)
{
    std::string input_file(MATRIX_FULL_PATH(ck400 ));
    std::string output_file(RESULT_FULL_PATH(ck400 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ck656)
{
    std::string input_file(MATRIX_FULL_PATH(ck656 ));
    std::string output_file(RESULT_FULL_PATH(ck656 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ckt11752_dc_1)
{
    std::string input_file(MATRIX_FULL_PATH(ckt11752_dc_1 ));
    std::string output_file(RESULT_FULL_PATH(ckt11752_dc_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ckt11752_tr_0)
{
    std::string input_file(MATRIX_FULL_PATH(ckt11752_tr_0 ));
    std::string output_file(RESULT_FULL_PATH(ckt11752_tr_0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cnr_2000)
{
    std::string input_file(MATRIX_FULL_PATH(cnr-2000 ));
    std::string output_file(RESULT_FULL_PATH(cnr-2000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, coater1)
{
    std::string input_file(MATRIX_FULL_PATH(coater1 ));
    std::string output_file(RESULT_FULL_PATH(coater1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, coater2)
{
    std::string input_file(MATRIX_FULL_PATH(coater2 ));
    std::string output_file(RESULT_FULL_PATH(coater2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, coAuthorsCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsCiteseer ));
    std::string output_file(RESULT_FULL_PATH(coAuthorsCiteseer ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, coAuthorsDBLP)
{
    std::string input_file(MATRIX_FULL_PATH(coAuthorsDBLP ));
    std::string output_file(RESULT_FULL_PATH(coAuthorsDBLP ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, commanche_dual)
{
    std::string input_file(MATRIX_FULL_PATH(commanche_dual ));
    std::string output_file(RESULT_FULL_PATH(commanche_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, comsol)
{
    std::string input_file(MATRIX_FULL_PATH(comsol ));
    std::string output_file(RESULT_FULL_PATH(comsol ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cond_mat_2003)
{
    std::string input_file(MATRIX_FULL_PATH(cond-mat-2003 ));
    std::string output_file(RESULT_FULL_PATH(cond-mat-2003 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cond_mat_2005)
{
    std::string input_file(MATRIX_FULL_PATH(cond-mat-2005 ));
    std::string output_file(RESULT_FULL_PATH(cond-mat-2005 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cond_mat)
{
    std::string input_file(MATRIX_FULL_PATH(cond-mat ));
    std::string output_file(RESULT_FULL_PATH(cond-mat ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_0_4x4_10)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_0-4x4-10 ));
    std::string output_file(RESULT_FULL_PATH(conf5_0-4x4-10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_0_4x4_14)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_0-4x4-14 ));
    std::string output_file(RESULT_FULL_PATH(conf5_0-4x4-14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_0_4x4_18)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_0-4x4-18 ));
    std::string output_file(RESULT_FULL_PATH(conf5_0-4x4-18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_0_4x4_22)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_0-4x4-22 ));
    std::string output_file(RESULT_FULL_PATH(conf5_0-4x4-22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_0_4x4_26)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_0-4x4-26 ));
    std::string output_file(RESULT_FULL_PATH(conf5_0-4x4-26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_4_8x8_05)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_4-8x8-05 ));
    std::string output_file(RESULT_FULL_PATH(conf5_4-8x8-05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_4_8x8_10)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_4-8x8-10 ));
    std::string output_file(RESULT_FULL_PATH(conf5_4-8x8-10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_4_8x8_15)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_4-8x8-15 ));
    std::string output_file(RESULT_FULL_PATH(conf5_4-8x8-15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf5_4_8x8_20)
{
    std::string input_file(MATRIX_FULL_PATH(conf5_4-8x8-20 ));
    std::string output_file(RESULT_FULL_PATH(conf5_4-8x8-20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf6_0_4x4_20)
{
    std::string input_file(MATRIX_FULL_PATH(conf6_0-4x4-20 ));
    std::string output_file(RESULT_FULL_PATH(conf6_0-4x4-20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf6_0_4x4_30)
{
    std::string input_file(MATRIX_FULL_PATH(conf6_0-4x4-30 ));
    std::string output_file(RESULT_FULL_PATH(conf6_0-4x4-30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf6_0_8x8_20)
{
    std::string input_file(MATRIX_FULL_PATH(conf6_0-8x8-20 ));
    std::string output_file(RESULT_FULL_PATH(conf6_0-8x8-20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf6_0_8x8_30)
{
    std::string input_file(MATRIX_FULL_PATH(conf6_0-8x8-30 ));
    std::string output_file(RESULT_FULL_PATH(conf6_0-8x8-30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, conf6_0_8x8_80)
{
    std::string input_file(MATRIX_FULL_PATH(conf6_0-8x8-80 ));
    std::string output_file(RESULT_FULL_PATH(conf6_0-8x8-80 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, consph)
{
    std::string input_file(MATRIX_FULL_PATH(consph ));
    std::string output_file(RESULT_FULL_PATH(consph ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cont_201)
{
    std::string input_file(MATRIX_FULL_PATH(cont-201 ));
    std::string output_file(RESULT_FULL_PATH(cont-201 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cont_300)
{
    std::string input_file(MATRIX_FULL_PATH(cont-300 ));
    std::string output_file(RESULT_FULL_PATH(cont-300 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cop20k_A)
{
    std::string input_file(MATRIX_FULL_PATH(cop20k_A ));
    std::string output_file(RESULT_FULL_PATH(cop20k_A ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, coPapersCiteseer)
{
    std::string input_file(MATRIX_FULL_PATH(coPapersCiteseer ));
    std::string output_file(RESULT_FULL_PATH(coPapersCiteseer ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, copter1)
{
    std::string input_file(MATRIX_FULL_PATH(copter1 ));
    std::string output_file(RESULT_FULL_PATH(copter1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, copter2)
{
    std::string input_file(MATRIX_FULL_PATH(copter2 ));
    std::string output_file(RESULT_FULL_PATH(copter2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, CO)
{
    std::string input_file(MATRIX_FULL_PATH(CO ));
    std::string output_file(RESULT_FULL_PATH(CO ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, coupled)
{
    std::string input_file(MATRIX_FULL_PATH(coupled ));
    std::string output_file(RESULT_FULL_PATH(coupled ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crack_dual)
{
    std::string input_file(MATRIX_FULL_PATH(crack_dual ));
    std::string output_file(RESULT_FULL_PATH(crack_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crack)
{
    std::string input_file(MATRIX_FULL_PATH(crack ));
    std::string output_file(RESULT_FULL_PATH(crack ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crankseg_1)
{
    std::string input_file(MATRIX_FULL_PATH(crankseg_1 ));
    std::string output_file(RESULT_FULL_PATH(crankseg_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crankseg_2)
{
    std::string input_file(MATRIX_FULL_PATH(crankseg_2 ));
    std::string output_file(RESULT_FULL_PATH(crankseg_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crashbasis)
{
    std::string input_file(MATRIX_FULL_PATH(crashbasis ));
    std::string output_file(RESULT_FULL_PATH(crashbasis ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crplat2)
{
    std::string input_file(MATRIX_FULL_PATH(crplat2 ));
    std::string output_file(RESULT_FULL_PATH(crplat2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cryg10000)
{
    std::string input_file(MATRIX_FULL_PATH(cryg10000 ));
    std::string output_file(RESULT_FULL_PATH(cryg10000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cryg2500)
{
    std::string input_file(MATRIX_FULL_PATH(cryg2500 ));
    std::string output_file(RESULT_FULL_PATH(cryg2500 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crystk01)
{
    std::string input_file(MATRIX_FULL_PATH(crystk01 ));
    std::string output_file(RESULT_FULL_PATH(crystk01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crystk02)
{
    std::string input_file(MATRIX_FULL_PATH(crystk02 ));
    std::string output_file(RESULT_FULL_PATH(crystk02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crystk03)
{
    std::string input_file(MATRIX_FULL_PATH(crystk03 ));
    std::string output_file(RESULT_FULL_PATH(crystk03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crystm01)
{
    std::string input_file(MATRIX_FULL_PATH(crystm01 ));
    std::string output_file(RESULT_FULL_PATH(crystm01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crystm02)
{
    std::string input_file(MATRIX_FULL_PATH(crystm02 ));
    std::string output_file(RESULT_FULL_PATH(crystm02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, crystm03)
{
    std::string input_file(MATRIX_FULL_PATH(crystm03 ));
    std::string output_file(RESULT_FULL_PATH(crystm03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cs4)
{
    std::string input_file(MATRIX_FULL_PATH(cs4 ));
    std::string output_file(RESULT_FULL_PATH(cs4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, CSphd)
{
    std::string input_file(MATRIX_FULL_PATH(CSphd ));
    std::string output_file(RESULT_FULL_PATH(CSphd ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ct20stif)
{
    std::string input_file(MATRIX_FULL_PATH(ct20stif ));
    std::string output_file(RESULT_FULL_PATH(ct20stif ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cti)
{
    std::string input_file(MATRIX_FULL_PATH(cti ));
    std::string output_file(RESULT_FULL_PATH(cti ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cvxbqp1)
{
    std::string input_file(MATRIX_FULL_PATH(cvxbqp1 ));
    std::string output_file(RESULT_FULL_PATH(cvxbqp1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cvxqp3)
{
    std::string input_file(MATRIX_FULL_PATH(cvxqp3 ));
    std::string output_file(RESULT_FULL_PATH(cvxqp3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, cyl6)
{
    std::string input_file(MATRIX_FULL_PATH(cyl6 ));
    std::string output_file(RESULT_FULL_PATH(cyl6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, darcy003)
{
    std::string input_file(MATRIX_FULL_PATH(darcy003 ));
    std::string output_file(RESULT_FULL_PATH(darcy003 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, data)
{
    std::string input_file(MATRIX_FULL_PATH(data ));
    std::string output_file(RESULT_FULL_PATH(data ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dawson5)
{
    std::string input_file(MATRIX_FULL_PATH(dawson5 ));
    std::string output_file(RESULT_FULL_PATH(dawson5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dblp_2010)
{
    std::string input_file(MATRIX_FULL_PATH(dblp-2010 ));
    std::string output_file(RESULT_FULL_PATH(dblp-2010 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dc1)
{
    std::string input_file(MATRIX_FULL_PATH(dc1 ));
    std::string output_file(RESULT_FULL_PATH(dc1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dc2)
{
    std::string input_file(MATRIX_FULL_PATH(dc2 ));
    std::string output_file(RESULT_FULL_PATH(dc2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dc3)
{
    std::string input_file(MATRIX_FULL_PATH(dc3 ));
    std::string output_file(RESULT_FULL_PATH(dc3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n10)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n10 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n11)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n11 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n12)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n12 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n13)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n13 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n14)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n14 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n15)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n15 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n16)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n16 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n17)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n17 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n18)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n18 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, delaunay_n19)
{
    std::string input_file(MATRIX_FULL_PATH(delaunay_n19 ));
    std::string output_file(RESULT_FULL_PATH(delaunay_n19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, denormal)
{
    std::string input_file(MATRIX_FULL_PATH(denormal ));
    std::string output_file(RESULT_FULL_PATH(denormal ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, descriptor_xingo6u)
{
    std::string input_file(MATRIX_FULL_PATH(descriptor_xingo6u ));
    std::string output_file(RESULT_FULL_PATH(descriptor_xingo6u ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, diag)
{
    std::string input_file(MATRIX_FULL_PATH(diag ));
    std::string output_file(RESULT_FULL_PATH(diag ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dictionary28)
{
    std::string input_file(MATRIX_FULL_PATH(dictionary28 ));
    std::string output_file(RESULT_FULL_PATH(dictionary28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dielFilterV3clx)
{
    std::string input_file(MATRIX_FULL_PATH(dielFilterV3clx ));
    std::string output_file(RESULT_FULL_PATH(dielFilterV3clx ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dixmaanl)
{
    std::string input_file(MATRIX_FULL_PATH(dixmaanl ));
    std::string output_file(RESULT_FULL_PATH(dixmaanl ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, DK01R)
{
    std::string input_file(MATRIX_FULL_PATH(DK01R ));
    std::string output_file(RESULT_FULL_PATH(DK01R ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, d_pretok)
{
    std::string input_file(MATRIX_FULL_PATH(d_pretok ));
    std::string output_file(RESULT_FULL_PATH(d_pretok ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dtoc)
{
    std::string input_file(MATRIX_FULL_PATH(dtoc ));
    std::string output_file(RESULT_FULL_PATH(dtoc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Dubcova1)
{
    std::string input_file(MATRIX_FULL_PATH(Dubcova1 ));
    std::string output_file(RESULT_FULL_PATH(Dubcova1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Dubcova2)
{
    std::string input_file(MATRIX_FULL_PATH(Dubcova2 ));
    std::string output_file(RESULT_FULL_PATH(Dubcova2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Dubcova3)
{
    std::string input_file(MATRIX_FULL_PATH(Dubcova3 ));
    std::string output_file(RESULT_FULL_PATH(Dubcova3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dw1024)
{
    std::string input_file(MATRIX_FULL_PATH(dw1024 ));
    std::string output_file(RESULT_FULL_PATH(dw1024 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dw2048)
{
    std::string input_file(MATRIX_FULL_PATH(dw2048 ));
    std::string output_file(RESULT_FULL_PATH(dw2048 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dw256A)
{
    std::string input_file(MATRIX_FULL_PATH(dw256A ));
    std::string output_file(RESULT_FULL_PATH(dw256A ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dw256B)
{
    std::string input_file(MATRIX_FULL_PATH(dw256B ));
    std::string output_file(RESULT_FULL_PATH(dw256B ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dw4096)
{
    std::string input_file(MATRIX_FULL_PATH(dw4096 ));
    std::string output_file(RESULT_FULL_PATH(dw4096 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dw8192)
{
    std::string input_file(MATRIX_FULL_PATH(dw8192 ));
    std::string output_file(RESULT_FULL_PATH(dw8192 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwa512)
{
    std::string input_file(MATRIX_FULL_PATH(dwa512 ));
    std::string output_file(RESULT_FULL_PATH(dwa512 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwb512)
{
    std::string input_file(MATRIX_FULL_PATH(dwb512 ));
    std::string output_file(RESULT_FULL_PATH(dwb512 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwg961a)
{
    std::string input_file(MATRIX_FULL_PATH(dwg961a ));
    std::string output_file(RESULT_FULL_PATH(dwg961a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwg961b)
{
    std::string input_file(MATRIX_FULL_PATH(dwg961b ));
    std::string output_file(RESULT_FULL_PATH(dwg961b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_1005)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_1005 ));
    std::string output_file(RESULT_FULL_PATH(dwt_1005 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_1007)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_1007 ));
    std::string output_file(RESULT_FULL_PATH(dwt_1007 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_1242)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_1242 ));
    std::string output_file(RESULT_FULL_PATH(dwt_1242 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_162)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_162 ));
    std::string output_file(RESULT_FULL_PATH(dwt_162 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_193)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_193 ));
    std::string output_file(RESULT_FULL_PATH(dwt_193 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_198)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_198 ));
    std::string output_file(RESULT_FULL_PATH(dwt_198 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_209)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_209 ));
    std::string output_file(RESULT_FULL_PATH(dwt_209 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_221)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_221 ));
    std::string output_file(RESULT_FULL_PATH(dwt_221 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_245)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_245 ));
    std::string output_file(RESULT_FULL_PATH(dwt_245 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_2680)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_2680 ));
    std::string output_file(RESULT_FULL_PATH(dwt_2680 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_307)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_307 ));
    std::string output_file(RESULT_FULL_PATH(dwt_307 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_310)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_310 ));
    std::string output_file(RESULT_FULL_PATH(dwt_310 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_346)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_346 ));
    std::string output_file(RESULT_FULL_PATH(dwt_346 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_361)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_361 ));
    std::string output_file(RESULT_FULL_PATH(dwt_361 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_419)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_419 ));
    std::string output_file(RESULT_FULL_PATH(dwt_419 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_492)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_492 ));
    std::string output_file(RESULT_FULL_PATH(dwt_492 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_503)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_503 ));
    std::string output_file(RESULT_FULL_PATH(dwt_503 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_512)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_512 ));
    std::string output_file(RESULT_FULL_PATH(dwt_512 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_592)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_592 ));
    std::string output_file(RESULT_FULL_PATH(dwt_592 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_607)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_607 ));
    std::string output_file(RESULT_FULL_PATH(dwt_607 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_758)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_758 ));
    std::string output_file(RESULT_FULL_PATH(dwt_758 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_869)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_869 ));
    std::string output_file(RESULT_FULL_PATH(dwt_869 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_878)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_878 ));
    std::string output_file(RESULT_FULL_PATH(dwt_878 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_918)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_918 ));
    std::string output_file(RESULT_FULL_PATH(dwt_918 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, dwt_992)
{
    std::string input_file(MATRIX_FULL_PATH(dwt_992 ));
    std::string output_file(RESULT_FULL_PATH(dwt_992 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, e40r0100)
{
    std::string input_file(MATRIX_FULL_PATH(e40r0100 ));
    std::string output_file(RESULT_FULL_PATH(e40r0100 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EAT_RS)
{
    std::string input_file(MATRIX_FULL_PATH(EAT_RS ));
    std::string output_file(RESULT_FULL_PATH(EAT_RS ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EAT_SR)
{
    std::string input_file(MATRIX_FULL_PATH(EAT_SR ));
    std::string output_file(RESULT_FULL_PATH(EAT_SR ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ecl32)
{
    std::string input_file(MATRIX_FULL_PATH(ecl32 ));
    std::string output_file(RESULT_FULL_PATH(ecl32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, email_Enron)
{
    std::string input_file(MATRIX_FULL_PATH(email-Enron ));
    std::string output_file(RESULT_FULL_PATH(email-Enron ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, email_EuAll)
{
    std::string input_file(MATRIX_FULL_PATH(email-EuAll ));
    std::string output_file(RESULT_FULL_PATH(email-EuAll ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, email)
{
    std::string input_file(MATRIX_FULL_PATH(email ));
    std::string output_file(RESULT_FULL_PATH(email ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, engine)
{
    std::string input_file(MATRIX_FULL_PATH(engine ));
    std::string output_file(RESULT_FULL_PATH(engine ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, enron)
{
    std::string input_file(MATRIX_FULL_PATH(enron ));
    std::string output_file(RESULT_FULL_PATH(enron ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EPA)
{
    std::string input_file(MATRIX_FULL_PATH(EPA ));
    std::string output_file(RESULT_FULL_PATH(EPA ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, epb0)
{
    std::string input_file(MATRIX_FULL_PATH(epb0 ));
    std::string output_file(RESULT_FULL_PATH(epb0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, epb1)
{
    std::string input_file(MATRIX_FULL_PATH(epb1 ));
    std::string output_file(RESULT_FULL_PATH(epb1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, epb2)
{
    std::string input_file(MATRIX_FULL_PATH(epb2 ));
    std::string output_file(RESULT_FULL_PATH(epb2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, epb3)
{
    std::string input_file(MATRIX_FULL_PATH(epb3 ));
    std::string output_file(RESULT_FULL_PATH(epb3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Erdos02)
{
    std::string input_file(MATRIX_FULL_PATH(Erdos02 ));
    std::string output_file(RESULT_FULL_PATH(Erdos02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Erdos971)
{
    std::string input_file(MATRIX_FULL_PATH(Erdos971 ));
    std::string output_file(RESULT_FULL_PATH(Erdos971 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Erdos972)
{
    std::string input_file(MATRIX_FULL_PATH(Erdos972 ));
    std::string output_file(RESULT_FULL_PATH(Erdos972 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Erdos981)
{
    std::string input_file(MATRIX_FULL_PATH(Erdos981 ));
    std::string output_file(RESULT_FULL_PATH(Erdos981 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Erdos982)
{
    std::string input_file(MATRIX_FULL_PATH(Erdos982 ));
    std::string output_file(RESULT_FULL_PATH(Erdos982 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Erdos991)
{
    std::string input_file(MATRIX_FULL_PATH(Erdos991 ));
    std::string output_file(RESULT_FULL_PATH(Erdos991 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Erdos992)
{
    std::string input_file(MATRIX_FULL_PATH(Erdos992 ));
    std::string output_file(RESULT_FULL_PATH(Erdos992 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, eris1176)
{
    std::string input_file(MATRIX_FULL_PATH(eris1176 ));
    std::string output_file(RESULT_FULL_PATH(eris1176 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, eurqsa)
{
    std::string input_file(MATRIX_FULL_PATH(eurqsa ));
    std::string output_file(RESULT_FULL_PATH(eurqsa ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EVA)
{
    std::string input_file(MATRIX_FULL_PATH(EVA ));
    std::string output_file(RESULT_FULL_PATH(EVA ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex10hs)
{
    std::string input_file(MATRIX_FULL_PATH(ex10hs ));
    std::string output_file(RESULT_FULL_PATH(ex10hs ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex10)
{
    std::string input_file(MATRIX_FULL_PATH(ex10 ));
    std::string output_file(RESULT_FULL_PATH(ex10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex11)
{
    std::string input_file(MATRIX_FULL_PATH(ex11 ));
    std::string output_file(RESULT_FULL_PATH(ex11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex12)
{
    std::string input_file(MATRIX_FULL_PATH(ex12 ));
    std::string output_file(RESULT_FULL_PATH(ex12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex13)
{
    std::string input_file(MATRIX_FULL_PATH(ex13 ));
    std::string output_file(RESULT_FULL_PATH(ex13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex14)
{
    std::string input_file(MATRIX_FULL_PATH(ex14 ));
    std::string output_file(RESULT_FULL_PATH(ex14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex15)
{
    std::string input_file(MATRIX_FULL_PATH(ex15 ));
    std::string output_file(RESULT_FULL_PATH(ex15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex18)
{
    std::string input_file(MATRIX_FULL_PATH(ex18 ));
    std::string output_file(RESULT_FULL_PATH(ex18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex19)
{
    std::string input_file(MATRIX_FULL_PATH(ex19 ));
    std::string output_file(RESULT_FULL_PATH(ex19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex1)
{
    std::string input_file(MATRIX_FULL_PATH(ex1 ));
    std::string output_file(RESULT_FULL_PATH(ex1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EX1)
{
    std::string input_file(MATRIX_FULL_PATH(EX1 ));
    std::string output_file(RESULT_FULL_PATH(EX1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex20)
{
    std::string input_file(MATRIX_FULL_PATH(ex20 ));
    std::string output_file(RESULT_FULL_PATH(ex20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex21)
{
    std::string input_file(MATRIX_FULL_PATH(ex21 ));
    std::string output_file(RESULT_FULL_PATH(ex21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex22)
{
    std::string input_file(MATRIX_FULL_PATH(ex22 ));
    std::string output_file(RESULT_FULL_PATH(ex22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex23)
{
    std::string input_file(MATRIX_FULL_PATH(ex23 ));
    std::string output_file(RESULT_FULL_PATH(ex23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex24)
{
    std::string input_file(MATRIX_FULL_PATH(ex24 ));
    std::string output_file(RESULT_FULL_PATH(ex24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex25)
{
    std::string input_file(MATRIX_FULL_PATH(ex25 ));
    std::string output_file(RESULT_FULL_PATH(ex25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex26)
{
    std::string input_file(MATRIX_FULL_PATH(ex26 ));
    std::string output_file(RESULT_FULL_PATH(ex26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex27)
{
    std::string input_file(MATRIX_FULL_PATH(ex27 ));
    std::string output_file(RESULT_FULL_PATH(ex27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex28)
{
    std::string input_file(MATRIX_FULL_PATH(ex28 ));
    std::string output_file(RESULT_FULL_PATH(ex28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex29)
{
    std::string input_file(MATRIX_FULL_PATH(ex29 ));
    std::string output_file(RESULT_FULL_PATH(ex29 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex2)
{
    std::string input_file(MATRIX_FULL_PATH(ex2 ));
    std::string output_file(RESULT_FULL_PATH(ex2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EX2)
{
    std::string input_file(MATRIX_FULL_PATH(EX2 ));
    std::string output_file(RESULT_FULL_PATH(EX2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex31)
{
    std::string input_file(MATRIX_FULL_PATH(ex31 ));
    std::string output_file(RESULT_FULL_PATH(ex31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex32)
{
    std::string input_file(MATRIX_FULL_PATH(ex32 ));
    std::string output_file(RESULT_FULL_PATH(ex32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex33)
{
    std::string input_file(MATRIX_FULL_PATH(ex33 ));
    std::string output_file(RESULT_FULL_PATH(ex33 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex35)
{
    std::string input_file(MATRIX_FULL_PATH(ex35 ));
    std::string output_file(RESULT_FULL_PATH(ex35 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex36)
{
    std::string input_file(MATRIX_FULL_PATH(ex36 ));
    std::string output_file(RESULT_FULL_PATH(ex36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex37)
{
    std::string input_file(MATRIX_FULL_PATH(ex37 ));
    std::string output_file(RESULT_FULL_PATH(ex37 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex3sta1)
{
    std::string input_file(MATRIX_FULL_PATH(ex3sta1 ));
    std::string output_file(RESULT_FULL_PATH(ex3sta1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex3)
{
    std::string input_file(MATRIX_FULL_PATH(ex3 ));
    std::string output_file(RESULT_FULL_PATH(ex3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EX3)
{
    std::string input_file(MATRIX_FULL_PATH(EX3 ));
    std::string output_file(RESULT_FULL_PATH(EX3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex40)
{
    std::string input_file(MATRIX_FULL_PATH(ex40 ));
    std::string output_file(RESULT_FULL_PATH(ex40 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex4)
{
    std::string input_file(MATRIX_FULL_PATH(ex4 ));
    std::string output_file(RESULT_FULL_PATH(ex4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EX4)
{
    std::string input_file(MATRIX_FULL_PATH(EX4 ));
    std::string output_file(RESULT_FULL_PATH(EX4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EX5)
{
    std::string input_file(MATRIX_FULL_PATH(EX5 ));
    std::string output_file(RESULT_FULL_PATH(EX5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex6)
{
    std::string input_file(MATRIX_FULL_PATH(ex6 ));
    std::string output_file(RESULT_FULL_PATH(ex6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, EX6)
{
    std::string input_file(MATRIX_FULL_PATH(EX6 ));
    std::string output_file(RESULT_FULL_PATH(EX6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex7)
{
    std::string input_file(MATRIX_FULL_PATH(ex7 ));
    std::string output_file(RESULT_FULL_PATH(ex7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex8)
{
    std::string input_file(MATRIX_FULL_PATH(ex8 ));
    std::string output_file(RESULT_FULL_PATH(ex8 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ex9)
{
    std::string input_file(MATRIX_FULL_PATH(ex9 ));
    std::string output_file(RESULT_FULL_PATH(ex9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, exdata_1)
{
    std::string input_file(MATRIX_FULL_PATH(exdata_1 ));
    std::string output_file(RESULT_FULL_PATH(exdata_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, extr1b)
{
    std::string input_file(MATRIX_FULL_PATH(extr1b ));
    std::string output_file(RESULT_FULL_PATH(extr1b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, extr1)
{
    std::string input_file(MATRIX_FULL_PATH(extr1 ));
    std::string output_file(RESULT_FULL_PATH(extr1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, F1)
{
    std::string input_file(MATRIX_FULL_PATH(F1 ));
    std::string output_file(RESULT_FULL_PATH(F1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, F2)
{
    std::string input_file(MATRIX_FULL_PATH(F2 ));
    std::string output_file(RESULT_FULL_PATH(F2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, FA)
{
    std::string input_file(MATRIX_FULL_PATH(FA ));
    std::string output_file(RESULT_FULL_PATH(FA ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fcondp2)
{
    std::string input_file(MATRIX_FULL_PATH(fcondp2 ));
    std::string output_file(RESULT_FULL_PATH(fcondp2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fd12)
{
    std::string input_file(MATRIX_FULL_PATH(fd12 ));
    std::string output_file(RESULT_FULL_PATH(fd12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fd15)
{
    std::string input_file(MATRIX_FULL_PATH(fd15 ));
    std::string output_file(RESULT_FULL_PATH(fd15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fd18)
{
    std::string input_file(MATRIX_FULL_PATH(fd18 ));
    std::string output_file(RESULT_FULL_PATH(fd18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fe_4elt2)
{
    std::string input_file(MATRIX_FULL_PATH(fe_4elt2 ));
    std::string output_file(RESULT_FULL_PATH(fe_4elt2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fe_body)
{
    std::string input_file(MATRIX_FULL_PATH(fe_body ));
    std::string output_file(RESULT_FULL_PATH(fe_body ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, FEM_3D_thermal1)
{
    std::string input_file(MATRIX_FULL_PATH(FEM_3D_thermal1 ));
    std::string output_file(RESULT_FULL_PATH(FEM_3D_thermal1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, FEM_3D_thermal2)
{
    std::string input_file(MATRIX_FULL_PATH(FEM_3D_thermal2 ));
    std::string output_file(RESULT_FULL_PATH(FEM_3D_thermal2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fem_filter)
{
    std::string input_file(MATRIX_FULL_PATH(fem_filter ));
    std::string output_file(RESULT_FULL_PATH(fem_filter ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fem_hifreq_circuit)
{
    std::string input_file(MATRIX_FULL_PATH(fem_hifreq_circuit ));
    std::string output_file(RESULT_FULL_PATH(fem_hifreq_circuit ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fe_ocean)
{
    std::string input_file(MATRIX_FULL_PATH(fe_ocean ));
    std::string output_file(RESULT_FULL_PATH(fe_ocean ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fe_rotor)
{
    std::string input_file(MATRIX_FULL_PATH(fe_rotor ));
    std::string output_file(RESULT_FULL_PATH(fe_rotor ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fe_sphere)
{
    std::string input_file(MATRIX_FULL_PATH(fe_sphere ));
    std::string output_file(RESULT_FULL_PATH(fe_sphere ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fe_tooth)
{
    std::string input_file(MATRIX_FULL_PATH(fe_tooth ));
    std::string output_file(RESULT_FULL_PATH(fe_tooth ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, filter2D)
{
    std::string input_file(MATRIX_FULL_PATH(filter2D ));
    std::string output_file(RESULT_FULL_PATH(filter2D ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, filter3D)
{
    std::string input_file(MATRIX_FULL_PATH(filter3D ));
    std::string output_file(RESULT_FULL_PATH(filter3D ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, finan512)
{
    std::string input_file(MATRIX_FULL_PATH(finan512 ));
    std::string output_file(RESULT_FULL_PATH(finan512 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, finance256)
{
    std::string input_file(MATRIX_FULL_PATH(finance256 ));
    std::string output_file(RESULT_FULL_PATH(finance256 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, flowmeter0)
{
    std::string input_file(MATRIX_FULL_PATH(flowmeter0 ));
    std::string output_file(RESULT_FULL_PATH(flowmeter0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, flowmeter5)
{
    std::string input_file(MATRIX_FULL_PATH(flowmeter5 ));
    std::string output_file(RESULT_FULL_PATH(flowmeter5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, foldoc)
{
    std::string input_file(MATRIX_FULL_PATH(foldoc ));
    std::string output_file(RESULT_FULL_PATH(foldoc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ford1)
{
    std::string input_file(MATRIX_FULL_PATH(ford1 ));
    std::string output_file(RESULT_FULL_PATH(ford1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ford2)
{
    std::string input_file(MATRIX_FULL_PATH(ford2 ));
    std::string output_file(RESULT_FULL_PATH(ford2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_01)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_01 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_02)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_02 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_03)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_03 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_04)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_04 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_05)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_05 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_06)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_06 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_07)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_07 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_08)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_08 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_09)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_09 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_10)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_10 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_11)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_11 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_12)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_12 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_13)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_13 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_14)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_14 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_15)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_15 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_16)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_16 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_17)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_17 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_18)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_18 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_19)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_19 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_20)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_20 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_21)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_21 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_22)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_22 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_23)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_23 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_24)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_24 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_25)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_25 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_26)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_26 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_27)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_27 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_28)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_28 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_29)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_29 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_29 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_30)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_30 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_31)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_31 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_32)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_32 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_33)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_33 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_33 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_34)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_34 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_34 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_35)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_35 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_35 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_36)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_36 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_37)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_37 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_37 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_38)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_38 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_38 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_39)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_39 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_39 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_40)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_40 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_40 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_41)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_41 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_41 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_42)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_42 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_42 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_43)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_43 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_43 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_44)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_44 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_44 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_45)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_45 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_45 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_46)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_46 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_46 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_47)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_47 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_47 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_48)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_48 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_48 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_49)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_49 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_49 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_50)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_50 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_50 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_dcop_51)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_dcop_51 ));
    std::string output_file(RESULT_FULL_PATH(fpga_dcop_51 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_trans_01)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_trans_01 ));
    std::string output_file(RESULT_FULL_PATH(fpga_trans_01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fpga_trans_02)
{
    std::string input_file(MATRIX_FULL_PATH(fpga_trans_02 ));
    std::string output_file(RESULT_FULL_PATH(fpga_trans_02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fp)
{
    std::string input_file(MATRIX_FULL_PATH(fp ));
    std::string output_file(RESULT_FULL_PATH(fp ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_183_3)
{
    std::string input_file(MATRIX_FULL_PATH(fs_183_3 ));
    std::string output_file(RESULT_FULL_PATH(fs_183_3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_183_4)
{
    std::string input_file(MATRIX_FULL_PATH(fs_183_4 ));
    std::string output_file(RESULT_FULL_PATH(fs_183_4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_541_1)
{
    std::string input_file(MATRIX_FULL_PATH(fs_541_1 ));
    std::string output_file(RESULT_FULL_PATH(fs_541_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_541_2)
{
    std::string input_file(MATRIX_FULL_PATH(fs_541_2 ));
    std::string output_file(RESULT_FULL_PATH(fs_541_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_541_3)
{
    std::string input_file(MATRIX_FULL_PATH(fs_541_3 ));
    std::string output_file(RESULT_FULL_PATH(fs_541_3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_541_4)
{
    std::string input_file(MATRIX_FULL_PATH(fs_541_4 ));
    std::string output_file(RESULT_FULL_PATH(fs_541_4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_680_1)
{
    std::string input_file(MATRIX_FULL_PATH(fs_680_1 ));
    std::string output_file(RESULT_FULL_PATH(fs_680_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_680_2)
{
    std::string input_file(MATRIX_FULL_PATH(fs_680_2 ));
    std::string output_file(RESULT_FULL_PATH(fs_680_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_680_3)
{
    std::string input_file(MATRIX_FULL_PATH(fs_680_3 ));
    std::string output_file(RESULT_FULL_PATH(fs_680_3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_760_1)
{
    std::string input_file(MATRIX_FULL_PATH(fs_760_1 ));
    std::string output_file(RESULT_FULL_PATH(fs_760_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_760_2)
{
    std::string input_file(MATRIX_FULL_PATH(fs_760_2 ));
    std::string output_file(RESULT_FULL_PATH(fs_760_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fs_760_3)
{
    std::string input_file(MATRIX_FULL_PATH(fs_760_3 ));
    std::string output_file(RESULT_FULL_PATH(fs_760_3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fullb)
{
    std::string input_file(MATRIX_FULL_PATH(fullb ));
    std::string output_file(RESULT_FULL_PATH(fullb ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fv1)
{
    std::string input_file(MATRIX_FULL_PATH(fv1 ));
    std::string output_file(RESULT_FULL_PATH(fv1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fv2)
{
    std::string input_file(MATRIX_FULL_PATH(fv2 ));
    std::string output_file(RESULT_FULL_PATH(fv2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fv3)
{
    std::string input_file(MATRIX_FULL_PATH(fv3 ));
    std::string output_file(RESULT_FULL_PATH(fv3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fxm3_6)
{
    std::string input_file(MATRIX_FULL_PATH(fxm3_6 ));
    std::string output_file(RESULT_FULL_PATH(fxm3_6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, fxm4_6)
{
    std::string input_file(MATRIX_FULL_PATH(fxm4_6 ));
    std::string output_file(RESULT_FULL_PATH(fxm4_6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G10)
{
    std::string input_file(MATRIX_FULL_PATH(G10 ));
    std::string output_file(RESULT_FULL_PATH(G10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G11)
{
    std::string input_file(MATRIX_FULL_PATH(G11 ));
    std::string output_file(RESULT_FULL_PATH(G11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G12)
{
    std::string input_file(MATRIX_FULL_PATH(G12 ));
    std::string output_file(RESULT_FULL_PATH(G12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G13)
{
    std::string input_file(MATRIX_FULL_PATH(G13 ));
    std::string output_file(RESULT_FULL_PATH(G13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G14)
{
    std::string input_file(MATRIX_FULL_PATH(G14 ));
    std::string output_file(RESULT_FULL_PATH(G14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G15)
{
    std::string input_file(MATRIX_FULL_PATH(G15 ));
    std::string output_file(RESULT_FULL_PATH(G15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G16)
{
    std::string input_file(MATRIX_FULL_PATH(G16 ));
    std::string output_file(RESULT_FULL_PATH(G16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G17)
{
    std::string input_file(MATRIX_FULL_PATH(G17 ));
    std::string output_file(RESULT_FULL_PATH(G17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G18)
{
    std::string input_file(MATRIX_FULL_PATH(G18 ));
    std::string output_file(RESULT_FULL_PATH(G18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G19)
{
    std::string input_file(MATRIX_FULL_PATH(G19 ));
    std::string output_file(RESULT_FULL_PATH(G19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G1)
{
    std::string input_file(MATRIX_FULL_PATH(G1 ));
    std::string output_file(RESULT_FULL_PATH(G1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G20)
{
    std::string input_file(MATRIX_FULL_PATH(G20 ));
    std::string output_file(RESULT_FULL_PATH(G20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G21)
{
    std::string input_file(MATRIX_FULL_PATH(G21 ));
    std::string output_file(RESULT_FULL_PATH(G21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G22)
{
    std::string input_file(MATRIX_FULL_PATH(G22 ));
    std::string output_file(RESULT_FULL_PATH(G22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G23)
{
    std::string input_file(MATRIX_FULL_PATH(G23 ));
    std::string output_file(RESULT_FULL_PATH(G23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G24)
{
    std::string input_file(MATRIX_FULL_PATH(G24 ));
    std::string output_file(RESULT_FULL_PATH(G24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G25)
{
    std::string input_file(MATRIX_FULL_PATH(G25 ));
    std::string output_file(RESULT_FULL_PATH(G25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G26)
{
    std::string input_file(MATRIX_FULL_PATH(G26 ));
    std::string output_file(RESULT_FULL_PATH(G26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G27)
{
    std::string input_file(MATRIX_FULL_PATH(G27 ));
    std::string output_file(RESULT_FULL_PATH(G27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G28)
{
    std::string input_file(MATRIX_FULL_PATH(G28 ));
    std::string output_file(RESULT_FULL_PATH(G28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G29)
{
    std::string input_file(MATRIX_FULL_PATH(G29 ));
    std::string output_file(RESULT_FULL_PATH(G29 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G2_circuit)
{
    std::string input_file(MATRIX_FULL_PATH(G2_circuit ));
    std::string output_file(RESULT_FULL_PATH(G2_circuit ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G2)
{
    std::string input_file(MATRIX_FULL_PATH(G2 ));
    std::string output_file(RESULT_FULL_PATH(G2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G30)
{
    std::string input_file(MATRIX_FULL_PATH(G30 ));
    std::string output_file(RESULT_FULL_PATH(G30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G31)
{
    std::string input_file(MATRIX_FULL_PATH(G31 ));
    std::string output_file(RESULT_FULL_PATH(G31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G32)
{
    std::string input_file(MATRIX_FULL_PATH(G32 ));
    std::string output_file(RESULT_FULL_PATH(G32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G33)
{
    std::string input_file(MATRIX_FULL_PATH(G33 ));
    std::string output_file(RESULT_FULL_PATH(G33 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G34)
{
    std::string input_file(MATRIX_FULL_PATH(G34 ));
    std::string output_file(RESULT_FULL_PATH(G34 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G35)
{
    std::string input_file(MATRIX_FULL_PATH(G35 ));
    std::string output_file(RESULT_FULL_PATH(G35 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G36)
{
    std::string input_file(MATRIX_FULL_PATH(G36 ));
    std::string output_file(RESULT_FULL_PATH(G36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G37)
{
    std::string input_file(MATRIX_FULL_PATH(G37 ));
    std::string output_file(RESULT_FULL_PATH(G37 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G38)
{
    std::string input_file(MATRIX_FULL_PATH(G38 ));
    std::string output_file(RESULT_FULL_PATH(G38 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G39)
{
    std::string input_file(MATRIX_FULL_PATH(G39 ));
    std::string output_file(RESULT_FULL_PATH(G39 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g3rmt3m3)
{
    std::string input_file(MATRIX_FULL_PATH(g3rmt3m3 ));
    std::string output_file(RESULT_FULL_PATH(g3rmt3m3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G3)
{
    std::string input_file(MATRIX_FULL_PATH(G3 ));
    std::string output_file(RESULT_FULL_PATH(G3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G40)
{
    std::string input_file(MATRIX_FULL_PATH(G40 ));
    std::string output_file(RESULT_FULL_PATH(G40 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G41)
{
    std::string input_file(MATRIX_FULL_PATH(G41 ));
    std::string output_file(RESULT_FULL_PATH(G41 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G42)
{
    std::string input_file(MATRIX_FULL_PATH(G42 ));
    std::string output_file(RESULT_FULL_PATH(G42 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G43)
{
    std::string input_file(MATRIX_FULL_PATH(G43 ));
    std::string output_file(RESULT_FULL_PATH(G43 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G44)
{
    std::string input_file(MATRIX_FULL_PATH(G44 ));
    std::string output_file(RESULT_FULL_PATH(G44 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G45)
{
    std::string input_file(MATRIX_FULL_PATH(G45 ));
    std::string output_file(RESULT_FULL_PATH(G45 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G46)
{
    std::string input_file(MATRIX_FULL_PATH(G46 ));
    std::string output_file(RESULT_FULL_PATH(G46 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G47)
{
    std::string input_file(MATRIX_FULL_PATH(G47 ));
    std::string output_file(RESULT_FULL_PATH(G47 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G48)
{
    std::string input_file(MATRIX_FULL_PATH(G48 ));
    std::string output_file(RESULT_FULL_PATH(G48 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G49)
{
    std::string input_file(MATRIX_FULL_PATH(G49 ));
    std::string output_file(RESULT_FULL_PATH(G49 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G4)
{
    std::string input_file(MATRIX_FULL_PATH(G4 ));
    std::string output_file(RESULT_FULL_PATH(G4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G50)
{
    std::string input_file(MATRIX_FULL_PATH(G50 ));
    std::string output_file(RESULT_FULL_PATH(G50 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G51)
{
    std::string input_file(MATRIX_FULL_PATH(G51 ));
    std::string output_file(RESULT_FULL_PATH(G51 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G52)
{
    std::string input_file(MATRIX_FULL_PATH(G52 ));
    std::string output_file(RESULT_FULL_PATH(G52 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G53)
{
    std::string input_file(MATRIX_FULL_PATH(G53 ));
    std::string output_file(RESULT_FULL_PATH(G53 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G54)
{
    std::string input_file(MATRIX_FULL_PATH(G54 ));
    std::string output_file(RESULT_FULL_PATH(G54 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G55)
{
    std::string input_file(MATRIX_FULL_PATH(G55 ));
    std::string output_file(RESULT_FULL_PATH(G55 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G56)
{
    std::string input_file(MATRIX_FULL_PATH(G56 ));
    std::string output_file(RESULT_FULL_PATH(G56 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G57)
{
    std::string input_file(MATRIX_FULL_PATH(G57 ));
    std::string output_file(RESULT_FULL_PATH(G57 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G58)
{
    std::string input_file(MATRIX_FULL_PATH(G58 ));
    std::string output_file(RESULT_FULL_PATH(G58 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G59)
{
    std::string input_file(MATRIX_FULL_PATH(G59 ));
    std::string output_file(RESULT_FULL_PATH(G59 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G5)
{
    std::string input_file(MATRIX_FULL_PATH(G5 ));
    std::string output_file(RESULT_FULL_PATH(G5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G60)
{
    std::string input_file(MATRIX_FULL_PATH(G60 ));
    std::string output_file(RESULT_FULL_PATH(G60 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G61)
{
    std::string input_file(MATRIX_FULL_PATH(G61 ));
    std::string output_file(RESULT_FULL_PATH(G61 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G62)
{
    std::string input_file(MATRIX_FULL_PATH(G62 ));
    std::string output_file(RESULT_FULL_PATH(G62 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G63)
{
    std::string input_file(MATRIX_FULL_PATH(G63 ));
    std::string output_file(RESULT_FULL_PATH(G63 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G64)
{
    std::string input_file(MATRIX_FULL_PATH(G64 ));
    std::string output_file(RESULT_FULL_PATH(G64 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G65)
{
    std::string input_file(MATRIX_FULL_PATH(G65 ));
    std::string output_file(RESULT_FULL_PATH(G65 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G66)
{
    std::string input_file(MATRIX_FULL_PATH(G66 ));
    std::string output_file(RESULT_FULL_PATH(G66 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G67)
{
    std::string input_file(MATRIX_FULL_PATH(G67 ));
    std::string output_file(RESULT_FULL_PATH(G67 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G6)
{
    std::string input_file(MATRIX_FULL_PATH(G6 ));
    std::string output_file(RESULT_FULL_PATH(G6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac010sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac010sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac010sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac010)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac010 ));
    std::string output_file(RESULT_FULL_PATH(g7jac010 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac020sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac020sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac020sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac020)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac020 ));
    std::string output_file(RESULT_FULL_PATH(g7jac020 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac040sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac040sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac040sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac040)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac040 ));
    std::string output_file(RESULT_FULL_PATH(g7jac040 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac050sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac050sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac050sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac060sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac060sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac060sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac060)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac060 ));
    std::string output_file(RESULT_FULL_PATH(g7jac060 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac080sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac080sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac080sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac080)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac080 ));
    std::string output_file(RESULT_FULL_PATH(g7jac080 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac100sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac100sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac100sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac100)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac100 ));
    std::string output_file(RESULT_FULL_PATH(g7jac100 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac120sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac120sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac120sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac120)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac120 ));
    std::string output_file(RESULT_FULL_PATH(g7jac120 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac140sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac140sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac140sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac140)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac140 ));
    std::string output_file(RESULT_FULL_PATH(g7jac140 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac160sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac160sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac160sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac160)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac160 ));
    std::string output_file(RESULT_FULL_PATH(g7jac160 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac180sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac180sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac180sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac180)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac180 ));
    std::string output_file(RESULT_FULL_PATH(g7jac180 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac200sc)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac200sc ));
    std::string output_file(RESULT_FULL_PATH(g7jac200sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, g7jac200)
{
    std::string input_file(MATRIX_FULL_PATH(g7jac200 ));
    std::string output_file(RESULT_FULL_PATH(g7jac200 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G7)
{
    std::string input_file(MATRIX_FULL_PATH(G7 ));
    std::string output_file(RESULT_FULL_PATH(G7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G8)
{
    std::string input_file(MATRIX_FULL_PATH(G8 ));
    std::string output_file(RESULT_FULL_PATH(G8 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, G9)
{
    std::string input_file(MATRIX_FULL_PATH(G9 ));
    std::string output_file(RESULT_FULL_PATH(G9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Ga10As10H30)
{
    std::string input_file(MATRIX_FULL_PATH(Ga10As10H30 ));
    std::string output_file(RESULT_FULL_PATH(Ga10As10H30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Ga19As19H42)
{
    std::string input_file(MATRIX_FULL_PATH(Ga19As19H42 ));
    std::string output_file(RESULT_FULL_PATH(Ga19As19H42 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Ga3As3H12)
{
    std::string input_file(MATRIX_FULL_PATH(Ga3As3H12 ));
    std::string output_file(RESULT_FULL_PATH(Ga3As3H12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Ga41As41H72)
{
    std::string input_file(MATRIX_FULL_PATH(Ga41As41H72 ));
    std::string output_file(RESULT_FULL_PATH(Ga41As41H72 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, GaAsH6)
{
    std::string input_file(MATRIX_FULL_PATH(GaAsH6 ));
    std::string output_file(RESULT_FULL_PATH(GaAsH6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, garon1)
{
    std::string input_file(MATRIX_FULL_PATH(garon1 ));
    std::string output_file(RESULT_FULL_PATH(garon1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, garon2)
{
    std::string input_file(MATRIX_FULL_PATH(garon2 ));
    std::string output_file(RESULT_FULL_PATH(garon2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gas_sensor)
{
    std::string input_file(MATRIX_FULL_PATH(gas_sensor ));
    std::string output_file(RESULT_FULL_PATH(gas_sensor ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, GD00_c)
{
    std::string input_file(MATRIX_FULL_PATH(GD00_c ));
    std::string output_file(RESULT_FULL_PATH(GD00_c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, GD06_Java)
{
    std::string input_file(MATRIX_FULL_PATH(GD06_Java ));
    std::string output_file(RESULT_FULL_PATH(GD06_Java ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, GD96_a)
{
    std::string input_file(MATRIX_FULL_PATH(GD96_a ));
    std::string output_file(RESULT_FULL_PATH(GD96_a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Ge87H76)
{
    std::string input_file(MATRIX_FULL_PATH(Ge87H76 ));
    std::string output_file(RESULT_FULL_PATH(Ge87H76 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Ge99H100)
{
    std::string input_file(MATRIX_FULL_PATH(Ge99H100 ));
    std::string output_file(RESULT_FULL_PATH(Ge99H100 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gearbox)
{
    std::string input_file(MATRIX_FULL_PATH(gearbox ));
    std::string output_file(RESULT_FULL_PATH(gearbox ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gemat11)
{
    std::string input_file(MATRIX_FULL_PATH(gemat11 ));
    std::string output_file(RESULT_FULL_PATH(gemat11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gemat12)
{
    std::string input_file(MATRIX_FULL_PATH(gemat12 ));
    std::string output_file(RESULT_FULL_PATH(gemat12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, geom)
{
    std::string input_file(MATRIX_FULL_PATH(geom ));
    std::string output_file(RESULT_FULL_PATH(geom ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, goodwin)
{
    std::string input_file(MATRIX_FULL_PATH(goodwin ));
    std::string output_file(RESULT_FULL_PATH(goodwin ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gr_30_30)
{
    std::string input_file(MATRIX_FULL_PATH(gr_30_30 ));
    std::string output_file(RESULT_FULL_PATH(gr_30_30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, graham1)
{
    std::string input_file(MATRIX_FULL_PATH(graham1 ));
    std::string output_file(RESULT_FULL_PATH(graham1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gre_1107)
{
    std::string input_file(MATRIX_FULL_PATH(gre_1107 ));
    std::string output_file(RESULT_FULL_PATH(gre_1107 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gre_343)
{
    std::string input_file(MATRIX_FULL_PATH(gre_343 ));
    std::string output_file(RESULT_FULL_PATH(gre_343 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gre_512)
{
    std::string input_file(MATRIX_FULL_PATH(gre_512 ));
    std::string output_file(RESULT_FULL_PATH(gre_512 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, grid2_dual)
{
    std::string input_file(MATRIX_FULL_PATH(grid2_dual ));
    std::string output_file(RESULT_FULL_PATH(grid2_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, grid2)
{
    std::string input_file(MATRIX_FULL_PATH(grid2 ));
    std::string output_file(RESULT_FULL_PATH(grid2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gridgena)
{
    std::string input_file(MATRIX_FULL_PATH(gridgena ));
    std::string output_file(RESULT_FULL_PATH(gridgena ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, GT01R)
{
    std::string input_file(MATRIX_FULL_PATH(GT01R ));
    std::string output_file(RESULT_FULL_PATH(GT01R ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gupta1)
{
    std::string input_file(MATRIX_FULL_PATH(gupta1 ));
    std::string output_file(RESULT_FULL_PATH(gupta1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gupta2)
{
    std::string input_file(MATRIX_FULL_PATH(gupta2 ));
    std::string output_file(RESULT_FULL_PATH(gupta2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gupta3)
{
    std::string input_file(MATRIX_FULL_PATH(gupta3 ));
    std::string output_file(RESULT_FULL_PATH(gupta3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gyro_k)
{
    std::string input_file(MATRIX_FULL_PATH(gyro_k ));
    std::string output_file(RESULT_FULL_PATH(gyro_k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gyro_m)
{
    std::string input_file(MATRIX_FULL_PATH(gyro_m ));
    std::string output_file(RESULT_FULL_PATH(gyro_m ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, gyro)
{
    std::string input_file(MATRIX_FULL_PATH(gyro ));
    std::string output_file(RESULT_FULL_PATH(gyro ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, H2O)
{
    std::string input_file(MATRIX_FULL_PATH(H2O ));
    std::string output_file(RESULT_FULL_PATH(H2O ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, halfb)
{
    std::string input_file(MATRIX_FULL_PATH(halfb ));
    std::string output_file(RESULT_FULL_PATH(halfb ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Hamrle2)
{
    std::string input_file(MATRIX_FULL_PATH(Hamrle2 ));
    std::string output_file(RESULT_FULL_PATH(Hamrle2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Harvard500)
{
    std::string input_file(MATRIX_FULL_PATH(Harvard500 ));
    std::string output_file(RESULT_FULL_PATH(Harvard500 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hcircuit)
{
    std::string input_file(MATRIX_FULL_PATH(hcircuit ));
    std::string output_file(RESULT_FULL_PATH(hcircuit ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, heart1)
{
    std::string input_file(MATRIX_FULL_PATH(heart1 ));
    std::string output_file(RESULT_FULL_PATH(heart1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, heart2)
{
    std::string input_file(MATRIX_FULL_PATH(heart2 ));
    std::string output_file(RESULT_FULL_PATH(heart2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, heart3)
{
    std::string input_file(MATRIX_FULL_PATH(heart3 ));
    std::string output_file(RESULT_FULL_PATH(heart3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, helm2d03)
{
    std::string input_file(MATRIX_FULL_PATH(helm2d03 ));
    std::string output_file(RESULT_FULL_PATH(helm2d03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, helm3d01)
{
    std::string input_file(MATRIX_FULL_PATH(helm3d01 ));
    std::string output_file(RESULT_FULL_PATH(helm3d01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, HEP_th_new)
{
    std::string input_file(MATRIX_FULL_PATH(HEP-th-new ));
    std::string output_file(RESULT_FULL_PATH(HEP-th-new ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hep_th)
{
    std::string input_file(MATRIX_FULL_PATH(hep-th ));
    std::string output_file(RESULT_FULL_PATH(hep-th ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, HEP_th)
{
    std::string input_file(MATRIX_FULL_PATH(HEP-th ));
    std::string output_file(RESULT_FULL_PATH(HEP-th ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hood)
{
    std::string input_file(MATRIX_FULL_PATH(hood ));
    std::string output_file(RESULT_FULL_PATH(hood ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hor_131)
{
    std::string input_file(MATRIX_FULL_PATH(hor_131 ));
    std::string output_file(RESULT_FULL_PATH(hor_131 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, HTC_336_4438)
{
    std::string input_file(MATRIX_FULL_PATH(HTC_336_4438 ));
    std::string output_file(RESULT_FULL_PATH(HTC_336_4438 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, HTC_336_9129)
{
    std::string input_file(MATRIX_FULL_PATH(HTC_336_9129 ));
    std::string output_file(RESULT_FULL_PATH(HTC_336_9129 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, human_gene1)
{
    std::string input_file(MATRIX_FULL_PATH(human_gene1 ));
    std::string output_file(RESULT_FULL_PATH(human_gene1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, human_gene2)
{
    std::string input_file(MATRIX_FULL_PATH(human_gene2 ));
    std::string output_file(RESULT_FULL_PATH(human_gene2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hvdc1)
{
    std::string input_file(MATRIX_FULL_PATH(hvdc1 ));
    std::string output_file(RESULT_FULL_PATH(hvdc1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hvdc2)
{
    std::string input_file(MATRIX_FULL_PATH(hvdc2 ));
    std::string output_file(RESULT_FULL_PATH(hvdc2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hydr1c)
{
    std::string input_file(MATRIX_FULL_PATH(hydr1c ));
    std::string output_file(RESULT_FULL_PATH(hydr1c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, hydr1)
{
    std::string input_file(MATRIX_FULL_PATH(hydr1 ));
    std::string output_file(RESULT_FULL_PATH(hydr1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ibm_matrix_2)
{
    std::string input_file(MATRIX_FULL_PATH(ibm_matrix_2 ));
    std::string output_file(RESULT_FULL_PATH(ibm_matrix_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, igbt3)
{
    std::string input_file(MATRIX_FULL_PATH(igbt3 ));
    std::string output_file(RESULT_FULL_PATH(igbt3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Ill_Stokes)
{
    std::string input_file(MATRIX_FULL_PATH(Ill_Stokes ));
    std::string output_file(RESULT_FULL_PATH(Ill_Stokes ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, impcol_c)
{
    std::string input_file(MATRIX_FULL_PATH(impcol_c ));
    std::string output_file(RESULT_FULL_PATH(impcol_c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, impcol_d)
{
    std::string input_file(MATRIX_FULL_PATH(impcol_d ));
    std::string output_file(RESULT_FULL_PATH(impcol_d ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, impcol_e)
{
    std::string input_file(MATRIX_FULL_PATH(impcol_e ));
    std::string output_file(RESULT_FULL_PATH(impcol_e ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, init_adder1)
{
    std::string input_file(MATRIX_FULL_PATH(init_adder1 ));
    std::string output_file(RESULT_FULL_PATH(init_adder1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, inlet)
{
    std::string input_file(MATRIX_FULL_PATH(inlet ));
    std::string output_file(RESULT_FULL_PATH(inlet ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, inline_1)
{
    std::string input_file(MATRIX_FULL_PATH(inline_1 ));
    std::string output_file(RESULT_FULL_PATH(inline_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ins2)
{
    std::string input_file(MATRIX_FULL_PATH(ins2 ));
    std::string output_file(RESULT_FULL_PATH(ins2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, internet)
{
    std::string input_file(MATRIX_FULL_PATH(internet ));
    std::string output_file(RESULT_FULL_PATH(internet ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, invextr1_new)
{
    std::string input_file(MATRIX_FULL_PATH(invextr1_new ));
    std::string output_file(RESULT_FULL_PATH(invextr1_new ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, iprob)
{
    std::string input_file(MATRIX_FULL_PATH(iprob ));
    std::string output_file(RESULT_FULL_PATH(iprob ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh1)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh1 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh2)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh2 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh3)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh3 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh4)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh4 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh5)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh5 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh6)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh6 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh7)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh7 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh8)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh8 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh8 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jagmesh9)
{
    std::string input_file(MATRIX_FULL_PATH(jagmesh9 ));
    std::string output_file(RESULT_FULL_PATH(jagmesh9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac020sc)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac020sc ));
    std::string output_file(RESULT_FULL_PATH(jan99jac020sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac020)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac020 ));
    std::string output_file(RESULT_FULL_PATH(jan99jac020 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac040sc)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac040sc ));
    std::string output_file(RESULT_FULL_PATH(jan99jac040sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac040)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac040 ));
    std::string output_file(RESULT_FULL_PATH(jan99jac040 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac060sc)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac060sc ));
    std::string output_file(RESULT_FULL_PATH(jan99jac060sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac060)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac060 ));
    std::string output_file(RESULT_FULL_PATH(jan99jac060 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac080sc)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac080sc ));
    std::string output_file(RESULT_FULL_PATH(jan99jac080sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac080)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac080 ));
    std::string output_file(RESULT_FULL_PATH(jan99jac080 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac100sc)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac100sc ));
    std::string output_file(RESULT_FULL_PATH(jan99jac100sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac100)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac100 ));
    std::string output_file(RESULT_FULL_PATH(jan99jac100 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac120sc)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac120sc ));
    std::string output_file(RESULT_FULL_PATH(jan99jac120sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jan99jac120)
{
    std::string input_file(MATRIX_FULL_PATH(jan99jac120 ));
    std::string output_file(RESULT_FULL_PATH(jan99jac120 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jazz)
{
    std::string input_file(MATRIX_FULL_PATH(jazz ));
    std::string output_file(RESULT_FULL_PATH(jazz ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jnlbrng1)
{
    std::string input_file(MATRIX_FULL_PATH(jnlbrng1 ));
    std::string output_file(RESULT_FULL_PATH(jnlbrng1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, jpwh_991)
{
    std::string input_file(MATRIX_FULL_PATH(jpwh_991 ));
    std::string output_file(RESULT_FULL_PATH(jpwh_991 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, juba40k)
{
    std::string input_file(MATRIX_FULL_PATH(juba40k ));
    std::string output_file(RESULT_FULL_PATH(juba40k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, k1_san)
{
    std::string input_file(MATRIX_FULL_PATH(k1_san ));
    std::string output_file(RESULT_FULL_PATH(k1_san ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, k3plates)
{
    std::string input_file(MATRIX_FULL_PATH(k3plates ));
    std::string output_file(RESULT_FULL_PATH(k3plates ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Kaufhold)
{
    std::string input_file(MATRIX_FULL_PATH(Kaufhold ));
    std::string output_file(RESULT_FULL_PATH(Kaufhold ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, kim1)
{
    std::string input_file(MATRIX_FULL_PATH(kim1 ));
    std::string output_file(RESULT_FULL_PATH(kim1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, kim2)
{
    std::string input_file(MATRIX_FULL_PATH(kim2 ));
    std::string output_file(RESULT_FULL_PATH(kim2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Kohonen)
{
    std::string input_file(MATRIX_FULL_PATH(Kohonen ));
    std::string output_file(RESULT_FULL_PATH(Kohonen ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, kron_g500_logn16)
{
    std::string input_file(MATRIX_FULL_PATH(kron_g500-logn16 ));
    std::string output_file(RESULT_FULL_PATH(kron_g500-logn16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, kron_g500_logn17)
{
    std::string input_file(MATRIX_FULL_PATH(kron_g500-logn17 ));
    std::string output_file(RESULT_FULL_PATH(kron_g500-logn17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, kron_g500_logn18)
{
    std::string input_file(MATRIX_FULL_PATH(kron_g500-logn18 ));
    std::string output_file(RESULT_FULL_PATH(kron_g500-logn18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, kron_g500_logn19)
{
    std::string input_file(MATRIX_FULL_PATH(kron_g500-logn19 ));
    std::string output_file(RESULT_FULL_PATH(kron_g500-logn19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Kuu)
{
    std::string input_file(MATRIX_FULL_PATH(Kuu ));
    std::string output_file(RESULT_FULL_PATH(Kuu ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, L_9)
{
    std::string input_file(MATRIX_FULL_PATH(L-9 ));
    std::string output_file(RESULT_FULL_PATH(L-9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, laminar_duct3D)
{
    std::string input_file(MATRIX_FULL_PATH(laminar_duct3D ));
    std::string output_file(RESULT_FULL_PATH(laminar_duct3D ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, language)
{
    std::string input_file(MATRIX_FULL_PATH(language ));
    std::string output_file(RESULT_FULL_PATH(language ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, largebasis)
{
    std::string input_file(MATRIX_FULL_PATH(largebasis ));
    std::string output_file(RESULT_FULL_PATH(largebasis ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, laser)
{
    std::string input_file(MATRIX_FULL_PATH(laser ));
    std::string output_file(RESULT_FULL_PATH(laser ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Lederberg)
{
    std::string input_file(MATRIX_FULL_PATH(Lederberg ));
    std::string output_file(RESULT_FULL_PATH(Lederberg ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, LF10000)
{
    std::string input_file(MATRIX_FULL_PATH(LF10000 ));
    std::string output_file(RESULT_FULL_PATH(LF10000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, LFAT5000)
{
    std::string input_file(MATRIX_FULL_PATH(LFAT5000 ));
    std::string output_file(RESULT_FULL_PATH(LFAT5000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr01)
{
    std::string input_file(MATRIX_FULL_PATH(lhr01 ));
    std::string output_file(RESULT_FULL_PATH(lhr01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr02)
{
    std::string input_file(MATRIX_FULL_PATH(lhr02 ));
    std::string output_file(RESULT_FULL_PATH(lhr02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr04c)
{
    std::string input_file(MATRIX_FULL_PATH(lhr04c ));
    std::string output_file(RESULT_FULL_PATH(lhr04c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr04)
{
    std::string input_file(MATRIX_FULL_PATH(lhr04 ));
    std::string output_file(RESULT_FULL_PATH(lhr04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr07c)
{
    std::string input_file(MATRIX_FULL_PATH(lhr07c ));
    std::string output_file(RESULT_FULL_PATH(lhr07c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr07)
{
    std::string input_file(MATRIX_FULL_PATH(lhr07 ));
    std::string output_file(RESULT_FULL_PATH(lhr07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr10c)
{
    std::string input_file(MATRIX_FULL_PATH(lhr10c ));
    std::string output_file(RESULT_FULL_PATH(lhr10c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr10)
{
    std::string input_file(MATRIX_FULL_PATH(lhr10 ));
    std::string output_file(RESULT_FULL_PATH(lhr10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr11c)
{
    std::string input_file(MATRIX_FULL_PATH(lhr11c ));
    std::string output_file(RESULT_FULL_PATH(lhr11c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr11)
{
    std::string input_file(MATRIX_FULL_PATH(lhr11 ));
    std::string output_file(RESULT_FULL_PATH(lhr11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr14c)
{
    std::string input_file(MATRIX_FULL_PATH(lhr14c ));
    std::string output_file(RESULT_FULL_PATH(lhr14c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr17c)
{
    std::string input_file(MATRIX_FULL_PATH(lhr17c ));
    std::string output_file(RESULT_FULL_PATH(lhr17c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr17)
{
    std::string input_file(MATRIX_FULL_PATH(lhr17 ));
    std::string output_file(RESULT_FULL_PATH(lhr17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr34c)
{
    std::string input_file(MATRIX_FULL_PATH(lhr34c ));
    std::string output_file(RESULT_FULL_PATH(lhr34c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr34)
{
    std::string input_file(MATRIX_FULL_PATH(lhr34 ));
    std::string output_file(RESULT_FULL_PATH(lhr34 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr71c)
{
    std::string input_file(MATRIX_FULL_PATH(lhr71c ));
    std::string output_file(RESULT_FULL_PATH(lhr71c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lhr71)
{
    std::string input_file(MATRIX_FULL_PATH(lhr71 ));
    std::string output_file(RESULT_FULL_PATH(lhr71 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, light_in_tissue)
{
    std::string input_file(MATRIX_FULL_PATH(light_in_tissue ));
    std::string output_file(RESULT_FULL_PATH(light_in_tissue ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Lin)
{
    std::string input_file(MATRIX_FULL_PATH(Lin ));
    std::string output_file(RESULT_FULL_PATH(Lin ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, linverse)
{
    std::string input_file(MATRIX_FULL_PATH(linverse ));
    std::string output_file(RESULT_FULL_PATH(linverse ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, li)
{
    std::string input_file(MATRIX_FULL_PATH(li ));
    std::string output_file(RESULT_FULL_PATH(li ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lns_3937)
{
    std::string input_file(MATRIX_FULL_PATH(lns_3937 ));
    std::string output_file(RESULT_FULL_PATH(lns_3937 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lns_511)
{
    std::string input_file(MATRIX_FULL_PATH(lns_511 ));
    std::string output_file(RESULT_FULL_PATH(lns_511 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lnsp3937)
{
    std::string input_file(MATRIX_FULL_PATH(lnsp3937 ));
    std::string output_file(RESULT_FULL_PATH(lnsp3937 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lnsp_511)
{
    std::string input_file(MATRIX_FULL_PATH(lnsp_511 ));
    std::string output_file(RESULT_FULL_PATH(lnsp_511 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lock1074)
{
    std::string input_file(MATRIX_FULL_PATH(lock1074 ));
    std::string output_file(RESULT_FULL_PATH(lock1074 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lock2232)
{
    std::string input_file(MATRIX_FULL_PATH(lock2232 ));
    std::string output_file(RESULT_FULL_PATH(lock2232 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lock3491)
{
    std::string input_file(MATRIX_FULL_PATH(lock3491 ));
    std::string output_file(RESULT_FULL_PATH(lock3491 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lock_700)
{
    std::string input_file(MATRIX_FULL_PATH(lock_700 ));
    std::string output_file(RESULT_FULL_PATH(lock_700 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lpl1)
{
    std::string input_file(MATRIX_FULL_PATH(lpl1 ));
    std::string output_file(RESULT_FULL_PATH(lpl1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp1009)
{
    std::string input_file(MATRIX_FULL_PATH(lshp1009 ));
    std::string output_file(RESULT_FULL_PATH(lshp1009 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp1270)
{
    std::string input_file(MATRIX_FULL_PATH(lshp1270 ));
    std::string output_file(RESULT_FULL_PATH(lshp1270 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp1561)
{
    std::string input_file(MATRIX_FULL_PATH(lshp1561 ));
    std::string output_file(RESULT_FULL_PATH(lshp1561 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp1882)
{
    std::string input_file(MATRIX_FULL_PATH(lshp1882 ));
    std::string output_file(RESULT_FULL_PATH(lshp1882 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp2233)
{
    std::string input_file(MATRIX_FULL_PATH(lshp2233 ));
    std::string output_file(RESULT_FULL_PATH(lshp2233 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp2614)
{
    std::string input_file(MATRIX_FULL_PATH(lshp2614 ));
    std::string output_file(RESULT_FULL_PATH(lshp2614 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp_265)
{
    std::string input_file(MATRIX_FULL_PATH(lshp_265 ));
    std::string output_file(RESULT_FULL_PATH(lshp_265 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp3025)
{
    std::string input_file(MATRIX_FULL_PATH(lshp3025 ));
    std::string output_file(RESULT_FULL_PATH(lshp3025 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp3466)
{
    std::string input_file(MATRIX_FULL_PATH(lshp3466 ));
    std::string output_file(RESULT_FULL_PATH(lshp3466 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp_406)
{
    std::string input_file(MATRIX_FULL_PATH(lshp_406 ));
    std::string output_file(RESULT_FULL_PATH(lshp_406 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp_577)
{
    std::string input_file(MATRIX_FULL_PATH(lshp_577 ));
    std::string output_file(RESULT_FULL_PATH(lshp_577 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lshp_778)
{
    std::string input_file(MATRIX_FULL_PATH(lshp_778 ));
    std::string output_file(RESULT_FULL_PATH(lshp_778 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, L)
{
    std::string input_file(MATRIX_FULL_PATH(L ));
    std::string output_file(RESULT_FULL_PATH(L ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lund_a)
{
    std::string input_file(MATRIX_FULL_PATH(lund_a ));
    std::string output_file(RESULT_FULL_PATH(lund_a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lund_b)
{
    std::string input_file(MATRIX_FULL_PATH(lund_b ));
    std::string output_file(RESULT_FULL_PATH(lund_b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lung1)
{
    std::string input_file(MATRIX_FULL_PATH(lung1 ));
    std::string output_file(RESULT_FULL_PATH(lung1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, lung2)
{
    std::string input_file(MATRIX_FULL_PATH(lung2 ));
    std::string output_file(RESULT_FULL_PATH(lung2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, luxembourg_osm)
{
    std::string input_file(MATRIX_FULL_PATH(luxembourg_osm ));
    std::string output_file(RESULT_FULL_PATH(luxembourg_osm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, M10PI_n1)
{
    std::string input_file(MATRIX_FULL_PATH(M10PI_n1 ));
    std::string output_file(RESULT_FULL_PATH(M10PI_n1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, M10PI_n)
{
    std::string input_file(MATRIX_FULL_PATH(M10PI_n ));
    std::string output_file(RESULT_FULL_PATH(M10PI_n ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, m133_b3)
{
    std::string input_file(MATRIX_FULL_PATH(m133-b3 ));
    std::string output_file(RESULT_FULL_PATH(m133-b3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, m14b)
{
    std::string input_file(MATRIX_FULL_PATH(m14b ));
    std::string output_file(RESULT_FULL_PATH(m14b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, M20PI_n1)
{
    std::string input_file(MATRIX_FULL_PATH(M20PI_n1 ));
    std::string output_file(RESULT_FULL_PATH(M20PI_n1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, M20PI_n)
{
    std::string input_file(MATRIX_FULL_PATH(M20PI_n ));
    std::string output_file(RESULT_FULL_PATH(M20PI_n ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, m3plates)
{
    std::string input_file(MATRIX_FULL_PATH(m3plates ));
    std::string output_file(RESULT_FULL_PATH(m3plates ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, M40PI_n1)
{
    std::string input_file(MATRIX_FULL_PATH(M40PI_n1 ));
    std::string output_file(RESULT_FULL_PATH(M40PI_n1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, M40PI_n)
{
    std::string input_file(MATRIX_FULL_PATH(M40PI_n ));
    std::string output_file(RESULT_FULL_PATH(M40PI_n ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, M80PI_n1)
{
    std::string input_file(MATRIX_FULL_PATH(M80PI_n1 ));
    std::string output_file(RESULT_FULL_PATH(M80PI_n1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, M80PI_n)
{
    std::string input_file(MATRIX_FULL_PATH(M80PI_n ));
    std::string output_file(RESULT_FULL_PATH(M80PI_n ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mac_econ_fwd500)
{
    std::string input_file(MATRIX_FULL_PATH(mac_econ_fwd500 ));
    std::string output_file(RESULT_FULL_PATH(mac_econ_fwd500 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mahindas)
{
    std::string input_file(MATRIX_FULL_PATH(mahindas ));
    std::string output_file(RESULT_FULL_PATH(mahindas ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, majorbasis)
{
    std::string input_file(MATRIX_FULL_PATH(majorbasis ));
    std::string output_file(RESULT_FULL_PATH(majorbasis ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, man_5976)
{
    std::string input_file(MATRIX_FULL_PATH(man_5976 ));
    std::string output_file(RESULT_FULL_PATH(man_5976 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mario001)
{
    std::string input_file(MATRIX_FULL_PATH(mario001 ));
    std::string output_file(RESULT_FULL_PATH(mario001 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mario002)
{
    std::string input_file(MATRIX_FULL_PATH(mario002 ));
    std::string output_file(RESULT_FULL_PATH(mario002 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac020sc)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac020sc ));
    std::string output_file(RESULT_FULL_PATH(mark3jac020sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac020)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac020 ));
    std::string output_file(RESULT_FULL_PATH(mark3jac020 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac040sc)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac040sc ));
    std::string output_file(RESULT_FULL_PATH(mark3jac040sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac040)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac040 ));
    std::string output_file(RESULT_FULL_PATH(mark3jac040 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac060sc)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac060sc ));
    std::string output_file(RESULT_FULL_PATH(mark3jac060sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac060)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac060 ));
    std::string output_file(RESULT_FULL_PATH(mark3jac060 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac080sc)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac080sc ));
    std::string output_file(RESULT_FULL_PATH(mark3jac080sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac080)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac080 ));
    std::string output_file(RESULT_FULL_PATH(mark3jac080 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac100sc)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac100sc ));
    std::string output_file(RESULT_FULL_PATH(mark3jac100sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac100)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac100 ));
    std::string output_file(RESULT_FULL_PATH(mark3jac100 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac120sc)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac120sc ));
    std::string output_file(RESULT_FULL_PATH(mark3jac120sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac120)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac120 ));
    std::string output_file(RESULT_FULL_PATH(mark3jac120 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac140sc)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac140sc ));
    std::string output_file(RESULT_FULL_PATH(mark3jac140sc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mark3jac140)
{
    std::string input_file(MATRIX_FULL_PATH(mark3jac140 ));
    std::string output_file(RESULT_FULL_PATH(mark3jac140 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, matrix_9)
{
    std::string input_file(MATRIX_FULL_PATH(matrix_9 ));
    std::string output_file(RESULT_FULL_PATH(matrix_9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, matrix_new_3)
{
    std::string input_file(MATRIX_FULL_PATH(matrix-new_3 ));
    std::string output_file(RESULT_FULL_PATH(matrix-new_3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mbeacxc)
{
    std::string input_file(MATRIX_FULL_PATH(mbeacxc ));
    std::string output_file(RESULT_FULL_PATH(mbeacxc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mbeaflw)
{
    std::string input_file(MATRIX_FULL_PATH(mbeaflw ));
    std::string output_file(RESULT_FULL_PATH(mbeaflw ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mbeause)
{
    std::string input_file(MATRIX_FULL_PATH(mbeause ));
    std::string output_file(RESULT_FULL_PATH(mbeause ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mc2depi)
{
    std::string input_file(MATRIX_FULL_PATH(mc2depi ));
    std::string output_file(RESULT_FULL_PATH(mc2depi ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mcca)
{
    std::string input_file(MATRIX_FULL_PATH(mcca ));
    std::string output_file(RESULT_FULL_PATH(mcca ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mcfe)
{
    std::string input_file(MATRIX_FULL_PATH(mcfe ));
    std::string output_file(RESULT_FULL_PATH(mcfe ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, meg1)
{
    std::string input_file(MATRIX_FULL_PATH(meg1 ));
    std::string output_file(RESULT_FULL_PATH(meg1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, meg4)
{
    std::string input_file(MATRIX_FULL_PATH(meg4 ));
    std::string output_file(RESULT_FULL_PATH(meg4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, memplus)
{
    std::string input_file(MATRIX_FULL_PATH(memplus ));
    std::string output_file(RESULT_FULL_PATH(memplus ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mesh2e1)
{
    std::string input_file(MATRIX_FULL_PATH(mesh2e1 ));
    std::string output_file(RESULT_FULL_PATH(mesh2e1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mesh2em5)
{
    std::string input_file(MATRIX_FULL_PATH(mesh2em5 ));
    std::string output_file(RESULT_FULL_PATH(mesh2em5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mesh3e1)
{
    std::string input_file(MATRIX_FULL_PATH(mesh3e1 ));
    std::string output_file(RESULT_FULL_PATH(mesh3e1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mesh3em5)
{
    std::string input_file(MATRIX_FULL_PATH(mesh3em5 ));
    std::string output_file(RESULT_FULL_PATH(mesh3em5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mhd1280a)
{
    std::string input_file(MATRIX_FULL_PATH(mhd1280a ));
    std::string output_file(RESULT_FULL_PATH(mhd1280a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mhd1280b)
{
    std::string input_file(MATRIX_FULL_PATH(mhd1280b ));
    std::string output_file(RESULT_FULL_PATH(mhd1280b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mhd3200a)
{
    std::string input_file(MATRIX_FULL_PATH(mhd3200a ));
    std::string output_file(RESULT_FULL_PATH(mhd3200a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mhd3200b)
{
    std::string input_file(MATRIX_FULL_PATH(mhd3200b ));
    std::string output_file(RESULT_FULL_PATH(mhd3200b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mhd4800a)
{
    std::string input_file(MATRIX_FULL_PATH(mhd4800a ));
    std::string output_file(RESULT_FULL_PATH(mhd4800a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mhd4800b)
{
    std::string input_file(MATRIX_FULL_PATH(mhd4800b ));
    std::string output_file(RESULT_FULL_PATH(mhd4800b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mhda416)
{
    std::string input_file(MATRIX_FULL_PATH(mhda416 ));
    std::string output_file(RESULT_FULL_PATH(mhda416 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mhdb416)
{
    std::string input_file(MATRIX_FULL_PATH(mhdb416 ));
    std::string output_file(RESULT_FULL_PATH(mhdb416 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mimo28x28_system)
{
    std::string input_file(MATRIX_FULL_PATH(mimo28x28_system ));
    std::string output_file(RESULT_FULL_PATH(mimo28x28_system ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mimo46x46_system)
{
    std::string input_file(MATRIX_FULL_PATH(mimo46x46_system ));
    std::string output_file(RESULT_FULL_PATH(mimo46x46_system ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mimo8x8_system)
{
    std::string input_file(MATRIX_FULL_PATH(mimo8x8_system ));
    std::string output_file(RESULT_FULL_PATH(mimo8x8_system ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, minnesota)
{
    std::string input_file(MATRIX_FULL_PATH(minnesota ));
    std::string output_file(RESULT_FULL_PATH(minnesota ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, minsurfo)
{
    std::string input_file(MATRIX_FULL_PATH(minsurfo ));
    std::string output_file(RESULT_FULL_PATH(minsurfo ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mip1)
{
    std::string input_file(MATRIX_FULL_PATH(mip1 ));
    std::string output_file(RESULT_FULL_PATH(mip1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mixtank_new)
{
    std::string input_file(MATRIX_FULL_PATH(mixtank_new ));
    std::string output_file(RESULT_FULL_PATH(mixtank_new ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mono_500Hz)
{
    std::string input_file(MATRIX_FULL_PATH(mono_500Hz ));
    std::string output_file(RESULT_FULL_PATH(mono_500Hz ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mouse_gene)
{
    std::string input_file(MATRIX_FULL_PATH(mouse_gene ));
    std::string output_file(RESULT_FULL_PATH(mouse_gene ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mplate)
{
    std::string input_file(MATRIX_FULL_PATH(mplate ));
    std::string output_file(RESULT_FULL_PATH(mplate ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, msc00726)
{
    std::string input_file(MATRIX_FULL_PATH(msc00726 ));
    std::string output_file(RESULT_FULL_PATH(msc00726 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, msc01050)
{
    std::string input_file(MATRIX_FULL_PATH(msc01050 ));
    std::string output_file(RESULT_FULL_PATH(msc01050 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, msc01440)
{
    std::string input_file(MATRIX_FULL_PATH(msc01440 ));
    std::string output_file(RESULT_FULL_PATH(msc01440 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, msc04515)
{
    std::string input_file(MATRIX_FULL_PATH(msc04515 ));
    std::string output_file(RESULT_FULL_PATH(msc04515 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, msc10848)
{
    std::string input_file(MATRIX_FULL_PATH(msc10848 ));
    std::string output_file(RESULT_FULL_PATH(msc10848 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, msc23052)
{
    std::string input_file(MATRIX_FULL_PATH(msc23052 ));
    std::string output_file(RESULT_FULL_PATH(msc23052 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, msdoor)
{
    std::string input_file(MATRIX_FULL_PATH(msdoor ));
    std::string output_file(RESULT_FULL_PATH(msdoor ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, m_t1)
{
    std::string input_file(MATRIX_FULL_PATH(m_t1 ));
    std::string output_file(RESULT_FULL_PATH(m_t1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mult_dcop_01)
{
    std::string input_file(MATRIX_FULL_PATH(mult_dcop_01 ));
    std::string output_file(RESULT_FULL_PATH(mult_dcop_01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mult_dcop_02)
{
    std::string input_file(MATRIX_FULL_PATH(mult_dcop_02 ));
    std::string output_file(RESULT_FULL_PATH(mult_dcop_02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, mult_dcop_03)
{
    std::string input_file(MATRIX_FULL_PATH(mult_dcop_03 ));
    std::string output_file(RESULT_FULL_PATH(mult_dcop_03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Muu)
{
    std::string input_file(MATRIX_FULL_PATH(Muu ));
    std::string output_file(RESULT_FULL_PATH(Muu ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, n3c6_b7)
{
    std::string input_file(MATRIX_FULL_PATH(n3c6-b7 ));
    std::string output_file(RESULT_FULL_PATH(n3c6-b7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Na5)
{
    std::string input_file(MATRIX_FULL_PATH(Na5 ));
    std::string output_file(RESULT_FULL_PATH(Na5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nasa1824)
{
    std::string input_file(MATRIX_FULL_PATH(nasa1824 ));
    std::string output_file(RESULT_FULL_PATH(nasa1824 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nasa2146)
{
    std::string input_file(MATRIX_FULL_PATH(nasa2146 ));
    std::string output_file(RESULT_FULL_PATH(nasa2146 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nasa2910)
{
    std::string input_file(MATRIX_FULL_PATH(nasa2910 ));
    std::string output_file(RESULT_FULL_PATH(nasa2910 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nasa4704)
{
    std::string input_file(MATRIX_FULL_PATH(nasa4704 ));
    std::string output_file(RESULT_FULL_PATH(nasa4704 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nasasrb)
{
    std::string input_file(MATRIX_FULL_PATH(nasasrb ));
    std::string output_file(RESULT_FULL_PATH(nasasrb ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ncvxbqp1)
{
    std::string input_file(MATRIX_FULL_PATH(ncvxbqp1 ));
    std::string output_file(RESULT_FULL_PATH(ncvxbqp1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ncvxqp1)
{
    std::string input_file(MATRIX_FULL_PATH(ncvxqp1 ));
    std::string output_file(RESULT_FULL_PATH(ncvxqp1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ncvxqp3)
{
    std::string input_file(MATRIX_FULL_PATH(ncvxqp3 ));
    std::string output_file(RESULT_FULL_PATH(ncvxqp3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ncvxqp5)
{
    std::string input_file(MATRIX_FULL_PATH(ncvxqp5 ));
    std::string output_file(RESULT_FULL_PATH(ncvxqp5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ncvxqp7)
{
    std::string input_file(MATRIX_FULL_PATH(ncvxqp7 ));
    std::string output_file(RESULT_FULL_PATH(ncvxqp7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ncvxqp9)
{
    std::string input_file(MATRIX_FULL_PATH(ncvxqp9 ));
    std::string output_file(RESULT_FULL_PATH(ncvxqp9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nd12k)
{
    std::string input_file(MATRIX_FULL_PATH(nd12k ));
    std::string output_file(RESULT_FULL_PATH(nd12k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nd24k)
{
    std::string input_file(MATRIX_FULL_PATH(nd24k ));
    std::string output_file(RESULT_FULL_PATH(nd24k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nd3k)
{
    std::string input_file(MATRIX_FULL_PATH(nd3k ));
    std::string output_file(RESULT_FULL_PATH(nd3k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nd6k)
{
    std::string input_file(MATRIX_FULL_PATH(nd6k ));
    std::string output_file(RESULT_FULL_PATH(nd6k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth01)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth01 ));
    std::string output_file(RESULT_FULL_PATH(nemeth01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth02)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth02 ));
    std::string output_file(RESULT_FULL_PATH(nemeth02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth03)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth03 ));
    std::string output_file(RESULT_FULL_PATH(nemeth03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth04)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth04 ));
    std::string output_file(RESULT_FULL_PATH(nemeth04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth05)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth05 ));
    std::string output_file(RESULT_FULL_PATH(nemeth05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth06)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth06 ));
    std::string output_file(RESULT_FULL_PATH(nemeth06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth07)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth07 ));
    std::string output_file(RESULT_FULL_PATH(nemeth07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth08)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth08 ));
    std::string output_file(RESULT_FULL_PATH(nemeth08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth09)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth09 ));
    std::string output_file(RESULT_FULL_PATH(nemeth09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth10)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth10 ));
    std::string output_file(RESULT_FULL_PATH(nemeth10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth11)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth11 ));
    std::string output_file(RESULT_FULL_PATH(nemeth11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth12)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth12 ));
    std::string output_file(RESULT_FULL_PATH(nemeth12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth13)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth13 ));
    std::string output_file(RESULT_FULL_PATH(nemeth13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth14)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth14 ));
    std::string output_file(RESULT_FULL_PATH(nemeth14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth15)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth15 ));
    std::string output_file(RESULT_FULL_PATH(nemeth15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth16)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth16 ));
    std::string output_file(RESULT_FULL_PATH(nemeth16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth17)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth17 ));
    std::string output_file(RESULT_FULL_PATH(nemeth17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth18)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth18 ));
    std::string output_file(RESULT_FULL_PATH(nemeth18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth19)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth19 ));
    std::string output_file(RESULT_FULL_PATH(nemeth19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth20)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth20 ));
    std::string output_file(RESULT_FULL_PATH(nemeth20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth21)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth21 ));
    std::string output_file(RESULT_FULL_PATH(nemeth21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth22)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth22 ));
    std::string output_file(RESULT_FULL_PATH(nemeth22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth23)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth23 ));
    std::string output_file(RESULT_FULL_PATH(nemeth23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth24)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth24 ));
    std::string output_file(RESULT_FULL_PATH(nemeth24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth25)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth25 ));
    std::string output_file(RESULT_FULL_PATH(nemeth25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nemeth26)
{
    std::string input_file(MATRIX_FULL_PATH(nemeth26 ));
    std::string output_file(RESULT_FULL_PATH(nemeth26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, net100)
{
    std::string input_file(MATRIX_FULL_PATH(net100 ));
    std::string output_file(RESULT_FULL_PATH(net100 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, net125)
{
    std::string input_file(MATRIX_FULL_PATH(net125 ));
    std::string output_file(RESULT_FULL_PATH(net125 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, net150)
{
    std::string input_file(MATRIX_FULL_PATH(net150 ));
    std::string output_file(RESULT_FULL_PATH(net150 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, net25)
{
    std::string input_file(MATRIX_FULL_PATH(net25 ));
    std::string output_file(RESULT_FULL_PATH(net25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, net4_1)
{
    std::string input_file(MATRIX_FULL_PATH(net4-1 ));
    std::string output_file(RESULT_FULL_PATH(net4-1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, net50)
{
    std::string input_file(MATRIX_FULL_PATH(net50 ));
    std::string output_file(RESULT_FULL_PATH(net50 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, net75)
{
    std::string input_file(MATRIX_FULL_PATH(net75 ));
    std::string output_file(RESULT_FULL_PATH(net75 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, netscience)
{
    std::string input_file(MATRIX_FULL_PATH(netscience ));
    std::string output_file(RESULT_FULL_PATH(netscience ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, netz4504_dual)
{
    std::string input_file(MATRIX_FULL_PATH(netz4504_dual ));
    std::string output_file(RESULT_FULL_PATH(netz4504_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, netz4504)
{
    std::string input_file(MATRIX_FULL_PATH(netz4504 ));
    std::string output_file(RESULT_FULL_PATH(netz4504 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nmos3)
{
    std::string input_file(MATRIX_FULL_PATH(nmos3 ));
    std::string output_file(RESULT_FULL_PATH(nmos3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nnc1374)
{
    std::string input_file(MATRIX_FULL_PATH(nnc1374 ));
    std::string output_file(RESULT_FULL_PATH(nnc1374 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nnc261)
{
    std::string input_file(MATRIX_FULL_PATH(nnc261 ));
    std::string output_file(RESULT_FULL_PATH(nnc261 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nnc666)
{
    std::string input_file(MATRIX_FULL_PATH(nnc666 ));
    std::string output_file(RESULT_FULL_PATH(nnc666 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nopoly)
{
    std::string input_file(MATRIX_FULL_PATH(nopoly ));
    std::string output_file(RESULT_FULL_PATH(nopoly ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nopss_11k)
{
    std::string input_file(MATRIX_FULL_PATH(nopss_11k ));
    std::string output_file(RESULT_FULL_PATH(nopss_11k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nos2)
{
    std::string input_file(MATRIX_FULL_PATH(nos2 ));
    std::string output_file(RESULT_FULL_PATH(nos2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nos3)
{
    std::string input_file(MATRIX_FULL_PATH(nos3 ));
    std::string output_file(RESULT_FULL_PATH(nos3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nos5)
{
    std::string input_file(MATRIX_FULL_PATH(nos5 ));
    std::string output_file(RESULT_FULL_PATH(nos5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nos6)
{
    std::string input_file(MATRIX_FULL_PATH(nos6 ));
    std::string output_file(RESULT_FULL_PATH(nos6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, nos7)
{
    std::string input_file(MATRIX_FULL_PATH(nos7 ));
    std::string output_file(RESULT_FULL_PATH(nos7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, NotreDame_www)
{
    std::string input_file(MATRIX_FULL_PATH(NotreDame_www ));
    std::string output_file(RESULT_FULL_PATH(NotreDame_www ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, NotreDame_yeast)
{
    std::string input_file(MATRIX_FULL_PATH(NotreDame_yeast ));
    std::string output_file(RESULT_FULL_PATH(NotreDame_yeast ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ns3Da)
{
    std::string input_file(MATRIX_FULL_PATH(ns3Da ));
    std::string output_file(RESULT_FULL_PATH(ns3Da ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, obstclae)
{
    std::string input_file(MATRIX_FULL_PATH(obstclae ));
    std::string output_file(RESULT_FULL_PATH(obstclae ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, odepa400)
{
    std::string input_file(MATRIX_FULL_PATH(odepa400 ));
    std::string output_file(RESULT_FULL_PATH(odepa400 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ODLIS)
{
    std::string input_file(MATRIX_FULL_PATH(ODLIS ));
    std::string output_file(RESULT_FULL_PATH(ODLIS ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, offshore)
{
    std::string input_file(MATRIX_FULL_PATH(offshore ));
    std::string output_file(RESULT_FULL_PATH(offshore ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ohne2)
{
    std::string input_file(MATRIX_FULL_PATH(ohne2 ));
    std::string output_file(RESULT_FULL_PATH(ohne2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oilpan)
{
    std::string input_file(MATRIX_FULL_PATH(oilpan ));
    std::string output_file(RESULT_FULL_PATH(oilpan ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, olafu)
{
    std::string input_file(MATRIX_FULL_PATH(olafu ));
    std::string output_file(RESULT_FULL_PATH(olafu ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, olesnik0)
{
    std::string input_file(MATRIX_FULL_PATH(olesnik0 ));
    std::string output_file(RESULT_FULL_PATH(olesnik0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, olm1000)
{
    std::string input_file(MATRIX_FULL_PATH(olm1000 ));
    std::string output_file(RESULT_FULL_PATH(olm1000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, olm2000)
{
    std::string input_file(MATRIX_FULL_PATH(olm2000 ));
    std::string output_file(RESULT_FULL_PATH(olm2000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, olm5000)
{
    std::string input_file(MATRIX_FULL_PATH(olm5000 ));
    std::string output_file(RESULT_FULL_PATH(olm5000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, olm500)
{
    std::string input_file(MATRIX_FULL_PATH(olm500 ));
    std::string output_file(RESULT_FULL_PATH(olm500 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, onera_dual)
{
    std::string input_file(MATRIX_FULL_PATH(onera_dual ));
    std::string output_file(RESULT_FULL_PATH(onera_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, onetone1)
{
    std::string input_file(MATRIX_FULL_PATH(onetone1 ));
    std::string output_file(RESULT_FULL_PATH(onetone1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, onetone2)
{
    std::string input_file(MATRIX_FULL_PATH(onetone2 ));
    std::string output_file(RESULT_FULL_PATH(onetone2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, OPF_10000)
{
    std::string input_file(MATRIX_FULL_PATH(OPF_10000 ));
    std::string output_file(RESULT_FULL_PATH(OPF_10000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, OPF_3754)
{
    std::string input_file(MATRIX_FULL_PATH(OPF_3754 ));
    std::string output_file(RESULT_FULL_PATH(OPF_3754 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, OPF_6000)
{
    std::string input_file(MATRIX_FULL_PATH(OPF_6000 ));
    std::string output_file(RESULT_FULL_PATH(OPF_6000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, opt1)
{
    std::string input_file(MATRIX_FULL_PATH(opt1 ));
    std::string output_file(RESULT_FULL_PATH(opt1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, orani678)
{
    std::string input_file(MATRIX_FULL_PATH(orani678 ));
    std::string output_file(RESULT_FULL_PATH(orani678 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Oregon_1)
{
    std::string input_file(MATRIX_FULL_PATH(Oregon-1 ));
    std::string output_file(RESULT_FULL_PATH(Oregon-1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Oregon_2)
{
    std::string input_file(MATRIX_FULL_PATH(Oregon-2 ));
    std::string output_file(RESULT_FULL_PATH(Oregon-2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, orsirr_1)
{
    std::string input_file(MATRIX_FULL_PATH(orsirr_1 ));
    std::string output_file(RESULT_FULL_PATH(orsirr_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, orsirr_2)
{
    std::string input_file(MATRIX_FULL_PATH(orsirr_2 ));
    std::string output_file(RESULT_FULL_PATH(orsirr_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, orsreg_1)
{
    std::string input_file(MATRIX_FULL_PATH(orsreg_1 ));
    std::string output_file(RESULT_FULL_PATH(orsreg_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_01)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_01 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_02)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_02 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_03)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_03 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_04)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_04 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_05)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_05 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_06)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_06 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_07)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_07 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_08)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_08 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_09)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_09 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_10)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_10 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_11)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_11 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_12)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_12 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_13)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_13 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_14)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_14 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_15)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_15 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_16)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_16 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_17)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_17 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_18)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_18 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_19)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_19 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_20)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_20 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_21)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_21 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_22)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_22 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_23)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_23 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_24)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_24 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_25)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_25 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_26)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_26 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_27)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_27 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_28)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_28 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_29)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_29 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_29 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_30)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_30 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_31)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_31 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_32)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_32 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_32 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_33)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_33 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_33 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_34)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_34 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_34 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_35)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_35 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_35 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_36)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_36 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_37)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_37 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_37 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_38)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_38 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_38 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_39)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_39 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_39 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_40)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_40 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_40 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_41)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_41 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_41 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_42)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_42 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_42 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_43)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_43 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_43 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_44)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_44 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_44 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_45)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_45 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_45 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_46)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_46 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_46 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_47)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_47 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_47 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_48)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_48 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_48 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_49)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_49 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_49 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_50)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_50 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_50 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_51)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_51 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_51 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_52)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_52 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_52 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_53)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_53 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_53 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_54)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_54 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_54 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_55)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_55 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_55 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_56)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_56 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_56 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_dcop_57)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_dcop_57 ));
    std::string output_file(RESULT_FULL_PATH(oscil_dcop_57 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, oscil_trans_01)
{
    std::string input_file(MATRIX_FULL_PATH(oscil_trans_01 ));
    std::string output_file(RESULT_FULL_PATH(oscil_trans_01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella04)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella04 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella05)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella05 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella06)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella06 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella08)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella08 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella09)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella09 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella24)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella24 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella25)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella25 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella30)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella30 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, p2p_Gnutella31)
{
    std::string input_file(MATRIX_FULL_PATH(p2p-Gnutella31 ));
    std::string output_file(RESULT_FULL_PATH(p2p-Gnutella31 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, para_10)
{
    std::string input_file(MATRIX_FULL_PATH(para-10 ));
    std::string output_file(RESULT_FULL_PATH(para-10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, para_4)
{
    std::string input_file(MATRIX_FULL_PATH(para-4 ));
    std::string output_file(RESULT_FULL_PATH(para-4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, para_5)
{
    std::string input_file(MATRIX_FULL_PATH(para-5 ));
    std::string output_file(RESULT_FULL_PATH(para-5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, para_6)
{
    std::string input_file(MATRIX_FULL_PATH(para-6 ));
    std::string output_file(RESULT_FULL_PATH(para-6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, para_7)
{
    std::string input_file(MATRIX_FULL_PATH(para-7 ));
    std::string output_file(RESULT_FULL_PATH(para-7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, para_8)
{
    std::string input_file(MATRIX_FULL_PATH(para-8 ));
    std::string output_file(RESULT_FULL_PATH(para-8 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, para_9)
{
    std::string input_file(MATRIX_FULL_PATH(para-9 ));
    std::string output_file(RESULT_FULL_PATH(para-9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, patents_main)
{
    std::string input_file(MATRIX_FULL_PATH(patents_main ));
    std::string output_file(RESULT_FULL_PATH(patents_main ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pattern1)
{
    std::string input_file(MATRIX_FULL_PATH(pattern1 ));
    std::string output_file(RESULT_FULL_PATH(pattern1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pcrystk02)
{
    std::string input_file(MATRIX_FULL_PATH(pcrystk02 ));
    std::string output_file(RESULT_FULL_PATH(pcrystk02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pcrystk03)
{
    std::string input_file(MATRIX_FULL_PATH(pcrystk03 ));
    std::string output_file(RESULT_FULL_PATH(pcrystk03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pct20stif)
{
    std::string input_file(MATRIX_FULL_PATH(pct20stif ));
    std::string output_file(RESULT_FULL_PATH(pct20stif ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pdb1HYS)
{
    std::string input_file(MATRIX_FULL_PATH(pdb1HYS ));
    std::string output_file(RESULT_FULL_PATH(pdb1HYS ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pde225)
{
    std::string input_file(MATRIX_FULL_PATH(pde225 ));
    std::string output_file(RESULT_FULL_PATH(pde225 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pde2961)
{
    std::string input_file(MATRIX_FULL_PATH(pde2961 ));
    std::string output_file(RESULT_FULL_PATH(pde2961 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pde900)
{
    std::string input_file(MATRIX_FULL_PATH(pde900 ));
    std::string output_file(RESULT_FULL_PATH(pde900 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pds10)
{
    std::string input_file(MATRIX_FULL_PATH(pds10 ));
    std::string output_file(RESULT_FULL_PATH(pds10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Pd)
{
    std::string input_file(MATRIX_FULL_PATH(Pd ));
    std::string output_file(RESULT_FULL_PATH(Pd ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pesa)
{
    std::string input_file(MATRIX_FULL_PATH(pesa ));
    std::string output_file(RESULT_FULL_PATH(pesa ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pf2177)
{
    std::string input_file(MATRIX_FULL_PATH(pf2177 ));
    std::string output_file(RESULT_FULL_PATH(pf2177 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pfinan512)
{
    std::string input_file(MATRIX_FULL_PATH(pfinan512 ));
    std::string output_file(RESULT_FULL_PATH(pfinan512 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, PGPgiantcompo)
{
    std::string input_file(MATRIX_FULL_PATH(PGPgiantcompo ));
    std::string output_file(RESULT_FULL_PATH(PGPgiantcompo ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, piston)
{
    std::string input_file(MATRIX_FULL_PATH(piston ));
    std::string output_file(RESULT_FULL_PATH(piston ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk01)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk01 ));
    std::string output_file(RESULT_FULL_PATH(pkustk01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk02)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk02 ));
    std::string output_file(RESULT_FULL_PATH(pkustk02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk03)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk03 ));
    std::string output_file(RESULT_FULL_PATH(pkustk03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk04)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk04 ));
    std::string output_file(RESULT_FULL_PATH(pkustk04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk05)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk05 ));
    std::string output_file(RESULT_FULL_PATH(pkustk05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk06)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk06 ));
    std::string output_file(RESULT_FULL_PATH(pkustk06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk07)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk07 ));
    std::string output_file(RESULT_FULL_PATH(pkustk07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk08)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk08 ));
    std::string output_file(RESULT_FULL_PATH(pkustk08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk09)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk09 ));
    std::string output_file(RESULT_FULL_PATH(pkustk09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk10)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk10 ));
    std::string output_file(RESULT_FULL_PATH(pkustk10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk11)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk11 ));
    std::string output_file(RESULT_FULL_PATH(pkustk11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk12)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk12 ));
    std::string output_file(RESULT_FULL_PATH(pkustk12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk13)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk13 ));
    std::string output_file(RESULT_FULL_PATH(pkustk13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pkustk14)
{
    std::string input_file(MATRIX_FULL_PATH(pkustk14 ));
    std::string output_file(RESULT_FULL_PATH(pkustk14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, plat1919)
{
    std::string input_file(MATRIX_FULL_PATH(plat1919 ));
    std::string output_file(RESULT_FULL_PATH(plat1919 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, plat362)
{
    std::string input_file(MATRIX_FULL_PATH(plat362 ));
    std::string output_file(RESULT_FULL_PATH(plat362 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, plbuckle)
{
    std::string input_file(MATRIX_FULL_PATH(plbuckle ));
    std::string output_file(RESULT_FULL_PATH(plbuckle ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pli)
{
    std::string input_file(MATRIX_FULL_PATH(pli ));
    std::string output_file(RESULT_FULL_PATH(pli ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, plsk1919)
{
    std::string input_file(MATRIX_FULL_PATH(plsk1919 ));
    std::string output_file(RESULT_FULL_PATH(plsk1919 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, plskz362)
{
    std::string input_file(MATRIX_FULL_PATH(plskz362 ));
    std::string output_file(RESULT_FULL_PATH(plskz362 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, poisson2D)
{
    std::string input_file(MATRIX_FULL_PATH(poisson2D ));
    std::string output_file(RESULT_FULL_PATH(poisson2D ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, poisson3Da)
{
    std::string input_file(MATRIX_FULL_PATH(poisson3Da ));
    std::string output_file(RESULT_FULL_PATH(poisson3Da ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, poisson3Db)
{
    std::string input_file(MATRIX_FULL_PATH(poisson3Db ));
    std::string output_file(RESULT_FULL_PATH(poisson3Db ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, polblogs)
{
    std::string input_file(MATRIX_FULL_PATH(polblogs ));
    std::string output_file(RESULT_FULL_PATH(polblogs ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, poli3)
{
    std::string input_file(MATRIX_FULL_PATH(poli3 ));
    std::string output_file(RESULT_FULL_PATH(poli3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, poli4)
{
    std::string input_file(MATRIX_FULL_PATH(poli4 ));
    std::string output_file(RESULT_FULL_PATH(poli4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, poli_large)
{
    std::string input_file(MATRIX_FULL_PATH(poli_large ));
    std::string output_file(RESULT_FULL_PATH(poli_large ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, poli)
{
    std::string input_file(MATRIX_FULL_PATH(poli ));
    std::string output_file(RESULT_FULL_PATH(poli ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pores_2)
{
    std::string input_file(MATRIX_FULL_PATH(pores_2 ));
    std::string output_file(RESULT_FULL_PATH(pores_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pores_3)
{
    std::string input_file(MATRIX_FULL_PATH(pores_3 ));
    std::string output_file(RESULT_FULL_PATH(pores_3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, powersim)
{
    std::string input_file(MATRIX_FULL_PATH(powersim ));
    std::string output_file(RESULT_FULL_PATH(powersim ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, power)
{
    std::string input_file(MATRIX_FULL_PATH(power ));
    std::string output_file(RESULT_FULL_PATH(power ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, PR02R)
{
    std::string input_file(MATRIX_FULL_PATH(PR02R ));
    std::string output_file(RESULT_FULL_PATH(PR02R ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Pres_Poisson)
{
    std::string input_file(MATRIX_FULL_PATH(Pres_Poisson ));
    std::string output_file(RESULT_FULL_PATH(Pres_Poisson ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, problem1)
{
    std::string input_file(MATRIX_FULL_PATH(problem1 ));
    std::string output_file(RESULT_FULL_PATH(problem1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, psmigr_1)
{
    std::string input_file(MATRIX_FULL_PATH(psmigr_1 ));
    std::string output_file(RESULT_FULL_PATH(psmigr_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, psmigr_2)
{
    std::string input_file(MATRIX_FULL_PATH(psmigr_2 ));
    std::string output_file(RESULT_FULL_PATH(psmigr_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, psmigr_3)
{
    std::string input_file(MATRIX_FULL_PATH(psmigr_3 ));
    std::string output_file(RESULT_FULL_PATH(psmigr_3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pwtk)
{
    std::string input_file(MATRIX_FULL_PATH(pwtk ));
    std::string output_file(RESULT_FULL_PATH(pwtk ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, pwt)
{
    std::string input_file(MATRIX_FULL_PATH(pwt ));
    std::string output_file(RESULT_FULL_PATH(pwt ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, qa8fk)
{
    std::string input_file(MATRIX_FULL_PATH(qa8fk ));
    std::string output_file(RESULT_FULL_PATH(qa8fk ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, qa8fm)
{
    std::string input_file(MATRIX_FULL_PATH(qa8fm ));
    std::string output_file(RESULT_FULL_PATH(qa8fm ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, qc2534)
{
    std::string input_file(MATRIX_FULL_PATH(qc2534 ));
    std::string output_file(RESULT_FULL_PATH(qc2534 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, qc324)
{
    std::string input_file(MATRIX_FULL_PATH(qc324 ));
    std::string output_file(RESULT_FULL_PATH(qc324 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, qh1484)
{
    std::string input_file(MATRIX_FULL_PATH(qh1484 ));
    std::string output_file(RESULT_FULL_PATH(qh1484 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, qh768)
{
    std::string input_file(MATRIX_FULL_PATH(qh768 ));
    std::string output_file(RESULT_FULL_PATH(qh768 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, qh882)
{
    std::string input_file(MATRIX_FULL_PATH(qh882 ));
    std::string output_file(RESULT_FULL_PATH(qh882 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, qpband)
{
    std::string input_file(MATRIX_FULL_PATH(qpband ));
    std::string output_file(RESULT_FULL_PATH(qpband ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, radfr1)
{
    std::string input_file(MATRIX_FULL_PATH(radfr1 ));
    std::string output_file(RESULT_FULL_PATH(radfr1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, raefsky1)
{
    std::string input_file(MATRIX_FULL_PATH(raefsky1 ));
    std::string output_file(RESULT_FULL_PATH(raefsky1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, raefsky2)
{
    std::string input_file(MATRIX_FULL_PATH(raefsky2 ));
    std::string output_file(RESULT_FULL_PATH(raefsky2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, raefsky3)
{
    std::string input_file(MATRIX_FULL_PATH(raefsky3 ));
    std::string output_file(RESULT_FULL_PATH(raefsky3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, raefsky4)
{
    std::string input_file(MATRIX_FULL_PATH(raefsky4 ));
    std::string output_file(RESULT_FULL_PATH(raefsky4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, raefsky5)
{
    std::string input_file(MATRIX_FULL_PATH(raefsky5 ));
    std::string output_file(RESULT_FULL_PATH(raefsky5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, raefsky6)
{
    std::string input_file(MATRIX_FULL_PATH(raefsky6 ));
    std::string output_file(RESULT_FULL_PATH(raefsky6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rail_1357)
{
    std::string input_file(MATRIX_FULL_PATH(rail_1357 ));
    std::string output_file(RESULT_FULL_PATH(rail_1357 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rail_20209)
{
    std::string input_file(MATRIX_FULL_PATH(rail_20209 ));
    std::string output_file(RESULT_FULL_PATH(rail_20209 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rail_5177)
{
    std::string input_file(MATRIX_FULL_PATH(rail_5177 ));
    std::string output_file(RESULT_FULL_PATH(rail_5177 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rail_79841)
{
    std::string input_file(MATRIX_FULL_PATH(rail_79841 ));
    std::string output_file(RESULT_FULL_PATH(rail_79841 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Raj1)
{
    std::string input_file(MATRIX_FULL_PATH(Raj1 ));
    std::string output_file(RESULT_FULL_PATH(Raj1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat01)
{
    std::string input_file(MATRIX_FULL_PATH(rajat01 ));
    std::string output_file(RESULT_FULL_PATH(rajat01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat02)
{
    std::string input_file(MATRIX_FULL_PATH(rajat02 ));
    std::string output_file(RESULT_FULL_PATH(rajat02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat03)
{
    std::string input_file(MATRIX_FULL_PATH(rajat03 ));
    std::string output_file(RESULT_FULL_PATH(rajat03 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat04)
{
    std::string input_file(MATRIX_FULL_PATH(rajat04 ));
    std::string output_file(RESULT_FULL_PATH(rajat04 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat05)
{
    std::string input_file(MATRIX_FULL_PATH(rajat05 ));
    std::string output_file(RESULT_FULL_PATH(rajat05 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat06)
{
    std::string input_file(MATRIX_FULL_PATH(rajat06 ));
    std::string output_file(RESULT_FULL_PATH(rajat06 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat07)
{
    std::string input_file(MATRIX_FULL_PATH(rajat07 ));
    std::string output_file(RESULT_FULL_PATH(rajat07 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat08)
{
    std::string input_file(MATRIX_FULL_PATH(rajat08 ));
    std::string output_file(RESULT_FULL_PATH(rajat08 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat09)
{
    std::string input_file(MATRIX_FULL_PATH(rajat09 ));
    std::string output_file(RESULT_FULL_PATH(rajat09 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat10)
{
    std::string input_file(MATRIX_FULL_PATH(rajat10 ));
    std::string output_file(RESULT_FULL_PATH(rajat10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat11)
{
    std::string input_file(MATRIX_FULL_PATH(rajat11 ));
    std::string output_file(RESULT_FULL_PATH(rajat11 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat12)
{
    std::string input_file(MATRIX_FULL_PATH(rajat12 ));
    std::string output_file(RESULT_FULL_PATH(rajat12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat13)
{
    std::string input_file(MATRIX_FULL_PATH(rajat13 ));
    std::string output_file(RESULT_FULL_PATH(rajat13 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat14)
{
    std::string input_file(MATRIX_FULL_PATH(rajat14 ));
    std::string output_file(RESULT_FULL_PATH(rajat14 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat15)
{
    std::string input_file(MATRIX_FULL_PATH(rajat15 ));
    std::string output_file(RESULT_FULL_PATH(rajat15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat16)
{
    std::string input_file(MATRIX_FULL_PATH(rajat16 ));
    std::string output_file(RESULT_FULL_PATH(rajat16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat17)
{
    std::string input_file(MATRIX_FULL_PATH(rajat17 ));
    std::string output_file(RESULT_FULL_PATH(rajat17 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat18)
{
    std::string input_file(MATRIX_FULL_PATH(rajat18 ));
    std::string output_file(RESULT_FULL_PATH(rajat18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat19)
{
    std::string input_file(MATRIX_FULL_PATH(rajat19 ));
    std::string output_file(RESULT_FULL_PATH(rajat19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat20)
{
    std::string input_file(MATRIX_FULL_PATH(rajat20 ));
    std::string output_file(RESULT_FULL_PATH(rajat20 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat21)
{
    std::string input_file(MATRIX_FULL_PATH(rajat21 ));
    std::string output_file(RESULT_FULL_PATH(rajat21 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat22)
{
    std::string input_file(MATRIX_FULL_PATH(rajat22 ));
    std::string output_file(RESULT_FULL_PATH(rajat22 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat23)
{
    std::string input_file(MATRIX_FULL_PATH(rajat23 ));
    std::string output_file(RESULT_FULL_PATH(rajat23 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat24)
{
    std::string input_file(MATRIX_FULL_PATH(rajat24 ));
    std::string output_file(RESULT_FULL_PATH(rajat24 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat25)
{
    std::string input_file(MATRIX_FULL_PATH(rajat25 ));
    std::string output_file(RESULT_FULL_PATH(rajat25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat26)
{
    std::string input_file(MATRIX_FULL_PATH(rajat26 ));
    std::string output_file(RESULT_FULL_PATH(rajat26 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat27)
{
    std::string input_file(MATRIX_FULL_PATH(rajat27 ));
    std::string output_file(RESULT_FULL_PATH(rajat27 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rajat28)
{
    std::string input_file(MATRIX_FULL_PATH(rajat28 ));
    std::string output_file(RESULT_FULL_PATH(rajat28 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ramage02)
{
    std::string input_file(MATRIX_FULL_PATH(ramage02 ));
    std::string output_file(RESULT_FULL_PATH(ramage02 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rbsa480)
{
    std::string input_file(MATRIX_FULL_PATH(rbsa480 ));
    std::string output_file(RESULT_FULL_PATH(rbsa480 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rbsb480)
{
    std::string input_file(MATRIX_FULL_PATH(rbsb480 ));
    std::string output_file(RESULT_FULL_PATH(rbsb480 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb1250l)
{
    std::string input_file(MATRIX_FULL_PATH(rdb1250l ));
    std::string output_file(RESULT_FULL_PATH(rdb1250l ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb1250)
{
    std::string input_file(MATRIX_FULL_PATH(rdb1250 ));
    std::string output_file(RESULT_FULL_PATH(rdb1250 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb200l)
{
    std::string input_file(MATRIX_FULL_PATH(rdb200l ));
    std::string output_file(RESULT_FULL_PATH(rdb200l ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb200)
{
    std::string input_file(MATRIX_FULL_PATH(rdb200 ));
    std::string output_file(RESULT_FULL_PATH(rdb200 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb2048_noL)
{
    std::string input_file(MATRIX_FULL_PATH(rdb2048_noL ));
    std::string output_file(RESULT_FULL_PATH(rdb2048_noL ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb2048)
{
    std::string input_file(MATRIX_FULL_PATH(rdb2048 ));
    std::string output_file(RESULT_FULL_PATH(rdb2048 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb3200l)
{
    std::string input_file(MATRIX_FULL_PATH(rdb3200l ));
    std::string output_file(RESULT_FULL_PATH(rdb3200l ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb450l)
{
    std::string input_file(MATRIX_FULL_PATH(rdb450l ));
    std::string output_file(RESULT_FULL_PATH(rdb450l ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb450)
{
    std::string input_file(MATRIX_FULL_PATH(rdb450 ));
    std::string output_file(RESULT_FULL_PATH(rdb450 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb5000)
{
    std::string input_file(MATRIX_FULL_PATH(rdb5000 ));
    std::string output_file(RESULT_FULL_PATH(rdb5000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb800l)
{
    std::string input_file(MATRIX_FULL_PATH(rdb800l ));
    std::string output_file(RESULT_FULL_PATH(rdb800l ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdb968)
{
    std::string input_file(MATRIX_FULL_PATH(rdb968 ));
    std::string output_file(RESULT_FULL_PATH(rdb968 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdist1)
{
    std::string input_file(MATRIX_FULL_PATH(rdist1 ));
    std::string output_file(RESULT_FULL_PATH(rdist1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdist2)
{
    std::string input_file(MATRIX_FULL_PATH(rdist2 ));
    std::string output_file(RESULT_FULL_PATH(rdist2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rdist3a)
{
    std::string input_file(MATRIX_FULL_PATH(rdist3a ));
    std::string output_file(RESULT_FULL_PATH(rdist3a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Reuters911)
{
    std::string input_file(MATRIX_FULL_PATH(Reuters911 ));
    std::string output_file(RESULT_FULL_PATH(Reuters911 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, RFdevice)
{
    std::string input_file(MATRIX_FULL_PATH(RFdevice ));
    std::string output_file(RESULT_FULL_PATH(RFdevice ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rgg_n_2_15_s0)
{
    std::string input_file(MATRIX_FULL_PATH(rgg_n_2_15_s0 ));
    std::string output_file(RESULT_FULL_PATH(rgg_n_2_15_s0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rgg_n_2_16_s0)
{
    std::string input_file(MATRIX_FULL_PATH(rgg_n_2_16_s0 ));
    std::string output_file(RESULT_FULL_PATH(rgg_n_2_16_s0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rgg_n_2_17_s0)
{
    std::string input_file(MATRIX_FULL_PATH(rgg_n_2_17_s0 ));
    std::string output_file(RESULT_FULL_PATH(rgg_n_2_17_s0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rgg_n_2_18_s0)
{
    std::string input_file(MATRIX_FULL_PATH(rgg_n_2_18_s0 ));
    std::string output_file(RESULT_FULL_PATH(rgg_n_2_18_s0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rgg_n_2_19_s0)
{
    std::string input_file(MATRIX_FULL_PATH(rgg_n_2_19_s0 ));
    std::string output_file(RESULT_FULL_PATH(rgg_n_2_19_s0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rim)
{
    std::string input_file(MATRIX_FULL_PATH(rim ));
    std::string output_file(RESULT_FULL_PATH(rim ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, RM07R)
{
    std::string input_file(MATRIX_FULL_PATH(RM07R ));
    std::string output_file(RESULT_FULL_PATH(RM07R ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rma10)
{
    std::string input_file(MATRIX_FULL_PATH(rma10 ));
    std::string output_file(RESULT_FULL_PATH(rma10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Roget)
{
    std::string input_file(MATRIX_FULL_PATH(Roget ));
    std::string output_file(RESULT_FULL_PATH(Roget ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rotor2)
{
    std::string input_file(MATRIX_FULL_PATH(rotor2 ));
    std::string output_file(RESULT_FULL_PATH(rotor2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rw136)
{
    std::string input_file(MATRIX_FULL_PATH(rw136 ));
    std::string output_file(RESULT_FULL_PATH(rw136 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rw496)
{
    std::string input_file(MATRIX_FULL_PATH(rw496 ));
    std::string output_file(RESULT_FULL_PATH(rw496 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, rw5151)
{
    std::string input_file(MATRIX_FULL_PATH(rw5151 ));
    std::string output_file(RESULT_FULL_PATH(rw5151 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, S10PI_n1)
{
    std::string input_file(MATRIX_FULL_PATH(S10PI_n1 ));
    std::string output_file(RESULT_FULL_PATH(S10PI_n1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, S10PI_n)
{
    std::string input_file(MATRIX_FULL_PATH(S10PI_n ));
    std::string output_file(RESULT_FULL_PATH(S10PI_n ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s1rmq4m1)
{
    std::string input_file(MATRIX_FULL_PATH(s1rmq4m1 ));
    std::string output_file(RESULT_FULL_PATH(s1rmq4m1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s1rmt3m1)
{
    std::string input_file(MATRIX_FULL_PATH(s1rmt3m1 ));
    std::string output_file(RESULT_FULL_PATH(s1rmt3m1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, S20PI_n1)
{
    std::string input_file(MATRIX_FULL_PATH(S20PI_n1 ));
    std::string output_file(RESULT_FULL_PATH(S20PI_n1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, S20PI_n)
{
    std::string input_file(MATRIX_FULL_PATH(S20PI_n ));
    std::string output_file(RESULT_FULL_PATH(S20PI_n ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s2rmq4m1)
{
    std::string input_file(MATRIX_FULL_PATH(s2rmq4m1 ));
    std::string output_file(RESULT_FULL_PATH(s2rmq4m1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s2rmt3m1)
{
    std::string input_file(MATRIX_FULL_PATH(s2rmt3m1 ));
    std::string output_file(RESULT_FULL_PATH(s2rmt3m1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s3dkq4m2)
{
    std::string input_file(MATRIX_FULL_PATH(s3dkq4m2 ));
    std::string output_file(RESULT_FULL_PATH(s3dkq4m2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s3dkt3m2)
{
    std::string input_file(MATRIX_FULL_PATH(s3dkt3m2 ));
    std::string output_file(RESULT_FULL_PATH(s3dkt3m2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s3rmq4m1)
{
    std::string input_file(MATRIX_FULL_PATH(s3rmq4m1 ));
    std::string output_file(RESULT_FULL_PATH(s3rmq4m1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s3rmt3m1)
{
    std::string input_file(MATRIX_FULL_PATH(s3rmt3m1 ));
    std::string output_file(RESULT_FULL_PATH(s3rmt3m1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s3rmt3m3)
{
    std::string input_file(MATRIX_FULL_PATH(s3rmt3m3 ));
    std::string output_file(RESULT_FULL_PATH(s3rmt3m3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, S40PI_n1)
{
    std::string input_file(MATRIX_FULL_PATH(S40PI_n1 ));
    std::string output_file(RESULT_FULL_PATH(S40PI_n1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, S40PI_n)
{
    std::string input_file(MATRIX_FULL_PATH(S40PI_n ));
    std::string output_file(RESULT_FULL_PATH(S40PI_n ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, s4dkt3m2)
{
    std::string input_file(MATRIX_FULL_PATH(s4dkt3m2 ));
    std::string output_file(RESULT_FULL_PATH(s4dkt3m2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, S80PI_n1)
{
    std::string input_file(MATRIX_FULL_PATH(S80PI_n1 ));
    std::string output_file(RESULT_FULL_PATH(S80PI_n1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, S80PI_n)
{
    std::string input_file(MATRIX_FULL_PATH(S80PI_n ));
    std::string output_file(RESULT_FULL_PATH(S80PI_n ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, saylr1)
{
    std::string input_file(MATRIX_FULL_PATH(saylr1 ));
    std::string output_file(RESULT_FULL_PATH(saylr1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, saylr3)
{
    std::string input_file(MATRIX_FULL_PATH(saylr3 ));
    std::string output_file(RESULT_FULL_PATH(saylr3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, saylr4)
{
    std::string input_file(MATRIX_FULL_PATH(saylr4 ));
    std::string output_file(RESULT_FULL_PATH(saylr4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, SciMet)
{
    std::string input_file(MATRIX_FULL_PATH(SciMet ));
    std::string output_file(RESULT_FULL_PATH(SciMet ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, scircuit)
{
    std::string input_file(MATRIX_FULL_PATH(scircuit ));
    std::string output_file(RESULT_FULL_PATH(scircuit ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, se)
{
    std::string input_file(MATRIX_FULL_PATH(se ));
    std::string output_file(RESULT_FULL_PATH(se ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shallow_water1)
{
    std::string input_file(MATRIX_FULL_PATH(shallow_water1 ));
    std::string output_file(RESULT_FULL_PATH(shallow_water1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shallow_water2)
{
    std::string input_file(MATRIX_FULL_PATH(shallow_water2 ));
    std::string output_file(RESULT_FULL_PATH(shallow_water2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shar_te2_b3)
{
    std::string input_file(MATRIX_FULL_PATH(shar_te2-b3 ));
    std::string output_file(RESULT_FULL_PATH(shar_te2-b3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sherman1)
{
    std::string input_file(MATRIX_FULL_PATH(sherman1 ));
    std::string output_file(RESULT_FULL_PATH(sherman1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sherman2)
{
    std::string input_file(MATRIX_FULL_PATH(sherman2 ));
    std::string output_file(RESULT_FULL_PATH(sherman2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sherman3)
{
    std::string input_file(MATRIX_FULL_PATH(sherman3 ));
    std::string output_file(RESULT_FULL_PATH(sherman3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sherman4)
{
    std::string input_file(MATRIX_FULL_PATH(sherman4 ));
    std::string output_file(RESULT_FULL_PATH(sherman4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sherman5)
{
    std::string input_file(MATRIX_FULL_PATH(sherman5 ));
    std::string output_file(RESULT_FULL_PATH(sherman5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shermanACa)
{
    std::string input_file(MATRIX_FULL_PATH(shermanACa ));
    std::string output_file(RESULT_FULL_PATH(shermanACa ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shermanACb)
{
    std::string input_file(MATRIX_FULL_PATH(shermanACb ));
    std::string output_file(RESULT_FULL_PATH(shermanACb ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shermanACd)
{
    std::string input_file(MATRIX_FULL_PATH(shermanACd ));
    std::string output_file(RESULT_FULL_PATH(shermanACd ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ship_001)
{
    std::string input_file(MATRIX_FULL_PATH(ship_001 ));
    std::string output_file(RESULT_FULL_PATH(ship_001 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ship_003)
{
    std::string input_file(MATRIX_FULL_PATH(ship_003 ));
    std::string output_file(RESULT_FULL_PATH(ship_003 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shipsec1)
{
    std::string input_file(MATRIX_FULL_PATH(shipsec1 ));
    std::string output_file(RESULT_FULL_PATH(shipsec1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shipsec5)
{
    std::string input_file(MATRIX_FULL_PATH(shipsec5 ));
    std::string output_file(RESULT_FULL_PATH(shipsec5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shipsec8)
{
    std::string input_file(MATRIX_FULL_PATH(shipsec8 ));
    std::string output_file(RESULT_FULL_PATH(shipsec8 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shl_0)
{
    std::string input_file(MATRIX_FULL_PATH(shl_0 ));
    std::string output_file(RESULT_FULL_PATH(shl_0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shl_200)
{
    std::string input_file(MATRIX_FULL_PATH(shl_200 ));
    std::string output_file(RESULT_FULL_PATH(shl_200 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shl_400)
{
    std::string input_file(MATRIX_FULL_PATH(shl_400 ));
    std::string output_file(RESULT_FULL_PATH(shl_400 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shock_9)
{
    std::string input_file(MATRIX_FULL_PATH(shock-9 ));
    std::string output_file(RESULT_FULL_PATH(shock-9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shuttle_eddy)
{
    std::string input_file(MATRIX_FULL_PATH(shuttle_eddy ));
    std::string output_file(RESULT_FULL_PATH(shuttle_eddy ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shyy161)
{
    std::string input_file(MATRIX_FULL_PATH(shyy161 ));
    std::string output_file(RESULT_FULL_PATH(shyy161 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, shyy41)
{
    std::string input_file(MATRIX_FULL_PATH(shyy41 ));
    std::string output_file(RESULT_FULL_PATH(shyy41 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Si10H16)
{
    std::string input_file(MATRIX_FULL_PATH(Si10H16 ));
    std::string output_file(RESULT_FULL_PATH(Si10H16 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Si2)
{
    std::string input_file(MATRIX_FULL_PATH(Si2 ));
    std::string output_file(RESULT_FULL_PATH(Si2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Si34H36)
{
    std::string input_file(MATRIX_FULL_PATH(Si34H36 ));
    std::string output_file(RESULT_FULL_PATH(Si34H36 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Si41Ge41H72)
{
    std::string input_file(MATRIX_FULL_PATH(Si41Ge41H72 ));
    std::string output_file(RESULT_FULL_PATH(Si41Ge41H72 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Si5H12)
{
    std::string input_file(MATRIX_FULL_PATH(Si5H12 ));
    std::string output_file(RESULT_FULL_PATH(Si5H12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Si87H76)
{
    std::string input_file(MATRIX_FULL_PATH(Si87H76 ));
    std::string output_file(RESULT_FULL_PATH(Si87H76 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Sieber)
{
    std::string input_file(MATRIX_FULL_PATH(Sieber ));
    std::string output_file(RESULT_FULL_PATH(Sieber ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, SiH4)
{
    std::string input_file(MATRIX_FULL_PATH(SiH4 ));
    std::string output_file(RESULT_FULL_PATH(SiH4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, SiNa)
{
    std::string input_file(MATRIX_FULL_PATH(SiNa ));
    std::string output_file(RESULT_FULL_PATH(SiNa ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sinc12)
{
    std::string input_file(MATRIX_FULL_PATH(sinc12 ));
    std::string output_file(RESULT_FULL_PATH(sinc12 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sinc15)
{
    std::string input_file(MATRIX_FULL_PATH(sinc15 ));
    std::string output_file(RESULT_FULL_PATH(sinc15 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sinc18)
{
    std::string input_file(MATRIX_FULL_PATH(sinc18 ));
    std::string output_file(RESULT_FULL_PATH(sinc18 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, SiO2)
{
    std::string input_file(MATRIX_FULL_PATH(SiO2 ));
    std::string output_file(RESULT_FULL_PATH(SiO2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, SiO)
{
    std::string input_file(MATRIX_FULL_PATH(SiO ));
    std::string output_file(RESULT_FULL_PATH(SiO ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sit100)
{
    std::string input_file(MATRIX_FULL_PATH(sit100 ));
    std::string output_file(RESULT_FULL_PATH(sit100 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, skirt)
{
    std::string input_file(MATRIX_FULL_PATH(skirt ));
    std::string output_file(RESULT_FULL_PATH(skirt ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, SmaGri)
{
    std::string input_file(MATRIX_FULL_PATH(SmaGri ));
    std::string output_file(RESULT_FULL_PATH(SmaGri ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sme3Da)
{
    std::string input_file(MATRIX_FULL_PATH(sme3Da ));
    std::string output_file(RESULT_FULL_PATH(sme3Da ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sme3Db)
{
    std::string input_file(MATRIX_FULL_PATH(sme3Db ));
    std::string output_file(RESULT_FULL_PATH(sme3Db ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sme3Dc)
{
    std::string input_file(MATRIX_FULL_PATH(sme3Dc ));
    std::string output_file(RESULT_FULL_PATH(sme3Dc ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, smt)
{
    std::string input_file(MATRIX_FULL_PATH(smt ));
    std::string output_file(RESULT_FULL_PATH(smt ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, soc_Epinions1)
{
    std::string input_file(MATRIX_FULL_PATH(soc-Epinions1 ));
    std::string output_file(RESULT_FULL_PATH(soc-Epinions1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, soc_sign_epinions)
{
    std::string input_file(MATRIX_FULL_PATH(soc-sign-epinions ));
    std::string output_file(RESULT_FULL_PATH(soc-sign-epinions ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, soc_sign_Slashdot081106)
{
    std::string input_file(MATRIX_FULL_PATH(soc-sign-Slashdot081106 ));
    std::string output_file(RESULT_FULL_PATH(soc-sign-Slashdot081106 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, soc_sign_Slashdot090216)
{
    std::string input_file(MATRIX_FULL_PATH(soc-sign-Slashdot090216 ));
    std::string output_file(RESULT_FULL_PATH(soc-sign-Slashdot090216 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, soc_sign_Slashdot090221)
{
    std::string input_file(MATRIX_FULL_PATH(soc-sign-Slashdot090221 ));
    std::string output_file(RESULT_FULL_PATH(soc-sign-Slashdot090221 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, soc_Slashdot0811)
{
    std::string input_file(MATRIX_FULL_PATH(soc-Slashdot0811 ));
    std::string output_file(RESULT_FULL_PATH(soc-Slashdot0811 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, soc_Slashdot0902)
{
    std::string input_file(MATRIX_FULL_PATH(soc-Slashdot0902 ));
    std::string output_file(RESULT_FULL_PATH(soc-Slashdot0902 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sparsine)
{
    std::string input_file(MATRIX_FULL_PATH(sparsine ));
    std::string output_file(RESULT_FULL_PATH(sparsine ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sphere3)
{
    std::string input_file(MATRIX_FULL_PATH(sphere3 ));
    std::string output_file(RESULT_FULL_PATH(sphere3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, spiral)
{
    std::string input_file(MATRIX_FULL_PATH(spiral ));
    std::string output_file(RESULT_FULL_PATH(spiral ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, spmsrtls)
{
    std::string input_file(MATRIX_FULL_PATH(spmsrtls ));
    std::string output_file(RESULT_FULL_PATH(spmsrtls ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, srb1)
{
    std::string input_file(MATRIX_FULL_PATH(srb1 ));
    std::string output_file(RESULT_FULL_PATH(srb1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sstmodel)
{
    std::string input_file(MATRIX_FULL_PATH(sstmodel ));
    std::string output_file(RESULT_FULL_PATH(sstmodel ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Stanford)
{
    std::string input_file(MATRIX_FULL_PATH(Stanford ));
    std::string output_file(RESULT_FULL_PATH(Stanford ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, std1_Jac2_db)
{
    std::string input_file(MATRIX_FULL_PATH(std1_Jac2_db ));
    std::string output_file(RESULT_FULL_PATH(std1_Jac2_db ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, std1_Jac2)
{
    std::string input_file(MATRIX_FULL_PATH(std1_Jac2 ));
    std::string output_file(RESULT_FULL_PATH(std1_Jac2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, std1_Jac3_db)
{
    std::string input_file(MATRIX_FULL_PATH(std1_Jac3_db ));
    std::string output_file(RESULT_FULL_PATH(std1_Jac3_db ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, std1_Jac3)
{
    std::string input_file(MATRIX_FULL_PATH(std1_Jac3 ));
    std::string output_file(RESULT_FULL_PATH(std1_Jac3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, steam1)
{
    std::string input_file(MATRIX_FULL_PATH(steam1 ));
    std::string output_file(RESULT_FULL_PATH(steam1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, steam2)
{
    std::string input_file(MATRIX_FULL_PATH(steam2 ));
    std::string output_file(RESULT_FULL_PATH(steam2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, stokes128)
{
    std::string input_file(MATRIX_FULL_PATH(stokes128 ));
    std::string output_file(RESULT_FULL_PATH(stokes128 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, stokes64s)
{
    std::string input_file(MATRIX_FULL_PATH(stokes64s ));
    std::string output_file(RESULT_FULL_PATH(stokes64s ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, stokes64)
{
    std::string input_file(MATRIX_FULL_PATH(stokes64 ));
    std::string output_file(RESULT_FULL_PATH(stokes64 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, stomach)
{
    std::string input_file(MATRIX_FULL_PATH(stomach ));
    std::string output_file(RESULT_FULL_PATH(stomach ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, str_0)
{
    std::string input_file(MATRIX_FULL_PATH(str_0 ));
    std::string output_file(RESULT_FULL_PATH(str_0 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, str_200)
{
    std::string input_file(MATRIX_FULL_PATH(str_200 ));
    std::string output_file(RESULT_FULL_PATH(str_200 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, str_400)
{
    std::string input_file(MATRIX_FULL_PATH(str_400 ));
    std::string output_file(RESULT_FULL_PATH(str_400 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, str_600)
{
    std::string input_file(MATRIX_FULL_PATH(str_600 ));
    std::string output_file(RESULT_FULL_PATH(str_600 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, struct3)
{
    std::string input_file(MATRIX_FULL_PATH(struct3 ));
    std::string output_file(RESULT_FULL_PATH(struct3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, struct4)
{
    std::string input_file(MATRIX_FULL_PATH(struct4 ));
    std::string output_file(RESULT_FULL_PATH(struct4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, sts4098)
{
    std::string input_file(MATRIX_FULL_PATH(sts4098 ));
    std::string output_file(RESULT_FULL_PATH(sts4098 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, stufe_10)
{
    std::string input_file(MATRIX_FULL_PATH(stufe-10 ));
    std::string output_file(RESULT_FULL_PATH(stufe-10 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, stufe)
{
    std::string input_file(MATRIX_FULL_PATH(stufe ));
    std::string output_file(RESULT_FULL_PATH(stufe ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, swang1)
{
    std::string input_file(MATRIX_FULL_PATH(swang1 ));
    std::string output_file(RESULT_FULL_PATH(swang1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, swang2)
{
    std::string input_file(MATRIX_FULL_PATH(swang2 ));
    std::string output_file(RESULT_FULL_PATH(swang2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2dah_a)
{
    std::string input_file(MATRIX_FULL_PATH(t2dah_a ));
    std::string output_file(RESULT_FULL_PATH(t2dah_a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2dah_e)
{
    std::string input_file(MATRIX_FULL_PATH(t2dah_e ));
    std::string output_file(RESULT_FULL_PATH(t2dah_e ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2dah)
{
    std::string input_file(MATRIX_FULL_PATH(t2dah ));
    std::string output_file(RESULT_FULL_PATH(t2dah ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2dal_a)
{
    std::string input_file(MATRIX_FULL_PATH(t2dal_a ));
    std::string output_file(RESULT_FULL_PATH(t2dal_a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2dal_bci)
{
    std::string input_file(MATRIX_FULL_PATH(t2dal_bci ));
    std::string output_file(RESULT_FULL_PATH(t2dal_bci ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2dal_e)
{
    std::string input_file(MATRIX_FULL_PATH(t2dal_e ));
    std::string output_file(RESULT_FULL_PATH(t2dal_e ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2dal)
{
    std::string input_file(MATRIX_FULL_PATH(t2dal ));
    std::string output_file(RESULT_FULL_PATH(t2dal ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2d_q4)
{
    std::string input_file(MATRIX_FULL_PATH(t2d_q4 ));
    std::string output_file(RESULT_FULL_PATH(t2d_q4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t2d_q9)
{
    std::string input_file(MATRIX_FULL_PATH(t2d_q9 ));
    std::string output_file(RESULT_FULL_PATH(t2d_q9 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t3dh_a)
{
    std::string input_file(MATRIX_FULL_PATH(t3dh_a ));
    std::string output_file(RESULT_FULL_PATH(t3dh_a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t3dh_e)
{
    std::string input_file(MATRIX_FULL_PATH(t3dh_e ));
    std::string output_file(RESULT_FULL_PATH(t3dh_e ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t3dh)
{
    std::string input_file(MATRIX_FULL_PATH(t3dh ));
    std::string output_file(RESULT_FULL_PATH(t3dh ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t3dl_a)
{
    std::string input_file(MATRIX_FULL_PATH(t3dl_a ));
    std::string output_file(RESULT_FULL_PATH(t3dl_a ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t3dl_e)
{
    std::string input_file(MATRIX_FULL_PATH(t3dl_e ));
    std::string output_file(RESULT_FULL_PATH(t3dl_e ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t3dl)
{
    std::string input_file(MATRIX_FULL_PATH(t3dl ));
    std::string output_file(RESULT_FULL_PATH(t3dl ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t520)
{
    std::string input_file(MATRIX_FULL_PATH(t520 ));
    std::string output_file(RESULT_FULL_PATH(t520 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, t60k)
{
    std::string input_file(MATRIX_FULL_PATH(t60k ));
    std::string output_file(RESULT_FULL_PATH(t60k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tandem_dual)
{
    std::string input_file(MATRIX_FULL_PATH(tandem_dual ));
    std::string output_file(RESULT_FULL_PATH(tandem_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tandem_vtx)
{
    std::string input_file(MATRIX_FULL_PATH(tandem_vtx ));
    std::string output_file(RESULT_FULL_PATH(tandem_vtx ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ted_AB)
{
    std::string input_file(MATRIX_FULL_PATH(ted_AB ));
    std::string output_file(RESULT_FULL_PATH(ted_AB ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ted_AB_unscaled)
{
    std::string input_file(MATRIX_FULL_PATH(ted_AB_unscaled ));
    std::string output_file(RESULT_FULL_PATH(ted_AB_unscaled ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ted_A)
{
    std::string input_file(MATRIX_FULL_PATH(ted_A ));
    std::string output_file(RESULT_FULL_PATH(ted_A ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ted_A_unscaled)
{
    std::string input_file(MATRIX_FULL_PATH(ted_A_unscaled ));
    std::string output_file(RESULT_FULL_PATH(ted_A_unscaled ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ted_B)
{
    std::string input_file(MATRIX_FULL_PATH(ted_B ));
    std::string output_file(RESULT_FULL_PATH(ted_B ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ted_B_unscaled)
{
    std::string input_file(MATRIX_FULL_PATH(ted_B_unscaled ));
    std::string output_file(RESULT_FULL_PATH(ted_B_unscaled ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, thermal1)
{
    std::string input_file(MATRIX_FULL_PATH(thermal1 ));
    std::string output_file(RESULT_FULL_PATH(thermal1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, thermal)
{
    std::string input_file(MATRIX_FULL_PATH(thermal ));
    std::string output_file(RESULT_FULL_PATH(thermal ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, thermomech_dK)
{
    std::string input_file(MATRIX_FULL_PATH(thermomech_dK ));
    std::string output_file(RESULT_FULL_PATH(thermomech_dK ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, thermomech_dM)
{
    std::string input_file(MATRIX_FULL_PATH(thermomech_dM ));
    std::string output_file(RESULT_FULL_PATH(thermomech_dM ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, thermomech_TC)
{
    std::string input_file(MATRIX_FULL_PATH(thermomech_TC ));
    std::string output_file(RESULT_FULL_PATH(thermomech_TC ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, thermomech_TK)
{
    std::string input_file(MATRIX_FULL_PATH(thermomech_TK ));
    std::string output_file(RESULT_FULL_PATH(thermomech_TK ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, thread)
{
    std::string input_file(MATRIX_FULL_PATH(thread ));
    std::string output_file(RESULT_FULL_PATH(thread ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tols1090)
{
    std::string input_file(MATRIX_FULL_PATH(tols1090 ));
    std::string output_file(RESULT_FULL_PATH(tols1090 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tols2000)
{
    std::string input_file(MATRIX_FULL_PATH(tols2000 ));
    std::string output_file(RESULT_FULL_PATH(tols2000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tols340)
{
    std::string input_file(MATRIX_FULL_PATH(tols340 ));
    std::string output_file(RESULT_FULL_PATH(tols340 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tols4000)
{
    std::string input_file(MATRIX_FULL_PATH(tols4000 ));
    std::string output_file(RESULT_FULL_PATH(tols4000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tomography)
{
    std::string input_file(MATRIX_FULL_PATH(tomography ));
    std::string output_file(RESULT_FULL_PATH(tomography ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, torsion1)
{
    std::string input_file(MATRIX_FULL_PATH(torsion1 ));
    std::string output_file(RESULT_FULL_PATH(torsion1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, torso1)
{
    std::string input_file(MATRIX_FULL_PATH(torso1 ));
    std::string output_file(RESULT_FULL_PATH(torso1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, torso2)
{
    std::string input_file(MATRIX_FULL_PATH(torso2 ));
    std::string output_file(RESULT_FULL_PATH(torso2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, torso3)
{
    std::string input_file(MATRIX_FULL_PATH(torso3 ));
    std::string output_file(RESULT_FULL_PATH(torso3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, trans4)
{
    std::string input_file(MATRIX_FULL_PATH(trans4 ));
    std::string output_file(RESULT_FULL_PATH(trans4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, trans5)
{
    std::string input_file(MATRIX_FULL_PATH(trans5 ));
    std::string output_file(RESULT_FULL_PATH(trans5 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, transient)
{
    std::string input_file(MATRIX_FULL_PATH(transient ));
    std::string output_file(RESULT_FULL_PATH(transient ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, trdheim)
{
    std::string input_file(MATRIX_FULL_PATH(trdheim ));
    std::string output_file(RESULT_FULL_PATH(trdheim ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_150)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_150 ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_150 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_20000b)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_20000b ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_20000b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_20000)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_20000 ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_20000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_2000)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_2000 ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_2000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_200b)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_200b ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_200b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_200)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_200 ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_200 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_300)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_300 ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_300 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_500)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_500 ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_500 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Trefethen_700)
{
    std::string input_file(MATRIX_FULL_PATH(Trefethen_700 ));
    std::string output_file(RESULT_FULL_PATH(Trefethen_700 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, troll)
{
    std::string input_file(MATRIX_FULL_PATH(troll ));
    std::string output_file(RESULT_FULL_PATH(troll ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSC_OPF_1047)
{
    std::string input_file(MATRIX_FULL_PATH(TSC_OPF_1047 ));
    std::string output_file(RESULT_FULL_PATH(TSC_OPF_1047 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSC_OPF_300)
{
    std::string input_file(MATRIX_FULL_PATH(TSC_OPF_300 ));
    std::string output_file(RESULT_FULL_PATH(TSC_OPF_300 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b162_c1)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b162_c1 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b162_c1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b162_c3)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b162_c3 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b162_c3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b162_c4)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b162_c4 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b162_c4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b300_c1)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b300_c1 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b300_c1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b300_c2)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b300_c2 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b300_c2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b300_c3)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b300_c3 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b300_c3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b300)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b300 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b300 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b39_c19)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b39_c19 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b39_c19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b39_c30)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b39_c30 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b39_c30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b39_c7)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b39_c7 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b39_c7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b9_c1)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b9_c1 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b9_c1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_FS_b9_c6)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_FS_b9_c6 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_FS_b9_c6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b162_c1)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b162_c1 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b162_c1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b162_c3)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b162_c3 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b162_c3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b162_c4)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b162_c4 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b162_c4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b2052_c1)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2052_c1 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2052_c1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b2383_c1)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383_c1 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383_c1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b2383)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b2383 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b2383 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b300_c1)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b300_c1 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b300_c1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b300_c2)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b300_c2 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b300_c2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b300_c3)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b300_c3 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b300_c3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b39_c19)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b39_c19 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b39_c19 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b39_c30)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b39_c30 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b39_c30 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b39_c7)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b39_c7 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b39_c7 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b678_c1)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b678_c1 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b678_c1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b678_c2)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b678_c2 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b678_c2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TSOPF_RS_b9_c6)
{
    std::string input_file(MATRIX_FULL_PATH(TSOPF_RS_b9_c6 ));
    std::string output_file(RESULT_FULL_PATH(TSOPF_RS_b9_c6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, TS)
{
    std::string input_file(MATRIX_FULL_PATH(TS ));
    std::string output_file(RESULT_FULL_PATH(TS ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tsyl201)
{
    std::string input_file(MATRIX_FULL_PATH(tsyl201 ));
    std::string output_file(RESULT_FULL_PATH(tsyl201 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tub1000)
{
    std::string input_file(MATRIX_FULL_PATH(tub1000 ));
    std::string output_file(RESULT_FULL_PATH(tub1000 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tube1)
{
    std::string input_file(MATRIX_FULL_PATH(tube1 ));
    std::string output_file(RESULT_FULL_PATH(tube1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tube2)
{
    std::string input_file(MATRIX_FULL_PATH(tube2 ));
    std::string output_file(RESULT_FULL_PATH(tube2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tuma1)
{
    std::string input_file(MATRIX_FULL_PATH(tuma1 ));
    std::string output_file(RESULT_FULL_PATH(tuma1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, tuma2)
{
    std::string input_file(MATRIX_FULL_PATH(tuma2 ));
    std::string output_file(RESULT_FULL_PATH(tuma2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, turon_m)
{
    std::string input_file(MATRIX_FULL_PATH(turon_m ));
    std::string output_file(RESULT_FULL_PATH(turon_m ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, twotone)
{
    std::string input_file(MATRIX_FULL_PATH(twotone ));
    std::string output_file(RESULT_FULL_PATH(twotone ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ukerbe1_dual)
{
    std::string input_file(MATRIX_FULL_PATH(ukerbe1_dual ));
    std::string output_file(RESULT_FULL_PATH(ukerbe1_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ukerbe1)
{
    std::string input_file(MATRIX_FULL_PATH(ukerbe1 ));
    std::string output_file(RESULT_FULL_PATH(ukerbe1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, uk)
{
    std::string input_file(MATRIX_FULL_PATH(uk ));
    std::string output_file(RESULT_FULL_PATH(uk ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, USAir97)
{
    std::string input_file(MATRIX_FULL_PATH(USAir97 ));
    std::string output_file(RESULT_FULL_PATH(USAir97 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, USpowerGrid)
{
    std::string input_file(MATRIX_FULL_PATH(USpowerGrid ));
    std::string output_file(RESULT_FULL_PATH(USpowerGrid ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, usroads_48)
{
    std::string input_file(MATRIX_FULL_PATH(usroads-48 ));
    std::string output_file(RESULT_FULL_PATH(usroads-48 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, usroads)
{
    std::string input_file(MATRIX_FULL_PATH(usroads ));
    std::string output_file(RESULT_FULL_PATH(usroads ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, utm1700b)
{
    std::string input_file(MATRIX_FULL_PATH(utm1700b ));
    std::string output_file(RESULT_FULL_PATH(utm1700b ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, utm300)
{
    std::string input_file(MATRIX_FULL_PATH(utm300 ));
    std::string output_file(RESULT_FULL_PATH(utm300 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, utm3060)
{
    std::string input_file(MATRIX_FULL_PATH(utm3060 ));
    std::string output_file(RESULT_FULL_PATH(utm3060 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, utm5940)
{
    std::string input_file(MATRIX_FULL_PATH(utm5940 ));
    std::string output_file(RESULT_FULL_PATH(utm5940 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, vanbody)
{
    std::string input_file(MATRIX_FULL_PATH(vanbody ));
    std::string output_file(RESULT_FULL_PATH(vanbody ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, venkat01)
{
    std::string input_file(MATRIX_FULL_PATH(venkat01 ));
    std::string output_file(RESULT_FULL_PATH(venkat01 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, venkat25)
{
    std::string input_file(MATRIX_FULL_PATH(venkat25 ));
    std::string output_file(RESULT_FULL_PATH(venkat25 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, venkat50)
{
    std::string input_file(MATRIX_FULL_PATH(venkat50 ));
    std::string output_file(RESULT_FULL_PATH(venkat50 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, vfem)
{
    std::string input_file(MATRIX_FULL_PATH(vfem ));
    std::string output_file(RESULT_FULL_PATH(vfem ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, vibrobox)
{
    std::string input_file(MATRIX_FULL_PATH(vibrobox ));
    std::string output_file(RESULT_FULL_PATH(vibrobox ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, viscoplastic1)
{
    std::string input_file(MATRIX_FULL_PATH(viscoplastic1 ));
    std::string output_file(RESULT_FULL_PATH(viscoplastic1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, viscoplastic2)
{
    std::string input_file(MATRIX_FULL_PATH(viscoplastic2 ));
    std::string output_file(RESULT_FULL_PATH(viscoplastic2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, viscorocks)
{
    std::string input_file(MATRIX_FULL_PATH(viscorocks ));
    std::string output_file(RESULT_FULL_PATH(viscorocks ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wang1)
{
    std::string input_file(MATRIX_FULL_PATH(wang1 ));
    std::string output_file(RESULT_FULL_PATH(wang1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wang2)
{
    std::string input_file(MATRIX_FULL_PATH(wang2 ));
    std::string output_file(RESULT_FULL_PATH(wang2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wang3)
{
    std::string input_file(MATRIX_FULL_PATH(wang3 ));
    std::string output_file(RESULT_FULL_PATH(wang3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wang4)
{
    std::string input_file(MATRIX_FULL_PATH(wang4 ));
    std::string output_file(RESULT_FULL_PATH(wang4 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, water_tank)
{
    std::string input_file(MATRIX_FULL_PATH(water_tank ));
    std::string output_file(RESULT_FULL_PATH(water_tank ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wathen100)
{
    std::string input_file(MATRIX_FULL_PATH(wathen100 ));
    std::string output_file(RESULT_FULL_PATH(wathen100 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wathen120)
{
    std::string input_file(MATRIX_FULL_PATH(wathen120 ));
    std::string output_file(RESULT_FULL_PATH(wathen120 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, watt_1)
{
    std::string input_file(MATRIX_FULL_PATH(watt_1 ));
    std::string output_file(RESULT_FULL_PATH(watt_1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, watt_2)
{
    std::string input_file(MATRIX_FULL_PATH(watt_2 ));
    std::string output_file(RESULT_FULL_PATH(watt_2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, waveguide3D)
{
    std::string input_file(MATRIX_FULL_PATH(waveguide3D ));
    std::string output_file(RESULT_FULL_PATH(waveguide3D ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wave)
{
    std::string input_file(MATRIX_FULL_PATH(wave ));
    std::string output_file(RESULT_FULL_PATH(wave ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wb_cs_stanford)
{
    std::string input_file(MATRIX_FULL_PATH(wb-cs-stanford ));
    std::string output_file(RESULT_FULL_PATH(wb-cs-stanford ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, web_NotreDame)
{
    std::string input_file(MATRIX_FULL_PATH(web-NotreDame ));
    std::string output_file(RESULT_FULL_PATH(web-NotreDame ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, web_Stanford)
{
    std::string input_file(MATRIX_FULL_PATH(web-Stanford ));
    std::string output_file(RESULT_FULL_PATH(web-Stanford ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, west0381)
{
    std::string input_file(MATRIX_FULL_PATH(west0381 ));
    std::string output_file(RESULT_FULL_PATH(west0381 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, west0479)
{
    std::string input_file(MATRIX_FULL_PATH(west0479 ));
    std::string output_file(RESULT_FULL_PATH(west0479 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, west0497)
{
    std::string input_file(MATRIX_FULL_PATH(west0497 ));
    std::string output_file(RESULT_FULL_PATH(west0497 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, west0655)
{
    std::string input_file(MATRIX_FULL_PATH(west0655 ));
    std::string output_file(RESULT_FULL_PATH(west0655 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, west0989)
{
    std::string input_file(MATRIX_FULL_PATH(west0989 ));
    std::string output_file(RESULT_FULL_PATH(west0989 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, west1505)
{
    std::string input_file(MATRIX_FULL_PATH(west1505 ));
    std::string output_file(RESULT_FULL_PATH(west1505 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, west2021)
{
    std::string input_file(MATRIX_FULL_PATH(west2021 ));
    std::string output_file(RESULT_FULL_PATH(west2021 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, whitaker3_dual)
{
    std::string input_file(MATRIX_FULL_PATH(whitaker3_dual ));
    std::string output_file(RESULT_FULL_PATH(whitaker3_dual ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, whitaker3)
{
    std::string input_file(MATRIX_FULL_PATH(whitaker3 ));
    std::string output_file(RESULT_FULL_PATH(whitaker3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wiki_Vote)
{
    std::string input_file(MATRIX_FULL_PATH(wiki-Vote ));
    std::string output_file(RESULT_FULL_PATH(wiki-Vote ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, windscreen)
{
    std::string input_file(MATRIX_FULL_PATH(windscreen ));
    std::string output_file(RESULT_FULL_PATH(windscreen ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wing_nodal)
{
    std::string input_file(MATRIX_FULL_PATH(wing_nodal ));
    std::string output_file(RESULT_FULL_PATH(wing_nodal ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, wing)
{
    std::string input_file(MATRIX_FULL_PATH(wing ));
    std::string output_file(RESULT_FULL_PATH(wing ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Wordnet3)
{
    std::string input_file(MATRIX_FULL_PATH(Wordnet3 ));
    std::string output_file(RESULT_FULL_PATH(Wordnet3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, ww_vref_6405)
{
    std::string input_file(MATRIX_FULL_PATH(ww_vref_6405 ));
    std::string output_file(RESULT_FULL_PATH(ww_vref_6405 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, x104)
{
    std::string input_file(MATRIX_FULL_PATH(x104 ));
    std::string output_file(RESULT_FULL_PATH(x104 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, xenon1)
{
    std::string input_file(MATRIX_FULL_PATH(xenon1 ));
    std::string output_file(RESULT_FULL_PATH(xenon1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, xenon2)
{
    std::string input_file(MATRIX_FULL_PATH(xenon2 ));
    std::string output_file(RESULT_FULL_PATH(xenon2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, xingo3012)
{
    std::string input_file(MATRIX_FULL_PATH(xingo3012 ));
    std::string output_file(RESULT_FULL_PATH(xingo3012 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, xingo_afonso_itaipu)
{
    std::string input_file(MATRIX_FULL_PATH(xingo_afonso_itaipu ));
    std::string output_file(RESULT_FULL_PATH(xingo_afonso_itaipu ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, yeast)
{
    std::string input_file(MATRIX_FULL_PATH(yeast ));
    std::string output_file(RESULT_FULL_PATH(yeast ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, young1c)
{
    std::string input_file(MATRIX_FULL_PATH(young1c ));
    std::string output_file(RESULT_FULL_PATH(young1c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, young2c)
{
    std::string input_file(MATRIX_FULL_PATH(young2c ));
    std::string output_file(RESULT_FULL_PATH(young2c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, young3c)
{
    std::string input_file(MATRIX_FULL_PATH(young3c ));
    std::string output_file(RESULT_FULL_PATH(young3c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, young4c)
{
    std::string input_file(MATRIX_FULL_PATH(young4c ));
    std::string output_file(RESULT_FULL_PATH(young4c ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zd_Jac2_db)
{
    std::string input_file(MATRIX_FULL_PATH(Zd_Jac2_db ));
    std::string output_file(RESULT_FULL_PATH(Zd_Jac2_db ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zd_Jac2)
{
    std::string input_file(MATRIX_FULL_PATH(Zd_Jac2 ));
    std::string output_file(RESULT_FULL_PATH(Zd_Jac2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zd_Jac3_db)
{
    std::string input_file(MATRIX_FULL_PATH(Zd_Jac3_db ));
    std::string output_file(RESULT_FULL_PATH(Zd_Jac3_db ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zd_Jac3)
{
    std::string input_file(MATRIX_FULL_PATH(Zd_Jac3 ));
    std::string output_file(RESULT_FULL_PATH(Zd_Jac3 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zd_Jac6_db)
{
    std::string input_file(MATRIX_FULL_PATH(Zd_Jac6_db ));
    std::string output_file(RESULT_FULL_PATH(Zd_Jac6_db ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zd_Jac6)
{
    std::string input_file(MATRIX_FULL_PATH(Zd_Jac6 ));
    std::string output_file(RESULT_FULL_PATH(Zd_Jac6 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, zenios)
{
    std::string input_file(MATRIX_FULL_PATH(zenios ));
    std::string output_file(RESULT_FULL_PATH(zenios ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, zeros_nopss_13k)
{
    std::string input_file(MATRIX_FULL_PATH(zeros_nopss_13k ));
    std::string output_file(RESULT_FULL_PATH(zeros_nopss_13k ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zewail)
{
    std::string input_file(MATRIX_FULL_PATH(Zewail ));
    std::string output_file(RESULT_FULL_PATH(Zewail ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zhao1)
{
    std::string input_file(MATRIX_FULL_PATH(Zhao1 ));
    std::string output_file(RESULT_FULL_PATH(Zhao1 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}

TEST(cuda_test_spmv_LBNEC_FP64, Zhao2)
{
    std::string input_file(MATRIX_FULL_PATH(Zhao2 ));
    std::string output_file(RESULT_FULL_PATH(Zhao2 ));
    test_SpMV_accu_perf_FP64<perfSpB_SpMV_LBNEC_FP64>(input_file, output_file, false);
}