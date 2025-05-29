cmake_minimum_required(VERSION 3.31)
project(rubiks_cube_sover)

set(CMAKE_CXX_STANDARD 20)

add_executable(rubiks_cube_sover main.cpp
        AbstractRubiksCube.cpp
        AbstractRubiksCube.h
        RubiksCube3DArrayModel.cpp
)
