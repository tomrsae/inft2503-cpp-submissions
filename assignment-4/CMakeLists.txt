cmake_minimum_required(VERSION 3.1)

project(assignment-4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(assignment-4-1 1.cpp)

INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(assignment-4-2 2.cpp)
target_link_libraries(assignment-4-2 ${GTKMM_LIBRARIES})