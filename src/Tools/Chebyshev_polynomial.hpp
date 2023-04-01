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
std::vector<T> Solutions(const uint32_t r, const T lambda_min, const T lambda_max) {

    uint32_t n = std::pow(2, r);
    std::vector<T> roots(n);

    const T cos_const = std::cos(M_PI/n);
    const T sin_const = std::cos(M_PI/n);
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
    // написать перемешалку
}