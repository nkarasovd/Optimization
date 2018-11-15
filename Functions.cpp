//
// Created by Николай Карасов on 02/10/2018.
//
#include "Functions.h"

/*====================================================================================================================*/

/*
 * Functions of Function_1 class.
 */

const char *Function_1::get_name() {
    return "f(x, y) = (1 - x)^2 + 100 * (y - x^2)^2";
}

const double Function_1::get_value(std::vector<double> &x) {
    return (1 - x[0]) * (1 - x[0]) + 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]);
}

const int Function_1::get_dim() {
    return dim;
}

Function_1::Function_1() {
    dim = 2;
}

const VectorXd Function_1::Gradient(VectorXd &x) {
    VectorXd gradient(dim);
    gradient << 2 * (200 * x(0) * x(0) * x(0) - 200 * x(0) * x(1) + x(0) - 1), 200 * (x(1) - x(0) * x(0));
    return gradient;
}

const MatrixXd Function_1::Hessian(VectorXd &x) {
    MatrixXd hessian(dim, dim);
    hessian << 1200 * x(0) * x(0), -400 * x(0),
            -400 * x(0), 200;
    return hessian;
}

/*====================================================================================================================*/

/*
 * Functions of Function_2 class.
 */

const char *Function_2::get_name() {
    return "f(x, y, z) = x^2 + y^2 + z^2";
}

Function_2::Function_2() {
    dim = 3;
}

const double Function_2::get_value(std::vector<double> &x) {
    return x[0] * x[0] + x[1] * x[1] + x[2] * x[2];
}

const int Function_2::get_dim() {
    return dim;
}

const VectorXd Function_2::Gradient(VectorXd &x) {
    VectorXd gradient(dim);
    gradient << 2 * x(0), 2 * x(1), 2 * x(2);
    return gradient;
}

const MatrixXd Function_2::Hessian(VectorXd &x) {
    MatrixXd hessian(dim, dim);
    hessian << 2, 0, 0,
            0, 2, 0,
            0, 0, 2;
    return hessian;
}

/*====================================================================================================================*/

/*
 * Functions of Function_3 class.
 */

const char *Function_3::get_name() {
    return "f(x, y) = 5 * x^2 - 6 * x * y + 5 * y^2";
}

Function_3::Function_3() {
    dim = 2;
}

const double Function_3::get_value(std::vector<double> &x) {
    return 5 * x[0] * x[0] - 6 * x[0] * x[1] + 5 * x[1] * x[1];
}

const int Function_3::get_dim() {
    return 2;
}

const VectorXd Function_3::Gradient(VectorXd &x) {
    VectorXd gradient(dim);
    gradient << 10 * x(0) - 6 * x(1), -6 * x(0) + 10 * x(1);
    return gradient;
}

const MatrixXd Function_3::Hessian(VectorXd &x) {
    MatrixXd hessian(dim, dim);
    hessian << 10, -6,
            -6, 10;
    return hessian;
}

/*====================================================================================================================*/

