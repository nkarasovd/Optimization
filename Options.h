//
// Created by Николай Карасов on 03/10/2018.
//

#ifndef OPTIMIZATION_OPTIONS_H
#define OPTIMIZATION_OPTIONS_H

/*====================================================================================================================*/

#include <vector>

/*
 * Класс создан для удобства передачи параметров
 * в методы оптимизации, чтобы не перечислять все
 * и сразу, а просто передать коробку со всем добром.
 */
class Options {
    double delta;
    int count_iter;
    double epsilon;
    int last_iter; // Число итераций прошедших с последнего улучшения
    int index = 0;
    std::vector<double> x_k;
    std::vector<double> x_kj;
public:
    Options(double _delta, int _iteration, double _epsilon);

    double get_delta() const;

    int get_iter() const;

    double get_epsilon() const;

    int get_last_iter() const;

    void set_last_iter(int _iter);

    void set_x_k(std::vector<double> _v);

    std::vector<double> & get_x_k();

    std::vector<double> &get_x_kj();

    Options() = default;
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_OPTIONS_H
