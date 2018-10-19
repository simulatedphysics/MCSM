//
// Created by Patrick O'Brien on 10/17/18.
//

#include "Square.hpp"

void Square::generate_lattice() {
    this->lat.resize(16);
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            (this->lat)[4*i + j] = Site(j, i, 0);
        }
    }
}