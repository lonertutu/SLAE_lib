//
// Created by lonertutu on 04.03.23.
//
#pragma once

#include <cmath>
#include <vector>

template<typename T>
struct Norm {
    double Euclid_Norm(const std::vector<T>& vec);
};

template<>
double Norm<double>::Euclid_Norm(const std::vector<double> &vec) {
    double vec_norm = 0.;
    for(double i : vec)
        vec_norm += i * i;
    return sqrt(vec_norm);
}
