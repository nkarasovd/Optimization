//
// Created by Николай Карасов on 02/10/2018.
//
#include <stdexcept>
#include <vector>
#include <iostream>
#include "Optimization.h"

/*====================================================================================================================*/

/*
 * Functions of RandomSearch class.
 */

const char *RandomSearch::get_name() {
    return "Random Search --- number 1";
}

RandomSearch::RandomSearch(double p) {
    this->set_p(p);
    std::random_device rd;
    std::mt19937 mt(rd());
    _generate = mt;
    std::uniform_real_distribution<> d(0, 1);
    _dist = d;
}

RandomSearch::~RandomSearch() {
    p = 0;
}

const double RandomSearch::get_p() {
    return p;
}

std::vector<double>
RandomSearch::optimization(Function &function, Rectangle &rectangle, Stop &stop, Options &options) {
    int dim = function.get_dim();

    std::vector<double> y_0(dim);
    y_0 = rand_vector(rectangle);
    std::vector<double> y_n(dim);
    y_n = rand_vector(rectangle);

    std::vector<double> curr_pos(dim);

    int last_iter = 0;
    options.set_last_iter(last_iter);

    double delta = rectangle.get_delta();

    while (stop.criterion(count_iter, function, options)) {
        ++this->count_iter;
        double q = _dist(_generate);

        if (q >= p) {
            Rectangle new_rectangle(rectangle.get_left(), rectangle.get_right(), y_n, dim, delta);
            curr_pos = rand_vector(new_rectangle);
        } else {
            curr_pos = rand_vector(rectangle);
        }
        if (function.get_value(curr_pos) < function.get_value(y_n)) {
            last_iter = 0;
            options.set_last_iter(last_iter);
            options.set_x_k(curr_pos);
            y_n = curr_pos;
            if (q >= p) {
                delta *= 0.7;
            }
        } else {
            ++last_iter;
            options.set_last_iter(last_iter);
        }
    }
    return y_n;
}


std::vector<double> RandomSearch::rand_vector(Rectangle &rectangle) {
    int dim = rectangle.get_dim();
    std::vector<double> point(dim);
    for (int i = 0; i < dim; ++i) {
        point[i] = (rectangle.get_right(i) - rectangle.get_left(i)) * _dist(_generate) + rectangle.get_left(i);
    }
    return point;
}

void RandomSearch::set_p(double prob) {
    p = prob;
}

/*====================================================================================================================*/
NewtonByDirection::NewtonByDirection(const std::vector<double> &_x_0) {
    this->x_0 = _x_0;
}

std::vector<double>
NewtonByDirection::optimization(std::vector<double> &point, Function &function, Stop &stop, Options &options) {
    int dim = function.get_dim();
    int last_iter = 0;
    options.set_last_iter(last_iter);

    VectorXd last_v(dim);

    VectorXd cur_v(dim);
    std::vector<double> p_cur(dim);

    last_v = copy(last_v, point);

    while (stop.criterion(count_iter, function, options)) {
        ++this->count_iter;
        cur_v = last_v - function.Hessian(last_v).colPivHouseholderQr().solve(function.Gradient(last_v));

        point = copy(point, last_v);


        p_cur = copy(p_cur, cur_v);

        if (function.get_value(p_cur) < function.get_value(point)) {

            options.set_x_k(p_cur);
            last_iter = 0;
            options.set_last_iter(last_iter);
        } else {
            std::cout << " asasasas" << std::endl;
            ++last_iter;
            options.set_last_iter(last_iter);
        }
        last_v = cur_v;
    }
    point = copy(point, last_v);

    return point;
}

const char *NewtonByDirection::get_name() {
    return "Newton by direction --- number 2";
}

std::vector<double> NewtonByDirection::copy(std::vector<double> &v, VectorXd &x) {

    for (int i = 0; i < x.size(); ++i) {
        v[i] = x(i);
    }
    return v;
}

VectorXd NewtonByDirection::copy(VectorXd &x, std::vector<double> &v) {
    for (int i = 0; i < x.size(); ++i) {
        x(i) = v[i];
    }
    return x;
}
