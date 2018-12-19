//
// Created by Patrick O'Brien on 9/18/18.
//

#include "Heisenberg.hpp"

mat Heisenberg::create_ferromagnetic_exchange_matrix() {
    this->exchange_matrix = -ones(static_cast<const uword>(this->system_size),
                                  static_cast<const uword>(this->system_size));
    return -ones(this->system_size, this->system_size);
}

Heisenberg::Heisenberg(int system_size) {
    this->system_size = system_size;
    create_ferromagnetic_exchange_matrix();
}

mat Heisenberg::new_spin() {
    return normalise(randu<rowvec>(3));
}

mat Heisenberg::create_initial_spin_configuration() {
    mat spin_configuration(this->system_size, 3);

    for (int i = 0; i < this->system_size; i++) {
        mat ns = new_spin();
        for (int j = 0; j < 3; j++) {
            spin_configuration(i, j) = ns(j);
        }
    }

    this->spin_config = spin_configuration;
    return spin_configuration;
}


double Heisenberg::energy() {
    double eng = 0.0;

    for (int i = 0; i < this->system_size; i++) {
        for (int j = 0; j < this->system_size; j++) {
            for (int k = 0; k < 3; k++) {
                eng += this->exchange_matrix(i, j) * (this->spin_config)(i, k) * (this->spin_config)(j, k);
            }
        }
    }

    return eng;
}

double Heisenberg::energy_change(int ind, mat new_spin_vec) {
    double del_eng = 0.0;

    for (int i = 0; i < this->system_size; i++) {
        for (int k = 0; k < 3; k++) {
            del_eng += 2 * this->exchange_matrix(i, ind) * (new_spin_vec(k) - (this->spin_config)(ind, k)) *
                       (this->spin_config)(i, k);
        }
    }

    for (int k = 0; k < 3; k++) {
        del_eng -= 2 * this->exchange_matrix(ind, ind) * (new_spin_vec(k) - (this->spin_config)(ind, k)) *
                   (this->spin_config)(ind, k);
    }

    return del_eng;
}

imat Heisenberg::choose_random_index() {
    return randi(1, 1, distr_param(1, this->system_size));
}

mat Heisenberg::old_spin() {
//    return (this->spin_config)(randi(1,1, distr_param(+1, +10)), 0);
    return zeros(this->system_size, 3);
}

void Heisenberg::update_spin_configuration(uword ind, mat n_spin) {
    this->spin_config.row(ind) = n_spin;
}

std::stringstream Heisenberg::save_spin_configuration(int spin_config_number) {
    std::stringstream output;

    output << "{\"step\": " << spin_config_number << ", \"data\": [";

    for (int i = 0; i < (this->system_size) - 1; i++) {
        output << "{\"spin_number\": " << i << "," << "\"x\": " << (this->spin_config)(i, 0) << "," << "\"y\": "
               << (this->spin_config)(i, 1) << "," << "\"z\": " << (this->spin_config)(i, 2) << "}, ";
    }

    output << "{\"spin_number\": " << (this->system_size) - 1 << "," << "\"x\": "
           << (this->spin_config)((this->system_size) - 1, 0) << "," << "\"y\": "
           << (this->spin_config)((this->system_size) - 1, 1) << "," << "\"z\": "
           << (this->spin_config)((this->system_size) - 1, 2) << "}]}";

    return output;
}

//mat Heisenberg::create_ferromagnetic_spin_configuration() {
//    return arma::mat();
//}


void Heisenberg::create_ferromagnetic_spin_configuration() {
    mat spin_configuration(10, 3);

    rowvec ns = new_spin();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            spin_configuration(i, j) = ns(j);
        }
    }

    this->spin_config = spin_configuration;
//    return spin_configuration;
}