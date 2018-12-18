//
// Created by Patrick O'Brien on 9/19/18.
//

#include "../Model/Model.hpp"
#include <armadillo>

using namespace arma;

class Algorithm {
public:
    virtual void simulate(int nitr)=0; //, Model *model_ptr)=0;
};