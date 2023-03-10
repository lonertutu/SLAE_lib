//
// Created by lonertutu on 09.03.23.
//
#include "../src/SLAE_Solvers/Jacobi.hpp"
#include "gtest/gtest.h"

TEST(TEST_Jacobi, Jacobi_first) {
    std::set<Triplet<double>> data{{0, 0, 2.}, {0, 1, 1.}, {0, 2, 3.},
                                   {1, 0, 1.}, {1, 1, 30.}, {1, 2, 2.},
                                   {2, 0, 3.}, {2, 1, 2.}, {2, 2, 2.}};
    CSR<double> matrix(3, 3, data);
    std::vector<double> b(3);
    b[0] = 1.;
    b[1] = 2.;
    b[2] = 3.;
    std::vector<double> init_vec(3);
    init_vec[0] = 1.;
    init_vec[1] = 1.;
    init_vec[2] = 1.;
    double tolerance = 1e-12;
    auto sol_vec = Jacobi<double>(matrix, b, init_vec, tolerance);

    std::cout << sol_vec[0] << " " << sol_vec[1] << " " << sol_vec[2];
}