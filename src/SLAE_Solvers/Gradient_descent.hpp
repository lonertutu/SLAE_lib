//
// Created by lonertutu on 06.04.23.
//
#ifndef SLAE_LIB_Gradient_descent_HPP
#define SLAE_LIB_Gradient_descent_HPP

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include "../Tools/Overloads.hpp"
#include <vector>
#include <iostream>


/*!
    \brief Function of finding a solution using the gradient descent method.
           With alpha - argmin of the functional

    \param A - sparse matrix
    \param b - free coefficients column
    \param tolerance - accuracy for residual estimation

*/
template<typename T>
std::vector<T> gradDescent(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance) {

    std::vector<T> x = init_vec;
    std::vector<T> r =  A*x - b;
    std::vector<T> h_min = {1, 0, 0, 0};
    std::vector<T> h_max = {0, 0, 0, 1};
    T alpha;

    while(EuclidNorm(r) > tolerance) {
        alpha = (r * r) / (r * (A * r));
        x = x - alpha * r;
        r =  A*x - b;
        std::cout <<  x[3] * h_max[3]<< ", ";
    }
    return x;
}

#endif