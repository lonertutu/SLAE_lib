//
// Created by lonertutu on 05.03.23.
//

#include "../src/SLAE_Solvers/Simple_iteration.hpp"
#include "gtest/gtest.h"

TEST(Simple_Iter, first_test) {
    std::set<Triplet<double>> data1{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
                                   {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.},
                                   {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
    CSR<double> matrix_iter(3, 3, data1);

    double tolerance = 1e-12;
    std::vector<double> b = {20.0, 30.0, 1.0};
    std::vector<double> init_vec = {0., 0., 0.};
    double parametr = 0.05;

    auto solution = simpIter<double>(matrix_iter, b, init_vec, tolerance, parametr);
    ASSERT_NEAR(solution[0], 1.5942, 1e-5);
    ASSERT_NEAR(solution[1], 4.05797, 1e-5);
    ASSERT_NEAR(solution[2], 0.594203, 1e-5);
}

TEST(Simple_Iter, second_test) {
    std::set<Triplet<double>> data1{{0, 0, 10.}, {0, 1, 1.}, {0, 2, 0.},
                                    {1, 0, 1.}, {1, 1, 7.}, {1, 2, 0.},
                                    {2, 0, 0.}, {2, 1, 0.1}, {2, 2, 1.}};
    CSR<double> matrix_iter(3, 3, data1);

    double tolerance = 1e-12;
    std::vector<double> b = {20.0, 30.0, 1.0};
    std::vector<double> init_vec = {0., 0., 0.};
    double lambda_min = 1;
    double lambda_max = 10;

    std::vector<double> solution;
    solution = simpIter_chebBoost<double>(matrix_iter, b, init_vec, tolerance, lambda_min, lambda_max, 32, 6);

    std::cout << solution[0] << " " << solution[1] << " " << solution[2];
}

TEST(Simple_Iter, task_test) {
    std::set<Triplet<double>> data1{{0, 0, 8.}, {0, 1, 0.}, {0, 2, 0.}, {0, 3, 0.},
                                    {1, 0, 0.}, {1, 1, 9.0}, {1, 2, 0.}, {1, 3, 0.},
                                    {2, 0, 0.}, {2, 1, 0.}, {2, 2, 10.}, {2, 3, 0.},
                                    {3, 0, 0.}, {3, 1, 0.}, {3, 2, 0.}, {3, 3, 12.}};
    CSR<double> matrix_iter(4, 4, data1);

    double tolerance = 1e-13;
    std::vector<double> b = {3.0, 3.0, 3.0, 3.0};
    std::vector<double> init_vec = {0., 0., 0., 0.};
    double parametr = 0.9*2/12;
    double lambda_min = 8;
    double lambda_max = 12;

    auto solution = simpIter<double>(matrix_iter, b, init_vec, tolerance, parametr);
    std::cout << solution[0] << " " << solution[1] << " " << solution[2] << " " << solution[3];
}

TEST(Simple_Iter, task_test2) {
    std::set<Triplet<double>> data1{{0, 0, 8.}, {0, 1, 0.}, {0, 2, 0.}, {0, 3, 0.},
                                    {1, 0, 0.}, {1, 1, 9.0}, {1, 2, 0.}, {1, 3, 0.},
                                    {2, 0, 0.}, {2, 1, 0.}, {2, 2, 10.}, {2, 3, 0.},
                                    {3, 0, 0.}, {3, 1, 0.}, {3, 2, 0.}, {3, 3, 12.}};
    CSR<double> matrix_iter(4, 4, data1);

    double tolerance = 1e-13;
    std::vector<double> b = {3.0, 3.0, 3.0, 3.0};
    std::vector<double> init_vec = {0., 0., 0., 0.};
    double lambda_min = 8;
    double lambda_max = 12;
    double parametr = 2/(lambda_max + lambda_min);

    auto solution = simpIter<double>(matrix_iter, b, init_vec, tolerance, parametr);
    std::cout << solution[0] << " " << solution[1] << " " << solution[2] << " " << solution[3];
}

TEST(Simple_Iter, task_test3) {
    std::set<Triplet<double>> data1{{0, 0, 8.}, {0, 1, 0.}, {0, 2, 0.}, {0, 3, 0.},
                                    {1, 0, 0.}, {1, 1, 9.0}, {1, 2, 0.}, {1, 3, 0.},
                                    {2, 0, 0.}, {2, 1, 0.}, {2, 2, 10.}, {2, 3, 0.},
                                    {3, 0, 0.}, {3, 1, 0.}, {3, 2, 0.}, {3, 3, 12.}};
    CSR<double> matrix_iter(4, 4, data1);

    double tolerance = 1e-13;
    std::vector<double> b = {3.0, 3.0, 3.0, 3.0};
    std::vector<double> init_vec = {0., 0., 0., 0.};
    double lambda_min = 8;
    double lambda_max = 12;

    auto solution = simpIter_chebBoost<double>(matrix_iter, b, init_vec, tolerance, lambda_min, lambda_max, 8, 3);
    std::cout << solution[0] << " " << solution[1] << " " << solution[2] << " " << solution[3];
}

TEST(Simple_Iter, task_test4) {

    std::set<Triplet<double>> values;
    std::vector<double> b(289, 4);
    std::vector<double> init_vec(289, 0);

    for (uint32_t i = 0; i < 289;  ++i) {
        values.insert(Triplet<double> {i,i, 38});
    }
    for (uint32_t i = 0; i < 144; ++i) {
        values.insert(Triplet<double>{i, i + 144, 8});
        values.insert(Triplet<double>{i + 144, i, 8});
        values.insert(Triplet<double>{i, i + 1, 8});
        values.insert(Triplet<double>{i + 1, i, 8});
    }
    CSR<double> matrix_iter(289, 289, values);
    double tolerance = 1.07e-13;
    double lambda_max = 107.51;
    double parametr = 1/lambda_max;

    auto solution = simpIter<double>(matrix_iter, b, init_vec, tolerance, parametr);
    //std::cout << solution[0] << " " << solution[1] << " " << solution[2] << " " << solution[3];
}

TEST(Simple_Iter, task_test5) {

    std::set<Triplet<double>> values;
    std::vector<double> b(289, 4);
    std::vector<double> init_vec(289, 0);

    for (uint32_t i = 0; i < 289;  ++i) {
        values.insert(Triplet<double> {i,i, 38});
    }
    for (uint32_t i = 0; i < 144; ++i) {
        values.insert(Triplet<double>{i, i + 144, 8});
        values.insert(Triplet<double>{i + 144, i, 8});
        values.insert(Triplet<double>{i, i + 1, 8});
        values.insert(Triplet<double>{i + 1, i, 8});
    }
    CSR<double> matrix_iter(289, 289, values);
    double tolerance = 1.07e-13;
    double lambda_max = 107.51;
    double lambda_min = 44.48;
    double parametr = 2/(lambda_max + lambda_min);

    auto solution = simpIter<double>(matrix_iter, b, init_vec, tolerance, parametr);
    //std::cout << solution[0] << " " << solution[1] << " " << solution[2] << " " << solution[3];
}

TEST(Simple_Iter, task_test6) {

    std::set<Triplet<double>> values;
    std::vector<double> b(289, 4);
    std::vector<double> init_vec(289, 0);

    for (uint32_t i = 0; i < 289;  ++i) {
        values.insert(Triplet<double> {i,i, 38});
    }
    for (uint32_t i = 0; i < 144; ++i) {
        values.insert(Triplet<double>{i, i + 144, 8});
        values.insert(Triplet<double>{i + 144, i, 8});
        values.insert(Triplet<double>{i, i + 1, 8});
        values.insert(Triplet<double>{i + 1, i, 8});
    }
    CSR<double> matrix_iter(289, 289, values);
    double tolerance = 1.07e-13;
    double lambda_max = 80.51;
    double lambda_min = 44.48;


    auto solution = simpIter_chebBoost<double>(matrix_iter, b, init_vec, tolerance, lambda_min, lambda_max, 8, 3);
}

TEST(Simple_Iter, CW_test) {
    std::set<Triplet<double>> data1{{0, 0, 10.}, {0, 1, 3.}, {0, 2, 6.},
                                    {1, 0, 3.}, {1, 1, 5.}, {1, 2, 1.},
                                    {2, 0, 6.}, {2, 1, 1.}, {2, 2, 8.}};
    CSR<double> matrix_iter(3, 3, data1);

    double tolerance = 1e-12;
    std::vector<double> b = {0.0, 0.0, 0.0};
    std::vector<double> init_vec = {0., 0., 0.};
    double lambda_min = 1;
    double lambda_max = 10;

    std::vector<double> solution;
    solution = simpIter_chebBoost<double>(matrix_iter, b, init_vec, tolerance, lambda_min, lambda_max, 32, 6);

    std::cout << solution[0] << " " << solution[1] << " " << solution[2];
}
