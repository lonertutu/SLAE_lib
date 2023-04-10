//
// Created by lonertutu on 04.03.23.
//
#pragma once

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include "../Tools/Overloads.hpp"
#include <vector>
#include <iostream>



template <typename T>
std::vector<T> Gauss_Seidel(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, T tolerance) {

    std::vector<T> x = init_vec;
    std::vector<T> r(b.size());
    std::vector<T> A_elements = A.get_elements();
    std::vector<uint32_t> columns = A.get_columns();
    std::vector<uint32_t> rows = A.get_rows();

    r = b - A * x;

    while (EuclidNorm(r) > tolerance) {
        for (uint32_t i = 0; i < b.size(); ++i) {
            x[i] = b[i];
            double diagonal;
            for (uint32_t j = rows[i]; j < rows[i + 1]; ++j) {
                if (i == columns[j]) {
                    diagonal = A(i, columns[j]);
                    continue;
                }
                x[i] -= A_elements[j] * x[columns[j]];
            }
            x[i] = x[i] /diagonal;
        }
        r = b - A * x;
        std::cout << EuclidNorm(r) << std::endl;
    }
    return x;
}


// Отдельно методы
template <typename T>
std::vector<T> Iteration_Gauss_Seidel(const CSR<T> &A, const std::vector<T> &b, std::vector<T> x) {

    std::vector<T> A_elements = A.get_elements();
    std::vector<uint32_t> columns = A.get_columns();
    std::vector<uint32_t> rows = A.get_rows();

    for (uint32_t i = 0; i < b.size(); ++i) {
        x[i] = b[i];
        double diagonal;
        for (uint32_t j = rows[i]; j < rows[i + 1]; ++j) {
            if (i == columns[j]) {
                diagonal = A(i, columns[j]);
                continue;
            }
            x[i] -= A_elements[j] * x[columns[j]];
        }
        x[i] = x[i] / diagonal;
    }
    return x;
}
template <typename T>
std::vector<T> Down_Iteration_Gauss_Seidel(const CSR<T> &A, const std::vector<T> &b, std::vector<T> x) {

    std::vector<T> A_elements = A.get_elements();
    std::vector<uint32_t> columns = A.get_columns();
    std::vector<uint32_t> rows = A.get_rows();

    for (int i = b.size(); i >= 0; i--) {
        x[i] = b[i];
        double diagonal;
        for (uint32_t j = rows[i]; j < rows[i + 1]; ++j) {
            if (i == columns[j]) {
                diagonal = A(i, columns[j]);
                continue;
            }
            x[i] -= A_elements[j] * x[columns[j]];
        }
        x[i] = x[i] / diagonal;
    }
    return x;
}

template <typename T>
std::vector<T> SymGauss_Seidel(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, T tolerance) {

    std::vector<T> x = init_vec;
    std::vector<T> r(b.size());

    r = b - A * x;
    while (EuclidNorm(r) > tolerance) {
        x = Iteration_Gauss_Seidel(A, b, x);
        x = Down_Iteration_Gauss_Seidel(A, b, x);
        r = b - A * x;
        //std::cout << EuclidNorm(r) << std::endl;
    }
    return x;
}