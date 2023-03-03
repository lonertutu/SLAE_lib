#include <iostream>
#include <cmath>
#include "Dense.hpp"

//template<typename T>
//Dense_matrix<T>::Dense_matrix(uint32_t rows, uint32_t columns, T* matrix_el)


template<typename T>
void Dense_matrix<T>::mult_vec_matrix(T* &v, T* x)
{
    for (int i = 0; i < this->rows; ++i)
    {
        x[i] = 0;
    }
    for (int j = 0; j < this->rows; ++j) {
        for (int i = 0; i < this->columns; ++i)
        {
            x[j] += this->matrix_el[this->columns*j + i]*v[i];
        }
    }
}
