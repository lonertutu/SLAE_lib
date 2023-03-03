//
// Created by lonertutu on 01.03.23.
//
#include "../src/Matrixes/tridiagonal_matrix.hpp"
#include "gtest/gtest.h"

//TEST(A, B) {
//    std::cout << "test";
//}
//ASSERT_EQ(x, y) //проверка на сравнение двух величин
// _NE, _LT - less than, _LE, _GT, _GE - greater than or equal

TEST(Matrix, Create_zero_matrix)
{
    //Arrange
    int size = 10;
    //ACT
    SLAE::Tri_matrix::Tridiagonal_matrix Matrix_of_zeroes = SLAE::Tri_matrix::Tridiagonal_matrix::zero_field(size);

    // ASSERT
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(Matrix_of_zeroes(i, j), 0.0);
        }
    }
}
