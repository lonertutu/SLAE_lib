//
// Created by lonertutu on 04.03.23.
//

#pragma once

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"
#include <fstream>


std::ofstream out;          // поток для записи

// tau = 2/lambda_max
template<typename T>
std::vector<T> Simple_Iter(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance, const T &parametr) {

    auto result = static_cast<T>(0);
    std::vector<T> x = init_vec;
    std::vector<T> r(b.size);
    std::vector<std::vector<T>> iteration;{}
    uint32_t p = 0;

    iteration.reserve(50);
    r = b - A*init_vec;
    while(Norm(r) > tolerance) {
        if (parametr != 0) {
                init_vec = init_vec - parametr*r;

        }
        else return 0;

        ++p;
        //обновляем невязку
        r = b - A*init_vec;
        iteration.push_back(Norm(r), p);
        out.open("data.txt");
        out << iteration;

    }
    out.close();


}