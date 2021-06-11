cmake_minimum_required(VERSION 3.19)
project(graph_connectivity C)

set(CMAKE_C_STANDARD 99)

add_executable(graph_connectivity main.c graph.c graph.h list.c list.h benchmark.c benchmark.h)