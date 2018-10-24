//
// Created by Николай Карасов on 02/10/2018.
//
#include "Area.h"

/*====================================================================================================================*/

const int Rectangle::get_dim() {
    return dim;
}

Rectangle::~Rectangle() {
    dim = 0;
}

const double Rectangle::get_left(int i) {
    if (i < 0 || i > dim - 1) {
        throw std::invalid_argument("Error! 0 <= i <= " + (dim - 1));
    }
    return left_border[i];
}

const double Rectangle::get_right(int i) {
    if (i < 0 || i > dim - 1) {
        throw std::invalid_argument("Error! 0 <= i <= " + (dim - 1));
    }
    return right_border[i];
}

Rectangle::Rectangle(std::vector<double> &l, std::vector<double> &r, int d) {
    dim = d;
    left_border = l;
    right_border = r;
}

Rectangle::Rectangle(std::vector<double> &l, std::vector<double> &r, std::vector<double> &y_n,
                     int d, double delta) {
    dim = d;
    for (int i = 0; i < dim; ++i) {
        if ((y_n[i] - delta) < l[i]) {
            left_border.push_back(l[i]);
        } else {
            left_border.push_back(y_n[i] - delta);
        }
        if ((y_n[i] + delta) > r[i]) {
            right_border.push_back(r[i]);
        } else {
            right_border.push_back(y_n[i] + delta);
        }
    }
}

std::vector<double> &Rectangle::get_left() {
    return left_border;
}

std::vector<double> &Rectangle::get_right() {
    return right_border;
}

/*====================================================================================================================*/