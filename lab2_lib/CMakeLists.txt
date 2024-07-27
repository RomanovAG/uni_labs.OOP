cmake_minimum_required(VERSION 3.5)

project(lab2_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES D:/Labs/OOP/lab2/conchoidnicomed.h D:/Labs/OOP/lab2/conchoidnicomed.cpp)
add_library(lab2_lib STATIC ${SOURCE_FILES})

#add_executable(lab2_lib main.cpp)
