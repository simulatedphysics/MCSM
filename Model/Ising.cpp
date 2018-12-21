//
// Created by solidangle on 10/25/18.
//

#include <random>
#include "Ising.hpp"
#include "../Lattice/Square.hpp"


Ising::Ising(int system_size) {
    this->system_size = system_size;
}

double Ising::energy(){
    return 0.0;
};

double Ising::energy_change(int ind, mat new_spin_vec){
    std::cout << new_spin_vec << std::endl;
    return ind*0.0;
};

//imat Ising::choose_random_index(){
//    return imat(3,3);
//};

mat Ising::old_spin(){
    return mat(1,3);
};

mat Ising::new_spin(){
    mat s = zeros(1, 3);
    s(0, 2) = 2*(std::rand()%2) - 1;
    return s;
};

void Ising::create_initial_spin_configuration(){
    mat spin_configuration(this->system_size, 3);

    for (int i = 0; i < this->system_size; i++) {
        mat ns = new_spin();
        for (int j = 0; j < 3; j++) {
            spin_configuration(i, j) = ns(j);
        }
    }

    this->spin_config = spin_configuration;
};

void Ising::update_spin_configuration(uword ind, mat n_spin) {
    this->spin_config.row(ind) = n_spin;
}

std::stringstream Ising::save_spin_configuration(int spin_config_number){
    std::stringstream output;

    output << "{\"step\": " << spin_config_number << ", \"data\": [";

    for (int i = 0; i < (this->system_size) - 1; i++) {
        output << "{\"spin_number\": " << i << "," << "\"x\": " << (this->spin_config)(i, 0) << "," << "\"y\": "
               << (this->spin_config)(i, 1) << "," << "\"z\": " << (this->spin_config)(i, 2) << "}, ";
    }

    output << "{\"spin_number\": " << (this->system_size) - 1 << "," << "\"x\": "
           << (this->spin_config)((this->system_size) - 1, 0) << "," << "\"y\": "
           << (this->spin_config)((this->system_size) - 1, 1) << "," << "\"z\": "
           << (this->spin_config)((this->system_size) - 1, 2) << "}]}";

    return output;
};

void Ising::create_ferromagnetic_spin_configuration() {
    mat spin_configuration(10, 3);

    rowvec ns = new_spin();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            spin_configuration(i, j) = ns(j);
        }
    }

    spin_config = spin_configuration;
}