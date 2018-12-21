//
// Created by Patrick O'Brien on 10/2/18.
//

#include "Model.hpp"

class Heisenberg : public Model {
public:
//    mat exchange_matrix;

    double energy() override;

    double energy_change(int ind, mat new_spin_vec) override;

//    imat choose_random_index() override;

    mat old_spin() override;

    mat new_spin() override;

    void create_initial_spin_configuration() override;

    mat create_ferromagnetic_exchange_matrix();

    void create_ferromagnetic_spin_configuration() override;

    void update_spin_configuration(uword ind, mat n_spin) override;

    std::stringstream save_spin_configuration(int spin_config_number) override;

    explicit Heisenberg(int system_size);
};