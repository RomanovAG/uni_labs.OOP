cmake_minimum_required(VERSION 3.5)

project(lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab2 main.cpp conchoidnicomed.h conchoidnicomed.cpp dialog.cpp dialog.h)
