//
// Created by lonertutu on 04.03.23.
//
#pragma once

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include "../Tools/Overloads.hpp"
#include <vector>
#include <iostream>
#include <fstream>



template <typename T>
std::vector<T> Gauss_Seidel(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, T tolerance) {

    std::vector<T> x(init_vec);
    //std::vector<T> iter_x = x;
    std::vector<T> r(b.size());
    std::vector<T> A_elements = A.get_elements();

    std::vector<uint32_t> columns = A.get_columns();
    std::vector<uint32_t> rows = A.get_rows();
    r = b - A * x;

    while (Norm(r) > tolerance) {
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

        //x = iter_x;
        r = b - A * x;
        std::cout << Norm(r) << std::endl;
    }
    return x;
}


template <typename T>
std::vector<T> SOR(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, T tolerance) {

    std::vector<T> x(init_vec);
    std::vector<T> iter_x(b.size());
    std::vector<T> r(b.size());
    std::vector<T> A_elements = A.get_elements();

    // Good job, keep grinding!!!
    // P.S. by vL

    r = b - A * x;

    while (Norm(r) > tolerance) {
        for (uint32_t i = 0; i < b.size(); ++i) {
            iter_x[i] = b[i];
            double diagonal;
            for (uint32_t j = A.get_row(i); j < A.get_row(i + 1); ++j) {
                if (i == A.get_column(j)) {
                    diagonal = A(i, A.get_column(j));
                    continue;
                }
                iter_x[i] -= A(i, A.get_column(j)) * x[A.get_column(j)];
            }
            iter_x[i] = iter_x[i] /diagonal;
            std::cout << iter_x[i] << std::endl;
        }
        x = iter_x;
        r = b - A * x;
    }
    return x;
}

