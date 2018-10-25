#include <iostream>
#include <armadillo>
//#include "Model/Heisenberg.hpp"
//#include "Algorithm/MonteCarlo.hpp"
#include "Lattice/Square.hpp"
#include "Lattice/Lattice.hpp"
#include <random>
#include "Model/Ising.hpp"

using namespace arma;

int main() {
    std::cout << "Phys-sym v. 0.0" << std::endl;
    std::cout << "Simulation software" << std::endl << std::endl;

//    Model *model_ptr;
//    Heisenberg heisenberg(10);
//    model_ptr = &heisenberg;
//
//    heisenberg.create_ferromagnetic_exchange_matrix();
//    model_ptr->create_initial_spin_configuration();
//    std::cout << "The spin configuration is: " << std::endl << model_ptr->spin_config << std::endl;
//    std::cout << "The energy of the system is: " << model_ptr->energy() << std::endl;
//
//    int n_itr = 10000;
//    Algorithm *alg;
//    MonteCarlo mc;
//    alg = &mc;
//    alg->simulate(n_itr, model_ptr);
//
//    std::cout << "The spin configuration is: " << std::endl << model_ptr->spin_config << std::endl;
//    std::cout << "The energy of the system is: " << model_ptr->energy() << std::endl;

    Lattice *lattice_ptr;
    Square square;
    lattice_ptr = &square;
    lattice_ptr->generate_lattice();
    Site s((lattice_ptr->lat)[5]);

    Site *s_ptr = &s;

    lattice_ptr->print_lattice();

    lattice_ptr->find_neighbor_indices(0, 0);
    (*((lattice_ptr->lat)[0].neighbors[0])).print_site();
    (*((lattice_ptr->lat)[0].neighbors[1])).print_site();

    Model *model_ptr;
    Ising ising;
    model_ptr = &ising;

    for (int i = 0; i < 15; i++)
        std::cout << "New spin: " << model_ptr->new_spin() << std::endl;

    return 0;
}