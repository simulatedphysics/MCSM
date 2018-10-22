//
// Created by Patrick O'Brien on 10/17/18.
//

#include "Square.hpp"

void Square::generate_lattice() {
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            lat.push_back(Site(j, i, 0));
        }
    }
}