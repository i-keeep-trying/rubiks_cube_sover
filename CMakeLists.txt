cmake_minimum_required(VERSION 3.31)
project(rubiks_cube_sover)

set(CMAKE_CXX_STANDARD 20)

add_executable(rubiks_cube_sover main.cpp
        Models/AbstractRubiksCube.cpp
        Models/AbstractRubiksCube.h
        Models/RubiksCube3DArrayModel.cpp
        Models/RubiksCube1DArrayModel.cpp
        Models/RubiksCubeBitboardModel.cpp
        Solvers/DFSSolver.h
        Solvers/BFSSolver.h
        Solvers/IDDFSSolver.h
        Solvers/IDAStarSolver.h
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/NibbleArray.h
        PatternDatabases/Math.cpp
        PatternDatabases/Math.h
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/CornerDatabaseMaker.cpp
        PatternDatabases/CornerDatabaseMaker.h
)
