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

public:
    Site(int in_x, int in_y, int in_z);
    std::vector<Site*> neighbors;
    int getX(){return x;};
    int getY(){return y;};
    int getZ(){return z;};
    Spin & getSpin(){return spin;};

    void print_site(){std::cout << getX() << ", " << getY() << ", " << getZ() << std::endl;}
    void set_spin(Spin new_s){spin = new_s;}
};
