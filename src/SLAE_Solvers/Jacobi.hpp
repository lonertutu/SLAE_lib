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


//init_vec - приближеный вектор решений
template <typename T>
std::vector<T> Jacobi(const CSR<T> &A, const std::vector<T> &b, std::vector<T> init_vec, T tolerance) {


    std::vector<T> x(init_vec);
    std::vector<T> iter_x(x);
    std::vector<T> r(b.size());

    //считаем невязку
    r = b - A * x;

    std::ofstream data;
    data.open("Jacobi_data");

    //итерации останавливаются, когда невязка становится меньше чем заданное число tolerance
    while (Norm(r) > tolerance) {
        for (uint32_t i = 0; i < b.size(); ++i) {
            double result = 0;
            for (uint32_t j = A.get_row(i); j < A.get_row(i + 1); ++j) {
                if (i != A.get_column(j)) {
                    result += A(i, A.get_column(j)) * x[A.get_column(j)];
                }
                iter_x[i] = ((b[i] - result) / A(i, i));
            }
            std::cout<< iter_x[i] << '\n';
        }
        //обновляем вектор приближения к решению x
        x = iter_x;
        //обновляем невязку
        r = b - A * x;
        //data << Norm(r);
    }
    return x;
}