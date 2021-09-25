cmake_minimum_required(VERSION 3.20)
project(matrix-cpp)

set(SOURCE_EXE main/main.cpp)
set(SOURCE_LIB include/matrix.cpp)

add_library(matrix STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main matrix)