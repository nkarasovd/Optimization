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
 * Класс методов оптимизации.
 * Есть два метода:
 * <1> Случайный поиск --- optimizationRandomSearch
 * <2> Метод Ньютона по направлению --- optimizationNewton
 */
class Optimization {
protected:
    int count_iter = 0; // Number of iterations performed

    std::mt19937 _generate;
    std::uniform_real_distribution<> _dist;
public:
    Optimization();
    /*
     * Функция случайного поиска.
     */
    std::vector<double>
    optimizationRandomSearch(Function *function, Rectangle &rectangle, Stop *stop, Options *options, double p);

    /*
     * Функция возвращает случайную точку из области.
     */
    std::vector<double> rand_vector(Rectangle &area);

    /*
     * Метод Ньютона по направлению.
     */
    std::vector<double>
    optimizationNewton(std::vector<double> &point, Function *function, Stop *stop, Options *options, Rectangle &rectangle);


    std::vector<double> copy(std::vector<double> &v, VectorXd &x);

    VectorXd copy(VectorXd &x, std::vector<double> &v);
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_OPTIMIZATION_H
