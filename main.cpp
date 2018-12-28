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

//    std::cout << "Generating initial spin configuration..." << std::endl;
//    ising_model_ptr->create_initial_spin_configuration();

//    std::cout << "Printing lattice..." << std::endl;
//    ising_model_ptr->getLattice().print_lattice();

//    std::cout << std::endl << "The initial Ising spin configuration is: " << std::endl;
//    ising_model_ptr -> print_spin_configuration();

//    std::cout << "The system size is: " << ising_model_ptr->getSystemSize() << std::endl;

//    std::cout << "The energy of the initial spin configuration is: " << std::endl;
//    std::cout << ising_model_ptr->energy() << std::endl << std::endl;
//    ising_model_ptr->getLattice().getLattice()[0].print_site();
//    ising_model_ptr->getLattice().getLattice()[0].getSpin().print_spin();
//    ising_model_ptr->getLattice().getLattice()[1].getSpin().print_spin();

//    std::cout << "Initializing Heisenberg Model..." << std::endl;
//    std::shared_ptr<Model> model_ptr(new Heisenberg(10));

//    std::cout << "Creating initial spin configuration..." << std::endl;
//    model_ptr->create_initial_spin_configuration();

//    std::cout << std::endl << "The initial spin configuration is: " << std::endl << model_ptr->spin_config << std::endl;
//    std::cout << "The energy of the initial spin configuration is: " << model_ptr->energy() << std::endl << std::endl;

    std::unique_ptr<Algorithm> alg(new MonteCarlo);

    const int n_itr(100000000);
    std::cout << "Monte Carlo simulation is running... " << "(" << n_itr << " iterations)" << std::endl << std::endl;
    alg->simulate(n_itr, ising_model_ptr, 1.0);

//    std::cout << std::endl << "The final Ising spin configuration is: " << std::endl;
//    ising_model_ptr -> print_spin_configuration();
//
//    std::cout << "The energy of the final spin configuration is: " << std::endl;
//    std::cout << ising_model_ptr->energy() << std::endl;

//    std::cout << "The final spin configuration is: " << std::endl << model_ptr->spin_config << std::endl;
//    std::cout << "The energy of the final spin configuration is: " << model_ptr->energy() << std::endl << std::endl;
//
//    std::cout << "Generating lattice..." << std::endl;
//    std::unique_ptr<Lattice> lattice_ptr(new Square);
//

    return 0;
}