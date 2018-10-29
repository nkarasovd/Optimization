//
// Created by Николай Карасов on 02/10/2018.
//

#ifndef OPTIMIZATION_OPTIMIZATION_H
#define OPTIMIZATION_OPTIMIZATION_H

#include "Functions.h"
#include "StopCriterion.h"
#include "Area.h"
#include <random>
#include "Options.h"

/*====================================================================================================================*/

/**
 * Абстрактный класс оптимизации.
 * Будет иметь двух наслдеников.
 */
class Optimization {
protected:
    int count_iter = 0; // Number of iterations performed

    std::mt19937 _generate;
    std::uniform_real_distribution<> _dist;
public:
    Optimization();
    std::vector<double>
    optimizationRa(Function *function, Rectangle &rectangle, Stop *stop, Options *options, double p);

    std::vector<double> rand_vector(Rectangle &area);

    std::vector<double>
    optimizationNe(std::vector<double> &point, Function *function, Stop *stop, Options *options);


    std::vector<double> copy(std::vector<double> &v, VectorXd &x);

    VectorXd copy(VectorXd &x, std::vector<double> &v);
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_OPTIMIZATION_H
