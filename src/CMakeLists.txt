if(NOT PerfSparse_MODULES_PATH)
    set(PerfSparse_MODULES_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
endif(NOT PerfSparse_MODULES_PATH)

message("-- PerfSparse_MODULES_PATH : ${PerfSparse_MODULES_PATH}")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR})

PerfSparse_glob_modules(${PerfSparse_MODULES_PATH})
if(BUILD_WITH_CUDA)
    include_directories(${CUDA_INCLUDE_DIRS})
endif()