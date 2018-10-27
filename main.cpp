#include "Options.h"
#include "Functions.h"
#include "Area.h"
#include "Optimization.h"
#include <string>
#include <iostream>
#include <cmath>

int main() {
/*====================================================================================================================*/

    std::cout << "\n************************* Optimization Program *************************\n" << std::endl;

    std::cout << "\nChoose your function:\n"
              << "< 1 > (1 - x)^2 + 100 * (y - x^2)^2\n"
              << "< 2 > \n"
              << "< 3 > \n" << std::endl;

    int number;
    double number_d = 0;
    while (!(number_d == 1 || number_d == 2 || number_d == 3)) {
        std::cout << "Please , enter a number (1, 2, 3)\n";
        std::cout << "> ";
        std::cin >> number_d;
        if ((number_d == 1 || number_d == 2 || number_d == 3)) {
            number = (int) number_d;
            break;
        }
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);
        std::cout << "\nUnfortunately, your input is not 1, 2 or 3. Try again..." << std::endl;
    }

    Function *function;
    switch (number) {
        case 1: {
            function = new Function_1();
            break;
        }
        case 2: {
            function = new Function_2();
            break;
        }
        case 3: {
            function = new Function_3();
            break;
        }
        default:
            break;
    }

/*====================================================================================================================*/

    int count_iter;
    double count_iter_d = 0,
            fractpart,                   // дробная часть
            intpart;                     // целая часть;

    std::cout << "\nMaximum number of iterations:\n";
    while (count_iter_d <= 0 || modf(count_iter_d, &intpart) != 0) {
        std::cout << "Please , enter a positive integer\n" << "> ";
        std::cin >> count_iter_d;
        if (!(count_iter_d <= 0 || modf(count_iter_d, &intpart) != 0)) {
            count_iter = (int) count_iter_d;
            break;
        }
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);
        std::cout << "\nUnfortunately, your input is not 1, 2 or 3. Try again..." << std::endl;
    }

/*====================================================================================================================*/

    double epsilon = 0;
    std::cout << "epsilon: " << std::endl;
    std::cin >> epsilon;
    std::cout << std::endl;

    Options options(count_iter, epsilon);

    int dim = function->get_dim();
    std::vector<double> res(dim);
    std::cout << "Выберите метод оптимизации" << std::endl;
    StopCriterion_1 stop;
    int method;
    std::cin >> method;

    Optimization opt;

    if (method == 1) {
        double delta = 0;
        std::cout << "delta: " << std::endl;
        std::cin >> delta;
        std::cout << std::endl;

        double p;
        std::cout << "probability p: " << std::endl;
        std::cin >> p;

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

        rectangle.set_delta(delta);

        res = opt.optimizationRa(function, rectangle, stop, options, p);
    } else {
        std::vector<double> x(dim);
        double t;
        std::cout << "point start" << std::endl;
        for (int i = 0; i < dim; ++i) {
            std::cin >> t;
            x[i] = t;
        }
        res = opt.optimizationNe(x, function, stop, options);
    }
    std::cout << "minimum point: ";
    for (int i = 0; i < dim; ++i) {
        std::cout << res[i];
        std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "value: " << function->get_value(res) << std::endl;
    return 0;
}