//
// Created by lonertutu on 04.05.23.
//

#ifndef SLAE_LIB_TRIPLET_HPP
#define SLAE_LIB_TRIPLET_HPP

#include <set>
#include <iostream>
/*!
    \brief Class of Triplet for CSR matrix

    \param i - element row
    \param j - element column
    \param matrix_element
*/
template <typename T>
struct Triplet {
    uint32_t i;
    uint32_t j;
    T matrix_element;
    bool operator<(Triplet<T> const & cep) const{
        bool res;
        i == cep.i ? res = j < cep.j : res = i < cep.i;
        return res;
    }
};

#endif //SLAE_LIB_TRIPLET_HPP
