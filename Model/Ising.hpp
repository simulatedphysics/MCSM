//
// Created by solidangle on 10/25/18.
//

#include "Model.hpp"

class Ising : public Model {
    double energy() override;

    double energy_change(int ind, mat new_spin_vec) override;

    imat choose_random_index() override;

    mat old_spin() override;

    mat new_spin() override;

    mat create_initial_spin_configuration() override;

    void update_spin_configuration(uword ind, mat n_spin) override;

    std::stringstream save_spin_configuration(int spin_config_number) override;
};