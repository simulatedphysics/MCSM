cmake_minimum_required(VERSION 3.10)
project(MCSM)

set(CMAKE_CXX_STANDARD 11)

find_library(MCSM libarmadillo)

add_executable(
        MCSM
        main.cpp
#        Model/Model.hpp
        Model/Heisenberg.hpp
        Model/Heisenberg.cpp
        Algorithm/MonteCarlo.cpp
#        Lattice/Lattice.hpp
        Algorithm/Algorithm.hpp
        Lattice/Square.cpp
#        Lattice/Square.hpp
        )

target_link_libraries(MCSM armadillo)