cmake_minimum_required(VERSION 3.8)
project(.)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES DecoratorPattern.cpp)
add_executable(. ${SOURCE_FILES})
