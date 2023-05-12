//
// Created by lonertutu on 03.05.23.
//

#include "../src/SLAE_Solvers/BiCG.hpp"
#include "gtest/gtest.h"

TEST(BiCD, first_test) {
    std::vector<double> els = {1, 2, 4, 2, 6};
    std::vector<uint32_t> c = {0, 1, 1, 1, 2};
    std::vector<uint32_t> r = {0, 2, 3, 5};
    CSR<double> matrix(els, c, r, 3, 3);

    double tolerance = 1e-12;
    std::vector<double> b = {20.0, 30.0, 1.0};
    std::vector<double> init_vec = {0., 0., 0.};

    auto solution = BiCG<double>(matrix, b, init_vec, tolerance);
    ASSERT_NEAR(solution[0], 5, 1e-6);
    ASSERT_NEAR(solution[1], 7.5, 1e-6);
    ASSERT_NEAR(solution[2], -2.33333, 1e-5);
}

//Проверка на симметричной матрице, когда BiCG->CG
TEST(BiCD, second_test) {
    std::vector<double> els = {10., 1., 1., 7, 0.1, 0.1, 1};
    std::vector<uint32_t> c = {0, 1, 0, 1, 2, 1, 2};
    std::vector<uint32_t> r = {0, 2, 5, 7};
    CSR<double> matrix(els, c, r, 3, 3);

    double tolerance = 1e-12;
    std::vector<double> b = {20.0, 30.0, 1.0};
    std::vector<double> init_vec = {0., 0., 0.};

    auto solution = BiCG<double>(matrix, b, init_vec, tolerance);
    ASSERT_NEAR(solution[0], 1.59507, 1e-5);
    ASSERT_NEAR(solution[1], 4.04935, 1e-5);
    ASSERT_NEAR(solution[2], 0.595065, 1e-5);
}

//на матрицце с большей размерностью, несимметричная
TEST(BiCD, third_test) {
    std::vector<double> els = {1., 2., 2., 3., 5., 10., 2., 1., 3., 20.};
    std::vector<uint32_t> c = {0, 5, 0, 2, 1, 3, 3, 4, 1, 5};
    std::vector<uint32_t> r = {0, 2, 3, 4, 6, 8, 10};
    CSR<double> matrix(els, c, r, 6, 6);

    double tolerance = 1e-12;
    std::vector<double> b = {20.0, 30.0, 1.0, 5.0, 6., 3.};
    std::vector<double> init_vec = {0., 0., 0., 0., 0., 0.};

    auto solution = BiCG<double>(matrix, b, init_vec, tolerance);
    ASSERT_NEAR(solution[0], 15, 1e-5);
    ASSERT_NEAR(solution[1], -15.6667, 1e-4);
    ASSERT_NEAR(solution[2], 0.333333, 1e-6);
    ASSERT_NEAR(solution[3], 8.33333, 1e-5);
    ASSERT_NEAR(solution[4], -10.6667, 1e-4);
    ASSERT_NEAR(solution[5], 2.5, 1e-7);
}


//симметричный аналог матрицы 3-го теста (BiCG->CG)
TEST(BiCD, fourth_test) {
    std::vector<double> els = {1., 2., 2., 5., 3., 3., 5., 10., 2., 2., 1., 3., 20.};
    std::vector<uint32_t> c = {0, 1, 0, 3, 5, 2, 1, 3, 4, 3, 4, 1, 5};
    std::vector<uint32_t> r = {0, 2, 5, 6, 9, 11, 13};
    CSR<double> matrix(els, c, r, 6, 6);

    double tolerance = 1e-12;
    std::vector<double> b = {20.0, 30.0, 1.0, 5.0, 6., 3.};
    std::vector<double> init_vec = {0., 0., 0., 0., 0., 0.};

    auto solution = BiCG<double>(matrix, b, init_vec, tolerance);
    ASSERT_NEAR(solution[0], 18.92843, 1e-5);
    ASSERT_NEAR(solution[1], 0.535783, 1e-6);
    ASSERT_NEAR(solution[2], 0.333333, 1e-6);
    ASSERT_NEAR(solution[3], -1.61315, 1e-5);
    ASSERT_NEAR(solution[4], 9.22631, 1e-5);
    ASSERT_NEAR(solution[5], 0.0696325, 1e-7);
}