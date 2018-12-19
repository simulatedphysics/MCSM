#include <iostream>
#include <armadillo>
#include "Model/Heisenberg.hpp"
#include "Algorithm/MonteCarlo.hpp"
#include "Lattice/Square.hpp"
#include "Lattice/Lattice.hpp"
#include <random>
#include <bits/unique_ptr.h>
#include "Model/Ising.hpp"
#include <memory>

using namespace arma;

int main() {
    std::cout << "Phys-sym v. 0.0" << std::endl;
    std::cout << "Simulation software" << std::endl << std::endl;

    std::unique_ptr<Model> model_ptr(new Heisenberg(10));

    std::cout << (model_ptr -> new_spin()) << std::endl;
    model_ptr->create_ferromagnetic_spin_configuration();
//    model_ptr->create_initial_spin_configuration();
    std::cout << "The spin configuration is: " << std::endl << model_ptr->spin_config << std::endl;
//    std::cout << "The energy of the system is: " << model_ptr->energy() << std::endl;
//
//    int n_itr = 10000;
//    std::unique_ptr<Algorithm> alg;
//    MonteCarlo mc;
//    alg = &mc;
//    alg->simulate(n_itr, model_ptr);
//
//    std::cout << "The spin configuration is: " << std::endl << model_ptr->spin_config << std::endl;
//    std::cout << "The energy of the system is: " << model_ptr->energy() << std::endl;

//    Square square;
    std::unique_ptr<Lattice> lattice_ptr(new Square);

//    lattice_ptr->generate_lattice();
//    Site s((lattice_ptr->lat)[5]);
//
//    Site *s_ptr = &s;

    lattice_ptr->print_lattice();

    lattice_ptr->find_neighbor_indices(0, 0);
    (*((lattice_ptr->lat)[0].neighbors[1])).print_site();
//
//    std::unique_ptr<Model> model_ptr(new Ising(16));
//
//    model_ptr->create_initial_spin_configuration();
//    std::cout << model_ptr->spin_config << std::endl;

    return 0;
}