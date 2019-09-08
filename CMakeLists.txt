cmake_minimum_required(VERSION 3.10)
project(MCSM)

set(CMAKE_CXX_STANDARD 11)

find_library(MCSM libarmadillo)

add_executable(
        MCSM
        main.cpp
#        Model/Heisenberg.cpp
        Algorithm/MonteCarlo.cpp
        Lattice/Square.cpp
        Lattice/Site.hpp
        Lattice/Site.cpp
        Spin/Spin.hpp
        Model/Ising.hpp
        Model/Ising.cpp
#        Plot/MagneticStatePlot.cpp
#        Plot/AverageEnergyPlot.cpp
        Lattice/Triangular.hpp Lattice/Triangular.cpp)

target_link_libraries(MCSM armadillo util boost_iostreams boost_system boost_filesystem)