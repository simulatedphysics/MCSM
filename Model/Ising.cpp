//
// Created by solidangle on 10/25/18.
//

#include <random>
#include "Ising.hpp"
#include "../Lattice/Square.hpp"


//Ising::Ising(int system_size) {
//    setSystemSize(system_size);
//};

//Ising::Ising(int nx_in, int ny_in) {}

double Ising::energy(){
    double tot_eng(0.0);
    double J(1.0);
    std::cout << "tot_eng: " << tot_eng << std::endl;
    std::cout << "J: " << J << std::endl;
    for(auto &m: getLattice().getLattice()) {
//        (m.getNeighbors()[0])->print_site();
//        (m.getNeighbors()[1])->print_site();
//        m.getSpin().print_spin();
//        m.getNeighbors()[0]->getSpin().print_spin();
//        (m.getNeighbors()[1])->getSpin().print_spin();
        tot_eng += -J * ((m.getSpin()).dot((m.getNeighbors()[0])->getSpin()));
//        std::cout << "tot_eng: " << tot_eng << std::endl;
        tot_eng += -J * ((m.getSpin()).dot((m.getNeighbors()[1])->getSpin()));
//        std::cout << "tot_eng: " << tot_eng << std::endl;
    }
    return tot_eng;
};

double Ising::energy_change(int ind, Site & lattice_s, Spin & old_s, Spin & new_s){
    double tot_eng = 0.0;
    double J = 1.0;

    Spin spin_difference(new_s - old_s);

    for(auto &m: lattice_s.getNeighbors())
        tot_eng += -J * spin_difference.dot(m->getSpin());

    return tot_eng;
};

//mat Ising::old_spin(){
//    return mat(1,3);
//};

Spin Ising::new_spin(std::mt19937 & a, std::uniform_int_distribution<int> & b){
    return {0.0, 0.0, 2.0*b(a) - 1.0};
};

//void Ising::create_initial_spin_configuration(std::mt19937 & a, std::uniform_int_distribution<int> & b){
//    for (auto &m: getLattice().getLattice()) {
//        Spin s(new_spin(a, b));
//        s.print_spin();
//        m.set_spin(s);
//    }
//};

void Ising::update_spin_configuration(int ind, Spin & n_spin) {
    getLattice().getLattice()[ind].set_spin(n_spin);
}

std::stringstream Ising::save_spin_configuration(int spin_config_number){
    std::stringstream output;

//    output << "{\"step\": " << spin_config_number << ", \"data\": [";
//
//    for (int i = 0; i < (getSystemSize()) - 1; i++) {
//        output << "{\"spin_number\": " << i << "," << "\"x\": " << (spin_config)(i, 0) << "," << "\"y\": "
//               << (spin_config)(i, 1) << "," << "\"z\": " << (spin_config)(i, 2) << "}, ";
//    }
//
//    output << "{\"spin_number\": " << (system_size) - 1 << "," << "\"x\": "
//           << (spin_config)((system_size) - 1, 0) << "," << "\"y\": "
//           << (spin_config)((system_size) - 1, 1) << "," << "\"z\": "
//           << (spin_config)((system_size) - 1, 2) << "}]}";

    return output;
};

void Ising::create_ferromagnetic_spin_configuration() {
    for (auto &m: getLattice().getLattice()) {
        m.set_spin(Spin(0.0, 0.0, 1.0));
    }
}