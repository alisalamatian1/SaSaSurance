cmake_minimum_required(VERSION 3.22)
project(SaSaSurance2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_executable(${CMAKE_PROJECT_NAME}_run main.cpp)
add_subdirectory(Google_tests)
target_link_libraries(${CMAKE_PROJECT_NAME}_run ${CMAKE_PROJECT_NAME}_lib)