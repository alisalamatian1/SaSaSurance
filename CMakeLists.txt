cmake_minimum_required(VERSION 3.22)
project(SaSaSurance2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SaSaSurance2 main.cpp Client.h Client.cpp Business.h Business.cpp Plan.h EyePlan.h EyePlan.cpp Insurance.h Insurance.cpp AmountExceedException.h Plan.cpp)
