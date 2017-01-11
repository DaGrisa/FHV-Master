cmake_minimum_required(VERSION 3.6)
project(Observer)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c observer.h observer.c)
add_executable(Observer ${SOURCE_FILES})