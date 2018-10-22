//
// Created by Patrick O'Brien on 9/27/18.
//

#include <utility>
#include <vector>
#include <iostream>

#pragma once
class Site{
public:
    int x;
    int y;
    int z;

    Site(int in_x, int in_y, int in_z){
        x = in_x;
        y = in_y;
        z = in_z;
    };

//    Site(){};
};

//Site::Site(int in_x, int in_y, int in_z){
//    x = in_x;
//    y = in_y;
//    z = in_z;
//}

class Lattice{
public:
    int n_x;
    int n_y;
    int n_z;

    std::vector<Site> lat;

    virtual void generate_lattice()=0;
//    void print_lattice(){for(auto &m:lat){std::cout << m.x << ", " << m.y << ", " << m.z << std::endl;}};
};
