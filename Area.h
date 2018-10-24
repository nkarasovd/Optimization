//
// Created by Николай Карасов on 02/10/2018.
//

#ifndef OPTIMIZATION_AREA_H
#define OPTIMIZATION_AREA_H

#include <vector>

/*====================================================================================================================*/

class Area {
protected:
    int dim = 0;
public:
    virtual const int get_dim() = 0;
};

/*====================================================================================================================*/

class Rectangle : public Area {
protected:
    std::vector<double> left_border;
    std::vector<double> right_border;
public:
    const int get_dim() override;

    const double get_left(int i);

    const double get_right(int i);

    Rectangle() = default;

    Rectangle(std::vector<double> &l, std::vector<double> &r, int d);

    ~Rectangle();

    Rectangle(std::vector<double> &l, std::vector<double> &r, std::vector<double> &y_n,
              int d, double delta);

    std::vector<double> & get_left();

    std::vector<double> & get_right();
};

/*====================================================================================================================*/

#endif //OPTIMIZATION_AREA_H
