//
// Created by Patrick O'Brien on 9/7/19.
//

#include "Lattice.hpp"

#pragma once
class Triangular : public Lattice {
public:
    void generate_lattice() override;
    void set_neighbors() override;
    int convert_to_index(int x_, int y_) override;
    Triangular(int nx_in, int ny_in);
    Triangular() = default;
    void print_neighbors();
};
