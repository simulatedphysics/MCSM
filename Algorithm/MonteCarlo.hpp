//
// Created by Patrick O'Brien on 10/2/18.
//

#include "Algorithm.hpp"
#include "../Model/Model.hpp"

class MonteCarlo : public Algorithm {
public:
    void simulate(int nitr, std::shared_ptr<Model> & model_ptr) override;
};