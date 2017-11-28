
cmake_minimum_required(VERSION 3.8)
project(leet_code)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ListNode.h ListUtility.cpp MergeTwoSortedList.cpp ReverseList.cpp ConvertBTreeToList.cpp ListUtility.h main.cpp)

add_executable(list_solution ${SOURCE_FILES})
