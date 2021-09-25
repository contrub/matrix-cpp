cmake_minimum_required(VERSION 3.20)
project(matrix-cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories("include/")

add_executable(matrix-cpp main/main.cpp)
