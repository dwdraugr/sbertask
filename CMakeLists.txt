cmake_minimum_required(VERSION 3.21)
project(match_3 C)

set(CMAKE_C_STANDARD 23)

add_executable(match_3 main.c match_3_turn_searcher.c match_3_turn_searcher.h)
