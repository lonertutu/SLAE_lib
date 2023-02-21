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

public:
    using elements = T;

private:
    const T hight, width;
    std::vector<elements> matrix_el;
    std::vector<T> rows;
    std::vector<T> columns;

public:

    /*!
        \brief Constructor for CSR
        
        \param vec Vector of values
    */
   Construct_CSR(const std::set<Triplet<elements>> &data, const T &h, const T &w) : hight(H), width(w) {

    values.resize(data.size());
    columns.resize(data.size());
    rows.resize(h + 1, 0)

   }


};
