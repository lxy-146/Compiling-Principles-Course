cmake_minimum_required(VERSION 3.17)
project(Compiling_Principles_Course)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Compiling_Principles_Course
        resources/productions.txt
        resources/right_test.txt
        resources/wrong_test.txt
        ir_generator.cpp
        ir_generator.h
        lextual.cpp
        lextual.h
        main.cpp
        object_generator.cpp
        object_generator.h
        parser.cpp
        parser.h)
