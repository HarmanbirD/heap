cmake_minimum_required(VERSION 3.12)
project(heap)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(heap main.cpp heap.hpp)