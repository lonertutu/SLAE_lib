//
// Created by lonertutu on 06.04.23.
//

#include "../src/SLAE_Solvers/Gradient_descent.hpp"
#include "gtest/gtest.h"

TEST(GD, first_test) {
std::set<Triplet<double>> data1{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
                                {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.},
                                {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
CSR<double> matrix_iter(3, 3, data1);

double tolerance = 1e-12;
std::vector<double> b = {20.0, 30.0, 1.0};
std::vector<double> init_vec = {0., 0., 0.};

auto solution = gradDescent<double>(matrix_iter, b, init_vec, tolerance);
std::cout << solution[0] << " " << solution[1] << " " << solution[2];
ASSERT_NEAR(solution[0], 1.5942, 1e-5);
ASSERT_NEAR(solution[1], 4.05797, 1e-5);
ASSERT_NEAR(solution[2], 0.594203, 1e-5);
}

//матрица с нестрогим диагональным преобладанием
TEST(GD, second_test) {
    std::set<Triplet<double>> data1{{0, 0, 2.}, {0, 1, 2.}, {0, 2, 2.},
                                    {1, 0, 3.}, {1, 1, 7.}, {1, 2, 8.},
                                    {2, 0, 4.}, {2, 1, 9.}, {2, 2, 100.}};
    CSR<double> matrix_iter(3, 3, data1);

    double tolerance = 1e-12;
    std::vector<double> b = {10.0, 15.0, 4.0};
    std::vector<double> init_vec = {0., 0., 0.};

    auto solution = gradDescent<double>(matrix_iter, b, init_vec, tolerance);
    std::cout << solution[0] << " " << solution[1] << " " << solution[2];
    ASSERT_NEAR(solution[0], 4.95543, 1e-5);
    ASSERT_NEAR(solution[1], .222841, 1e-5);
    ASSERT_NEAR(solution[2], -0.178273, 1e-5);
}