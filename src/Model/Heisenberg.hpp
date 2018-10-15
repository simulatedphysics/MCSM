//
// Created by Patrick O'Brien on 10/2/18.
//

#ifndef SIMULATION_HEISENBERG_HPP
#define SIMULATION_HEISENBERG_HPP

#include "Model.hpp"

#endif //SIMULATION_HEISENBERG_HPP

class Heisenberg: public Model {
public:
    mat exchange_matrix;
    double energy() override;
    double energy_change(int ind, mat new_spin_vec) override;
    imat choose_random_index() override;
    mat old_spin() override;
    mat new_spin() override;
    mat create_initial_spin_configuration() override;
    mat create_ferromagnetic_exchange_matrix();
    mat create_ferromagnetic_spin_configuration();
    void update_spin_configuration(uword ind, mat n_spin) override;
    std::stringstream save_spin_configuration(int spin_config_number) override;

    explicit Heisenberg(int system_size);
};