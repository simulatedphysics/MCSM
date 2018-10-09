//
// Created by Patrick O'Brien on 9/19/18.
//

#ifndef SIMULATION_ALGORITHM_HPP
#define SIMULATION_ALGORITHM_HPP

#include "../Model/Model.hpp"
#include <armadillo>
using namespace arma;

#endif //SIMULATION_ALGORITHM_HPP


class Algorithm{
public:
    virtual void simulate(int nitr, Model *model_ptr)=0;
};