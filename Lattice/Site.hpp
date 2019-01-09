//
// Created by solidangle on 10/21/18.
//

#include <vector>
#include <iostream>
#include "../Spin/Spin.hpp"
#include <armadillo>

using namespace arma;

#pragma once
class Site{
private:
    int x;
    int y;
    int z;
    Spin spin;
    std::vector<Site*> neighbors;

public:
    Site(int in_x, int in_y, int in_z);
    int get_x(){return x;};
    int get_y(){return y;};
    int get_z(){return z;};
    Spin & get_spin(){return spin;};
    std::vector<Site*> & get_neighbors(){return neighbors;};
    void print_site(){std::cout << get_x() << ", " << get_y() << ", " << get_z() << std::endl;}
    void set_spin(Spin new_s){spin = new_s;}
};
