project(BFS_Searching)

cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++11)

set(sources BFS.cpp main.cpp )

set(CMAKE_BUILD_TYPE Debug)

add_executable(a ${sources})


