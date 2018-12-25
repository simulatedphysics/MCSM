//
// Created by solidangle on 10/21/18.
//

#include <vector>
#include <iostream>
#include "../Spin/Spin.hpp"

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

    void print_site(){std::cout << getX() << ", " << getY() << ", " << getZ() << std::endl;}
};
