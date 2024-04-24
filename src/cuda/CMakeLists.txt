set(the_description "cuda")  
# 设置CUDA源文件路径
set(CUDA_SOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src) 

# 使用file命令获取CUDA源文件列表
file(GLOB cuda_sources "${CUDA_SOURCES_PATH}/**/*.cu")
# set(cuda_sources
#     ${CUDA_SOURCES_PATH}/spmv/spmv_adaptive.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_nonempty_column.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_pcsr.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_light.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_pcsr_warp.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_line_enhance.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_mergepath.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_LBNEC.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_exp.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_acsr.cu
#     ${CUDA_SOURCES_PATH}/spmv/spmv_vnec.cu
# )

include_directories(
    ${PROJECT_SOURCE_DIR}/src/core/include
    ${PROJECT_SOURCE_DIR}/src/cuda/include
    ${PROJECT_SOURCE_DIR}/utilities
)

# 设置utilities路径
set(UTILITIES_PATH ${PROJECT_SOURCE_DIR}/utilities) 
list(APPEND cuda_sources "${UTILITIES_PATH}/util.cpp")


find_package(CUDA REQUIRED)
find_package(GTest)

# 创建一个CUDA库
cuda_add_library(PerfSparse_cuda ${cuda_sources})

# 设置CUDA测试文件路径
set(CUDA_TEST_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test)

# set(CUDA_TEST_FILES
#   ${CUDA_TEST_PATH}/test_spmv_cuda.cpp
# )
# 使用file命令获取CUDA测试文件列表
file(GLOB CUDA_TEST_FILES "${CUDA_TEST_PATH}/**/*.cpp" "${CUDA_TEST_PATH}/**/*.hpp")
# set(CUDA_TEST_FILES
#     ${CUDA_TEST_PATH}/spmv/test_spmv_cuda.cpp
#     ${CUDA_TEST_PATH}/spmv/test_spmv_cuda.hpp
#     ${CUDA_TEST_PATH}/spmv/lbnec.hpp
#     ${CUDA_TEST_PATH}/cusparse/test_cusparse_spmv_csr.cpp
# )

# 添加CUDA测试的可执行文件
cuda_add_executable(PerfSparse_test_cuda ${CUDA_TEST_FILES})

# PerfSparse_test_cuda链接测试需要的库
target_link_libraries(PerfSparse_test_cuda PerfSparse_cuda PerfSparse_core PerfSparse_cpu gtest gtest_main)



# 查找CUSPARSE库
find_library(CUSPARSE_LIBRARY NAMES libcusparse.so PATHS "${CUDA_TOOLKIT_ROOT_DIR}/targets/x86_64-linux/lib")

# 检查是否找到CUSPARSE库
if(NOT CUSPARSE_LIBRARY)
    message(FATAL_ERROR "CUSPARSE_LIBRARY not found. Please set it manually.")
endif()

# 链接CUSPARSE库
target_link_libraries(PerfSparse_test_cuda ${CUSPARSE_LIBRARY})

# set_source_files_properties(${CUDA_SOURCES_PATH} PROPERTIES LANGUAGE C)