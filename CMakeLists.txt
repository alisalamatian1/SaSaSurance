cmake_minimum_required(VERSION 3.22)
project(SaSaSurance2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SaSaSurance2 src/main.cpp src/client/Client.h src/client/Client.cpp src/business/Business.h src/business/Business.cpp src/insurance/Plan.h src/insurance/EyePlan.h src/insurance/EyePlan.cpp src/insurance/Insurance.h src/insurance/Insurance.cpp src/AmountExceedException.h src/insurance/Plan.cpp)
