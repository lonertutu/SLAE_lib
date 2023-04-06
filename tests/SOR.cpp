//
// Created by lonertutu on 24.03.23.
//

#include "../src/SLAE_Solvers/SOR.hpp"
#include "gtest/gtest.h"

TEST(TEST_SOR, SOR_first) {
    std::set<Triplet<double>> data{{0, 0, 400.}, {0, 1, 5.}, {0, 2, 6.},
                                   {1, 0, 5.}, {1, 1, 60.}, {1, 2, 9.},
                                   {2, 0, 6.}, {2, 1, 9.}, {2, 2, 40.}};
    CSR<double> matrix(3, 3, data);
    std::vector<double> b(3);
    b[0] = 2.;
    b[1] = 2.;
    b[2] = 4.;
    double tolerance = 1e-12;
    double w = 0.8;
    auto sol_vec = SOR<double>(matrix, b, tolerance, w);

    std::cout << sol_vec[0] << " " << sol_vec[1] << " " << sol_vec[2];
}

TEST(TEST_SOR, SOR_sec) {
    std::set<Triplet<double>> data{{0, 0, 12.}, {0, 1, 17.}, {0, 2, 3.},
                                   {1, 0, 17.}, {1, 1, 15825.}, {1, 2, 28.},
                                   {2, 0, 3.}, {2, 1, 28.}, {2, 2, 238.}};
    CSR<double> matrix(3, 3, data);
    std::vector<double> b(3);
    b[0] = 1.;
    b[1] = 2.;
    b[2] = 3.;
    double tolerance = 1e-12;
    double w = 0.9;
    auto sol_vec = SOR<double>(matrix, b, tolerance, w);

    //std::cout << sol_vec[0] << " " << sol_vec[1] << " " << sol_vec[2];
    ASSERT_NEAR(sol_vec[0], 0.0804084, 1e-6);
    ASSERT_NEAR(sol_vec[1], 1.94982e-05, 1e-6);
    ASSERT_NEAR(sol_vec[2], 0.0115892, 1e-6);
}