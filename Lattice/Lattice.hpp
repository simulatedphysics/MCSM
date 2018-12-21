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
    int n_x = 4;
    int n_y = 4;
    int n_z = 0;

    std::vector<Site> lat;

    virtual void generate_lattice()=0;
    void print_lattice(){for(auto &m:lat){std::cout << m.x << ", " << m.y << ", " << m.z << std::endl;}};

    virtual void set_neighbors() = 0;
    virtual int convert_to_index(int, int) = 0;

//    Probably should set this, because this is a base class
//    virtual ~Lattice(){};
};
