//
// Created by Patrick O'Brien on 10/2/18.
//

#ifndef SIMULATION_MONTECARLO_HPP
#define SIMULATION_MONTECARLO_HPP

#include "Algorithm.hpp"
#include "../Model/Model.hpp"

#endif //SIMULATION_MONTECARLO_HPP

class MonteCarlo: public Algorithm{
public:
    void simulate(int nitr, Model *model_ptr) override;
};