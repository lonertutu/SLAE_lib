#include "run_solver.hpp"
#include "../Matrixes/tridiagonal_matrix.hpp"
#include <iostream>
#include <vector>


namespace SLAE::Solver
{
    std::vector<double> solver_method_run(Tri_matrix::Tridiagonal_matrix &matrix, const std::vector<double> &free_coef)
    /*!
        \brief Function for Run method
        \param[in] matrix
    
    */
    {

        std::vector<double> solution(matrix.size());

        std::vector<double> alpha_beta(matrix.size() * 2);

        //отдельный расчёт первых коэффициентов
        alpha_beta[0] = -matrix(0, 1) / matrix(0, 0);
        alpha_beta[1] = free_coef[0] / matrix(0, 0);

        for (int i = 1; i < matrix.size() - 1; ++i)
        {
            alpha_beta[2 * i] = -matrix(i, 2) / (matrix(i, 0) * free_coef[2 * (i - 1)] + matrix(i, 1));

            alpha_beta[2 * i + 1] = (free_coef[i] - matrix(i, 0) * alpha_beta[1 + 2 * (i - 1)]) / 
            (matrix(i, 0) * alpha_beta[2 * (i - 1)] + matrix(i, 1));
        }

        // обратная прогонка
        // выразили X_{N - 1} - самый последний элемент. Сборка вектора решений начинается с конца.
        
        solution[(matrix.size() - 1)] = (free_coef[matrix.size() - 1] - matrix((matrix.size() - 1), 1) * alpha_beta[(matrix.size() - 2)]) / 
        (matrix((matrix.size() - 1), 2) + matrix((matrix.size() - 1), 1) * alpha_beta[(matrix.size() - 2)]);
        
        for (int j = matrix.size() - 2; j >= 0; --j)
        {
            solution[j] = alpha_beta[j * 2] * solution[j + 1] + alpha_beta[j * 2 + 1];
        }

        return solution;
    }
}
