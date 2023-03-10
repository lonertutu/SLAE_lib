//
// Created by lonertutu on 05.03.23.
//
//#include "../src/SLAE_Solvers/Simple_iteration.hpp"
//#include "../src/Matrixes/CSR.cpp"
//#include "gtest/gtest.h"

//TEST(Simple_Iter, first_test) {
//    std::set<Triplet<double>> data{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
//                                   {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.},
//                                   {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
//    CSR<double> first_CSR = CSR<double>(3, 3, data);
//
//    double tolerance = 0;
//    std::vector<double> b = {20.0, 30.0, 1.0};
//    std::vector<double> init_vec = {0., 0., 0.};
//
 //   std::vector<double> solution = Simple_Iter(first_CSR, b, init_vec, tolerance, tolerance);
//}