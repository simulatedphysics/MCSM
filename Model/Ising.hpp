//
// Created by solidangle on 10/25/18.
//

#include "Model.hpp"

class Ising : public Model {
public:
    explicit Ising(int system_size);

    double energy() override;

    double energy_change(int ind, Site & lattice_s, Spin & old_s, Spin & new_s) override;

//    imat choose_random_index() override;

    mat old_spin() override;

    Spin new_spin(std::mt19937 & a, std::uniform_int_distribution<int> & b) override;

    void create_initial_spin_configuration(std::mt19937 & a, std::uniform_int_distribution<int> & b) override;

    void create_ferromagnetic_spin_configuration() override;

    void update_spin_configuration(uword ind, mat n_spin) override;

    std::stringstream save_spin_configuration(int spin_config_number) override;
};