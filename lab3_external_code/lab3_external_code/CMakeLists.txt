cmake_minimum_required(VERSION 3.5)

project(lab3_external_code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3_external_code main.cpp randomiseV.hpp main2.cpp FunctionsLab3V.cpp)
