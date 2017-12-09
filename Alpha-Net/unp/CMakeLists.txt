cmake_minimum_required(VERSION 3.8)
project(alpha-net)

set(CMAKE_CXX_STANDARD  11)

set(SOURCE_FILES tcp_select_server.cpp tcp_poll_server.cpp daytimeclient.cpp)
add_executable(alpha-net ${SOURCE_FILES})

set(SOURCE_FILES_DAYTIME_SERVER daytimeserver.cpp)
add_executable(daytimeserver ${SOURCE_FILES_DAYTIME_SERVER})

set(SOURCE_FILES_DAYTIME_CLIENT daytimeclient.cpp)
add_executable(daytimeclient ${SOURCE_FILES_DAYTIME_CLIENT})
