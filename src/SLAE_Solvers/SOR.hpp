//
// Created by lonertutu on 24.03.23.
//

#pragma once

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include "../Tools/Overloads.hpp"
#include <vector>


template <typename T>
std::vector<T> SOR(const CSR<T> &A, const std::vector<T> &b, T tolerance, T w) {

    std::vector<T> x(b.size());
    std::vector<T> iter_x(b.size());
    std::vector<T> r(b.size());
    std::vector<T> A_elements = A.get_elements();

    std::vector<uint32_t> columns = A.get_columns();
    std::vector<uint32_t> rows = A.get_rows();

    // Good job, keep grinding!!!
    // P.S. by vL

    r = b - A * x;

    while (EuclidNorm(r) > tolerance) {
        for (uint32_t i = 0; i < b.size(); ++i) {
            T interim = x[i];
            T diagonal;
            x[i] = b[i]*w;
            for (uint32_t j = rows[i]; j < rows[i + 1]; ++j) {
                if (i == columns[j]) {
                    diagonal = A(i, columns[j]);
                    continue;
                }
                x[i] -= w*A_elements[j] * x[columns[j]];
            }
            x[i] /=diagonal;
            x[i] += (1-w)*interim;
        }
        r = b - A * x;
        //std::cout << EuclidNorm(r) << std::endl;
    }
    return x;
}
