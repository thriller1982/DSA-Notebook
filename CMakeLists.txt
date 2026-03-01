cmake_minimum_required(VERSION 3.16)
project(DSA_Notebook C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build example executables" ON)
option(BUILD_TESTS "Build tests" OFF)

add_subdirectory(common)
add_subdirectory(binary_heap)
add_subdirectory(hash_table)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
