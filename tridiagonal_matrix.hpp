#include <vector>

class Tridiagonal_matrix {

    private:
        int size_matrix = 0;  //size for colomuns or rows for quadratic matrix
        std::vector<double> matrix; //matrix coeff

    public:
        inline explicit Tridiagonal_matrix(int size) : size_matrix = size, matrix(std::vector<double>(3 * size)) {}; //явно определяем конструктор

        static Tridiagonal_matrix zero_field(int size); //один раз в программе выделяем место для полей с ноликами.

    double &operator()(unsigned int i, unsigned int j)
};