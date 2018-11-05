//
// Created by Patrick O'Brien on 10/17/18.
//

#include "Square.hpp"
#include <vector>

void Square::generate_lattice() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            lat.push_back(Site(j, i, 0));
        }
    }
}

//void Square::find_neighbors() {
//
//}

int Square::convert_to_index(int x_, int y_) {
    return n_x * y_ + x_;
}

void Square::find_neighbors() {
    std::vector<Site>::pointer a;
    a = &lat.front();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            lat[n_x * j + i].neighbors.push_back(a + convert_to_index(i % n_x, (j + 1) % n_y));
            lat[n_x * j + i].neighbors.push_back(a + convert_to_index((i + 1) % n_x, j % n_y));
        }
}