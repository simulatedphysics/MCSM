//
// Created by Patrick O'Brien on 10/17/18.
//

#include "Square.hpp"
#include <vector>

void Square::generate_lattice() {
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            lat.push_back(Site(j, i, 0));
        }
    }
}

int Square::convert_to_index(int x_, int y_) {
    return n_x * y_ + x_;
}

void Square::set_neighbors() {
    std::vector<Site>::pointer a;
    a = &lat.front();
    for(int i = 0; i < n_x; i++)
        for (int j =0; j< n_y; j++){
            int site_ind(convert_to_index(i , j));
            lat[site_ind].neighbors.push_back(a + convert_to_index(i % n_x, (j + 1) % n_y));
            lat[site_ind].neighbors.push_back(a + convert_to_index((i + 1) % n_x, j % n_y));
        }
}