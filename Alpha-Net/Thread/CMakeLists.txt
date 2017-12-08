cmake_minimum_required(VERSION 3.8)
project(alpha-thread)

set(SOURCE_FILES EchoThread.h Thread.cpp Thread.h main.cpp main.cpp)
add_executable(aplha-thread ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(aplha-thread Threads::Threads)
