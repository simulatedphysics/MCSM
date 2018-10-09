//
// Created by Patrick O'Brien on 9/19/18.
//

#include "MonteCarlo.hpp"
#include "../Model/Model.hpp"

void MonteCarlo::simulate(int nitr, Model *model_ptr) {
    std::ofstream output;
    output.open("output.json");
    model_ptr->create_initial_spin_configuration();

    output << R"({"type": "common_origin", "data": [)";

    int accepted_counter = 0;
    output << model_ptr->save_spin_configuration(accepted_counter).str();

    for (int i = 0; i < nitr; i++) {
        uword random_index = randi<umat>(1, 1, distr_param(0, (model_ptr->system_size) - 1))(0);
        mat old = model_ptr->spin_config.row(random_index);
        mat new_s = model_ptr->new_spin();
        double change_eng = model_ptr->energy_change(random_index, new_s);

        if (change_eng < 0.0) {
            output << ", ";
            model_ptr->update_spin_configuration(random_index, new_s);
            accepted_counter++;
            output << model_ptr->save_spin_configuration(accepted_counter).str();
        }
    }

    output << "]}";
    output.close();
}