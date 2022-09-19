cmake_minimum_required(VERSION 3.1)

project(assignment-3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(assignment-3-2 2.cpp)
add_executable(assignment-3-3 commodity.cpp 3.cpp)
add_executable(assignment-3-4 4.cpp)