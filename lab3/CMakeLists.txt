cmake_minimum_required(VERSION 3.5)

project(lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3 main.cpp  binary1.h binary1.cpp binary2.h binary2.cpp binary3.h binary3.cpp)
