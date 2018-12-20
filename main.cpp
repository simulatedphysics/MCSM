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
    std::cout << "-----------------------------------------------------" << std::endl << std::endl;

    std::cout << "Initializing Heisenberg Model..." << std::endl;
    std::shared_ptr<Model> model_ptr(new Heisenberg(10));

    std::cout << "Creating initial spin configuration..." << std::endl;
    model_ptr->create_initial_spin_configuration();

    std::cout << std::endl << "The initial spin configuration is: " << std::endl << model_ptr->spin_config << std::endl;
    std::cout << "The energy of the initial spin configuration is: " << model_ptr->energy() << std::endl << std::endl;

    int n_itr = 10000000;
    std::unique_ptr<Algorithm> alg(new MonteCarlo);

    std::cout << "Monte Carlo simulation is running..." << std::endl << std::endl;
    alg->simulate(n_itr, model_ptr);

    std::cout << "The final spin configuration is: " << std::endl << model_ptr->spin_config << std::endl;
    std::cout << "The energy of the final spin configuration is: " << model_ptr->energy() << std::endl << std::endl;

    std::cout << "Generating lattice..." << std::endl;
    std::unique_ptr<Lattice> lattice_ptr(new Square);

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