#include <iostream>
#include <vector>
#include <set>

template <typename T>
struct Triplet {

std::size_t i;
std::size_t j;
T matrix_element;
};

/*!
    \brief Class of CSR matrix
        
    \param hight, width Matrix size
    \param matrix_el
*/
template <typename T>
class CSR {

private:
    const std::size_t hight, width;
    std::vector<T> matrix_el;
    std::vector<std::size_t> rows;
    std::vector<std::size_t> columns;

public:

    /*!
        \brief Constructor for CSR
        
        \param vec Vector of values
    */
    Construct_CSR(const std::set<Triplet<T>> &data, const std::size_t &H, const std::size_t &W) : hight(H), width(W) {

        matrix_el.resize(data.size());
        rows.resize(H + 1, 0);
        columns.resize(data.size());

        unsigned int counter = 0;
        unsigned int actual_row = 0;

        auto val = data.begin();
        for (std::size_t n = 0; n < data.size(); ++n){
            while (actual_row < val->i){
                rows[actual_row + 1] = rows[actual_row] + counter;
                ++actual_row;
                counter = 0;
            }
        matrix_el[n] = val->value;
        columns[n] = val->j;
        ++counter;
        val = std::next(val);

        }

        for(++actual_row; actual_row <= hight; ++actual_row){
            rows[actual_row] = data.size();
        }

    }

    //Оператор получения элемента по i и j координате в матрице

    const T operator()(std::size_t const i, std::size_t const j) {
        std::size_t pass = rows[i];
        std::size_t counting = rows[i+1] - pass;
        for (std::size_t p = pass; p < pass+counting; ++p) {
            if (columns[p]==j) {
                return matrix_el[p];
            }
        }
    }
};

//actual_row
