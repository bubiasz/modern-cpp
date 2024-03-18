//
//  matrix.hpp
//  lab01
//
//  Created by Jakub Matysek on 04/03/2024.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <utility>

class Matrix {
    size_t N { 0 };
    size_t M { 0 };
    double* data { nullptr };

public:
    Matrix() = default;

    Matrix(const size_t N, const size_t M);

    Matrix(const std::initializer_list<std::initializer_list<double>>& data);

    Matrix(const Matrix& matrix);

    Matrix(Matrix&& matrix);

    ~Matrix();

    Matrix& operator=(const Matrix& matrix);

    Matrix& operator=(Matrix&& matrix);

    Matrix operator-() const;

    double operator()(const size_t row, const size_t col) const;

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};

#endif /* matrix_hpp */
