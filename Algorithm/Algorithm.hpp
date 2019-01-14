//
// Created by Patrick O'Brien on 9/19/18.
//

#include "../Model/Model.hpp"
#include <armadillo>
#include <memory>

using namespace arma;

class Algorithm {
public:
    virtual void simulate(const int nitr, std::unique_ptr<Model> & model_ptr, double temp, std::vector<double> &) = 0;
};