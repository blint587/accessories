cmake_minimum_required(VERSION 3.3)
project(design_process)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Error.h Error.cpp)
add_library(error SHARED ${SOURCE_FILES})
