#include <iostream>
#include <armadillo>
#include "Model/Heisenberg.hpp"
#include "Algorithm/MonteCarlo.hpp"

using namespace arma;

int main() {
    std::cout << "Phys-sym v. 0.0" << std::endl;
    std::cout << "Simulation software" << std::endl << std::endl;

    Model *model_ptr;
    Heisenberg heisenberg(10);
    model_ptr = &heisenberg;

    heisenberg.create_ferromagnetic_exchange_matrix();
    model_ptr -> create_initial_spin_configuration();
    std::cout << "The spin configuration is: " << std::endl << model_ptr -> spin_config << std::endl;
    std::cout << "The energy of the system is: " << model_ptr->energy() << std::endl;

    int n_itr = 10000;
    Algorithm *alg;
    MonteCarlo mc;
    alg = &mc;
    alg->simulate(n_itr, model_ptr);

    std::cout << "The spin configuration is: " << std::endl << model_ptr -> spin_config << std::endl;
    std::cout << "The energy of the system is: " << model_ptr->energy() << std::endl;

    return 0;
}