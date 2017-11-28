cmake_minimum_required(VERSION 3.8)
project(leet_code)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES SortSolution.cpp SortSolution.h main.cpp SortSolution.h SortSolution.cpp)
add_executable(sort_solution ${SOURCE_FILES})
