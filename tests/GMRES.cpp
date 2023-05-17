//
// Created by lonertutu on 10.05.23.
//

#include "../src/SLAE_Solvers/GMRES.hpp"
#include "gtest/gtest.h"

TEST(GMRES, first_test) {
    std::set<Triplet<double>> data{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
                                    {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.1},
                                    {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
    CSR<double> matrix_iter(3, 3, data);

    double tolerance = 1e-6;
    std::vector<double> b = {20.0, 30.0, 1.0};
    std::vector<double> init_vec = {10., 10., 10.};

    auto solution = GMRES<double>(matrix_iter, b, init_vec, tolerance);
    std::cout << solution[0] << " " << solution[1] << " " << solution[2];
    ASSERT_NEAR(solution[0], 1.59507, 1e-5);
    ASSERT_NEAR(solution[1], 4.04935, 1e-5);
    ASSERT_NEAR(solution[2], 0.595065, 1e-5);
}