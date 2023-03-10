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



std::ofstream out;          // поток для записи

// tau = 2/lambda_max
template<typename T>
std::vector<T> Simple_Iter(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &init_vec, const T &tolerance, const T &parametr) {

    std::vector<T> x = init_vec;
    std::vector<T> r(b.size());
    std::vector<T> iteration;
    iteration.reserve(500);

    //out.open("Simple_iteration.txt");
    r = A*x - b;
    while(Norm(r) > tolerance) {
        if (parametr != 0.)
                x = x - parametr*r;
        r = b - A*x;
        std::cout << parametr << std::endl;

        iteration.push_back(Norm(r));
        //for (uint32_t i = 0; i < iteration.size(); ++i)
            //out << iteration[i] << std::endl;
    }
    std::cout << x[1] << " " << x[2] << " " << x[3];
    //out.close();
    return x;
}