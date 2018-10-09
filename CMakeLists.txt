cmake_minimum_required(VERSION 3.10)
project(Simulation)

set(CMAKE_CXX_STANDARD 11)

find_library(Simulation libarmadillo)

add_executable(Simulation main.cpp Model/Model.hpp Model/Heisenberg.cpp Algorithm/MonteCarlo.cpp Lattice/Lattice.hpp Model/Heisenberg.hpp Algorithm/MonteCarlo.hpp Algorithm/Algorithm.hpp)

target_link_libraries(Simulation armadillo)