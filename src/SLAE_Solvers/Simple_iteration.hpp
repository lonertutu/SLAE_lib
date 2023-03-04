//
// Created by lonertutu on 04.03.23.
//

#pragma once

#include "../Matrixes/CSR.cpp"
#include "../Tools/Norm.hpp"

template<typename T>
std::vector<T> Simple_Iter(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance, const T &parametr) {

    auto result = static_cast<T>(0);
    std::vector<T> x = init_vec;
    std::vector<T> iter_x(b.size());
    std::vector<T> r(b.size);

    r = b - A*init_vec;
    while(Norm(r) > tolerance) {
        if (parametr != 0) {
                init_vec = init_vec - parametr*r;
        }
        //обновляем невязку
        r = b - A*init_vec;
    }
}