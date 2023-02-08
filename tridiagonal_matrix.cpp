#include "tridiagonal_matrix.hpp"


//Реализация перегруженного оператора, который был заявлен в .hpp
//Берётся два инта и возвращается ссылка на double

double &Tridiagonal_matrix::operator()(unsigned int i, unsigned int j) {
        return matrix[i*3 + j];
        }

//Реализация полей, заполенных только 0.