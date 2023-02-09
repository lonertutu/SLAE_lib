#include "run_solver.hpp"
#include <iostream>

namespace SLAE::Solver{
std::vector<double> solver_method_run(Tri_matrix::Tridiagonal_matrix &matrix, const std::vector<double> &free_coef) {
    
    std::vector<double> solution(matrix.size());

    std::vector<double> alpha_beta(matrix.size()*2);


    alpha_beta[0] = - matrix(0, 1) / matrix(0, 0);
    alpha_beta[1] = free_coef[0] / matrix(0, 0);

for (int i = 1; i < matrix.size() - 1; ++i) {
        alpha_beta[2*i] = - matrix(i, 2) / (matrix(i, 0)*free_coef[2*(i-1)] + matrix(i, 1));
        alpha_beta[2 * i + 1] = (free_coef[i] - matrix(i, 0) * alpha_beta[2 * (i - 1) + 1]) /(matrix(i, 0) * alpha_beta[2 * (i - 1)] + matrix(i, 1));
    }


}
}
