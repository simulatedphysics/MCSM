//
// Created by Patrick O'Brien on 9/27/18.
//

#include <utility>
#include <vector>
#include <iostream>
#include "Site.hpp"

#pragma once
class Lattice{
    int n_x = 4;
    int n_y = 4;
    int n_z = 0;
    std::vector<Site> lat;
public:
    virtual void generate_lattice() = 0;
    virtual void set_neighbors() = 0;
    virtual int convert_to_index(int, int) = 0;
    std::vector<Site> & getLattice(){return lat;};
    void print_lattice(){for(auto &m:lat){m.print_site();} std::cout << std::endl;};
    int get_nx(){return n_x;};
    int get_ny(){return n_y;};
    int get_nz(){return n_z;};

//    Probably should set this, because this is a base class
    virtual ~Lattice() = default;;
};
