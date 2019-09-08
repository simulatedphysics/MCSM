//
// Created by Patrick O'Brien on 10/17/18.
//

#include "Square.hpp"
#include <vector>

Square::Square(int nx_in, int ny_in)
{
    set_nx(nx_in);
    set_ny(ny_in);
    set_a1({1.0, 0.0, 0.0});
    set_a2({0.0, 1.0, 0.0});
    set_a3({0.0, 0.0, 1.0});
    generate_lattice();
}

void Square::generate_lattice() {
    for (int i = 0; i < get_ny(); i++) {
        for(int j = 0; j < get_nx(); j++) {
            vec3 siteValue = j*get_a1() + i*get_a2();
            get_lattice().emplace_back(Site(siteValue[0], siteValue[1], 0));
        }
    }
}

int Square::convert_to_index(int x_, int y_) {
    return get_nx() * y_ + x_;
}

void Square::set_neighbors() {
    std::vector<Site>::pointer a;
    a = &(get_lattice().front());
    for(int i = 0; i < get_nx(); i++)
        for (int j =0; j < get_ny(); j++){
            int site_ind(convert_to_index(i , j));
            get_lattice()[site_ind].get_neighbors().push_back(a + convert_to_index(i % get_nx(), (j + 1) % get_ny()));
            get_lattice()[site_ind].get_neighbors().push_back(a + convert_to_index((i + 1) % get_nx(), j % get_ny()));
            get_lattice()[site_ind].get_neighbors().push_back(a + convert_to_index(i % get_nx(), (j - 1 + get_ny()) % get_ny()));
            get_lattice()[site_ind].get_neighbors().push_back(a + convert_to_index((i - 1 + get_nx()) % get_nx(), j % get_ny()));
        }
}

void Square::print_neighbors(){
    for (auto &m: get_lattice())
        for (auto &n: m.get_neighbors())
            n->print_site();
}