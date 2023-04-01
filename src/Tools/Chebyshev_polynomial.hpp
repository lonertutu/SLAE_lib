//
// Created by lonertutu on 29.03.23.
//

#pragma once

#include <iostream>
#include <vector>
#include <cmath>

/*!
    \brief Function of solving Chebyshev polynomial

    \param r - power of two

*/
template <typename T>
std::vector<T> chebRoots(const uint32_t n, const T lambda_min, const T lambda_max) {
    std::vector<T> roots(n);

    const T cos_const = std::cos(M_PI/n);
    const T sin_const = std::sin(M_PI/n);  // Ошибка
    double sinB = std::sin(M_PI/(2*n));
    roots[0] = std::cos(M_PI/(2*n));

    for (uint32_t k = 1; k < n; ++k) {
        roots[k] = roots[k - 1] * cos_const  - sinB * sin_const;
        sinB = roots[k - 1] * sin_const + sinB * cos_const;
    }
    //Normalization
    for (uint32_t k = 0; k < n; ++k) {
        roots[k - 1] = 0.5*((lambda_max + lambda_min) + roots[k-1]*(lambda_max - lambda_min));
    }
    return roots;
}

/*!
    \brief Function of shuffling root indices for better convergence with usage of recursion

    \param r - power of two

*/
std::vector<unsigned int> chebRootsShake(unsigned int r) {
    uint32_t n = std::pow(r, 2);  // не использовать pow
    //std::vector<uint32_t> indexes(n);
    std::vector<uint32_t> next(n);
    std::vector<uint32_t> indexes = {0,1};
    uint32_t order = 2;
    for (uint32_t i = 1; i < r; ++i) {
        order = std::pow(2, i + 1);
        for (uint32_t j = 0; j < order - 1; j += 2){
            next[j] = indexes[j/2];
            next[j + 1] = order - 1 - next[j];
        }
        indexes = next;
    }
    return indexes;

}