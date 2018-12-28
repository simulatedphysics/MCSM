//
// Created by Patrick O'Brien on 9/19/18.
//

#include "MonteCarlo.hpp"
#include "../Model/Model.hpp"
#include <nlohmann/json.hpp>
#include <cmath>

using json = nlohmann::json;

void MonteCarlo::simulate(int nitr,  std::shared_ptr<Model> & model_ptr) {
    std::ofstream output;
    output.open("output.json");

    json output_json = {
		{"type", "common_origin"}, {"data", {} }
	};

    model_ptr->create_initial_spin_configuration();


    int accepted_counter = 0;
  	output_json["data"].push_back(model_ptr->save_spin_configuration(accepted_counter).str());

    for (int i = 0; i < nitr; i++) {
        uword random_index = static_cast<uword>(randi<umat>(1, 1, distr_param(0, (model_ptr->system_size) - 1))(0));
        mat old = model_ptr->spin_config.row(random_index);
        Spin new_s = model_ptr->new_spin();
        double change_eng = model_ptr->energy_change(static_cast<int>(random_index), new_s);

        if (change_eng < 0.0) {
            model_ptr->update_spin_configuration(random_index, new_s);
            accepted_counter++;
		  	output_json["data"].push_back(model_ptr->save_spin_configuration(accepted_counter).str());
        }
    }
    
    output << output_json.dump();
    output.close();
}