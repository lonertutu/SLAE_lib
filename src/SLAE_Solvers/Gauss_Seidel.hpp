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
std::vector<T> Gauss_Seidel(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, T tolerance) {


    std::vector<T> x(init_vec);
    std::vector<T> iter_x(b.size());
    std::vector<T> r(b.size());

    //считаем невязку
    r = b - A * x;

    std::ofstream data;
    data.open("Gauss_Seidel.txt");

    //итерации останавливаются, когда невязка становится меньше чем заданное число tolerance
    while (Norm(r) > tolerance) {
        for (uint32_t i = 0; i < b.size(); ++i) {
            iter_x[i] = b[i];
            //верхнетреугольные элементы
            for (uint32_t j = A.get_row(i); j < A.get_row(i + 1); ++j) {
                if (i < A.get_column(j))
                    iter_x[i] += -1.*A(i, A.get_column(j)) * x[A.get_column(j)];
            }
            //нижнетреугольные
            for (uint32_t j = A.get_row(i); j < A.get_row(i + 1); ++j) {
                if (i > A.get_column(j))
                    iter_x[i] += -1.*A(i, A.get_column(j) * iter_x[A.get_column(j)]);
            }
            iter_x[i] = iter_x[i] /A(i, i);
            std::cout << iter_x[i]<< std::endl;
        }
        //обновляем вектор приближения к решению x
        x = iter_x;

        //обновляем невязку
        r = b - A * x;
        std::cout << Norm(r);
        //data << Norm(r);
    }
    return x;
}

