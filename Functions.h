//
// Created by Николай Карасов on 02/10/2018.
//

#ifndef OPTIMIZATION_FUNCTIONS_H
#define OPTIMIZATION_FUNCTIONS_H

#include <vector>
#include "eigen-git-mirror/Eigen/Dense"

using namespace Eigen;

/*====================================================================================================================*/

/**
 * Абстрактный класс функция.
 * Наследников будет несколько.
 * Пока что сделал трех.
 */
class Function {
protected:
    int dim; // Размерность функции.
public:
    /*
     * Возвращает имя (аналитический вид) функции.
     */
    virtual const char *get_name() = 0;

    /*
     * Возвращает значение в точке.
     */
    virtual const double get_value(std::vector<double> &x) = 0;

    /*
     *Возвращает размерность функции.
     */
    virtual const int get_dim() = 0;

    virtual const MatrixXd Hessian(VectorXd &x) = 0;

    virtual const VectorXd Gradient(VectorXd &x) = 0;
};

/*====================================================================================================================*/

/**
 * Функция Розенброка.
 * f(x_{1}, x_{2}) = (1 - x)^{2} + 100 * (y - x^{2})^{2},
 * она имеет глобальный минимут в точке
 * (x_{1}, x_{2}) = (1, 1), где f(1, 1) = 0.
 */
class Function_1 : public Function {

public:
    Function_1();

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

    const VectorXd Gradient(VectorXd &x) override;

    const MatrixXd Hessian(VectorXd &x) override;
};

/*====================================================================================================================*/

/**
 * Вторая функция
 * f(x, y, z) = x^2 + y^2 + z^2
 * Имеет минимум в (0, 0, 0).
 */
class Function_2 : public Function {
public:
    const char *get_name() override;

    Function_2();

    const double get_value(std::vector<double> &x) override;

    const int get_dim() override;

    const VectorXd Gradient(VectorXd &x) override;

    const MatrixXd Hessian(VectorXd &x) override;
};

/*====================================================================================================================*/

/**
 * Третья функция
 * f(x, y) = 5 * x^2 - 6 * x * y + 5 * y^2
 * Имеет минимум в (0, 0).
 */
class Function_3 : public Function {
public:
    const char *get_name() override;

    Function_3();

    const double get_value(std::vector<double> &x) override;

    const int get_dim() override;

    const VectorXd Gradient(VectorXd &x) override;

    const MatrixXd Hessian(VectorXd &x) override;
};

/*====================================================================================================================*/


#endif //OPTIMIZATION_FUNCTIONS_H
