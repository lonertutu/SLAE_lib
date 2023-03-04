//
// Created by lonertutu on 04.03.23.
//
#pragma once

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include <vector>


//init_vec - приближеный вектор решений
template <typename T>
std::vector<T> Jacobi(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance) {

    auto result = static_cast<T>(0);
    std::vector<T> x = init_vec;
    std::vector<T> iter_x(b.size());
    std::vector<T> r(b.size);

    //считаем невязку
    r = b - A*x;

    //итерации останавливаются, когда невязка становится меньше чем заданное число tolerance
    while(Norm(r) > tolerance) {
        for (uint32_t i = 0; i < b.size(); ++i) {
            for (uint32_t j = A.rows[i]; j < A.rows[i + 1]; ++j) {
                if (i != A.columns[j]) result += A.matrix_el[j] * x[A.columns[j]];
            }
            iter_x[i] = (1 / A(i, i))*(b[i] - result);
        }

        //обновляем вектор приближения к решению x
        x = iter_x;
        //обновляем невязку
        r = b - A*iter_x;
    }
    return x;


}
