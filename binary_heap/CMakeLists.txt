cmake_minimum_required(VERSION 4.1)
project(binary_heap C)

set(CMAKE_C_STANDARD 11)

add_library(binary_heap STATIC library.c)
