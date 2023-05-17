//
// Created by lonertutu on 24.04.23.
//

#ifndef SLAE_LIB_GMRES_HPP
#define SLAE_LIB_GMRES_HPP

#include "../Matrixes/Dense.hpp"
#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include "../Tools/Overloads.hpp"
#include <vector>
#include <iostream>

/*!
    \brief Function of creating an orthonormal basis of the Krylov subspace

    \param[in] A - sparse matrix
    \param[in] V - dense matrix
    \param[in] H - dense matrix of the Hessenberg type

*/
template <typename T>
void ArnoldiAlg(const CSR<T>& A, DenseMatrix<T>& V, DenseMatrix<T>& H, uint32_t j) {

    std::vector<T> tmp(H.sizeWidth());
    double eps = 1e-12;
    tmp = A * V.get_column(j);
    //We project the vector v(j) onto the others v1,...,v(j-1) and get the ONB
    for (uint32_t i = 0; i < j + 1; ++j) {
        H(i, j) = V.get_column(i) * tmp;
        tmp = tmp - H(i, j) * V.get_column(i);
    }
    H(j + 1, j) = EuclidNorm(tmp);
    if (H(j + 1, j) > eps) //check for non-zero vector
        V.fill_col(tmp / H(j + 1, j), j + 1);
}

/*!
    \brief Gaussian back substitution to find y of a system Ry = z

    \param[in] R - dense matrix
    \param[in] V - dense matrix
    \param[in] H - dense matrix of the Hessenberg type
    \param[in] n - solution vector size

*/
template <typename T>
std::vector<T> GaussBackSubstitution(const DenseMatrix<T>& R, const std::vector<T>& b, const int& n)
{
    std::vector<T> solvec(n);

    for (uint32_t i = 0; i < n; ++i)
    {
        solvec[n - i - 1] = b[n - i - 1];
        for (uint32_t j = n - 1; j > n - i - 1; --j)
            solvec[n - i - 1] -= R(n - i - 1, j) * solvec[j];
        if (R(n - i - 1, n - i - 1) != 0.)
            solvec[n - i - 1] /= R(n - i - 1, n - i - 1);
    }
    return solvec;
}

/*!
    \brief Gaussian back substitution to find y of a system Ry = z

    \param[in] H - dense matrix of the Hessenberg type
    \param[in] rotCosSin - vector of pairs of cos and sin of the corresponding rotation
    \param[in] p - a vector with values that rotate

*/
template <typename T>
void GivensRotation(DenseMatrix<T>& H, std::vector<std::pair<T, T>>& rotCosSin, std::vector<T>& p, uint32_t j) {
    double sin, cos;
    double alpha, beta;
    for (uint32_t i = 0; i < j; ++i)
    {
        beta = H(i, j);
        H(i, j) = H(i, j) * rotCosSin[i].first - H(i + 1, j) * rotCosSin[i].second;
        H(i + 1, j) = beta * rotCosSin[i].second + H(i + 1, j) * rotCosSin[i].first;
    }
    alpha = std::sqrt(H(j, j) * H(j, j) + H(j + 1, j) * H(j + 1, j));
    cos = H(j, j) / alpha;
    sin = - H(j + 1, j) / alpha;
    std::pair<double, double> a(cos, sin);
    rotCosSin[j] = a;


    beta = H(j, j);
    H(j, j) = H(j, j) * cos - H(j + 1, j) * sin;
    H(j + 1, j) = beta * sin + H(j + 1, j) * cos;
    alpha = p[j];
    //Making a rotation
    p[j] = p[j] * cos - p[j + 1] * sin;
    p[j + 1] = alpha * sin + p[j + 1] * cos;
}

/*!
    \brief Generalized minimal residual method

    \param[in] A - sparse matrix of a system Ax = b
    \param[in] b - free coefficients column
    \param[in] init_vec - initial approximation to the solution
    \param[in] tolerance - accuracy for residual estimation

    \param[out] x - system solution vector

*/
template<typename T>
std::vector<T> GMRES(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance){
    uint32_t i = A.sizeHight();
    DenseMatrix<T> V(i, i + 1);
    DenseMatrix<T> H(i + 1, i);
    std::vector<T> r = A * init_vec - b;
    std::vector<T> x = init_vec;
    std::vector<T> z(i + 1);
    std::vector<T> y;
    std::vector<std::pair<T, T>> rotCosSin(i + 1, {0., 0.});
    bool end = false;

    while (!end)
    {
        std::fill(z.begin(), z.end(), 0.);
        z[0] = EuclidNorm(r);
        V.fill_col(r, 0);

        if (EuclidNorm(r) != 0.)
            V.fill_col(r / EuclidNorm(r), 0);

        for(uint32_t j = 1; j < i + 1; ++j)
        {
            ArnoldiAlg(A, V, H, j - 1);
            GivensRotation(H,  rotCosSin, z,j - 1);

            if (std::abs(z[j]) < tolerance)
            {
                y = GaussBackSubstitution(H, z, j);
                for (uint32_t k = 0; k < j; ++k)
                    x = x - V.get_column(k) * y[k];
                end = true;
                break;
            }
        }
        if (!end)
        {
            y = GaussBackSubstitution(H, z, i);
            for (uint32_t k = 0; k < i; ++k)
                x = x - y[k] * V.get_column(k);
        }
        r = A * x - b;
    }
    return x;
}

#endif //SLAE_LIB_GMRES_HPP
