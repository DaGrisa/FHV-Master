cmake_minimum_required(VERSION 3.6)
project(GenericLinkedList)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c list.h intlist.h doublelist.h list.c intlist.c doublelist.c)
add_executable(GenericLinkedList ${SOURCE_FILES})