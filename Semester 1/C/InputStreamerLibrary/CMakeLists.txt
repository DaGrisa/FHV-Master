cmake_minimum_required(VERSION 3.6)
project(InputStreamerLibrary)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c ByteArrayInputStream.h ByteArrayInputStream.c InputStream.h UpperCaseInputStream.c UpperCaseInputStream.h)
add_executable(InputStreamerLibrary ${SOURCE_FILES})