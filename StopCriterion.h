//
// Created by Николай Карасов on 02/10/2018.
//

#ifndef OPTIMIZATION_STOPCRITERION_H
#define OPTIMIZATION_STOPCRITERION_H

#include "Functions.h"
#include "Options.h"

/*====================================================================================================================*/

/**
 * Абстрактный класс критерия остановки.
 * Имеет наследников.
 */
class Stop {
public:
    /*
     * Функция возвращает либо True, либо False.
     * True == продолжаем поиск.
     * False == останавливаемся.
     */
    virtual bool
    criterion(int count_iter, Function &function, Options &options) = 0;

    /*
     * Функция вернет имя критерия остановки.
     */
    virtual const char *get_name() = 0;
};

/*====================================================================================================================*/

/**
 * Критерий номер 1.
 * Остановка происходит при достижении
 * максимального числа итераций.
 * Как только count_iter == options.get_max_iter(),
 * то сразу заканчиваем поиск.
 */
class StopCriterion_1 : public Stop {
    bool criterion(int count_iter, Function &function, Options &options) override;

    const char *get_name() override;
};

/*====================================================================================================================*/

/**
 * Критерий номер 2.
 * Остановка происходит при достижении
 * числа прошедших итераций с последнего улучшения
 * максимального числа итераций.
 * Как только options.get_last_iter() == options.get_max_iter(),
 * то сразу заканчиваем поиск.
 */
class StopCriterion_2 : public Stop {
    bool criterion(int count_iter, Function &function, Options &options) override;

    const char *get_name() override;
};

/*====================================================================================================================*/

/**
 * Критерий номер 3.
 * Остановка происходит, когда
 * разность значений функции в двух соседних точках
 * улучшения меньше epsilon.
 * |f(x_{k+j}) - f(x_{k})| < epsilon
 * Как только |f(options.get_x_k_Plus_j()) - f(options.get_x_kj())| < epsilon,
 * то сразу заканчиваем поиск.
 */
class StopCriterion_3 : public Stop {
    bool criterion(int count_iter, Function &function, Options &options) override;

    const char *get_name() override;
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_STOPCRITERION_H
