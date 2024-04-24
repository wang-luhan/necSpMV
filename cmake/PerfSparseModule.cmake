# clean modules info which needs to be recalculated
set(PerfSparse_MODULES_PUBLIC         "" CACHE INTERNAL "List of PerfSparse modules marked for export")
set(PerfSparse_MODULES_BUILD          "" CACHE INTERNAL "List of PerfSparse modules included into the build")
set(PerfSparse_MODULES_DISABLED_USER  "" CACHE INTERNAL "List of PerfSparse modules explicitly disabled by user")
set(PerfSparse_MODULES_DISABLED_AUTO  "" CACHE INTERNAL "List of PerfSparse modules implicitly disabled due to dependencies")
set(PerfSparse_MODULES_DISABLED_FORCE "" CACHE INTERNAL "List of PerfSparse modules which can not be build in current configuration")

# adds dependencies to PerfSparse module
# Usage:
#   add_dependencies(PerfSparse_<name> [REQUIRED] [<list of dependencies>] [OPTIONAL <list of modules>])
# Notes:
# * <list of dependencies> - can include full names of modules or full pathes to shared/static libraries or cmake targets

macro(PerfSparse_add_dependencies full_modname)
    #we don't clean the dependencies here to allow this macro several times for every module
    foreach(d "REQUIRED" ${ARGN})
        if(d STREQUAL "REQUIRED")
            set(__depsvar PerfSparse_MODULE_${full_modname}_REQ_DEPS)
        elseif(d STREQUAL "OPTIONAL")
            set(__depsvar PerfSparse_MODULE_${full_modname}_OPT_DEPS)
        else()
            list(APPEND ${__depsvar} "PerfSparse_${d}")
        endif()
    endforeach()
    unset(__depsvar)

    PerfSparse_list_unique(PerfSparse_MODULE_${full_modname}_REQ_DEPS)
    PerfSparse_list_unique(PerfSparse_MODULE_${full_modname}_OPT_DEPS)

    set(PerfSparse_MODULE_${full_modname}_REQ_DEPS ${PerfSparse_MODULE_${full_modname}_REQ_DEPS} CACHE INTERNAL "Required dependencies of ${full_modname} module")
    set(PerfSparse_MODULE_${full_modname}_OPT_DEPS ${PerfSparse_MODULE_${full_modname}_OPT_DEPS} CACHE INTERNAL "Optional dependencies of ${full_modname} module")

endmacro()

# declare new PerfSparse module in current folder
# Usage:
#   PerfSparse_add_module(<name> [INTERNAL|BINDINGS] [REQUIRED] [<list of dependencies>] [OPTIONAL <list of optional dependencies>])
# Example:
#   PerfSparse_add_module(yaom INTERNAL PerfSparse_core PerfSparse_highgui PerfSparse_flann OPTIONAL PerfSparse_gpu)
macro(PerfSparse_add_module _name)
    string(TOLOWER "${_name}" name)
    set(the_module     PerfSparse_${name})
    set(the_module_res ${name})

    # the first pass - collect modules info, the second pass - create targets
    if(PerfSparse_INITIAL_PASS)
        #guard agains redefinition
        if(";${PerfSparse_MODULES_BUILD};${PerfSparse_MODULES_DISABLED_USER};" MATCHES ";${the_module};")
            message(FATAL_ERROR "Redefinition of the ${the_module} module.
            at:                    ${CMAKE_CURRENT_SOURCE_DIR}
            previously defined at: ${PerfSparse_MODULE_${the_module}_LOCATION}
            ")
        endif()

        if(NOT DEFINED the_description)
            set(the_description "The ${name} PerfSparse module")
        endif()

        if(NOT DEFINED BUILD_${the_module}_INIT)
            set(BUILD_${the_module}_INIT ON)
        endif()


        # create option to enable/disable this module
        option(BUILD_${the_module} "Include ${the_module} module into the PerfSparse build" ${BUILD_${the_module}_INIT})

        # remember the module details
        set(PerfSparse_MODULE_${the_module}_DESCRIPTION "${the_description}"          CACHE INTERNAL "Brief description of ${the_module} module")
        set(PerfSparse_MODULE_${the_module}_LOCATION    "${CMAKE_CURRENT_SOURCE_DIR}" CACHE INTERNAL "Location of ${the_module} module sources")

        # parse list of dependencies
        if("${ARGV1}" STREQUAL "INTERNAL" OR "${ARGV1}" STREQUAL "BINDINGS")
            set(PerfSparse_MODULE_${the_module}_CLASS "${ARGV1}" CACHE INTERNAL "The cathegory of the module")
            set(__PerfSparse_argn__ ${ARGN})
            list(REMOVE_AT __PerfSparse_argn__ 0)
            PerfSparse_add_dependencies(${the_module} ${__PerfSparse_argn__})
            unset(__PerfSparse_argn__)
        else()
            set(PerfSparse_MODULE_${the_module}_CLASS "PUBLIC" CACHE INTERNAL "The cathegory of the module")
            PerfSparse_add_dependencies(${the_module} ${ARGN})
            if(BUILD_${the_module})
                set(PerfSparse_MODULES_PUBLIC ${PerfSparse_MODULES_PUBLIC} "${the_module}" CACHE INTERNAL "List of PerfSparse modules marked for export")
            endif()
        endif()

        if(BUILD_${the_module})
            set(PerfSparse_MODULES_BUILD ${PerfSparse_MODULES_BUILD} "${the_module}" CACHE INTERNAL "List of PerfSparse modules included into the build")
        else()
            set(PerfSparse_MODULES_DISABLED_USER ${PerfSparse_MODULES_DISABLED_USER} "${the_module}" CACHE INTERNAL "List of PerfSparse modules explicitly disabled by user")
        endif()

        return()
    else(PerfSparse_INITIAL_PASS) #
        if(NOT BUILD_${the_module})
            return() # extra protection from redefinition
        endif()
        project(${the_module})
    endif(PerfSparse_INITIAL_PASS)
endmacro()

# excludes module from current configuration
macro(PerfSparse_disable_module module)
    set(__modname ${module})
    if(NOT __modname MATCHES "^PerfSparse_")
        set(__modname PerfSparse_${module})
    endif()

    list(APPEND PerfSparse_MODULES_DISABLED_FORCE "${__modname}")
    set(HAVE_${__modname} OFF CACHE INTERNAL "Module ${__modname} can not be built in current configuration")
    set(PerfSparse_MODULE_${__modname}_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}" CACHE INTERNAL "Location of ${__modname} module sources")
    set(PerfSparse_MODULES_DISABLED_FORCE "${PerfSparse_MODULES_DISABLED_FORCE}" CACHE INTERNAL "List of PerfSparse modules which can not be build in current configuration")
    if(BUILD_${__modname})
        # touch variable controlling build of the module to suppress "unused variable" CMake warning
    endif()
    unset(__modname)
    return() # leave the current folder
endmacro()

macro(__PerfSparse_module_turn_off the_module)
  list(REMOVE_ITEM PerfSparse_MODULES_DISABLED_AUTO "${the_module}")
  list(APPEND      PerfSparse_MODULES_DISABLED_AUTO "${the_module}")
  list(REMOVE_ITEM PerfSparse_MODULES_BUILD "${the_module}")
  list(REMOVE_ITEM PerfSparse_MODULES_PUBLIC "${the_module}")
  set(HAVE_${the_module} OFF CACHE INTERNAL "Module ${the_module} can not be built in current configuration")
endmacro()

macro(__PerfSparse_flatten_module_required_dependencies the_module)
    set(__flattened_deps "")
    set(__resolved_deps "")
    set(__req_depends ${PerfSparse_MODULE_${the_module}_REQ_DEPS})

    while(__req_depends)
        PerfSparse_list_pop_front(__req_depends __dep)

        #depends on self
        if(__dep STREQUAL the_module)
            __PerfSparse_module_turn_off(${the_module})
            break()

            #depends on disabled module
        elseif(";${PerfSparse_MODULES_DISABLED_USER};${PerfSparse_MODULES_DISABLED_AUTO};" MATCHES ";${__dep};")

            __PerfSparse_module_turn_off(${the_module}) # depends on disabled module
            #list(APPEND __flattened_deps "${__dep}")
            break() #TODO

            #depends on build-enabled module
        elseif(";${PerfSparse_MODULES_BUILD};" MATCHES ";${__dep};")

            if(";${__resolved_deps};" MATCHES ";${__dep};")
                list(APPEND __flattened_deps "${__dep}") # all dependencies of this module are already resolved
            else()
                # put all required subdependencies before this dependency and mark it as resolved
                list(APPEND __resolved_deps "${__dep}")
                list(INSERT __req_depends 0 ${PerfSparse_MODULE_${__dep}_REQ_DEPS} ${__dep})
            endif()

        elseif(__dep MATCHES "^PerfSparse_")
            __PerfSparse_module_turn_off(${the_module}) # depends on missing module
            message(WARNING "Unknown \"${__dep}\" module is listened in the dependencies of \"${the_module}\" module")
            break()
        else()
            # skip non-modules
        endif()
    endwhile()

    if(__flattened_deps)
        list(REMOVE_DUPLICATES __flattened_deps)
        set(PerfSparse_MODULE_${the_module}_DEPS ${__flattened_deps})
    else()
        set(PerfSparse_MODULE_${the_module}_DEPS "")
    endif()

    PerfSparse_clear_vars(__resolved_deps __flattened_deps __req_depends __dep)
endmacro()

macro(__PerfSparse_flatten_module_optional_dependencies the_module)
  set(__flattened_deps "")
  set(__resolved_deps "")
  set(__opt_depends ${PerfSparse_MODULE_${the_module}_REQ_DEPS} ${PerfSparse_MODULE_${the_module}_OPT_DEPS})

  while(__opt_depends)
    PerfSparse_list_pop_front(__opt_depends __dep)
    if(__dep STREQUAL the_module)
        __PerfSparse_module_turn_off(${the_module})
      break()

    elseif(";${PerfSparse_MODULES_BUILD};" MATCHES ";${__dep};")
      if(";${__resolved_deps};" MATCHES ";${__dep};")
        list(APPEND __flattened_deps "${__dep}") # all dependencies of this module are already resolved
      else()
        # put all subdependencies before this dependency and mark it as resolved
        list(APPEND __resolved_deps "${__dep}")
        list(INSERT __opt_depends 0 ${PerfSparse_MODULE_${__dep}_REQ_DEPS} ${PerfSparse_MODULE_${__dep}_OPT_DEPS} ${__dep})
      endif()
    else()
      # skip non-modules or missing modules
    endif()
  endwhile()

  if(__flattened_deps)
    list(REMOVE_DUPLICATES __flattened_deps)
    set(PerfSparse_MODULE_${the_module}_DEPS ${__flattened_deps})
  else()
    set(PerfSparse_MODULE_${the_module}_DEPS "")
  endif()

  PerfSparse_clear_vars(__resolved_deps __flattened_deps __opt_depends __dep)
endmacro()

macro(__PerfSparse_flatten_module_dependencies)

    foreach(m ${PerfSparse_MODULES_DISABLED_USER})
        set(HAVE_${m} OFF CACHE INTERNAL "Module ${m} will not be built in current configuration")
    endforeach()

    foreach(m ${PerfSparse_MODULES_BUILD})
        set(HAVE_${m} ON CACHE INTERNAL "Module ${m} will be built in current configuration")
        __PerfSparse_flatten_module_required_dependencies(${m})
        set(PerfSparse_MODULE_${m}_DEPS ${PerfSparse_MODULE_${m}_DEPS} CACHE INTERNAL "Flattened required dependencies of ${m} module")
    endforeach()

    foreach(m ${PerfSparse_MODULES_BUILD})
        __PerfSparse_flatten_module_optional_dependencies(${m})

        # save dependencies from other modules
        set(PerfSparse_MODULE_${m}_DEPS ${PerfSparse_MODULE_${m}_DEPS} CACHE INTERNAL "Flattened dependencies of ${m} module")
        # save extra dependencies
        set(PerfSparse_MODULE_${m}_DEPS_EXT ${PerfSparse_MODULE_${m}_REQ_DEPS} ${PerfSparse_MODULE_${m}_OPT_DEPS})
        if(PerfSparse_MODULE_${m}_DEPS_EXT AND PerfSparse_MODULE_${m}_DEPS)
            list(REMOVE_ITEM PerfSparse_MODULE_${m}_DEPS_EXT ${PerfSparse_MODULE_${m}_DEPS})
        endif()

        set(PerfSparse_MODULE_${m}_DEPS_EXT ${PerfSparse_MODULE_${m}_DEPS_EXT} CACHE INTERNAL "Extra dependencies of ${m} module")
    endforeach()

    # order modules by dependencies
    set(PerfSparse_MODULES_BUILD_ "")
    foreach(m ${PerfSparse_MODULES_BUILD})
        list(APPEND PerfSparse_MODULES_BUILD_ ${PerfSparse_MODULE_${m}_DEPS} ${m})
    endforeach()
    PerfSparse_list_unique(PerfSparse_MODULES_BUILD_)

    set(PerfSparse_MODULES_PUBLIC        ${PerfSparse_MODULES_PUBLIC}        CACHE INTERNAL "List of PerfSparse modules marked for export")
    set(PerfSparse_MODULES_BUILD         ${PerfSparse_MODULES_BUILD_}        CACHE INTERNAL "List of PerfSparse modules included into the build")
    set(PerfSparse_MODULES_DISABLED_AUTO ${PerfSparse_MODULES_DISABLED_AUTO} CACHE INTERNAL "List of PerfSparse modules implicitly disabled due to dependencies")
endmacro()
# collect modules from specified directories
# NB: must be called only once!
macro(PerfSparse_glob_modules)
    if(DEFINED PerfSparse_INITIAL_PASS)
        message(FATAL_ERROR "Perf_IPP has already loaded its modules. Calling PerfSparse_glob_modules second time is not allowed.")
    endif()

    # set(__directories_observed "")

    # collect modules
    set(PerfSparse_INITIAL_PASS ON)

    foreach(__path ${ARGN})
        PerfSparse_get_real_path(__path "${__path}")
        list(FIND __directories_observed "${__path}" __pathIdx)
        if(__pathIdx GREATER -1)
            message(FATAL_ERROR "The directory ${__path} is observed for PerfSparse modules second time.")
        endif()

        list(APPEND __directories_observed "${__path}")
        message("-- Source code path = ${__path}")

        file(GLOB __PerfSparsemodules RELATIVE "${__path}" "${__path}/*")

        if(__PerfSparsemodules)
            list(SORT __PerfSparsemodules)
            foreach(mod ${__PerfSparsemodules})

                PerfSparse_get_real_path(__modpath "${__path}/${mod}")
                if(EXISTS "${__modpath}/CMakeLists.txt")

                    list(FIND __directories_observed "${__modpath}" __pathIdx)
                    if(__pathIdx GREATER -1)
                        message(FATAL_ERROR "The module from ${__modpath} is already loaded.")
                    endif()
                    list(APPEND __directories_observed "${__modpath}")

                    add_subdirectory("${__modpath}" "${CMAKE_CURRENT_BINARY_DIR}/${mod}/.${mod}")

                endif()
            endforeach()
        endif()
    endforeach()

    PerfSparse_clear_vars(__PerfSparsemodules __directories_observed __path __modpath __pathIdx)

    # resolve dependencies
     __PerfSparse_flatten_module_dependencies()

    # create modules
    set(PerfSparse_INITIAL_PASS OFF PARENT_SCOPE)
    set(PerfSparse_INITIAL_PASS OFF)

    foreach(m ${PerfSparse_MODULES_BUILD})
        if(m MATCHES "^PerfSparse_")
            string(REGEX REPLACE "^PerfSparse_" "" __shortname "${m}")
            add_subdirectory("${PerfSparse_MODULE_${m}_LOCATION}" "${CMAKE_CURRENT_BINARY_DIR}/${__shortname}")
        endif()
    endforeach()
    unset(__shortname)
endmacro()

# setup include paths for the list of passed modules
macro(PerfSparse_include_modules)
    foreach(d ${ARGN})
        if(d MATCHES "^PerfSparse_" AND HAVE_${d})
            if (EXISTS "${PerfSparse_MODULE_${d}_LOCATION}/include")
                PerfSparse_include_directories("${PerfSparse_MODULE_${d}_LOCATION}/include")
            endif()
        elseif(EXISTS "${d}")
            PerfSparse_include_directories("${d}")
        endif()
    endforeach()
endmacro()

# setup include path for PerfSparse headers for specified module
# PerfSparse_module_include_directories(<extra include directories/extra include modules>)
macro(PerfSparse_module_include_directories)
    PerfSparse_include_directories("${PerfSparse_MODULE_${the_module}_LOCATION}/include"
        "${PerfSparse_MODULE_${the_module}_LOCATION}/src"
        "${CMAKE_CURRENT_BINARY_DIR}" # for precompiled headers
        )
    PerfSparse_include_modules(${PerfSparse_MODULE_${the_module}_DEPS} ${ARGN})
endmacro()

# sets header and source files for the current module
# NB: all files specified as headers will be installed
# Usage:
# PerfSparse_set_module_sources([HEADERS] <list of files> [SOURCES] <list of files>)
macro(PerfSparse_set_module_sources)
    set(PerfSparse_MODULE_${the_module}_HEADERS "")
    set(PerfSparse_MODULE_${the_module}_SOURCES "")

    foreach(f "HEADERS" ${ARGN})
        if(f STREQUAL "HEADERS" OR f STREQUAL "SOURCES")
            set(__filesvar "PerfSparse_MODULE_${the_module}_${f}")
        else()
            list(APPEND ${__filesvar} "${f}")
        endif()
    endforeach()

    # the hacky way to embeed any files into the PerfSparse without modification of its build system. This part will be rewritten
    #if(COMMAND PerfSparse_get_module_external_sources)
    #  PerfSparse_get_module_external_sources()
    #endif()

    # use full paths for module to be independent from the module location
    PerfSparse_convert_to_full_paths(PerfSparse_MODULE_${the_module}_HEADERS)

    set(PerfSparse_MODULE_${the_module}_HEADERS ${PerfSparse_MODULE_${the_module}_HEADERS} CACHE INTERNAL "List of header files for ${the_module}")
    set(PerfSparse_MODULE_${the_module}_SOURCES ${PerfSparse_MODULE_${the_module}_SOURCES} CACHE INTERNAL "List of source files for ${the_module}")
endmacro()

# creates PerfSparse module in current folder
# creates new target, configures standard dependencies, compilers flags, install rules
# Usage:
#   PerfSparse_create_module(<extra link dependencies>)
#   PerfSparse_create_module(SKIP_LINK)
macro(PerfSparse_create_module)
    ADD_LIBRARY(${the_module} ${PerfSparse_MODULE_TYPE} ${PerfSparse_MODULE_${the_module}_HEADERS} ${PerfSparse_MODULE_${the_module}_SOURCES})

    if(NOT "${ARGN}" STREQUAL "SKIP_LINK")
        TARGET_LINK_LIBRARIES(${the_module} ${PerfSparse_MODULE_${the_module}_DEPS} ${PerfSparse_MODULE_${the_module}_DEPS_EXT} ${PerfSparse_LINKER_LIBS} ${ARGN})
    endif()

    if(ENABLE_SOLUTION_FOLDERS)
        SET_TARGET_PROPERTIES(${the_module} PROPERTIES FOLDER "modules")
    endif()

    SET_TARGET_PROPERTIES(${the_module} PROPERTIES
        OUTPUT_NAME "${the_module}"
        DEBUG_POSTFIX "${PerfSparse_DEBUG_POSTFIX}"
        ARCHIVE_OUTPUT_DIRECTORY "${LIBRARY_OUTPUT_PATH}"
        LIBRARY_OUTPUT_DIRECTORY "${LIBRARY_OUTPUT_PATH}"
        RUNTIME_OUTPUT_DIRECTORY "${EXECUTABLE_OUTPUT_PATH}"
        INSTALL_NAME_DIR lib
        )

    # For dynamic link numbering convenions
    if(NOT ANDROID)
        # Android SDK build scripts can include only .so files into final .apk
        # As result we should not set version properties for Android
        SET_TARGET_PROPERTIES(${the_module} PROPERTIES
            VERSION   ${PerfSparse_LIBVERSION}
            )
    endif()

    if(BUILD_SHARED_LIBS)
        if(MSVC)
            SET_TARGET_PROPERTIES(${the_module} PROPERTIES DEFINE_SYMBOL CVAPI_EXPORTS)
        else()
            ADD_DEFINITIONS(-DCVAPI_EXPORTS)
        endif()
    endif()

    if(MSVC)
        if(CMAKE_CROSSCOMPILING)
            SET_TARGET_PROPERTIES(${the_module} PROPERTIES LINK_FLAGS "/NODEFAULTLIB:secchk")
        endif()
        SET_TARGET_PROPERTIES(${the_module} PROPERTIES LINK_FLAGS "/NODEFAULTLIB:libc /DEBUG")
    endif()

    #FILE(REMOVE_RECURSE ${PerfSparse_LIB_INSTALL_PATH})
    #FILE(REMOVE_RECURSE ${PerfSparse_INCLUDE_INSTALL_PATH})

#    INSTALL(TARGETS ${the_module}
#        RUNTIME DESTINATION ${PerfSparse_RUNTIME_INSTALL_PATH}
#        LIBRARY DESTINATION ${PerfSparse_LIB_INSTALL_PATH}
#        ARCHIVE DESTINATION ${PerfSparse_LIB_INSTALL_PATH}
#        COMPONENT main
#            )

    # only "public" headers need to be installed
    if(PerfSparse_MODULE_${the_module}_HEADERS AND ";${PerfSparse_MODULES_PUBLIC};" MATCHES ";${the_module};")
        foreach(hdr ${PerfSparse_MODULE_${the_module}_HEADERS})
            if(hdr MATCHES "([^/])+.h(..)?$")
                INSTALL(FILES ${hdr} DESTINATION "${PerfSparse_INCLUDE_INSTALL_PATH}/${the_module_res}" COMPONENT main)
            endif()
        endforeach()
    endif()
endmacro()

# ensures that all passed modules are available
# sets PerfSparse_DEPENDENCIES_FOUND variable to TRUE/FALSE
macro(PerfSparse_check_dependencies)
    set(PerfSparse_DEPENDENCIES_FOUND TRUE)
    foreach(d ${ARGN})
        if(d MATCHES "^PerfSparse_[^ ]+$" AND NOT HAVE_${d})
            set(PerfSparse_DEPENDENCIES_FOUND FALSE)
            break()
        endif()
    endforeach()
endmacro()

# auxiliary macro to parse arguments of PerfSparse_add_accuracy_tests and PerfSparse_add_perf_tests commands
macro(__PerfSparse_parse_test_sources tests_type)

    set(PerfSparse_${tests_type}_${the_module}_SOURCES "")
    set(PerfSparse_${tests_type}_${the_module}_DEPS "")
    set(__file_group_name    "")
    set(__file_group_sources "")

    foreach(arg "DEPENDS_ON" ${ARGN} "FILES")
        if(arg STREQUAL "FILES")
            set(__currentvar "__file_group_sources")
            if(__file_group_name AND __file_group_sources)
                SOURCE_GROUP("${__file_group_name}" FILES ${__file_group_sources})
                list(APPEND PerfSparse_${tests_type}_${the_module}_SOURCES ${__file_group_sources})
            endif()
            set(__file_group_name "")
            set(__file_group_sources "")
        elseif(arg STREQUAL "DEPENDS_ON")
            set(__currentvar "PerfSparse_TEST_${the_module}_DEPS")
        elseif("${__currentvar}" STREQUAL "__file_group_sources" AND NOT __file_group_name)
            set(__file_group_name "${arg}")
        else()
            list(APPEND ${__currentvar} "${arg}")
        endif()
    endforeach()
    unset(__file_group_name)
    unset(__file_group_sources)
    unset(__currentvar)
endmacro()

# this is a command for adding PerfSparse performance tests to the module
# PerfSparse_add_perf_tests(<extra_dependencies>)
function(PerfSparse_add_perf_tests)
    set(perf_path "${CMAKE_CURRENT_SOURCE_DIR}/perf")
    set(test_utilities_path "${CMAKE_SOURCE_DIR}/utilities")
    if(BUILD_PERF_TESTS AND EXISTS "${perf_path}")
        __PerfSparse_parse_test_sources(PERF ${ARGN})

        set(perf_deps ${the_module} ${PerfSparse_PERF_${the_module}_DEPS})
        PerfSparse_check_dependencies(${perf_deps})

        if(PerfSparse_DEPENDENCIES_FOUND)
            set(the_target "PerfSparse_perf_${name}")

            PerfSparse_include_directories(${PerfSparse_TEST_INCLUDE_DIRECTORIES})

            if(NOT PerfSparse_PERF_${the_module}_SOURCES)
                file(GLOB perf_srcs "${perf_path}/*.cpp" "${test_path}/*.c" "${test_utilities_path}/*.cpp")
                file(GLOB perf_hdrs "${perf_path}/*.hpp" "${perf_path}/*.h")
                SOURCE_GROUP("Src" FILES ${perf_srcs})
                SOURCE_GROUP("Include" FILES ${perf_hdrs})
                set(PerfSparse_PERF_${the_module}_SOURCES ${perf_srcs} ${perf_hdrs})
            endif()

            ADD_EXECUTABLE(${the_target} ${PerfSparse_PERF_${the_module}_SOURCES})
            TARGET_LINK_LIBRARIES(${the_target} ${PerfSparse_MODULE_${the_module}_DEPS} ${perf_deps} ${PerfSparse_LINKER_LIBS} ${PerfSparse_LINKER_TEST_LIBS} GTest::GTest GTest::Main)

            # Additional target properties
            SET_TARGET_PROPERTIES(${the_target} PROPERTIES
                DEBUG_POSTFIX "${PerfSparse_DEBUG_POSTFIX}"
                RUNTIME_OUTPUT_DIRECTORY "${EXECUTABLE_OUTPUT_PATH}"
                )

            if(ENABLE_SOLUTION_FOLDERS)
                SET_TARGET_PROPERTIES(${the_target} PROPERTIES FOLDER "tests_performance")
            endif()

            #PerfSparse_add_precompiled_headers(${the_target}) TODO

            #TODO
            #if (PYTHON_EXECUTABLE)
            #    add_dependencies(perf ${the_target})
            #endif()
        else(PerfSparse_DEPENDENCIES_FOUND)
            # TODO: warn about unsatisfied dependencies
        endif(PerfSparse_DEPENDENCIES_FOUND)
    endif()
endfunction()

# this is a command for adding PerfSparse accuracy/regression tests to the module
# PerfSparse_add_accuracy_tests([FILES <source group name> <list of sources>] [DEPENDS_ON] <list of extra dependencies>)
function(PerfSparse_add_accuracy_tests)
    set(test_path "${CMAKE_CURRENT_SOURCE_DIR}/test")
    set(test_utilities_path "${CMAKE_SOURCE_DIR}/utilities")
    if(BUILD_TESTS AND EXISTS "${test_path}")
        __PerfSparse_parse_test_sources(TEST ${ARGN})

        set(test_deps ${the_module} ${PerfSparse_TEST_${the_module}_DEPS})
        PerfSparse_check_dependencies(${test_deps})

        if(PerfSparse_DEPENDENCIES_FOUND)
            set(the_target "PerfSparse_test_${name}")

            PerfSparse_include_directories(${PerfSparse_TEST_INCLUDE_DIRECTORIES} ${test_utilities_path})

            if(NOT PerfSparse_TEST_${the_module}_SOURCES)
                file(GLOB test_srcs "${test_path}/*.cpp" "${test_path}/*.c" "${test_utilities_path}/*.cpp")
                file(GLOB test_hdrs "${test_path}/*.hpp" "${test_path}/*.h")
                source_group("Src" FILES ${test_srcs})
                source_group("Include" FILES ${test_hdrs})
                set(PerfSparse_TEST_${the_module}_SOURCES ${test_srcs} ${test_hdrs})
            endif()

            LINK_DIRECTORIES(${test_utilities_path})
            ADD_EXECUTABLE(${the_target} ${PerfSparse_TEST_${the_module}_SOURCES})
            TARGET_LINK_LIBRARIES(${the_target} ${test_deps} ${PerfSparse_LINKER_LIBS} ${PerfSparse_LINKER_TEST_LIBS} GTest::GTest GTest::Main)

            # Additional target properties
            SET_TARGET_PROPERTIES(${the_target} PROPERTIES
                DEBUG_POSTFIX "${PerfSparse_DEBUG_POSTFIX}"
                RUNTIME_OUTPUT_DIRECTORY "${EXECUTABLE_OUTPUT_PATH}"
                )

            if(ENABLE_SOLUTION_FOLDERS)
                SET_TARGET_PROPERTIES(${the_target} PROPERTIES FOLDER "tests_accuracy")
            endif()

        else(PerfSparse_DEPENDENCIES_FOUND)
            # TODO: warn about unsatisfied dependencies
        endif(PerfSparse_DEPENDENCIES_FOUND)
    endif()
endfunction()

# finds and sets headers and sources for the standard PerfSparse module
# Usage:
# PerfSparse_glob_module_sources(<extra sources&headers in the same format as used in PerfSparse_set_module_sources>)
macro(PerfSparse_glob_module_sources)
  file(GLOB_RECURSE lib_srcs "src/*.c" "src/*.cpp")
  file(GLOB_RECURSE lib_int_hdrs "src/*.hpp" "src/*.h")
  file(GLOB lib_hdrs "include/${name}/*.hpp" "include/${name}/*.h")

  source_group("Src" FILES ${lib_srcs} ${lib_int_hdrs})
  source_group("Include" FILES ${lib_hdrs})

  PerfSparse_set_module_sources(${ARGN} HEADERS ${lib_hdrs} SOURCES ${lib_srcs} ${lib_int_hdrs})
endmacro()
# short command for adding simple PerfSparse module
# see PerfSparse_add_module for argument details
# Usage:
# PerfSparse_define_module(module_name  [INTERNAL] [REQUIRED] [<list of dependencies>] [OPTIONAL <list of optional dependencies>])
macro(PerfSparse_define_module module_name)
  PerfSparse_add_module(${module_name} ${ARGN})
  PerfSparse_glob_module_sources()
  PerfSparse_module_include_directories()
  PerfSparse_create_module()

  if(BUILD_TESTS)
      PerfSparse_add_accuracy_tests()
  endif()
  if(BUILD_PERF_TESTS)
      PerfSparse_add_perf_tests()
  endif()
endmacro()
