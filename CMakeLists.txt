cmake_minimum_required(VERSION 3.4.0)
project(candy)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/gtest.cmake)
include_directories(include)
add_subdirectory(test)
