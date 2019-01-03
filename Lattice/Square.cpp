//
// Created by Patrick O'Brien on 10/17/18.
//

#include "Square.hpp"
#include <vector>

void Square::generate_lattice() {
    for (int i = 0; i < get_ny(); i++) {
        for(int j = 0; j < get_nx(); j++) {
            getLattice().emplace_back(Site(j, i, 0));
        }
    }
}

int Square::convert_to_index(int x_, int y_) {
    return get_nx() * y_ + x_;
}

void Square::set_neighbors() {
    std::vector<Site>::pointer a;
    a = &(getLattice().front());
    for(int i = 0; i < get_nx(); i++)
        for (int j =0; j < get_ny(); j++){
            int site_ind(convert_to_index(i , j));
            getLattice()[site_ind].getNeighbors().push_back(a + convert_to_index(i % get_nx(), (j + 1) % get_ny()));
            getLattice()[site_ind].getNeighbors().push_back(a + convert_to_index((i + 1) % get_nx(), j % get_ny()));
            getLattice()[site_ind].getNeighbors().push_back(a + convert_to_index(i % get_nx(), (j - 1 + get_ny()) % get_ny()));
            getLattice()[site_ind].getNeighbors().push_back(a + convert_to_index((i - 1 + get_nx()) % get_nx(), j % get_ny()));
        }
}

void Square::print_neighbors(){
    for (auto &m: getLattice())
        for (auto &n: m.getNeighbors())
            n->print_site();
}