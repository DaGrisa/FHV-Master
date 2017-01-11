cmake_minimum_required(VERSION 3.6)
project(StackTemplate)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack.h)
add_executable(StackTemplate ${SOURCE_FILES})