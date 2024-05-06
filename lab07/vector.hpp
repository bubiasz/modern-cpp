//
//  vector.hpp
//  lab07
//
//  Created by Jakub Matysek on 22/04/2024.
//

#ifndef vector_hpp
#define vector_hpp

#include "vectortraits.hpp"
#include <initializer_list>
#include <iostream>

template <typename T, size_t N, typename P>
class Vector {
    T data[N];

public:
    typedef T value_type;
    typedef size_t size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T& const_reference;

    Vector() {
        P::init(data, N);
    };

    Vector(const Vector& v) = default;

    Vector& operator=(const Vector& m) = default;

    Vector(const std::initializer_list<T>& list) {
        P::init(data, list, N);
    }

    size_type size() const {
        return N;
    }

    vector_traits<T>::ArgType get(size_type index) const {
        P::check(index, N);
        return data[index];
    }

    void set(size_type index, vector_traits<T>::ArgType value) {
        P::check(index, N);
        data[index] = value;
    }

    friend Vector operator*(vector_traits<T>::ScalarType x, const Vector& v) {
        Vector result;
        for (int i = 0; i < v.size(); ++i) {
            result.set(i, vector_traits<T>::mult(x, v.get(i)));
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        for (int i = 0; i < v.size(); ++i) {
            out << v.get(i) << " ";
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Vector& v) {
        Vector::value_type value;
        for (int i = 0; i < v.size(); ++i) {
            in >> value;
            if (in)
                v.set(i, value);
        }
        return in;
    }
};

#endif /* vector_hpp */
