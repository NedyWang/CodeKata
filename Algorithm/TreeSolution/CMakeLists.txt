cmake_minimum_required(VERSION 3.8)
project(code_kata)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BTreeSolution.cpp BTreeSolution.h TreeNode.h)
add_executable(btree_solution ${SOURCE_FILES})
