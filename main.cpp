#include <iostream>
#include "Options.h"
#include "Functions.h"
#include "Area.h"
#include "Optimization.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    int count_iter = 0;
    std::cout << "maximum number of iterations: " << std::endl;
    std::cin >> count_iter;

    double delta = 0;
    std::cout << "delta: " << std::endl;
    std::cin >> delta;
    std::cout << std::endl;

    double epsilon = 0;
    std::cout << "epsilon: " << std::endl;
    std::cin >> epsilon;
    std::cout << std::endl;

    Options options(delta, count_iter, epsilon);

    double p;
    std::cout << "probability p: " << std::endl;
    std::cin >> p;

    Function_1 function;
    int dim = function.get_dim();

    double point;

    std::vector<double> left_bound, right_bound;
    std::cout << "left bound:" << std::endl;
    for (int i = 0; i < dim; ++i) {
        std::cin >> point;
        left_bound.push_back(point);
    }


    std::cout << "right bound:" << std::endl;
    for (int i = 0; i < dim; ++i) {
        std::cin >> point;
        right_bound.push_back(point);
    }

    Rectangle rectangle(left_bound, right_bound, dim);
    StopCriterion_1 stop;
    std::vector<double> v;
    std::vector<double> res(dim);
//    RandomSearch randomSearch(p);
//    res = randomSearch.optimization(v, function, rectangle, stop, options);
    std::vector<double> x(dim);
    x[0] = -1;
    x[1] = -1;
    NewtonByDirection newtonByDirection(x);
    res = newtonByDirection.optimization(x, function, stop, options);
    std::cout << "minimum point: ";
    for (int i = 0; i < dim; ++i) {
        std::cout << res[i];
        std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "value: " << function.get_value(res) << std::endl;
    return 0;
}