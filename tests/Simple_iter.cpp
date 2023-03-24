//
// Created by lonertutu on 05.03.23.
//

#include "../src/SLAE_Solvers/Simple_iteration.hpp"
#include "gtest/gtest.h"

//TEST(Simple_Iter, first_test) {
//    std::set<Triplet<double>> data1{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
//                                   {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.},
//                                   {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
//    CSR<double> matrix_iter(3, 3, data1);
//
//    double tolerance = 1e-12;
//    std::vector<double> b = {20.0, 30.0, 1.0};
//    std::vector<double> init_vec = {0., 0., 0.};
//
//    for (double parametr = 0.0001; parametr  < 0.1900; parametr += 0.0001)
//        auto solution = Simple_Iter<double>(matrix_iter, b, init_vec, tolerance, parametr);
//}