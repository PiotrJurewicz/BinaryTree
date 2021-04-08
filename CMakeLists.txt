cmake_minimum_required(VERSION 3.10)

project(BinaryTree)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY &{CMAKE_BINARY_DIR}/../../build)
add_executable(Main cpp/main.cpp cpp/BinaryTree.cpp)
target_include_directories(Main PUBLIC hpp)
