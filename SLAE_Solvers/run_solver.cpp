#include "run_solver.hpp"
#include <iostream>

namespace SLAE::Solver{
std::vector<double> solver_method_run(const Tri_matrix::Tridiagonal_matrix &matrix, const std::vector<double> &free_coef) {
    
    std::vector<double> solution(matrix.size());

    std::vector<double> alpha_beta(matrix.size()*2);
}
}