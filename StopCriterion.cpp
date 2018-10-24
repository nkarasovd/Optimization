//
// Created by Николай Карасов on 02/10/2018.
//
#include "StopCriterion.h"
#include <cmath>

/*====================================================================================================================*/

/*
 * Все ниже для первого критерия.
 */

bool StopCriterion_1::criterion(int count_iter, Function &function, std::vector<double> &x1, std::vector<double> &x2,
                                Options &options) {
    return count_iter != options.get_iter();
}

const char *StopCriterion_1::get_name() {
    return "By Iterations";
}

/*====================================================================================================================*/

bool StopCriterion_2::criterion(int count_iter, Function &function, std::vector<double> &x1, std::vector<double> &x2,
                                Options &options) {
    return options.get_last_iter() < options.get_iter();
}

const char *StopCriterion_2::get_name() {
    return nullptr;
}

/*====================================================================================================================*/

bool StopCriterion_3::criterion(int count_iter, Function &function, std::vector<double> &x1, std::vector<double> &x2,
                                Options &options) {
    if (options.get_x_k().empty() || options.get_x_kj().empty()) return true;

    double value = fabs(function.get_value(options.get_x_kj()) - function.get_value(options.get_x_k()));

    return value > options.get_epsilon();

}

const char *StopCriterion_3::get_name() {
    return nullptr;
}

/*====================================================================================================================*/

