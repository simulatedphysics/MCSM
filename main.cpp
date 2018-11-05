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

    Lattice *lattice_ptr;
    Square square;
    lattice_ptr = &square;
    lattice_ptr->generate_lattice();
    Site s((lattice_ptr->lat)[5]);

    Site *s_ptr = &s;

    std::cout << "B1" << std::endl;

//    lattice_ptr->print_lattice();

//    std::cout << (*((lattice_ptr->lat)[7].neighbors[0])).x << std::endl;

    Model *model_ptr;
    Ising ising(16);
    model_ptr = &ising;

    std::cout << "B2" << std::endl;

    model_ptr->create_initial_spin_configuration();
//    std::cout << model_ptr->spin_config << std::endl;

    std::cout << "First spin:" << model_ptr->spin_config.row(0);
    std::cout << "Second spin:" << model_ptr->spin_config.row(1);
    std::cout << "Dot product:" << dot(model_ptr->spin_config.row(0), model_ptr->spin_config.row(1)) << std::endl;

    std::cout << "Energy: " << model_ptr->energy() << std::endl;

    return 0;
}