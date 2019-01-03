//
// Created by solidangle on 12/28/18.
//

#include <fstream>
#include <vector>
#include <map>
#include <limits>
#include <cmath>
#include <cstdio>
#include <boost/tuple/tuple.hpp>
#include <boost/foreach.hpp>

#include "gnuplot-iostream.h"
#include "../Model/Model.hpp"

#ifndef M_PI
#	define M_PI 3.14159265358979323846
#endif

//#pragma once
void demo_basic(std::unique_ptr<Model> & model_ptr) {
    Gnuplot gp;

    int nx = model_ptr->getLattice().get_nx();
    int ny = model_ptr->getLattice().get_ny();

    std::cout << "The x-size is: " << nx << std::endl;
    std::cout << "The y-size is: " << ny << std::endl;

    gp << "set xr [-0.5:" + std::to_string(nx - 0.5) + "]\nset yr [-0.5:" + std::to_string(ny - 0.5) + "]\n";
    gp << "unset tics\n";
    gp << "unset border\n";
    gp << "set size sq\n";
    gp << "set term x11\n";
    gp << "set style line 1 lt 1 lc rgb \"black\" lw 2\n";
    gp << "set style fill solid 2.0 noborder\n";

    for(int i = 0; i < ny; i++)
        gp << std::string("set arrow ") + std::to_string(i + 1) + " from " + "0," + std::to_string(i) + " to " + std::to_string(nx - 1) + "," + std::to_string(i) + " nohead ls 1\n";

    for(int i = 0; i < nx; i++)
        gp << std::string("set arrow ") + std::to_string(i + ny + 1) + " from " + std::to_string(i) + ",0 to " + std::to_string(i) + "," + std::to_string(ny - 1) + " nohead ls 1\n";

    std::string col;

    for (int i = 0; i < nx*ny; i++) {
        if(model_ptr->getLattice().getLattice()[i].getSpin().getZ() < 0.0)
            col = "\"navy\"";
        else
            col = "\"red\"";

        int x_coord(model_ptr->getLattice().getLattice()[i].getX());
        int y_coord(model_ptr->getLattice().getLattice()[i].getY());

        gp << "set object " + std::to_string(i+1) + " circle at " + std::to_string(x_coord) + "," + std::to_string(y_coord) + " size first 0.20 fc rgb " + col + " front\n";
    }

//    gp << "plot '-' with points title 'cubic', '-' with points title 'circle'\n";
    gp << "set sample 5000\n";
    gp << "p -4 ls 1 notitle\n";
    gp << "pause -1\n";


//    pause_if_needed();
}