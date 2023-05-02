//
// Created by lonertutu on 29.04.23.
//

#ifndef SLAE_LIB_BICG_HPP
#define SLAE_LIB_BICG_HPP

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

template <typename T>
std::vector<T> BiCG(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, T tolerance, T w) {

    std::vector<T> x = init_vec;
    std::vector<T> r = A * x - b;
    std::vector<T> p = r;
    std::vector<T> rk = r;
    std::vector<T> pk = r;
    std::vector<T> q = b.size();
    std::vector<T> teta = b.size();

    std::vector<T> qo = r*r/(r*A*p);

    while (EuclidNorm(r) > tolerance && r*r != 0) {
        prev = (d * r);
        alpha = prev / (d * (A * d));
        x = x - alpha * d;
        r = A * x - b;
        d = r + (r * r) / prev * d;
        //std::cout <<  x[0] * h_min[0]<< ", ";
    }
}

#endif //SLAE_LIB_BICG_HPP
