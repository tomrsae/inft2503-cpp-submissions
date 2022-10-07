cmake_minimum_required(VERSION 3.1)

project(assignment-6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(assignment-6-1 1.cpp)

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(assignment-6-2 2.cpp)
target_link_libraries(assignment-6-2 ${Boost_LIBRARIES})