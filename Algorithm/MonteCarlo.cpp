//
// Created by Patrick O'Brien on 9/19/18.
//

#include "MonteCarlo.hpp"
#include "../Model/Model.hpp"
#include <nlohmann/json.hpp>
#include <cmath>
#include "../Plot/MagneticStatePlot.cpp"

using json = nlohmann::json;

double MonteCarlo::boltzmann_factor(double eng_change, double temp) {
    return std::exp(-eng_change/temp);
};

//void MonteCarlo::simulate(int nitr, std::unique_ptr<Model> &model_ptr, double temp) {
//
//}

void MonteCarlo::simulate(const int nitr, std::unique_ptr<Model> & model_ptr, double temp) {
    std::cout << "The system size is: " << model_ptr->getSystemSize() << std::endl;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, model_ptr->getSystemSize() - 1);

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

    demo_basic(model_ptr);

//    std::cout << "The initial spin configuration is: " << std::endl;
//    model_ptr->print_spin_configuration();

    std::cout << "The energy of the initial spin configuration is: " << std::endl;
    std::cout << model_ptr->energy() << std::endl << std::endl;

    int accepted_counter = 0;
//  	output_json["data"].push_back(model_ptr->save_spin_configuration(accepted_counter).str());
//
//  	std::cout << "Inside MC..." << std::endl;

    std::cout << "Monte Carlo simulation is running... " << "(" << nitr << " iterations)" << std::endl << std::endl;

    for (int i = 0; i < nitr; i++) {
        int random_index(dist(mt));
//        std::cout << "The random index is: " << random_index << std::endl;

        Site lattice_site(model_ptr->getLattice().getLattice()[random_index]);
        Spin old_spin_vec(lattice_site.getSpin());
        Spin new_spin_vec(0.0, 0.0, -old_spin_vec.getZ());

//        Spin new_s(model_ptr->new_spin());

//        std::cout << "The old spin is: " << std::endl;
//        old_spin_vec.print_spin();
//        std::cout << "The new spin is: " << std::endl;
//        new_spin_vec.print_spin();

        double change_eng(model_ptr->energy_change(random_index, lattice_site, old_spin_vec, new_spin_vec));

//        std::cout << "The change in energy is: " << change_eng << std::endl;
//        double rand_num(dist2(mt2));

//        if (std::log(rand_num) < -change_eng/temp) {
        if (0.0 > change_eng) {
//            std::cout << "Change was accepted..." << std::endl;
//            std::cout << "Random index: " << random_index << std::endl;
            model_ptr->update_spin_configuration(random_index, new_spin_vec);
//            std::cout << "The spin configuration is:" << std::endl;
//            model_ptr->print_spin_configuration();
            add_to_energy_list(change_eng);
            accepted_counter++;
//		  	output_json["data"].push_back(model_ptr->save_spin_configuration(accepted_counter).str());
        }
    }

    demo_basic(model_ptr);

//    std::cout << "The final spin configuration is: " << std::endl;
//    model_ptr->print_spin_configuration();

    std::cout << "The energy of the final spin configuration is: " << std::endl;
    std::cout << model_ptr->energy() << std::endl << std::endl;
//    output << output_json.dump();
//    output.close();

    std::cout << "The energy list is: " << std::endl;
    print_energy_list();

    std::vector<double> en = get_energy_list();
    double tot_energy = std::accumulate(en.begin(), en.end(), 0.0);

    std::cout << "The total change in energy is: " << tot_energy << std::endl;
}

