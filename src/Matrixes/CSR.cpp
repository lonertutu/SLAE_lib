#include <iostream>
#include <vector>

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
    const index hight, width;
    std::vector<elements> matrix_el;
    std::vector<index> rows;
    std::vector<index> columns;

public:
    using elemets = T;
    using index = std::size_t

    /*!
        \brief Constructor for CSR
        
        \param vec Vector of values
    */
   Construct_CSR(const std::set<Triplet<elements>> &data, const index &h, const index &w) : hight(H), width(w) {
    
   }



};
