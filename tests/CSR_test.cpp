//
// Created by lonertutu on 01.03.23.
//

#include "gtest/gtest.h"
#include "../src/Matrixes/CSR.cpp"

//Filling with a few elements
TEST(TEST_CSR, CSR_fisrt){
    std::set<Triplet<double>> data{{0, 0, 4}, {1, 1, 9}};
    CSR<double> matrix(3, 3, data);
    //std::cout << matrix;
}

//Filling a whole matrix
TEST(TEST_CSR, CSR_second) {
    std::set<Triplet<double>> data{{0, 0, 10.}, {0, 1, 11.}, {0, 2, 4.},
                                   {1, 0, 4.}, {1, 1, 3.}, {1, 2, 2.},
                                   {2, 0, 4.}, {2, 1, 6.}, {2, 2, 5.}};

    CSR<double> matrix(3, 3, data);
}

TEST(TEST_CSR, CSR_third) {
    std::set<Triplet<double>> data{{0, 0, 4}, {1, 1, 4}};
    CSR<double> matrix(3, 3, data);
    std::vector<double> b(3);
    b[0] = 3.0; b[1] = 2.0; b[2] = 0;
    //std::cout << b[0] << b[1] << b[2] << std::endl;

    // проверка на равенство кол-ва столбцов матрицы и кол-ву строк
    ASSERT_EQ(b.size(), matrix.sizeWidth());

    //проверка на перемножение
    std::vector<double> sol_vec(matrix.sizeWidth());
    sol_vec = matrix * b;
    ASSERT_EQ(sol_vec[0], 12.);
    ASSERT_EQ(sol_vec[1], 8.);
    ASSERT_EQ(sol_vec[2], 0.);
}

TEST(TEST_CSR, CSR_fourth) {
    std::set<Triplet<double>> data{{0, 0, 10.}, {0, 1, 11.}, {0, 2, 4.},
                                   {1, 0, 4.}, {1, 1, 3.}, {1, 2, 2.},
                                   {2, 0, 4.}, {2, 1, 6.}, {2, 2, 5.}};

    CSR<double> matrix(3, 3, data);

    std::cout << matrix(0, 0) << " " << matrix(2, 2);
    std::cout << matrix.get_column(0);
}

TEST(A, b) {
    std::set<Triplet<double>> data{{0, 0, 2.}, {0, 2, 1.},
                                   {1, 1, 1.}, {2, 2, 1.}};
    CSR<double> matrix(3, 3, data);
    std::vector<double> x{-1, 2, 3};
    auto Ax = matrix * x;
    ASSERT_DOUBLE_EQ(Ax[0], 1);
    ASSERT_DOUBLE_EQ(Ax[1], 2);
    ASSERT_DOUBLE_EQ(Ax[2], 3);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


