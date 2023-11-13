cmake_minimum_required(VERSION 3.26)
project(TNG033)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab2)

add_executable(TNG033
        lab2/polynomial.cpp
        lab2/polynomial.h
        lab2/logarithm.h
        lab2/logarithm.cpp
        lab2/expression.h
        lab2/expression.cpp
        lab2/lab2.cpp)
