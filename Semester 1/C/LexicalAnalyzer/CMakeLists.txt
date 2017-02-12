cmake_minimum_required(VERSION 3.6)
project(LexicalAnalyzer)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES LexicalAnalyzer.h LexicalAnalyzer.c)
add_executable(LexicalAnalyzer ${SOURCE_FILES})