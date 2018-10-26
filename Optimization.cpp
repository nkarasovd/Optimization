//
// Created by Николай Карасов on 02/10/2018.
//
#include <stdexcept>
#include <vector>
#include "Optimization.h"

/*====================================================================================================================*/

/*
 * Functions of RandomSearch class.
 */

const char *RandomSearch::get_name() {
    return "Random Search";
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
RandomSearch::optimization(std::vector<double> &point, Function &function, Rectangle &rectangle, Stop &stop,
                           Options &options) {
    int dim = function.get_dim();

    std::vector<double> y_0(dim);
    y_0 = rand_vector(rectangle);
    std::vector<double> y_n(dim);
    y_n = rand_vector(rectangle);

    std::vector<double> curr_pos(dim);

    double delta = options.get_delta();

    while (stop.criterion(count_iter, function, y_0, y_n, options)) {
        ++this->count_iter;
        double q = _dist(_generate);

        if (q < p) {
            curr_pos = rand_vector(rectangle);
            if (function.get_value(curr_pos) < function.get_value(y_n)) {
                options.set_x_k(curr_pos);
                options.set_last_iter(count_iter);
                y_n = curr_pos;

            }
        } else {
            Rectangle new_rectangle(rectangle.get_left(), rectangle.get_right(), y_n, dim, delta);
            curr_pos = rand_vector(new_rectangle);
            if (function.get_value(curr_pos) < function.get_value(y_n)) {
                options.set_x_k(curr_pos);
                options.set_last_iter(count_iter);
                y_n = curr_pos;
                delta *= 0.7;
            }

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

    if (prob < 0 || prob > 1) {
        throw std::invalid_argument("Error! 0 <= p <= 1");
    }
    p = prob;
}

/*====================================================================================================================*/
NewtonByDirection::NewtonByDirection(const std::vector<double> &_x_0) {
    this->x_0 = _x_0;
}

std::vector<double>
NewtonByDirection::optimization(std::vector<double> &point, Function &function, Stop &stop,
                                Options &options) {
    int dim = function.get_dim();
    VectorXd v(dim);
    for (int i = 0; i < dim; ++i) {
        v(i) = point[i];
    }
    while (stop.criterion(count_iter, function, point, point, options)) {
        ++this->count_iter;
        v = v - function.Hessian(v).colPivHouseholderQr().solve(function.Gradient(v));
    }
    for (int i = 0; i < dim; ++i) {
        point[i] = v(i);
    }
    return point;
}

const char *NewtonByDirection::get_name() {
    return nullptr;
}
