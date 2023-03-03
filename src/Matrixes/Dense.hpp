#pragma once


template<typename T>
class Dense_matrix {

public:
    Dense_matrix(uint32_t rows, uint32_t columns, T* matrix_el);

    /*!
        \brief Matrix-vector multiplication function, kind of equation A*v = x

        \param v - vector of values
        \param x - answer
    */
    virtual void mult_vec_matrix(T* &v, T* x);


};