//
// Created by lonertutu on 04.03.23.
//

#ifndef SLAE_LIB_Simple_iteration_HPP
#define SLAE_LIB_Simple_iteration_HPP

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include "../Tools/Overloads.hpp"
#include "../Tools/Chebyshev_polynomial.hpp"
#include <vector>
#include <iostream>




// tau = 2/(lambda_max+lambda_min)
template<typename T>
std::vector<T> simpIter(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance, const T &parametr) {

    std::vector<T> x = init_vec;
    std::vector<T> r =  A*x - b;

    std::vector<T> h_min = {1, 0, 0, 0};
    std::vector<T> h_max = {0, 0, 0, 1};

    //out.open("Simple_iteration.txt");
    while(EuclidNorm(r) > tolerance) {
        if (parametr != 0.)
                x = x - parametr*r;
        r =  A*x - b;
        std::cout << std::log(EuclidNorm(r))<< ", ";
    }
    return x;
}

template<typename T>
std::vector<T> simpIter_chebBoost(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec,
                                  const T &tolerance, const T &lambda_min, const T &lambda_max, const unsigned int n, const unsigned int pow) {

    std::vector<T> x = init_vec;
    std::vector<T> r = A * x - b;
    std::vector<T> roots = chebRoots(n, lambda_min, lambda_max);
    //for (uint32_t i = 0; i < n; ++i) {
    //    roots[i] = chebRootsShake(pow)[i];
    //}
//    for (uint32_t i = 0; i < roots.size(); ++i)
//        std::cout << roots[i] << " ";

    while(EuclidNorm(r) > tolerance) {
        for (uint32_t i = 0; i < roots.size(); ++i) {
            x = x - 1 / roots[i] * r;
            r = A*x - b;
            std::cout << std::log(EuclidNorm(r))<< ", ";
        }
    }
    return x;
}

#endif