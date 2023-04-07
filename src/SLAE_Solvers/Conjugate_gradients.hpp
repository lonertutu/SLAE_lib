//
// Created by lonertutu on 06.04.23.
//

#pragma once

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include "../Tools/Overloads.hpp"
#include <vector>
#include <iostream>

/*!
    \brief Function of finding a solution using the conjugate gradients method
           With alpha - argmin of the functional

    \param A - sparse matrix
    \param b - free coefficients column
    \param tolerance - accuracy for residual estimation

*/
template<typename T>
std::vector<T> conjGrad(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance) {

    std::vector<T> x = init_vec;
    std::vector<T> r = A * x - b;
    std::vector<T> d = r;
    T alpha;
    T prev;

    while (EuclidNorm(r) > tolerance) {
        prev = (d * r);
        alpha = prev / (d * (A * d));
        x = x - alpha * d;
        r = A * x - b;
        d = r + (r * r) / prev * d;
        std::cout << EuclidNorm(d) << " ";
    }
    return x;
}