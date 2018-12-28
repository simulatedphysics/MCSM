//
// Created by Patrick O'Brien on 10/2/18.
//

#include "Algorithm.hpp"
#include "../Model/Model.hpp"

class MonteCarlo : public Algorithm {
private:
    double temperature = 1.0;
public:
    double boltzmann_factor(double eng_change, double temp);
    void simulate(const int nitr, std::unique_ptr<Model> & model_ptr, double temp) override;
};