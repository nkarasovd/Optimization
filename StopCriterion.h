//
// Created by Николай Карасов on 02/10/2018.
//

#ifndef OPTIMIZATION_STOPCRITERION_H
#define OPTIMIZATION_STOPCRITERION_H

#include "Functions.h"
#include "Options.h"

/*====================================================================================================================*/

/*
 * Абстрактный класс критерия остановки.
 * Пока не знаю что тут вообще будет
 * и сколько критериев будет. Для начала
 * сделаем хотя бы один.
 */

class Stop {
public:
    /*
     * Функция возвращать будет либо
     * TRUE либо FALSE. Типо пора остановаиться,
     * али нет.
     */
    virtual bool
    criterion(int count_iter, Function &function, std::vector<double> &x1, std::vector<double> &x2,
              Options &options) = 0;

    /*
     * Функция вернет имя критерия остановки,
     * конкретного критерия. Какие они будут,
     * пока что никто не знает.
     */
    virtual const char *get_name() = 0;
};

/*====================================================================================================================*/

/*
 * Первый критерий состоит в том,
 * что остановка происходит по причине достижения
 * максимального числа итераций.
 * Как только count_iter == options.get_iter(),
 * то сразу заканчиваем поиск.
 */

class StopCriterion_1 : public Stop {
    bool criterion(int count_iter, Function &function, std::vector<double> &x1, std::vector<double> &x2,
                   Options &options) override;

    const char *get_name() override;
};

/*====================================================================================================================*/

/*
 * Число прошедших итераций с последнего улучшения.
 */

class StopCriterion_2 : public Stop {
    bool criterion(int count_iter, Function &function, std::vector<double> &x1, std::vector<double> &x2,
                   Options &options) override;

    const char *get_name() override;
};

/*====================================================================================================================*/

/*
 * Разность значений функции в двух соседних точках
 * улучшения меньше epsilon.
 */
class StopCriterion_3 : public Stop {
    bool criterion(int count_iter, Function &function, std::vector<double> &x1, std::vector<double> &x2,
                   Options &options) override;

    const char *get_name() override;
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_STOPCRITERION_H
