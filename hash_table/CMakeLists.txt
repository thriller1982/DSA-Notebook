cmake_minimum_required(VERSION 4.1)
project(hash_table C)

set(CMAKE_C_STANDARD 11)

add_executable(sc_hash_table sc_hash_table.c
            sc_hash_table.h)