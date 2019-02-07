//
// Created by Patrick O'Brien on 9/27/18.
//

#include <utility>
#include <vector>
#include <iostream>
#include "Site.hpp"

#pragma once
class Lattice{
    int n_x;
    int n_y;
    int n_z = 0;
    std::vector<Site> lat;
public:
    virtual void generate_lattice() = 0;
    virtual void set_neighbors() = 0;
    virtual int convert_to_index(int, int) = 0;
    std::vector<Site> & get_lattice(){return lat;};
    void print_lattice(){for(auto &m:lat){m.print_site();} std::cout << std::endl;};
    double calculate_magnetization(){ double total_mag = 0;
        for(auto &m:lat){total_mag += m.get_spin().get_z();}
        return total_mag/(n_x * n_y);
    }
    int get_nx(){return n_x;};
    int get_ny(){return n_y;};
    int get_nz(){return n_z;};

    void set_nx(int nx_in){n_x = nx_in;};
    void set_ny(int ny_in){n_y = ny_in;};
    void set_nz(int nz_in){n_z = nz_in;};

    virtual ~Lattice() = default;;
};

