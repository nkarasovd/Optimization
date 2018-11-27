//
// Created by Николай Карасов on 02/10/2018.
//
#include <stdexcept>
#include <vector>
#include <iostream>
#include "Optimization.h"

/*====================================================================================================================*/

/*
 * Functions of Optimization class.
 */

Optimization::Optimization() {
    std::random_device rd;
    std::mt19937 mt(rd());
    _generate = mt;
    std::uniform_real_distribution<> d(0, 1);
    _dist = d;
}


std::vector<double>
Optimization::optimizationRandomSearch(Function *function, Rectangle &rectangle, Stop *stop, Options *options,
                                       double p) {
    int dim = function->get_dim();

    std::vector<double> y_0(dim);
    y_0 = rand_vector(rectangle);
    std::vector<double> y_n(dim);
    y_n = rand_vector(rectangle);

    std::vector<double> curr_pos(dim);

    int last_iter = 0;
    options->set_last_iter(last_iter);

    double delta = rectangle.get_delta();

    while (stop->criterion(count_iter, function, options)) {
        ++this->count_iter;
        double q = _dist(_generate);

        if (q >= p) {
            Rectangle new_rectangle(rectangle.get_left(), rectangle.get_right(), y_n, dim, delta);
            curr_pos = rand_vector(new_rectangle);
        } else {
            curr_pos = rand_vector(rectangle);
        }
        if (function->get_value(curr_pos) < function->get_value(y_n)) {
            last_iter = 0;
            options->set_x_k(curr_pos);
            y_n = curr_pos;
            if (q >= p) {
                delta *= 0.7;
            }
        } else {
            ++last_iter;
        }
        options->set_last_iter(last_iter);
    }
    return y_n;
}


std::vector<double> Optimization::rand_vector(Rectangle &rectangle) {
    int dim = rectangle.get_dim();
    std::vector<double> point(dim);
    for (int i = 0; i < dim; ++i) {
        point[i] = (rectangle.get_right(i) - rectangle.get_left(i)) * _dist(_generate) + rectangle.get_left(i);
    }
    return point;
}


/*====================================================================================================================*/

std::vector<double>
Optimization::optimizationNewton(std::vector<double> &point, Function *function, Stop *stop, Options *options,
                                 Rectangle &rectangle) {
    int dim = function->get_dim();
    int last_iter = 0;
    options->set_last_iter(last_iter);

    VectorXd last_v(dim);
    VectorXd cur_v(dim);
    VectorXd dir(dim);
    std::vector<double> p_cur(dim);

    last_v = copy(last_v, point);

    while (stop->criterion(count_iter, function, options)) {

        ++this->count_iter;

        dir = function->Hessian(last_v).colPivHouseholderQr().solve(function->Gradient(last_v));
        cur_v = last_v - dir;


        while (!(rectangle.is_in(cur_v))) {
            dir = dir / 2;
            cur_v = last_v - dir;
        }

        point = copy(point, last_v);

        p_cur = copy(p_cur, cur_v);

        while (function->get_value(p_cur) > function->get_value(point)) {
            dir = dir / 2;
            cur_v = last_v - dir;
            point = copy(point, last_v);

            p_cur = copy(p_cur, cur_v);
        }

        point = copy(point, last_v);

        p_cur = copy(p_cur, cur_v);

        if (function->get_value(p_cur) < function->get_value(point)) {
            options->set_x_k(p_cur);
            last_iter = 0;
        } else {
            ++last_iter;
        }
        options->set_last_iter(last_iter);
        last_v = cur_v;
    }
    point = copy(point, last_v);

    return point;
}

std::vector<double> Optimization::copy(std::vector<double> &v, VectorXd &x) {

    for (int i = 0; i < x.size(); ++i) {
        v[i] = x(i);
    }
    return v;
}

VectorXd Optimization::copy(VectorXd &x, std::vector<double> &v) {
    for (int i = 0; i < x.size(); ++i) {
        x(i) = v[i];
    }
    return x;
}

int Optimization::getCount_iter() const {
    return count_iter;
}
