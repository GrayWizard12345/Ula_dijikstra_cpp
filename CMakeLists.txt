cmake_minimum_required(VERSION 3.20)
project(Ula)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(labs
        astar.cpp
        astar.h
        dijkstra.cpp
        dijkstra.h
        input.cpp
        input.h
        main.cpp
        structures.h)
