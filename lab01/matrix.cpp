//
//  matrix.cpp
//  lab01
//
//  Created by Jakub Matysek on 04/03/2024.
//

#include "matrix.hpp"

Matrix::Matrix(const size_t N, const size_t M)
    : N(N)
    , M(M) {
    this->data = new double[N * M];
    std::fill(this->data, this->data + N * M, 0.0);

    std::cout << "constructor of " << N << "x" << M << " matrix" << std::endl;
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<double>>& data)
    : N(data.size()) {
    this->M = 0;
    for (const auto& row : data) {
        this->M = std::max(this->M, row.size());
    }

    this->data = new double[this->N * this->M];
    std::fill(this->data, this->data + this->N * this->M, 0.0);

    auto ptr { this->data };
    for (const auto& row : data) {
        std::copy(row.begin(), row.end(), ptr);
        ptr += this->M;
    }

    std::cout << "constructor of " << this->N << "x" << this->M
              << " matrix from initializer list" << std::endl;
}

Matrix::Matrix(const Matrix& matrix)
    : N(matrix.N)
    , M(matrix.M)
    , data(new double[N * M]) {
    std::copy(matrix.data, matrix.data + this->N * this->M, this->data);

    std::cout << "copy constructor of matrix" << std::endl;
}

Matrix::Matrix(Matrix&& matrix)
    : N(matrix.N)
    , M(matrix.M)
    , data(std::move(matrix.data)) {
    matrix.data = nullptr;

    std::cout << "move constructor of matrix" << std::endl;
}

Matrix::~Matrix() { delete[] this->data; }

Matrix& Matrix::operator=(const Matrix& matrix) {
    if (this != &matrix) {
        this->N = matrix.N;
        this->M = matrix.M;

        delete[] this->data;
        this->data = new double[this->N * this->M];
        std::copy(matrix.data, matrix.data + this->N * this->M, this->data);
    }

    std::cout << "copy assignment operator of matrix" << std::endl;

    return *this;
}

Matrix& Matrix::operator=(Matrix&& matrix) {
    if (this != &matrix) {
        this->N = std::exchange(matrix.N, 0);
        this->M = std::exchange(matrix.M, 0);

        delete[] this->data;
        this->data = std::exchange(matrix.data, nullptr);
    }

    std::cout << "move assignment operator of matrix" << std::endl;

    return *this;
}

Matrix Matrix::operator-() const {
    Matrix matrix(N, M);

    for (std::size_t i = 0; i < N * M; i++) {
        matrix.data[i] = -(this->data[i]);
    }

    return matrix;
}

double Matrix::operator()(const size_t row, const size_t col) const {
    return this->data[(row - 1) * M + (col - 1)];
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (size_t row = 1; row <= matrix.N; ++row) {
        out << "{";
        for (size_t col = 1; col < matrix.M; ++col) {
            out << matrix(row, col) << ", ";
        }
        out << matrix(row, matrix.M) << "}" << std::endl;
    }
    return out;
}
