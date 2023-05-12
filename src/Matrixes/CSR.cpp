#include "../Matrixes/Triplet.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <cassert>

/*!
    \brief Class of CSR matrix
        
    \param hight, width Matrix size
    \param matrix_el
*/
template <typename T>
class CSR {

private:
    const uint32_t hight, width;
    std::vector<T> matrix_els;
    std::vector<uint32_t> rows;
    std::vector<uint32_t> columns;

public:


    CSR(std::vector<T> els, const std::vector<uint32_t>& c, const std::vector<uint32_t>& r,
        const uint32_t &h, const uint32_t &w) : hight(h), width(w) {
        matrix_els = els;
        rows = r;
        columns = c;
    };

    /*!
        \brief Constructor for CSR
        
        \param vec Vector of values
    */
    CSR(const uint32_t &H, const uint32_t &W, const std::set<Triplet<T>>& data) : hight(H), width(W) {


        matrix_els.resize(data.size());
        rows.resize(H + 1, 0);
        columns.resize(data.size());

        uint32_t counter = 0;
        uint32_t actual_row = 0;

        rows[0] = 0;
        for (uint32_t n = 0; const auto& elem: data) {
            while (actual_row < elem.i) {
                rows[actual_row + 1] = rows[actual_row] + counter;
                ++actual_row;
                counter = 0;
            }
            matrix_els[n] = elem.matrix_element;
            columns[n] = elem.j;
            ++counter;
            ++n;
            }

        for(++actual_row; actual_row <= hight; ++actual_row) {
            rows[actual_row] = data.size();
        }
    };

    [[nodiscard]] std::vector<uint32_t> get_rows() const {
            return rows;
    };

    [[nodiscard]] std::vector<uint32_t> get_columns() const {
            return columns;
    };

    [[nodiscard]] std::vector<T> get_elements() const {
        return matrix_els;
    };


    [[nodiscard]] uint32_t get_column(uint32_t i) const {
        return columns[i];
    };

    [[nodiscard]] uint32_t get_row(uint32_t i) const {
        return rows[i];
    };
    //Оператор получения элемента по i и j координате в матрице

    const T operator()(uint32_t const i, uint32_t const j) const {
        for (uint32_t p = rows[i]; p < rows[i+1];  ++p) {
            if (columns[p] == j) return matrix_els[p];
        }
        return 0;
    }

    // оператор умножения матрицы на вектор
    std::vector<T> operator*(const std::vector<T> &b) const {
        assert(b.size() == width);

        std::vector<T> sol_vec(b.size());
        for (uint32_t i = 0; i < width; ++i) {
            for (uint32_t j = rows[i]; j < rows[i+1]; ++j) {
                sol_vec[i] += matrix_els[j] * b[columns[j]];
            }
        }
        return sol_vec;
    }

    [[nodiscard]] uint32_t sizeHight() const {
        return hight;
    }

    [[nodiscard]] uint32_t sizeWidth() const {
        return width;
    }

    //Code for transposing is taken from Dmitry Petrov's implementation
    CSR transpose() const {
        uint32_t Nonzero = matrix_els.size();
        std::vector<T> tmatrix_els(Nonzero);
        std::vector<uint32_t> tCols(Nonzero);
        std::vector<uint32_t> tRows(width + 1);
        for (uint32_t i = 0; i < Nonzero; ++i) tRows[columns[i] + 1]++;
        uint32_t S = 0;
        uint32_t tmp;
        for (uint32_t i = 1; i <= width; ++i) {
            tmp = tRows[i];
            tRows[i] = S;
            S += tmp;
        }
        uint32_t j1, j2, Col, RIndex, IIndex;
        T V;
        for (uint32_t i = 0; i < hight; ++i) {
            j1 = rows[i];
            j2 = rows[i+1];
            Col = i;
            for (uint32_t j = j1; j < j2; ++j) {
                V = matrix_els[j];
                RIndex = columns[j];
                IIndex = tRows[RIndex + 1];
                tmatrix_els[IIndex] = V;
                tCols[IIndex] = Col;
                tRows[RIndex + 1]++;
            }
        }
        return CSR(tmatrix_els, tCols, tRows, hight, width);
    }
};

