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
    std::vector<double> res(dim);
    std::cout << "Выберите метод оптимизации" << std::endl;
    StopCriterion_3 stop;
    int method;
    std::cin >> method;


    if (method == 1) {
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

        std::vector<double> v;
        RandomSearch randomSearch(p);
//        res = randomSearch.optimization(v, function, rectangle, stop, options);
    } else {
        std::vector<double> x(dim);
        double t;
        std::cout << "point start" << std::endl;
        for (int i = 0; i < dim; ++i) {
            std::cin >> t;
            x[i] = t;
        }
        NewtonByDirection newtonByDirection(x);
        res = newtonByDirection.optimization(x, function, stop, options);
    }
    std::cout << "minimum point: ";
    for (int i = 0; i < dim; ++i) {
        std::cout << res[i];
        std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "value: " << function.get_value(res) << std::endl;
    return 0;
}