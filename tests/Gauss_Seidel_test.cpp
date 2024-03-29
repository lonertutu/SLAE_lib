//
// Created by lonertutu on 05.03.23.
//
#include "../src/SLAE_Solvers/Gauss_Seidel.hpp"
#include "gtest/gtest.h"

TEST(TEST_Gauss, Gauss_first) {
    std::set<Triplet<double>> data{{0, 0, 12.}, {0, 1, 17.}, {0, 2, 3.},
                                   {1, 0, 17.}, {1, 1, 15825.}, {1, 2, 28.},
                                   {2, 0, 3.}, {2, 1, 28.}, {2, 2, 238.}};
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
    auto sol_vec = Gauss_Seidel<double>(matrix, b, init_vec, tolerance);

    std::cout << sol_vec[0] << " " << sol_vec[1] << " " << sol_vec[2];
}

TEST(TEST_Gauss, Gauss_second) {
    std::set<Triplet<double>> data{{0, 0, 4.}, {0, 1, 5.}, {0, 2, 6.},
                                   {1, 0, 5.}, {1, 1, 6.}, {1, 2, 9.},
                                   {2, 0, 6.}, {2, 1, 9.}, {2, 2, 4.}};
    CSR<double> matrix(3, 3, data);
    std::vector<double> b(3);
    b[0] = 2.;
    b[1] = 2.;
    b[2] = 4.;
    std::vector<double> init_vec(3);
    init_vec[0] = 1.;
    init_vec[1] = 1.;
    init_vec[2] = 1.;
    double tolerance = 1e-12;
    auto sol_vec = Gauss_Seidel<double>(matrix, b, init_vec, tolerance);

    std::cout << sol_vec[0] << " " << sol_vec[1] << " " << sol_vec[2];
}

TEST(TEST_Gauss, symgauss) {
    std::set<Triplet<double>> data{{0, 0, 4.}, {0, 1, 5.}, {0, 2, 6.},
                                   {1, 0, 5.}, {1, 1, 6.}, {1, 2, 9.},
                                   {2, 0, 6.}, {2, 1, 9.}, {2, 2, 4.}};
    CSR<double> matrix(3, 3, data);
    std::vector<double> b(3);
    b[0] = 2.;
    b[1] = 2.;
    b[2] = 4.;
    std::vector<double> init_vec(3);
    init_vec[0] = 1.;
    init_vec[1] = 1.;
    init_vec[2] = 1.;
    double tolerance = 1e-12;
    auto sol_vec = SymGauss_Seidel<double>(matrix, b, init_vec, tolerance);

    std::cout << sol_vec[0] << " " << sol_vec[1] << " " << sol_vec[2];
}

