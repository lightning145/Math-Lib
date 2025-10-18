cmake_minimum_required(VERSION 3.16)

project(MD-Math)

add_library(MD-Math 
            General.c)

add_executable(test1 test/test1/main.c)
target_link_libraries(test1 MD-Math)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)