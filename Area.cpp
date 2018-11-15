//
// Created by Николай Карасов on 02/10/2018.
//
#include "Area.h"

/*====================================================================================================================*/

Rectangle::~Rectangle() {
    dim = 0;
}

Rectangle::Rectangle(std::vector<double> &l, std::vector<double> &r, int _dim) {
    dim = _dim;
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

const int Rectangle::get_dim() {
    return dim;
}

const double Rectangle::get_left(int i) {
    return left_border[i];
}

const double Rectangle::get_right(int i) {
    return right_border[i];
}

std::vector<double> &Rectangle::get_left() {
    return left_border;
}

std::vector<double> &Rectangle::get_right() {
    return right_border;
}

double Rectangle::get_delta() const {
    return delta;
}

void Rectangle::set_delta(double delta) {
    Rectangle::delta = delta;
}

bool const Rectangle::is_in(VectorXd &V) {
    for (int i = 0; i < dim; ++i) {
        if (!(left_border[i] <= V(i) && V(i) <= right_border[i])) {
            return false;
        }
    }
    return true;
}

/*====================================================================================================================*/
