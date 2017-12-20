cmake_minimum_required(VERSION 3.8)
project(keep)

set(CMAKE_CXX_STANDARD  11)

set(SOURCE_FILES lambda.cpp)
add_executable(keep ${SOURCE_FILES})
