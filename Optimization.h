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
public:
    /*
     * Returns the name of the optimization method..
     */
    virtual const char *get_name() = 0;

    /*
     * Виртуальная функция оптимизации. Для каждого метода
     * будет своя реализация. Возвращает точку, в которой
     * достигается минимум функции function.
     */
//    virtual std::vector<double>
//    optimization(std::vector<double> &point, Function &function, Rectangle &rectangle, Stop &stop,
//                 Options &options) = 0;
};

/*====================================================================================================================*/

/**
 * Метод оптимизации "Random Search".
 */
class RandomSearch : public Optimization {
private:
    double p = 0.5; // Вероятность

    std::mt19937 _generate;
    std::uniform_real_distribution<> _dist;

public:
    void set_p(double prob);

    std::vector<double> rand_vector(Rectangle &area);

    RandomSearch() = default;

    RandomSearch(double p);

    ~RandomSearch();

    const char *get_name() override;

    const double get_p();

    std::vector<double>
    optimization(std::vector<double> &point, Function &function, Rectangle &rectangle, Stop &stop,
                 Options &options);

};

/*====================================================================================================================*/

/**
 * Метод оптимизации "Ньютон по направлению".
 * TODO: !!!РЕАЛИЗОВАТЬ!!!
 */
class NewtonByDirection : public Optimization {
private:
    std::vector<double> x_0;
public:
    NewtonByDirection(const std::vector<double> &_x_0);

    std::vector<double>
    optimization(std::vector<double> &point, Function &function, Stop &stop,
                 Options &options);

    const char *get_name() override;
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_OPTIMIZATION_H
