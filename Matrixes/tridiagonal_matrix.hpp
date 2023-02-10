#include <vector>

namespace SLAE::Tri_matrix {

/*!
    \brief Parent class of Tridiagonal Matrix

    \param size_matrix Matrix size
    \param matrix The values ​​of the coefficients in the matrix
    
    \warning The matrix is ​​square.
*/
class Tridiagonal_matrix {

    private:
        int size_matrix = 0;  //size for colomuns or rows for quadratic matrix
        std::vector<double> matrix; //matrix coeff

    public:
        /*!
        \brief Constructor of Tridiagonal Matrix 

        \param[in] size Number of rows or columns

        */
        inline explicit Tridiagonal_matrix(int size) : size_matrix(size), matrix(std::vector<double>(3 * size)) {};

        static Tridiagonal_matrix zero_field(int size); //один раз в программе выделяем место для полей с ноликами.
         
        int size() const noexcept {
            return size_matrix;
        }

        double &operator()(int i, int j);
};

}