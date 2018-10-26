//
// Created by Николай Карасов on 03/10/2018.
//

#ifndef OPTIMIZATION_OPTIONS_H
#define OPTIMIZATION_OPTIONS_H

/*====================================================================================================================*/

#include <vector>

/**
 * Класс создан для удобства передачи параметров
 * в методы оптимизации, чтобы не перечислять все
 * и сразу, а просто передать коробку со всем добром.
 */
class Options {
    double delta; // Радиус шара с центром в точке улучшения
    int max_iter; // Максимальное число итераций

    /*
     * Число итераций, прошедших с последнего улучшения.
     * Будем сравнивать с max_iter
     */
    int last_iter;

    int index; // Счетчик, чтобы знать, что заполнять: x_{k} || x_{k+j}
    std::vector<double> x_k; // Точка улучшения x_{k}
    std::vector<double> x_k_Plus_j; // Точка улучшения x_{k+j}
    double epsilon; // |f(x_{k+j}) - f(x_{k})| < epsilon
public:
    Options(double _delta, int _iteration, double _epsilon);

    double get_delta() const;

    int get_max_iter() const;

    double get_epsilon() const;

    int get_last_iter() const;

    void set_last_iter(int _iter);

    void set_x_k(std::vector<double> &_v);

    std::vector<double> & get_x_k();

    std::vector<double> &get_x_k_Plus_j();

    Options() = default;
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_OPTIONS_H
