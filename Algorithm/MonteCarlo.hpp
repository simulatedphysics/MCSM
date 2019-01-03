//
// Created by Patrick O'Brien on 10/2/18.
//

#include "Algorithm.hpp"
#include "../Model/Model.hpp"

class MonteCarlo : public Algorithm {
private:
    double temperature = 1.0;
    std::vector<double> energy_changes;
public:
    double boltzmann_factor(double eng_change, double temp);
    void simulate(const int nitr, std::unique_ptr<Model> & model_ptr, double temp) override;
    void add_to_energy_list(double eng){energy_changes.emplace_back(eng);}
    void print_energy_list(){for(auto &m: energy_changes) std::cout << m << std::endl;}
    std::vector<double> get_energy_list(){return energy_changes;}
};