//
//  matrix.hpp
//  lab08
//
//  Created by Jakub Matysek on 24/04/2024.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <algorithm>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <numeric>

template <typename T, size_t N, size_t M>
class Matrix {
    T data[N * M];

public:
    constexpr size_t numberOfRows() const {
        return N;
    }
    constexpr size_t numberOfColumns() const {
        return M;
    }

    Matrix(int nrows = N, int ncols = M) {
        std::fill_n(data, N * M, T {});
    }
    Matrix(const std::initializer_list<std::initializer_list<T>>& list) {
        T* p = data;
        for (const auto& row : list) {
            T* p2 = std::copy(row.begin(), row.end(), p);
            std::fill(p2, p += M, T {});
        }
    }

    Matrix(const Matrix& m) {
        std::copy_n(m.data, N * M, data);
    }

    Matrix& operator=(const Matrix& m) {
        if (&m != this) {
            std::copy_n(m.data, N * M, data);
        }
        return *this;
    }

    const T& operator()(int i, int j) const {
        return data[(i - 1) * M + j - 1];
    }

    T& operator()(int i, int j) {
        return data[(i - 1) * M + j - 1];
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b) {
        Matrix r;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                r(i, j) = a(i, j) + b(i, j);
            }
        }
        return r;
    }

    class Iterator {
    private:
        T* ptr;
        size_t step;

    public:
        Iterator(T* p, size_t s = 1)
            : ptr(p)
            , step(s) {
        }

        Iterator& operator++() {
            ptr += step;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        T& operator*() {
            return *ptr;
        }

        const T& operator*() const {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        const T* operator->() const {
            return ptr;
        }
    };

    using iterator = Iterator;
    using row_iterator = Iterator;
    using col_iterator = Iterator;
    using const_iterator = const Iterator;

    iterator begin() {
        return iterator(data);
    }

    iterator end() {
        return iterator(data + N * M);
    }

    row_iterator row_begin(size_t i) {
        return iterator(data + (i - 1) * M);
    }

    row_iterator row_end(size_t i) {
        return iterator(data + i * M);
    }

    col_iterator col_begin(size_t j) {
        return iterator(data + j - 1, M);
    }

    col_iterator col_end(size_t j) {
        return iterator(data + N * M + (j - 1), M);
    }
};

template <typename T, size_t N, size_t M>
void printMatrix(const Matrix<T, N, M>& m, int width = 10) {
    for (int i = 1; i <= m.numberOfRows(); ++i) {
        for (int j = 1; j <= m.numberOfColumns(); ++j) {
            if (j != 1)
                std::cout << " ";
            std::cout << std::setw(width) << m(i, j);
        }
        std::cout << std::endl;
    }
}

#endif /* matrix_hpp */
