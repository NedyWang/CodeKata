cmake_minimum_required(VERSION 3.8)
project(leet_code)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES MedianSortedArrays.cpp LongestPalindrome.cpp ZigzargConvert.cpp LengthOfLongestSubstring.cpp main.cpp ReverseInteger.cpp)
add_executable(leet_code ${SOURCE_FILES})
