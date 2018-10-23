//
// Created by Patrick O'Brien on 9/27/18.
//

#include <utility>
#include <vector>
#include <iostream>
#include "Site.hpp"

#pragma once
class Lattice{
public:
    int n_x;
    int n_y;
    int n_z;

    std::vector<Site> lat;

    virtual void generate_lattice()=0;
    void print_lattice(){for(auto &m:lat){std::cout << m.x << ", " << m.y << ", " << m.z << std::endl;}};

//    virtual void find_neighbors() = 0;
};
