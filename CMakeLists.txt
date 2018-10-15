cmake_minimum_required(VERSION 3.10)
project(MCSM)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.67.0 REQUIRED COMPONENTS system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

find_library(MCSM libarmadillo)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp")

add_executable(MCSM ${SOURCES})

target_link_libraries(MCSM armadillo)