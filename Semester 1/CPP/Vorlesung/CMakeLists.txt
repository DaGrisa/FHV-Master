cmake_minimum_required(VERSION 3.6)
project(Vorlesung)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.h Person.cpp Stack.h Student.h Student.cpp TypedStack.h)
add_executable(Vorlesung ${SOURCE_FILES})