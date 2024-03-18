//
//  matrixwithlabel.cpp
//  lab01
//
//  Created by Jakub Matysek on 04/03/2024.
//

#include "matrixwithlabel.hpp"

MatrixWithLabel::MatrixWithLabel(
    const std::string& label, const size_t N, const size_t M)
    : label(label)
    , Matrix(N, M) { }

MatrixWithLabel::MatrixWithLabel(const std::string& label,
    const std::initializer_list<std::initializer_list<double>>& data)
    : label(label)
    , Matrix(data) { }

MatrixWithLabel::MatrixWithLabel(const MatrixWithLabel& matrix)
    : label(matrix.label)
    , Matrix(matrix) { }

auto MatrixWithLabel::getLabel() -> std::string { return this->label; }

void MatrixWithLabel::setLabel(const std::string& label) {
    this->label = label;
}
