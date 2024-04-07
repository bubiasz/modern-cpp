//
//  dynamicvector.hpp
//  lab05
//
//  Created by Jakub Matysek on 02/04/2024.
//

#ifndef dynamicvector_hpp
#define dynamicvector_hpp

#include "staticvector.hpp"
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <string>

template <typename T>
class Vector<T, 0> {
private:
    std::unique_ptr<T[]> data { nullptr };
    size_t len { 0 };

public:
    typedef T value_type;

    Vector(size_t len)
        : len(len)
        , data(std::make_unique<T[]>(len)) {};

    Vector(const std::initializer_list<T>& x)
        : len(x.size())
        , data(std::make_unique<T[]>(x.size())) {
        std::copy(x.begin(), x.end(), this->data.get());
    }

    Vector(const Vector& x)
        : len(x.len)
        , data(std::make_unique<T[]>(x.len)) {
        std::copy(x.data.get(), x.data.get() + x.len, this->data.get());
    }

    T& operator[](size_t index) {
        return this->data[index];
    }

    const T& operator[](size_t index) const {
        return this->data[index];
    }

    template <size_t N>
    operator Vector<T, N>() const {
        if (N != this->len) {
            throw VectorException("Exception : incompatible sizes in "
                                  "Vector::operator Vector<T, N>");
        }
        Vector<T, N> result;
        for (size_t i = 0; i < this->len; i++) {
            result[i] = this->data[i];
        }
        return result;
    }

    Vector operator+(const Vector& x) {
        if (x.len != this->len) {
            throw VectorException(
                "Exception : incompatible sizes in Vector::operator+");
        }
        Vector<T, 0> result(x.len);
        for (size_t i = 0; i < result.len; i++) {
            result[i] = this->data[i] + x[i];
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& x) {
        for (size_t i = 0; i < x.len; i++) {
            out << x[i] << " ";
        }
        return out;
    }

    size_t size() const {
        return this->len;
    }

    void resize(size_t len) {
        auto data = std::make_unique<T[]>(len);
        std::copy(this->data.get(), this->data.get() + len, data.get());

        if (this->len < len) {
            std::fill(data.get() + this->len, data.get() + len, T());
        }
        this->len = len;
        this->data = std::exchange(data, nullptr);
    }
};

#endif // dynamicvector_hpp