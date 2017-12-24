cmake_minimum_required(VERSION 3.8)
project(keep)

set(CMAKE_CXX_STANDARD  11)

set(SOURCE_FILES lambda.cpp)
add_executable(keep ${SOURCE_FILES})

set(SOURCE_FILES_DAEMON daemon.cpp)
add_executable(daemon ${SOURCE_FILES_DAEMON})

set(SOURCE_FILES_ALGO MoreThanHalfNumber.cpp)
add_executable(algo ${SOURCE_FILES_ALGO})

set(SOURCE_FILES_OBJECT_MODEL objectModel.cpp)
add_executable(objectModel ${SOURCE_FILES_OBJECT_MODEL})
