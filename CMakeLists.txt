cmake_minimum_required(VERSION 3.16)

project(MD-Math)

add_library(MD-Math 
            General.c
            Vector.c
            Matrix.c
            Quaternion.c
            Transform.c)

add_executable(test1 test/test1/main.c)
target_link_libraries(test1 MD-Math)

add_executable(test2 test/test2/main.c)
target_link_libraries(test2 MD-Math)

add_executable(test3 test/test3/main.c)
target_link_libraries(test3 MD-Math)

add_executable(test4 test/test4/main.c)
target_link_libraries(test4 MD-Math)

add_executable(test5 WIN32 
            test/test5/main.c
            test/test5/glad.c)
target_link_libraries(test5 MD-Math opengl32 winmm)

add_executable(test6 WIN32 
            test/test6/main.c)
target_link_libraries(test6 MD-Math d3d9 d3dx9 winmm)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)