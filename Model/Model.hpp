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
public:
    int system_size;
    mat spin_config;
    mat exchange_matrix;
    Square lat;

    virtual double energy() = 0;

    virtual double energy_change(int ind, mat new_spin_vec) = 0;

//    virtual imat choose_random_index() = 0;

    virtual mat old_spin() = 0;

    virtual mat new_spin() = 0;

    virtual void create_initial_spin_configuration() = 0;

    void print_spin_configuration(){std::cout << spin_config << std::endl;};

    virtual void update_spin_configuration(uword ind, mat n_spin) = 0;

    virtual std::stringstream save_spin_configuration(int spin_config_number) = 0;

    virtual void create_ferromagnetic_spin_configuration() = 0;
};