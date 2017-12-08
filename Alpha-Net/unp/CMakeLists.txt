cmake_minimum_required(VERSION 3.8)
project(alpha-net)

set(CMAKE_CXX_STANDARD  11)

set(SOURCE_FILES tcp_select_server.cpp tcp_poll_server.cpp)
add_executable(alpha-net ${SOURCE_FILES})
