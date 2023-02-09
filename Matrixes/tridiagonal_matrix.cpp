#include "tridiagonal_matrix.hpp"

namespace SLAE::Tri_matrix{
    
//Реализация перегруженного оператора, который был заявлен в .hpp
//Берётся два инта и возвращается ссылка на double

double &Tridiagonal_matrix::operator()(unsigned int i, unsigned int j) {
        return matrix[i*3 + j];
        }

//Реализация полей, заполенных только 0.

Tridiagonal_matrix Tridiagonal_matrix::zero_field(int size) {
    
    Tridiagonal_matrix zero_matrix(size);
    zero_matrix.matrix = std::vector<double>(3 * size, 0);
    return zero_matrix;
}
}