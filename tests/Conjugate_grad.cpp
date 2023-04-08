//
// Created by lonertutu on 07.04.23.
//

#include "../src/SLAE_Solvers/Conjugate_gradients.hpp"
#include "gtest/gtest.h"

TEST(CD, first_test) {
std::set<Triplet<double>> data1{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
                                {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.},
                                {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
CSR<double> matrix_iter(3, 3, data1);

double tolerance = 1e-12;
std::vector<double> b = {20.0, 30.0, 1.0};
std::vector<double> init_vec = {0., 0., 0.};

auto solution = conjGrad<double>(matrix_iter, b, init_vec, tolerance);
std::cout << solution[0] << " " << solution[1] << " " << solution[2];
ASSERT_NEAR(solution[0], 1.5942, 1e-5);
ASSERT_NEAR(solution[1], 4.05797, 1e-5);
ASSERT_NEAR(solution[2], 0.594203, 1e-5);
}

//Не проходит тесты с матрицами без диагонального преобладания(нестрогого)
TEST(CD, second_test) {
    std::set<Triplet<double>> data1{{0, 0, 99.}, {0, 1, 12.}, {0, 2, 10.},
                                    {1, 0, 8.}, {1, 1, 10.9}, {1, 2, 0.1},
                                    {2, 0, 5.}, {2, 1, 4.}, {2, 2, 70.}};
    CSR<double> matrix_iter(3, 3, data1);

    double tolerance = 1e-12;
    std::vector<double> b = {1., 5., 4.};
    std::vector<double> init_vec = {0.01, 1.2, -0.14};

    auto solution = conjGrad<double>(matrix_iter, b, init_vec, tolerance);
    std::cout << solution[0] << " " << solution[1] << " " << solution[2];
    ASSERT_NEAR(solution[0], -0.0535106, 1e-6);
    ASSERT_NEAR(solution[1], 0.497691, 1e-6);
    ASSERT_NEAR(solution[2], 0.0325256, 1e-6);
}

//Проверка на матрицу большего размера
TEST(CD, third_test) {
    std::set<Triplet<double>> data1{{0, 0, 99.}, {0, 1, 12.}, {0, 2, 10.}, {0, 3, 24.},
                                    {1, 0, 8.}, {1, 1, 100.9}, {1, 2, 0.1}, {1, 3, 0.3},
                                    {2, 0, 5.}, {2, 1, 4.}, {2, 2, 70.}, {2, 3, 5.},
                                    {3, 0, 1.}, {3, 1, 3.}, {3, 2, 9.}, {3, 3, 100.}};
    CSR<double> matrix_iter(4, 4, data1);

    double tolerance = 1e-6;
    std::vector<double> b = {1., 5., 4., 21.};
    std::vector<double> init_vec = {0.01, 0.2, 0.5, 0.01};

    auto solution = conjGrad<double>(matrix_iter, b, init_vec, tolerance);
    std::cout << solution[0] << " " << solution[1] << " " << solution[2] << " " << solution[3];
    ASSERT_NEAR(solution[3], 0.20504, 1e-6);
    ASSERT_NEAR(solution[0], -0.050368, 1e-6);
    ASSERT_NEAR(solution[1], 0.0528952, 1e-6);
    ASSERT_NEAR(solution[2], 0.0430723, 1e-6);
}