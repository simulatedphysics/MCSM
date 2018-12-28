//
// Created by Patrick O'Brien on 9/19/18.
//

#include "MonteCarlo.hpp"
#include "../Model/Model.hpp"
#include <nlohmann/json.hpp>
#include <cmath>

using json = nlohmann::json;

double MonteCarlo::boltzmann_factor(double eng_change, double temp) {
    return std::exp(-eng_change/temp);
};

//void MonteCarlo::simulate(int nitr, std::unique_ptr<Model> &model_ptr, double temp) {
//
//}

void MonteCarlo::simulate(const int nitr, std::unique_ptr<Model> & model_ptr, double temp) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 15);

    std::random_device rd3;
    std::mt19937 mt3(rd3());
    std::uniform_int_distribution<int> dist3(0, 1);

//    std::ofstream output;
//    output.open("output.json");
//
//    json output_json = {
//		{"type", "common_origin"}, {"data", {} }
//	};

    model_ptr->create_initial_spin_configuration(mt3, dist3);


    int accepted_counter = 0;
  	output_json["data"].push_back(model_ptr->save_spin_configuration(accepted_counter).str());

    for (int i = 0; i < nitr; i++) {
        int random_index(dist(mt));
//        std::cout << "The random index is: " << random_index << std::endl;

        Site lattice_site(model_ptr->getLattice().getLattice()[random_index]);
        Spin old_spin_vec(lattice_site.getSpin());
        Spin new_spin_vec(0.0, 0.0, -old_spin_vec.getZ());

        if (change_eng < 0.0) {
            model_ptr->update_spin_configuration(random_index, new_s);
            accepted_counter++;
		  	output_json["data"].push_back(model_ptr->save_spin_configuration(accepted_counter).str());
        }
    }
    
    output << output_json.dump();
    output.close();
}