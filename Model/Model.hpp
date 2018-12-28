//
// Created by Patrick O'Brien on 9/18/18.
//

#include <armadillo>
#include <fstream>
#include <bits/unique_ptr.h>
#include "../Lattice/Square.hpp"

using namespace arma;

#pragma once

class Model {
private:
    int system_size;
    mat spin_config;
    mat exchange_matrix;
    Square lat;
public:
    virtual double energy() = 0;

    virtual double energy_change(int ind, Site & lattice_s, Spin & old_s, Spin & new_s) = 0;

//    virtual imat choose_random_index() = 0;

    virtual mat old_spin() = 0;

    virtual Spin new_spin(std::mt19937 & a, std::uniform_int_distribution<int> & b) = 0;

    Square & getLattice(){return lat;};

    virtual void create_initial_spin_configuration(std::mt19937 & a, std::uniform_int_distribution<int> & b) = 0;

    void print_spin_configuration(){for(auto &m: lat.getLattice()){m.getSpin().print_spin();} std::cout << std::endl;};

    void setSystemSize(int sys){system_size = sys;};

    int getSystemSize(){return system_size;};

    virtual void update_spin_configuration(int ind, Spin & n_spin) = 0;

    virtual std::stringstream save_spin_configuration(int spin_config_number) = 0;

    virtual void create_ferromagnetic_spin_configuration() = 0;
};