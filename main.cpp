#include <iostream>
#include <armadillo>
//#include "Model/Heisenberg.hpp"
#include "Algorithm/MonteCarlo.hpp"
#include "Lattice/Square.hpp"
#include "Lattice/Lattice.hpp"
#include <random>
#include <bits/unique_ptr.h>
#include "Model/Ising.hpp"
#include <memory>
#include <cmath>


using namespace arma;

int main() {
    std::cout << "Phys-sym v. 0.0" << std::endl;
    std::cout << "Simulation software" << std::endl << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl << std::endl;

    std::cout << "Generating Ising model..." << std::endl;
    std::unique_ptr<Model> ising_model_ptr(new Ising(16));

    std::cout << "Generating Monte Carlo algorithm..." << std::endl;
    std::unique_ptr<Algorithm> alg(new MonteCarlo);

    const int n_itr(100000000);
    std::cout << "Monte Carlo simulation is running... " << "(" << n_itr << " iterations)" << std::endl << std::endl;
    alg->simulate(n_itr, ising_model_ptr, 1.0);

    return 0;
}