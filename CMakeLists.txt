cmake_minimum_required(VERSION 3.30)
project(kallocator C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(kallocator SHARED kallocator.c)

target_link_libraries(kallocator dl)