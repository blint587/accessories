cmake_minimum_required(VERSION 3.3)
project(design_process)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Error.cpp Error.h)
add_executable(design_process ${SOURCE_FILES} Error.cpp Error.h)