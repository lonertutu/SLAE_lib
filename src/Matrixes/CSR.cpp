#include <iostream>
#include <vector>
#include <set>
#include <cassert>

template <typename T>
struct Triplet {
    uint32_t i;
    uint32_t j;
T matrix_element;
bool operator<(Triplet<T> const & rgh) const{
    bool res;
    i == rgh.i ? res = j < rgh.j : res = i < rgh.i;
    return res;
    }
};

/*!
    \brief Class of CSR matrix
        
    \param hight, width Matrix size
    \param matrix_el
*/
template <typename T>
class CSR {

private:
    const uint32_t hight, width;
    std::vector<T> matrix_el;
    std::vector<uint32_t> rows;
    std::vector<uint32_t> columns;

public:

    /*!
        \brief Constructor for CSR
        
        \param vec Vector of values
    */
    CSR(const uint32_t&H, const uint32_t &W, const std::set<Triplet<T>>& data) : hight(H), width(W) {


        matrix_el.resize(data.size());
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
            matrix_el[n] = elem.matrix_element;
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
        return matrix_el;
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
            if (columns[p] == j) return matrix_el[p];
        }
        return 0;

    }

    // оператор умножения матрицы на вектор
    std::vector<T> operator*(const std::vector<T> &b) const {
        assert(b.size() == width);

        std::vector<T> sol_vec(b.size());
        for (uint32_t i = 0; i < width; ++i) {
            for (uint32_t j = rows[i]; j < rows[i+1]; ++j) {
                sol_vec[i] += matrix_el[j] * b[columns[j]];
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

};

//actual_row
