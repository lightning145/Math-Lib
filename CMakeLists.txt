cmake_minimum_required(VERSION 3.16)

project(MD-Math)

add_library(MD-Math 
            General.c
            Vector.c)

add_executable(test1 test/test1/main.c)
target_link_libraries(test1 MD-Math)

add_executable(test2 test/test2/main.c)
target_link_libraries(test2 MD-Math)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)