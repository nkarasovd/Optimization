//
// Created by Николай Карасов on 02/10/2018.
//

#ifndef OPTIMIZATION_FUNCTIONS_H
#define OPTIMIZATION_FUNCTIONS_H

#include <vector>

/*====================================================================================================================*/

/*
 * Абстрактный класс функция.
 * Наследников будет несколько.
 * Пока что сделал трех.
 */
class Function {
public:
    /*
     * Метод будет возвращать название функции.
     * Ну может быть будет печатать ее аналитический вид.
     */
    virtual const char *get_name() = 0;

    /*
     * Метод будет возвращать знакчений в точке,
     * пока что непонятно, что передавать в качестве
     * параметра.
     */
    virtual const double get_value(std::vector<double> &x) = 0;

    /*
     *Возвращает размерность.
     */
    virtual const int get_dim() = 0;
};

/*====================================================================================================================*/

/*
 * Функция Розенброка.
 * f(x_{1}, x_{2}) = (1 - x)^{2} + 100 * (y - x^{2})^{2},
 * она имеет глобальный минимут в точке
 * (x_{1}, x_{2}) = (1, 1), где f(1, 1) = 0.
 */
class Function_1 : public Function {
private:
    int dim = 2;

public:
    /*
     * Вернет свой аналитический вид:
     * f(x_{1}, x_{2}) = (1 - x)^{2} + 100 * (y - x^{2})^{2}.
     */
    const char *get_name() override;

    /*
     * Возвращает значение в точке (x_{1}, x_{2}).
     */
    const double get_value(std::vector<double> &x) override;

    /*
     * Возвращает значение 2.
     */
    const int get_dim() override;

    Matrix* m = new Matrix(dim);

    std::vector<double> calc_x(std::vector<double> x_0);
};

/*====================================================================================================================*/

/*
 * Вторая функция наслденик Function
 * TODO: придумать и все реализовать
 */
class Function_2 : public Function {
    const char *get_name() override;

    const double get_value(std::vector<double> &x) override;

    const int get_dim() override;
};

/*====================================================================================================================*/

/*
 * Третья функция наслденик Function
 * TODO: придумать и все реализовать
 */
class Function_3 : public Function {
    const char *get_name() override;

    const double get_value(std::vector<double> &x) override;

    const int get_dim() override;
};

/*====================================================================================================================*/


class Matrix {
private:
    int size;
    std::vector<std::vector<double>>  matrix;
public:
    Matrix(int _size);

};
#endif //OPTIMIZATION_FUNCTIONS_H
