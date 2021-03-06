//
// Created by Николай Карасов on 03/10/2018.
//
#include <stdexcept>
#include "Options.h"

/*====================================================================================================================*/

Options::Options(int _iteration) {
    index = 0;
    max_iter = _iteration;
}

Options::Options(double _epsilon) {
    index = 0;
    epsilon = _epsilon;
}

int Options::get_max_iter() const {
    return max_iter;
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

int Options::getMax_iter_after() const {
    return max_iter_after;
}

void Options::setMax_iter_after(int max_iter_after) {
    Options::max_iter_after = max_iter_after;
}

/*====================================================================================================================*/