//
// Created by lonertutu on 04.03.23.
//
#pragma once

#include <cmath>
#include <vector>

template<typename T>
T EuclidNorm(const std::vector<T> &vec) {
    T vec_norm = 0.;
    for(auto i : vec)
        vec_norm += i * i;
    return sqrt(vec_norm);
}

template<typename T>
T InfNorm(const std::vector<T> &vec) {
    //
}
