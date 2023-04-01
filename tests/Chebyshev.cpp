//
// Created by lonertutu on 29.03.23.
//
#include "../src/Tools/Chebyshev_polynomial.hpp"
#include "gtest/gtest.h"

TEST(TEST_Cheb, Cheb_first) {


    std::vector<double> sol_vec(100);
    //sol_vec.reserve(100);
    for (uint32_t i = 0; i < 8; ++i) {
        sol_vec[i] = chebRootsShake(3)[i];
        //std::cout << sol_vec[i] << " ";
    }
    ASSERT_EQ(sol_vec[0], 0);
    ASSERT_EQ(sol_vec[1], 7);
    ASSERT_EQ(sol_vec[2], 3);
    ASSERT_EQ(sol_vec[3], 4);
    ASSERT_EQ(sol_vec[4], 1);
    ASSERT_EQ(sol_vec[5], 6);
    ASSERT_EQ(sol_vec[6], 2);
    ASSERT_EQ(sol_vec[7], 5);
}