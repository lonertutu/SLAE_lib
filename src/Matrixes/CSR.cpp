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
   Construct_CSR(const std::set<Triplet<elements>> &data, const std::size_t &H, const std::size_t &W) : hight(H), width(W) {

    values.resize(data.size());
    columns.resize(data.size());
    rows.resize(h + 1, 0)

   }


};
