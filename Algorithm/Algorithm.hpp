//
// Created by Patrick O'Brien on 9/19/18.
//

#include "../Model/Model.hpp"
#include <armadillo>
#include <memory>

using namespace arma;

class Algorithm {
public:
    virtual void simulate(int nitr, std::shared_ptr<Model> & model_ptr)=0;
};