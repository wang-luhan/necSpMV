cmake_minimum_required(VERSION 3.5)

project(PerfSparse CXX C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CPP_STANDARD 11)

# ----------------------------------------------------------------------------
# inclue required cmake files:
# ----------------------------------------------------------------------------
include(cmake/PerfSparseUtil.cmake)
include(cmake/PerfSparseModule.cmake)

string(TIMESTAMP BUILDDATE "%Y.%m.%d")
set(PerfSparse_VERSION_MAJOR 1)       # Add a feature or a new library. For example, increase the value of this parameter when adding the OMP.
set(PerfSparse_VERSION_MINOR 0)       # Increases when an interface is added.
set(PerfSparse_VERSION_PATCH 0)       # Increases when bugs are fixed
set(PerfSparse_VERSION_BUILDDATE \"${BUILDDATE}\")  # Last build time
set(PerfSparse_LIBVERSION "${PerfSparse_VERSION_MAJOR}.${PerfSparse_VERSION_MINOR}.${PerfSparse_VERSION_PATCH}")

# 打印编译选项
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ----------------------------------------------------------------------------
# config the output path of the library:
# ----------------------------------------------------------------------------

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" CACHE PATH "Output directory for application")
set(LIBRARY_OUTPUT_PATH    "${CMAKE_BINARY_DIR}/lib")

message("-- The output path of lib file is        ${LIBRARY_OUTPUT_PATH}")
message("-- The output path of executable file is ${EXECUTABLE_OUTPUT_PATH}")

# ----------------------------------------------------------------------------
# PerfSparse cmake options
# ----------------------------------------------------------------------------
PerfSparse_OPTION(BUILD_SHARED_LIBS      "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)"  ON)
PerfSparse_OPTION(BUILD_TESTS            "Build accuracy & regression tests"                                   ON)
PerfSparse_OPTION(BUILD_PERF_TESTS       "Build performance tests"                                             ON)
PerfSparse_OPTION(BUILD_WITH_OMP         "Build with OpenMP"                                                   ON)
PerfSparse_OPTION(BUILD_WITH_CUDA        "Build with CUDA"                                                     ON)
PerfSparse_OPTION(BUILD_ON_ARM           "Build on arm platform"                                               OFF)
PerfSparse_OPTION(BUILD_ON_X86           "Build on x86 platform"                                               ON)
PerfSparse_OPTION(BUILD_WITH_DEBUG_INFO  "Build with debug information"                                        ON)
PerfSparse_OPTION(BUILD_WITH_MEMORY_CHCKE "Build with -fsanitize=address"                                      OFF)

# GNU Scientific Library 支持
find_package(GSL REQUIRED)

if(BUILD_WITH_MEMORY_CHCKE)
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
endif()

if(BUILD_WITH_OMP)
    find_package(OpenMP)
	set (OpenMP_C_FLAGS "${OpenMP_C_FLAGS} -DWITH_OMP")
else()
    set (OpenMP_C_FLAGS "")
endif()

# if(BUILD_WITH_CUDA)
#     find_package (CUDA REQUIRED)
#     set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-gencode arch=compute_70,code=sm_70)
#     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CUDA_NVCC_FLAGS} -DWITH_CUDA=1")
# else()
#     set (CUDA_C_FLAGS "")
# endif()
if(BUILD_WITH_CUDA)
    find_package(CUDA REQUIRED)
    include_directories(${CUDA_INCLUDE_DIRS})
    set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-gencode arch=compute_70,code=sm_70)
endif()

if(BUILD_ON_ARM)
    set(PerfSparse_USE_NEON "-DARM_NEON")
else()
    set(PerfSparse_USE_NEON "")
endif()

if(BUILD_ON_X86)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DX86_SIMD -mavx -march=skylake-avx512 -mtune=skylake-avx512")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${PerfSparse_WITH_OMP} ${PerfSparse_USE_NEON}")

find_package(GTest)
# find_package(jemalloc REQUIRED)
find_package(PkgConfig REQUIRED)
# pkg_check_modules (JEMALLOC jemalloc)
# pkg_search_module(JEMALLOC REQUIRED jemalloc)

set(MAIN_PATH ${PROJECT_SOURCE_DIR})
configure_file(utilities/env.h.in ${PROJECT_SOURCE_DIR}/utilities/env.h)

#---------------------------------------------------------------------
# config build original makefile project
#--------------------------------------------------------------------------

#---------------------------------------------------------------------
# config linker libs
#--------------------------------------------------------------------------
SET(INTEL_ITT_PATH "/opt/intel/oneapi/vtune/latest/")
find_library(ITT_LIB ittnotify ${INTEL_ITT_PATH}sdk/lib64 NO_DEFAULT_PATH)

if( ITT_LIB AND (CMAKE_C_COMPILER_ID STREQUAL "Intel") AND (CMAKE_CXX_COMPILER_ID STREQUAL "Intel"))
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_INTEL_ITT -diag-disable=10441 ")
    SET(PerfSparse_TEST_INCLUDE_DIRECTORIES ${INTEL_ITT_PATH}/sdk/include)
    SET(PerfSparse_LINKER_TEST_LIBS ${ITT_LIB})
    include_directories(${INTEL_ITT_PATH}/sdk/include)
    message("-- Building with Intel Instrumentation and Tracing Technology")
else()
    set(ITT_LIB "")
    message("-- Building without Intel Instrumentation and Tracing Technology")
endif()
#---------------------------------------------------------------------
# config build option
#--------------------------------------------------------------------------
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS} ${CUDA_C_FLAGS} -Wall -O0")
	message("-- Building type: Debug")
else(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS} ${CUDA_C_FLAGS} -Wall")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND BUILD_ON_ARM)
        if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8.5" OR CMAKE_CXX_COMPILER_VERSION VERSION_EQUAL "4.8.5")
	        message("-- Insufficient gcc version:${CMAKE_CXX_COMPILER_VERSION}")
	        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv8-a+crc+crypto+fp+simd -mtune=cortex-a53 -std=c11")
        else()
	        message("-- Insufficient gcc version:${CMAKE_CXX_COMPILER_VERSION}")
	        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv8.2-a+crc+crypto+fp16+simd -mtune=cortex-a72")
        endif()
    endif()
	message("-- Building type: Release")

    if(BUILD_WITH_DEBUG_INFO)
        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -rdynamic")
        message("-- Building with debug information")
    else()
        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s")
    endif()
endif()

set (CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")
set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
message("-- C_FLAGS:   ${CMAKE_C_FLAGS}")
message("-- CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

# ----------------------------------------------------------------------------
# add_modules
# ----------------------------------------------------------------------------
if(BUILD_SHARED_LIBS)
    SET(PerfSparse_MODULE_TYPE SHARED)
else()
    SET(PerfSparse_MODULE_TYPE STATIC)
endif()

ADD_SUBDIRECTORY(src)

#show PerfSparse modules information
string(REPLACE "PerfSparse_" "" PerfSparse_MODULES_BUILD_ST          "${PerfSparse_MODULES_BUILD}")
string(REPLACE "PerfSparse_" "" PerfSparse_MODULES_DISABLED_USER_ST  "${PerfSparse_MODULES_DISABLED_USER}")
string(REPLACE "PerfSparse_" "" PerfSparse_MODULES_DISABLED_FORCE_ST "${pORTOCL_MODULES_DISABLED_FORCE}")

set(PerfSparse_MODULES_DISABLED_AUTO_ST "")
foreach(m ${PerfSparse_MODULES_DISABLED_AUTO})
    set(__mdeps "")
    foreach(d ${PerfSparse_MODULE_${m}_DEPS})
        if(d MATCHES "^PerfSparse_" AND NOT HAVE_${d})
            list(APPEND __mdeps ${d})
        endif()
    endforeach()
    if(__mdeps)
        list(APPEND PerfSparse_MODULES_DISABLED_AUTO_ST "${m}(deps: ${__mdeps})")
    else()
        list(APPEND PerfSparse_MODULES_DISABLED_AUTO_ST "${m}")
    endif()
endforeach()

string(REPLACE "PerfSparse_" "" PerfSparse_MODULES_DISABLED_AUTO_ST  "${PerfSparse_MODULES_DISABLED_AUTO_ST}")

message("===================The modules build information as follwos:")
message("    Public modules:         ${PerfSparse_MODULES_PUBLIC}"        )
message("    To be built:            ${PerfSparse_MODULES_BUILD}"         )


add_custom_command(OUTPUT libperfsparseblas.a
COMMAND rm -f ./lib/libperfsparseblas.a
COMMAND ar crsT ./lib/libperfsparseblas.a $<TARGET_FILE:PerfSparse_core> $<TARGET_FILE:PerfSparse_cpu> $<TARGET_FILE:PerfSparse_cuda>
DEPENDS PerfSparse_core PerfSparse_cpu PerfSparse_cuda)
add_custom_target(merge_PerfSpB_core_and_PerfSpB_cpu ALL DEPENDS libperfsparseblas.a)

add_custom_command(OUTPUT libperfsparseblas.so
COMMAND rm -f ./lib/libperfsparseblas.so
COMMAND ld -shared -o ./lib/libperfsparseblas.so $<TARGET_FILE:PerfSparse_core> $<TARGET_FILE:PerfSparse_cpu> $<TARGET_FILE:PerfSparse_cuda>
DEPENDS PerfSparse_core PerfSparse_cpu PerfSparse_cuda)


add_custom_target(merge_PerfSpB_core_and_PerfSpB_cpu_so ALL DEPENDS libperfsparseblas.so PerfSparse_cuda)

add_custom_target (
    run
    @echo "[make] testing..." &
    ./bin/PerfSparse_test_core &
    ./bin/PerfSparse_test_matrix &
    ./bin/PerfSparse_test_algorithm
    )


