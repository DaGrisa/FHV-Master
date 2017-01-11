cmake_minimum_required(VERSION 3.6)
project(MemoryManagement)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c mm.c mm.h)
add_executable(MemoryManagement ${SOURCE_FILES})