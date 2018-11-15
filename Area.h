//
// Created by Николай Карасов on 02/10/2018.
//

#ifndef OPTIMIZATION_AREA_H
#define OPTIMIZATION_AREA_H

#include <vector>
#include "eigen-git-mirror/Eigen/Dense"

using namespace Eigen;

/*====================================================================================================================*/
/**
 * Класс Area:
 * абстрактный класс,
 * имеет наслденика Rectangle -
 * прямоугольная область.
 */
class Area {
protected:
    int dim; // Размерность пространства
public:
    virtual const int get_dim() = 0;
};

/*====================================================================================================================*/
/**
 * Класс Rectangle:
 * наследник Area,
 * задает прямоугольную область
 * в пространстве R^{dim}.
 */
class Rectangle : public Area {
private:
    double delta; // Радиус шара с центром в точке улучшения

    std::vector<double> left_border; // Левая граница области
    std::vector<double> right_border; // Правая граница области
public:
    double get_delta() const;

    void set_delta(double delta);

    const int get_dim() override;

    /*
     * Возвращает i-ую координату левой границы
     */
    const double get_left(int i);

    /*
     * Возвращает i-ую координату правой границы
     */
    const double get_right(int i);

    Rectangle() = default;

    /*
     * Конструктор для задания начальной
     * прямоугольной области. Для этого нужны
     * обе границы и размерность пространства.
     */
    Rectangle(std::vector<double> &l, std::vector<double> &r, int _dim);

    ~Rectangle();

    /*
     * Конструктор для задания сжатой области.
     * Пересекаем имеющийся прямоугольник с
     * шаром в точке улучшения с радиусом delta.
     */
    Rectangle(std::vector<double> &l, std::vector<double> &r, std::vector<double> &y_n,
              int d, double delta);

    std::vector<double> &get_left();

    std::vector<double> &get_right();

    /*
     * Проверка: принадлжеит ли точка области.
     */
    bool const is_in(VectorXd &V);
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_AREA_H
