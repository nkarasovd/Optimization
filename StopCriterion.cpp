//
// Created by Николай Карасов on 02/10/2018.
//
#include "StopCriterion.h"

/*====================================================================================================================*/

/*
 * Все ниже для первого критерия.
 */

bool StopCriterion_1::criterion(int count_iter, Function *function, Options *options) {
    return count_iter != options->get_max_iter();
}

const char *StopCriterion_1::get_name() {
    return "By Iterations";
}

/*====================================================================================================================*/

/*
 * Все ниже для второго критерия.
 */

bool StopCriterion_2::criterion(int count_iter, Function *function, Options *options) {
    return (options->get_last_iter() < options->getMax_iter_after() && options->get_max_iter() > count_iter);
}

const char *StopCriterion_2::get_name() {
    return nullptr;
}

/*====================================================================================================================*/

/*
 * Все ниже для третьего критерия.
 */

bool StopCriterion_3::criterion(int count_iter, Function *function, Options *options) {
    if (options->get_x_k().empty() || options->get_x_k_Plus_j().empty()) return true;

    double value = fabs(function->get_value(options->get_x_k_Plus_j()) - function->get_value(options->get_x_k()));

    return (value > options->get_epsilon() && count_iter < options->get_max_iter());

}

const char *StopCriterion_3::get_name() {
    return nullptr;
}

/*====================================================================================================================*/

