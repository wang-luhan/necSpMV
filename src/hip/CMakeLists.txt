cmake_minimum_required(VERSION 3.5)
project(PerfSparse_hip)

set(the_description "HIP")
# 设置HIP源文件路径
set(HIP_SOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 使用file命令获取HIP源文件列表
file(GLOB hip_sources "${HIP_SOURCES_PATH}/**/*.cpp")

# 设置utilities路径
set(UTILITIES_PATH ${PROJECT_SOURCE_DIR}/../../utilities) 
list(APPEND hip_sources "${UTILITIES_PATH}/util.cpp")

# find_package(HIP REQUIRED)
# find_package(rocPRIM REQUIRED)

# set(hsa-runtime64_ROOT /opt/rocm/hsa)
# set(hsa-runtime64_LIB_PATH /opt/rocm/hsa/lib)
# find_package(hsa-runtime64 REQUIRED)

# set(HIP_ROOT_DIR /opt/rocm/hip)
# find_package(HIP REQUIRED PATHS ${HIP_ROOT_DIR})

# set(rocPRIM_ROOT_DIR /opt/rocm/rocprim)
# find_package(rocPRIM REQUIRED PATHS ${rocPRIM_ROOT_DIR})

set(GTEST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../tool/gtest")
set(GTEST_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../tool/gtest/lib64")
find_package(GTest REQUIRED)

# Ensure HIP is used to compile HIP sources
# if(HIP_FOUND)
    # set(CMAKE_CXX_COMPILER ${HIP_HIPCC_EXECUTABLE})
    set(CMAKE_CXX_COMPILER "/public/software/compiler/rocm/dtk-23.10.1/hip/bin/hipcc")
# endif()

if(GTEST_FOUND)
message(STATUS "GTest found !!!!!!")
endif()

# 创建一个HIP库
add_library(PerfSparse_hip ${hip_sources})

target_include_directories(PerfSparse_hip
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../core/include
        ${PROJECT_SOURCE_DIR}/include
)

set_target_properties(PerfSparse_hip PROPERTIES LINKER_LANGUAGE CXX)

# 设置HIP测试文件路径
set(HIP_TEST_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test)

# 使用file命令获取HIP测试文件列表
file(GLOB HIP_TEST_FILES "${HIP_TEST_PATH}/**/*.cpp" "${HIP_TEST_PATH}/**/*.hpp")

# 添加HIP测试的可执行文件
add_executable(PerfSparse_test_hip ${HIP_TEST_FILES})

target_include_directories(PerfSparse_test_hip
    PUBLIC
        ${PROJECT_SOURCE_DIR}/../core/include
        ${PROJECT_SOURCE_DIR}/include  # 确保这个路径是正确的
        ${PROJECT_SOURCE_DIR}/../../utilities/
        ${CMAKE_CURRENT_SOURCE_DIR}/../../tool/gtest/include/
        /opt/rocm/rocsparse/include/
        /opt/rocm/hipsparse/include/
        /public/software/compiler/rocm/dtk-23.10.1/hipsparse
        /public/software/compiler/rocm/dtk-23.10.1/hip/lib
        /public/software/compiler/rocm/dtk-23.10.1/hip/include
        /public/software/compiler/rocm/dtk-23.10.1/rocthrust/include
)

# PerfSparse_test_hip链接测试需要的库
link_directories(/opt/rocm/lib/ /opt/rocm/hsa/lib /opt/rocm/lib64/)

find_library(rocSPARSE_LIBRARY rocsparse PATHS /opt/rocm/rocsparse/lib /opt/rocm/lib /opt/rocm/lib64 NO_DEFAULT_PATH)
find_library(hipSPARSE_LIBRARY hipsparse PATHS /opt/rocm/hipsparse/lib /opt/rocm/lib /opt/rocm/lib64 NO_DEFAULT_PATH)
# 检查是否找到rocsparse库
if(NOT rocSPARSE_LIBRARY)
    message(FATAL_ERROR "rocSPARSE library not found.")
endif()




# find_library(HSA_LIBRARY libhsa-runtime64.so PATHS /opt/rocm/lib/)
# find_library(AMD_COMGR_LIBRARY libamd_comgr.so PATHS /opt/rocm/lib)
# if(NOT HSA_LIBRARY)
#     message(FATAL_ERROR "HSA runtime library not found. Please check your installation.")
# endif()

# if(NOT AMD_COMGR_LIBRARY)
#     message(FATAL_ERROR "AMD runtime library not found. Please check your installation.")
# endif()
find_library(HSA_RUNTIME hsa-runtime64 PATHS /public/software/compiler/rocm/dtk-23.10.1/hsa/lib)

target_link_libraries(PerfSparse_test_hip PerfSparse_hip PerfSparse_core 
                    ${GTEST_LIB_PATH}/libgtest.so  
                    ${GTEST_LIB_PATH}/libgtest_main.so 
                    ${hipSPARSE_LIBRARY} 
                    ${rocSPARSE_LIBRARY} 
                    # ${HSA_LIBRARY}
                    # /opt/rocm/hsa/lib/libhsa-runtime64.so.1
                    # /opt/rocm/lib64/libhsakmt.so.1
                    /opt/rocm/lib64/libhsakmt.so
                    ${HSA_RUNTIME}
                    /opt/rocm/lib/libhsa-runtime64.so
                    # ${AMD_COMGR_LIBRARY}
                    /opt/rocm/lib/libamd_comgr.so
                    /public/software/compiler/rocm/dtk-23.10.1/rocsparse/lib/librocsparse.so 
                    /public/software/compiler/rocm/dtk-23.10.1/hip/lib/libgalaxyhip.so.5 
                    /public/software/compiler/rocm/dtk-23.10.1/hipsparse/lib/libhipsparse.so
                    )



message(STATUS "Project source directory: ${PROJECT_SOURCE_DIR}")
message(STATUS "Gtest lib directory: ${GTEST_LIB_PATH}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR lib directory: ${CMAKE_CURRENT_SOURCE_DIR}")

