#pragma once

#include "../Matrixes/Triplet.hpp"
#include <vector>
#

template<typename T>
class DenseMatrix {

private:
    const uint32_t hight, width;
    std::vector<T> matrix_els;

public:
    //DenseMatrix(const uint32_t &h, const uint32_t &w): hight(h), width(w){
    //    matrix_els.resize(hight*width);
    //};
    /*!
        \brief Dense matrix constructor

        \param H, W - matrix size
        \param data - triplets with matrix data
    */
    DenseMatrix(const uint32_t &H, const uint32_t &W, const std::set<Triplet<T>>& data) : hight(H), width(W) {
        matrix_els.resize(H*W);
        for (auto p : data) matrix_els[p.i*W + p.j] = p.matrix_element;
    }


    T operator()(const uint32_t &i, const uint32_t &j) {
        return matrix_els[i * width + j];
    };

    void fill_col(const std::vector<T> &col, int p) {
        for(int i = 0; i < sizeHight(); ++i)
            matrix_els[i * width + p] = col[i];
    }

    void fill_row(const std::vector<T> &row, int p) {
        for(int i = 0; i < sizeWidth(); ++i)
            matrix_els[i * hight + p] = row[i];
    }



    [[nodiscard]] std::vector<uint32_t> get_row(uint32_t i) const {
        std::vector<T> row(width);

        for (uint32_t p = 0; p < width; ++p)
            row[p] = matrix_els[p * hight + i];
        return row;
    };

    [[nodiscard]] std::vector<uint32_t> get_column(uint32_t i) const {
        std::vector<T> column(hight);

        for (uint32_t p = 0; p < hight; ++p)
            column[p] = matrix_els[p * width + i];
        return column;
    };

    [[nodiscard]] std::vector<T> get_elements() const {
        return matrix_els;
    };


    [[nodiscard]] uint32_t sizeHight() const {
        return hight;
    }

    [[nodiscard]] uint32_t sizeWidth() const {
        return width;
    }
    /*!
        \brief Matrix-vector multiplication function, kind of equation A*v = x

        \param v - vector of values
        \param x - answer
    */
    //mult_vec_matrix();

};