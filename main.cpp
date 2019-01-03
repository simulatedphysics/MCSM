#include <iostream>
#include <cmath>
#include <memory>
#include <random>
#include <bits/unique_ptr.h>
#include <armadillo>

//#include "Model/Heisenberg.hpp"
#include "Algorithm/MonteCarlo.hpp"
#include "Lattice/Square.hpp"
#include "Lattice/Lattice.hpp"
#include "Model/Ising.hpp"

using namespace arma;

int main(int argc, char **argv) {
    std::cout << "Phys-sym v. 0.0" << std::endl;
    std::cout << "Simulation software" << std::endl << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl << std::endl;

//    std::cout << "Generating Ising model..." << std::endl;
//    std::unique_ptr<Model> ising_model_ptr(new Ising(16));

//    demo_basic(ising_model_ptr);

    int n_x_in = 20;
    int n_y_in = 20;

//    std::cout << "Enter number of unit cells in the x-direction: " <<std::endl;
//    std::cin >> n_x_in;

    Square a(n_x_in, n_y_in);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    std::unique_ptr<Model> is(new Ising(a, n_x_in * n_y_in));
//    is->getLattice().print_lattice();
//    is->getLattice().print_neighbors();
//    is->print_spin_configuration();
    is->new_spin(mt, dist).print_spin();

    is->create_initial_spin_configuration(mt, dist);
    is->getLattice().set_neighbors();
//    std::cout << "The spin configuration of the Ising Model is: " << std::endl;
//    is->print_spin_configuration();
    std::cout << "The energy of the Ising Model is: " << is->energy() << std::endl;
//    is->getLattice().getLattice()[0].getNeighbors()[0]->getSpin().print_spin();
//
//    is->getLattice().print_neighbors();
//
//    a.getLattice()[0].getNeighbors()[0]->getSpin().print_spin();

//    demo_basic(is);

//    is->new_spin(mt, dist).print_spin();
//
//    is->create_initial_spin_configuration(mt, dist);
//    is->getLattice().set_neighbors();

    std::cout << "Generating Monte Carlo algorithm..." << std::endl;
    std::unique_ptr<Algorithm> alg(new MonteCarlo);

    const int n_itr(1000000);
    alg->simulate(n_itr, is, 1.0);

    return 0;
}