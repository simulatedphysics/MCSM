//
// Created by Patrick O'Brien on 10/17/18.
//

#include "Lattice.hpp"

#pragma once
class Square : public Lattice {
public:
    void generate_lattice() override;
//    void find_neighbors() override;
    void find_neighbors() override;
    int convert_to_index(int x_, int y_) override;
};
