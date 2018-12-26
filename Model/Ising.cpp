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
    double tot_eng = 0.0;
    double J = 1;
    for(auto &m: lat.lat) {
        tot_eng += -J * m.getSpin().dot(m.neighbors[0]->getSpin());
        tot_eng += -J * m.getSpin().dot(m.neighbors[1]->getSpin());
    }
    return tot_eng;
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

Spin Ising::new_spin(){
    return Spin(0.0, 0.0, 2*(std::rand()%2) - 1);
};

void Ising::create_initial_spin_configuration(){
    for (auto &m: lat.lat) {
        m.set_spin(new_spin());
    }
};

void Ising::update_spin_configuration(uword ind, mat n_spin) {
    this->spin_config.row(ind) = n_spin;
}

std::stringstream Ising::save_spin_configuration(int spin_config_number){
    std::stringstream output;

    output << "{\"step\": " << spin_config_number << ", \"data\": [";

    for (int i = 0; i < (system_size) - 1; i++) {
        output << "{\"spin_number\": " << i << "," << "\"x\": " << (spin_config)(i, 0) << "," << "\"y\": "
               << (spin_config)(i, 1) << "," << "\"z\": " << (spin_config)(i, 2) << "}, ";
    }

    output << "{\"spin_number\": " << (system_size) - 1 << "," << "\"x\": "
           << (spin_config)((system_size) - 1, 0) << "," << "\"y\": "
           << (spin_config)((system_size) - 1, 1) << "," << "\"z\": "
           << (spin_config)((system_size) - 1, 2) << "}]}";

    return output;
};

void Ising::create_ferromagnetic_spin_configuration() {
    for (auto &m: lat.lat) {
        m.set_spin(Spin(0.0, 0.0, 1.0));
    }
}