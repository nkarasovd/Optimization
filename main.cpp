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
              << "< 2 > x^2 + y^2 + z^2\n"
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

    int stop_cr;
    double stop_cr_d = 0;
    std::cout << "Choose stop criterion:\n"
              << "< 1 > Maximum iterations.\n"
              << "< 2 > Number of iterations after last improvement.\n"
              << "< 3 > |f(x_{k+j}) - f(x_{k})| < epsilon\n" << std::endl;

    while (!(stop_cr_d == 1 || stop_cr_d == 2 || stop_cr_d == 3)) {
        std::cout << "Please , enter a number (1, 2, 3)\n";
        std::cout << "> ";
        std::cin >> stop_cr_d;
        if ((stop_cr_d == 1 || stop_cr_d == 2 || stop_cr_d == 3)) {
            stop_cr = (int) stop_cr_d;
            break;
        }
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);
        std::cout << "\nUnfortunately, your input is not 1, 2 or 3. Try again..." << std::endl;
    }

/*====================================================================================================================*/

    int count_iter;
    double count_iter_d = 0,
            fractpart,                   // дробная часть
            intpart;                     // целая часть;

/*====================================================================================================================*/

    Options *options;
    Stop *stop;
    switch (stop_cr) {
        case 1: {
            std::cout << "\nEnter maximum number of iterations:\n";
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
                std::cout << "\nUnfortunately, your input is not a positive integer. Try again..." << std::endl;
            }

            options = new Options(count_iter);
            stop = new StopCriterion_1();
            break;
        }
        case 2: {
            std::cout << "\nEnter maximum number of iterations:\n";
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
                std::cout << "\nUnfortunately, your input is not a positive integer. Try again..." << std::endl;
            }

            options = new Options(count_iter);
            stop = new StopCriterion_2();
            break;
        }
        case 3: {
            double epsilon;
            std::cout << "Enter epsilon.\n";
            epsilon = 0;
            while (epsilon >= 1 || epsilon <= 0) {
                std::cout << "Please , enter 0 < epsilon < 1\n" << "> ";
                std::cin >> epsilon;
                if (!(epsilon <= 0 || epsilon >= 1)) {
                    break;
                }
                std::cin.clear();
                std::string line;
                std::getline(std::cin, line);
                std::cout << "\nUnfortunately, your input is wrong. Try again..." << std::endl;
            }
            options = new Options(epsilon);
            stop = new StopCriterion_3();
            break;
        }
        default: {
            break;
        }
    }
/*====================================================================================================================*/



    int dim = function->get_dim();
    std::vector<double> res(dim);

    int method;
    double method_d = 0;

    std::cout << "Choose method, please:\n"
              << "< 1 > Random search.\n"
              << "< 2 > Newton by direction.\n" << std::endl;

    while (!(method_d == 1 || method_d == 2)) {
        std::cout << "Please , enter a number (1, 2)\n";
        std::cout << "> ";
        std::cin >> method_d;
        if ((method_d == 1 || method_d == 2)) {
            method = (int) method_d;
            break;
        }
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);
        std::cout << "\nUnfortunately, your input is not 1 or 2. Try again..." << std::endl;
    }

    Optimization opt;

    switch (method) {
        case 1: {
            double p;
            std::cout << "Enter probability.\n";
            p = 0;
            while (p >= 1 || p <= 0) {
                std::cout << "Please , enter 0 < p < 1\n" << "> ";
                std::cin >> p;
                if (!(p <= 0 || p >= 1)) {
                    break;
                }
                std::cin.clear();
                std::string line;
                std::getline(std::cin, line);
                std::cout << "\nUnfortunately, your input is wrong. Try again..." << std::endl;
            }

            double delta;
            std::cout << "Enter delta.\n";
            delta = 0;
            while (delta >= 1 || delta <= 0) {
                std::cout << "Please , enter 0 < delta < 1\n" << "> ";
                std::cin >> delta;
                if (!(delta <= 0 || delta >= 1)) {
                    break;
                }
                std::cin.clear();
                std::string line;
                std::getline(std::cin, line);
                std::cout << "\nUnfortunately, your input is wrong. Try again..." << std::endl;
            }

            std::vector<double> left_bound, right_bound;
            std::cout << "Enter left bound, please\n" << std::endl;
            double dot = 0;
            for (int i = 0; i < dim; ++i) {
                while (!(std::cin >> dot)) {
                    std::cout << "Ooops...\n";
                }
                left_bound.push_back(dot);
            }

            std::cout << "Enter right bound, please\n" << std::endl;
            dot = 0;
            for (int i = 0; i < dim; ++i) {
                while (!(std::cin >> dot)) {
                    std::cout << "Ooops...\n";
                }
                right_bound.push_back(dot);
            }

            Rectangle rectangle(left_bound, right_bound, dim);

            rectangle.set_delta(delta);

            res = opt.optimizationRa(function, rectangle, stop, options, p);
            break;
        }
        case 2: {
            std::vector<double> vector;
            std::cout << "Enter start point, please\n" << std::endl;
            double dot = 0;
            for (int i = 0; i < dim; ++i) {
                while (!(std::cin >> dot)) {
                    std::cout << "Ooops...\n";
                }
                vector.push_back(dot);
            }

            res = opt.optimizationNe(vector, function, stop, options);
            break;
        }
        default: {
            break;
        }
    }

    std::cout << "Point of minimum: ";
    for (int i = 0; i < dim; ++i) {
        std::cout << res[i];
        std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "Value: " << function->get_value(res) << std::endl;

    std::cout << "Goodbye!" << std::endl;
    return 0;
}