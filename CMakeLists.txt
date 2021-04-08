cmake_minimum_required(VERSION 3.10)

project(BinaryTree)

include(CMakeFiles/GTest.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY &{CMAKE_BINARY_DIR}/../../build)

#Tests setup
add_executable(Tests uts/ut.cpp)
target_include_directories(Tests PUBLIC hpp)
target_link_libraries(Tests gtest gtest_main)

#Exec setup
add_executable(Main cpp/main.cpp cpp/BinaryTree.cpp)
target_include_directories(Main PUBLIC hpp)
