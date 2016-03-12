cmake_minimum_required(VERSION 3.3)
project(design_process)

add_subdirectory(src/Error)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Error/Error.h src/Error/Error.cpp)
add_executable(design_process ${SOURCE_FILES})
