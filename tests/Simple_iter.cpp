//
// Created by lonertutu on 05.03.23.
//

#include "../src/SLAE_Solvers/Simple_iteration.hpp"
#include "gtest/gtest.h"

TEST(Simple_Iter, first_test) {
    std::set<Triplet<double>> data1{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
                                   {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.},
                                   {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
    CSR<double> matrix_iter(3, 3, data1);

    double tolerance = 1e-12;
    std::vector<double> b = {20.0, 30.0, 1.0};
    std::vector<double> init_vec = {0., 0., 0.};
    double parametr = 0.05;

    auto solution = simpIter<double>(matrix_iter, b, init_vec, tolerance, parametr);
    ASSERT_NEAR(solution[0], 1.5942, 1e-5);
    ASSERT_NEAR(solution[1], 4.05797, 1e-5);
    ASSERT_NEAR(solution[2], 0.594203, 1e-5);
}

TEST(Simple_Iter, second_test) {
    std::set<Triplet<double>> data1{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
                                    {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.},
                                    {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
    CSR<double> matrix_iter(3, 3, data1);

    double tolerance = 1e-12;
    std::vector<double> b = {20.0, 30.0, 1.0};
    std::vector<double> init_vec = {0., 0., 0.};
    double lambda_min = 1;
    double lambda_max = 10;

    std::vector<double> solution;
    solution = simpIter_chebBoost<double>(matrix_iter, b, init_vec, tolerance, lambda_min, lambda_max, 32, 6);

    std::cout << solution[0] << " " << solution[1] << " " << solution[2];
}