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

//void Square::find_neighbors() {
//
//}

int Square::convert_to_index(int x_, int y_) {
    return n_x * y_ + x_;
}

//void Square::find_neighbor_indices(int x_, int y_) {
//    std::vector<Site>::iterator a = lat.begin();
//    lat[0].neighbors.push_back(a + convert_to_index((x_ + 1) % n_x, (y_ + 1) % n_y));
//}