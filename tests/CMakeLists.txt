set(GOOGLETEST_VERSION 1.13.0)

enable_testing()
find_package(GTest REQUIRED)
add_executable(test test_test.cpp Simple_iter.cpp CSR_test.cpp Jacobi_test.cpp Gauss_Seidel_test.cpp SOR.cpp Chebyshev.cpp Gradient_descent.cpp Conjugate_grad.cpp)
target_include_directories(test PUBLIC ${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include)
include_directories(../../SLAE_lib)
target_link_libraries(test SLAE_lib GTest::gtest GTest::gtest_main)
add_test(NAME test COMMAND test)
