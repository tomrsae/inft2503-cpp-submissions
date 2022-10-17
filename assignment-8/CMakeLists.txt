cmake_minimum_required(VERSION 3.1)

project(assignment-8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(assignment-8-1 1.cpp)
add_executable(assignment-8-2 2.cpp Pair.hpp)