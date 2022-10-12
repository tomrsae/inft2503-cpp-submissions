cmake_minimum_required(VERSION 3.1)

project(assignment-7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(assignment-7-1 1.cpp fraction.hpp fraction.cpp)
add_executable(assignment-7-2 2.cpp set.hpp set.cpp)