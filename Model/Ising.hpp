//
// Created by solidangle on 10/25/18.
//

#include "Model.hpp"

class Ising : public Model {
public:
//    explicit Ising(int system_size);

    double energy() override;

    double energy_change(int ind, Site & lattice_s, Spin & old_s, Spin & new_s) override;

//    mat old_spin() override;

    Spin new_spin(std::mt19937 & a, std::uniform_int_distribution<int> & b) override;

//    void create_initial_spin_configuration(std::mt19937 & a, std::uniform_int_distribution<int> & b) override;

    void create_ferromagnetic_spin_configuration() override;

    void update_spin_configuration(int ind, Spin & n_spin) override;

    std::stringstream save_spin_configuration(int spin_config_number) override;

//    Ising(Square & sq_lat, int sys_size):Model(sq_lat, sys_size){set_lattice(sq_lat); setSystemSize(sys_size);};
    Ising(Square & sq_lat, int sys_size):Model(sq_lat, sys_size){set_lattice(sq_lat); setSystemSize(sys_size);};


};