cmake_minimum_required(VERSION 3.8)
project(leet_code)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ArraySolution.cpp ArraySolution.h GetLeastK.cpp main.cpp MaxSubSequenceSum.cpp ../SortSolution/SortSolution.h ../SortSolution/SortSolution.cpp)
add_executable(array_solution ${SOURCE_FILES})
