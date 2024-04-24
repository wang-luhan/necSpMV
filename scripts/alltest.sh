#!/bin/bash

# # Define the path to the directory containing FP32 and FP64
# BUILD_DIR="../build"
# OUTPUT_DIR="./xlsx"



../build/./bin/PerfSparse_test_cuda --gtest_filter=test_perf_cusparse_spmv_csr_FP32.* | tee FP32/cuSPARSE_FP32.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=test_perf_cusparse_spmv_csr_FP64.* | tee FP64/cuSPARSE_FP64.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_LBNEC_FP32.* | tee FP32/LBNEC_FP32.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_LBNEC_FP64.* | tee FP64/LBNEC_FP64.log


../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_ADP_FP64_COMMON.* | tee FP64/common_adp_fp64.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_LIGHT_FP64_COMMON.* | tee FP64/common_light_fp64.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_FP64_COMMON.* | tee FP64/common_cusp_fp64.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_FLAT_FP64_COMMON.* | tee FP64/common_flat_fp64.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_PCSR_FP64_COMMON.* | tee FP64/common_pcsr_fp64.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_LBNEC_FP64_COMMON.* | tee FP64/common_lbnec_fp64.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=test_perf_cusparse_spmv_csr_FP64_COMMON.* | tee FP64/common_cusparse_fp64.log

../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_ADP_FP32_COMMON.* | tee FP32/common_adp_fp32.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_LIGHT_FP32_COMMON.* | tee FP32/common_light_fp32.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_FP32_COMMON.* | tee FP32/common_cusp_fp32.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_FLAT_FP32_COMMON.* | tee FP32/common_flat_fp32.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_PCSR_FP32_COMMON.* | tee FP32/common_pcsr_fp32.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=cuda_test_spmv_LBNEC_FP32_COMMON.* | tee FP32/common_lbnec_fp32.log
../build/./bin/PerfSparse_test_cuda --gtest_filter=test_perf_cusparse_spmv_csr_FP32_COMMON.* | tee FP32/common_cusparse_fp32.log



# # Create the output directory if it does not exist
# mkdir -p "$OUTPUT_DIR"

# # Function to convert log files in a given directory to xlsx format
# convert_logs_to_xlsx () {
#     local log_type_dir=$1  # This is the subdirectory, either FP32 or FP64
#     echo "Processing log files in $BUILD_DIR/$log_type_dir..."

#     # Navigate to the directory containing the log files
#     local log_dir="$BUILD_DIR/$log_type_dir"
#     cd "$log_dir" || exit

#     # Loop through all .log files in the directory
#     for log_file in *.log; do
#         if [ -f "$log_file" ]; then  # Check if the file exists and is a regular file
#             local base_name="${log_file%.*}"
#             local xlsx_file="$OUTPUT_DIR/$base_name.xlsx"

#             # Perform the conversion from log to xlsx
#             echo "Converting $log_file to $xlsx_file..."
#             python "../../scripts/parse_tests.py" "$log_file" "$xlsx_file"
#         else
#             echo "No log files found in $log_dir"
#         fi
#     done

#     # Navigate back to the original directory
#     cd - > /dev/null
# }

# # Convert log files in both the FP32 and FP64 subdirectories
# convert_logs_to_xlsx "FP32"
# convert_logs_to_xlsx "FP64"

# echo "Conversion complete."