//
// Created by solidangle on 10/21/18.
//

#include <vector>
#include <iostream>
#include "../Spin/Spin.hpp"

#pragma once
class Site{
public:
    int x;
    int y;
    int z;
    Spin occupant;

    Site(int in_x, int in_y, int in_z);
    std::vector<Site*> neighbors;

    void print_site(){std::cout << x << ", " << y << ", " << z << std::endl;}
};
