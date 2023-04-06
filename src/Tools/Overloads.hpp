//
// Created by lonertutu on 04.03.23.
//
#pragma once

#include<vector>
#include<cmath>
#include<iostream>

template<typename T>
std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> sol_vec(a.size());

    for (uint32_t i = 0; i < a.size(); ++i)
        sol_vec[i] = a[i] + b[i];
    return sol_vec;
}

template<typename T>
std::vector<T> operator-(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> sol_vec;
    sol_vec.resize(a.size());

    for (uint32_t i = 0; i < a.size(); ++i)
        sol_vec[i] = a[i] - b[i];
    return sol_vec;
}

template<typename T>
std::vector<T> operator*(const std::vector<T> &a, const T number) {
    std::vector<T> sol_vec(a.size());

    for (uint32_t i = 0; i < a.size(); ++i)
        sol_vec[i] = a[i]*number;
    return sol_vec;
}

template<typename T>
std::vector<T> operator*(const T number, const std::vector<T>& a) {
    return a*number;
}

template<typename T>
T operator*(const std::vector<T>& a, const std::vector<T>& b) {
    T sol_vec = 0;

    for (uint32_t i = 0; i < a.size(); ++i)
        sol_vec += a[i] * b[i];
    return sol_vec;
}
