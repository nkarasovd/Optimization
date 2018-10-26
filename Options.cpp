//
// Created by Николай Карасов on 03/10/2018.
//
#include <stdexcept>
#include "Options.h"

/*====================================================================================================================*/

Options::Options(double _delta, int _iteration, double _epsilon) {
    if (_iteration < 1) {
        throw std::invalid_argument("Error! iterations > 0");
    }
    index = 0;
    max_iter = _iteration;
    delta = _delta;
    epsilon = _epsilon;
}

int Options::get_max_iter() const {
    return max_iter;
}

double Options::get_delta() const {
    return delta;
}

double Options::get_epsilon() const {
    return epsilon;
}

int Options::get_last_iter() const {
    return last_iter;
}

void Options::set_last_iter(int _iter) {
    last_iter = _iter;
}

void Options::set_x_k(std::vector<double> &_v) {
    if (index == 0) {
        x_k = _v;

    } else {
        x_k_Plus_j = _v;
    }
    ++index;
    index %= 2;
}

std::vector<double> &Options::get_x_k() {
    return x_k;
}

std::vector<double> &Options::get_x_k_Plus_j() {
    return x_k_Plus_j;
}

/*====================================================================================================================*/