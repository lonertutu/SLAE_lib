//
// Created by lonertutu on 09.03.23.
//
#pragma once

#include<vector>
#include<cmath>
#include<iostream>

std::vector<double> operator+(const std::vector<double>& a, const std::vector<double> &b) {
    std::vector<double> sol_vec(a.size());

    for (uint32_t i = 0; i < a.size(); ++i) {
        sol_vec[i] = a[i] + b[i];
    }
    return sol_vec;
}

std::vector<double> operator-(const std::vector<double>& a, const std::vector<double> &b) {
    std::vector<double> sol_vec;
    sol_vec.resize(a.size());

    for (uint32_t i = 0; i < a.size(); ++i) {
        sol_vec[i] = a[i] - b[i];
    }
    return sol_vec;
}

std::vector<double> operator*(const std::vector<double>& a, const double number) {
    std::vector<double> sol_vec(a.size());

    for (uint32_t i = 0; i < a.size(); ++i) {
        sol_vec[i] = a[i]*number;
    }
    return sol_vec;
}

std::vector<double> operator*(const double number, const std::vector<double>& a) {

    return a*number;
}