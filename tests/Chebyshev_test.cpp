//
// Created by lonertutu on 29.03.23.
//
#include "../src/Tools/Chebyshev_polynomial.hpp"
#include "gtest/gtest.h"


// Проверка работы подсчёта корней полиномов Чебышёва и их перемешивание
TEST(TEST_Cheb, Cheb_first) {
double lambda_min = 1;
double lambda_max = 100;
std::vector<double> ro = chebRoots(32, lambda_min, lambda_max);
for (double i : ro)
    std::cout << i << "   ";

// перемешивание только первых 8 корней
for (uint32_t i = 0; i < 8; ++i) {
    ro[i] = chebRootsShake(3)[i];
}
    ASSERT_EQ(ro[0], 0);
    ASSERT_EQ(ro[1], 7);
    ASSERT_EQ(ro[2], 3);
    ASSERT_EQ(ro[3], 4);
    ASSERT_EQ(ro[4], 1);
    ASSERT_EQ(ro[5], 6);
    ASSERT_EQ(ro[6], 2);
    ASSERT_EQ(ro[7], 5);
}


TEST(TEST_Cheb, Cheb_second) {
    double lambda_min = 2.25;
    double lambda_max = 15.88;
    std::vector<double> ro = chebRoots(32, lambda_min, lambda_max);
    for (double i : ro)
        std::cout << i << "   ";
        std::cout << std::endl;

// перемешивание только первых 8 корней
    for (uint32_t i = 0; i < 8; ++i) {
        ro[i] = chebRootsShake(3)[i];
    }
    for (double i : ro)
        std::cout << i << "   ";

}