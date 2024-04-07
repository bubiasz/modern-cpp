//
//  staticvector.hpp
//  lab05
//
//  Created by Jakub Matysek on 02/04/2024.
//

#ifndef staticvector_hpp
#define staticvector_hpp

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

class VectorException : public std::runtime_error {
public:
    VectorException(const std::string& message)
        : std::runtime_error(message) {
    }
};

template <typename T, size_t N>
class Vector {
    T data[N];

    Vector(T arg) {
        std::fill(this->data, this->data + N, arg);
    }

public:
    typedef T value_type;

    Vector() {
        std::fill(this->data, this->data + N, T());
    }

    Vector(const Vector& v) = default;

    Vector(const std::initializer_list<T>& x) {
        std::copy(x.begin(), x.end(), this->data);
    }

    Vector& operator=(const Vector& x) {
        std::copy(x.data, x.data + N, this->data);
        return *this;
    }

    T& operator[](size_t index) {
        return this->data[index];
    }

    const T& operator[](size_t index) const {
        return this->data[index];
    }

    constexpr size_t size() const {
        return N;
    }

    template <size_t M>
    Vector<T, N> operator+(const Vector<T, M>& x) {
        if (x.size() != N) {
            throw VectorException(
                "Exception : incompatible sizes in Vector::operator+");
        }
        Vector<T, N> result;
        for (size_t i = 0; i < x.size(); ++i) {
            result[i] = this->data[i] + x[i];
        }
        return result;
    }

    operator Vector<T, 0>() const {
        Vector<T, 0> result(N);
        for (size_t i = 0; i < N; ++i) {
            result[i] = this->data[i];
        }
        return result;
    }

    const T& get(size_t index) const {
        return this->data[index];
    }

    void set(size_t index, const T& value) {
        this->data[index] = value;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& x) {
        for (auto element : x.data) {
            out << element << " ";
        }
        return out;
    }
};

#endif // staticvector_hpp