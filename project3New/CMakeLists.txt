cmake_minimum_required(VERSION 3.28)
project(project3New)

set(CMAKE_CXX_STANDARD 17)

add_executable(project3New project3TestHarness.cpp
        sequence.cpp
        sequence.h)
