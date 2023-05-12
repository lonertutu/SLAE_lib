//
// Created by lonertutu on 29.04.23.
//

#ifndef SLAE_LIB_BICG_HPP
#define SLAE_LIB_BICG_HPP

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include "../Tools/Overloads.hpp"


/*!
    \brief Function of finding a solution using the biconjugate gradients method

    \param A - sparse matrix
    \param b - free coefficients column
    \param init_vec - vector of initial approximation to the solution
    \param tolerance - accuracy for residual estimation

*/

template <typename T>
std::vector<T> BiCG(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance) {

    std::vector<T> x = init_vec;
    std::vector<T> r = A * x - b;
    std::vector<T> rtilde = r;
    std::vector<T> ptilde = r;
    std::vector<T> q, qtilde;
    T rho, tmp;
    T beta, alpha;

    auto AT = A.transpose();
    rho = r * rtilde;
    tmp = rho;

    while (EuclidNorm(r) > tolerance && rho  != 0) {
        beta = rho / tmp;
        p = r + beta * p;
        ptilde = rtilde + beta * ptilde;
        q = A * p;
        qtilde = AT * ptilde;
        alpha = rho / (ptilde * q);
        x = x - alpha * p;
        r = r - alpha * q;
        rtilde = rtilde - alpha * qtilde;
        tmp = rho;
        rho = r * rtilde;
    }
    return x;
}
#endif //SLAE_LIB_BICG_HPP
