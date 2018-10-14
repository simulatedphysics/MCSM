cmake_minimum_required(VERSION 3.10)
project(MCSM)

set(CMAKE_CXX_STANDARD 11)

find_library(MCSM libarmadillo)

add_executable(MCSM main.cpp Model/Model.hpp Model/Heisenberg.cpp Algorithm/MonteCarlo.cpp Lattice/Lattice.hpp Model/Heisenberg.hpp Algorithm/MonteCarlo.hpp Algorithm/Algorithm.hpp)

target_link_libraries(MCSM armadillo)