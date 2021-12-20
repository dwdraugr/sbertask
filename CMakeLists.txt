cmake_minimum_required(VERSION 3.16)
project(match_3 C)

set(CMAKE_C_STANDARD 11)

# comment or modify it if output is useless
add_definitions(-DDISPLAY_MAP -DDISPLAY_TURNS)

add_executable(match_3 main.c match_3_turn_searcher.c match_3_turn_searcher.h)
