//
//  vectoroperators.hpp
//  lab07
//
//  Created by Jakub Matysek on 22/04/2024.
//

#ifndef vectoroperators_hpp
#define vectoroperators_hpp

#include <iostream>

template <int N>
class Vector {
    int data[N];

public:
    Vector() {
        std::cout << " Default constr" << std::endl;
    }

    Vector(std::initializer_list<int> list) {
        std::cout << " Init list constr" << std::endl;
        auto it = list.begin();
        for (int i = 0; i < N; i++) {
            data[i] = *it++;
        }
    }

    Vector(const Vector& m) {
        std::copy(m.data, m.data + N, data);
        std::cout << " Copy constr" << std::endl;
    }

    int operator[](int index) const {
        return data[index];
    }

    int& operator[](int index) {
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& m) {
        for (auto x : m.data) {
            std::cout << x << ", ";
        }
        return out;
    }
};

template <typename L, typename R>
class Node {
public:
    const L& l;
    const R& r;

public:
    Node(L&& l, R&& r)
        : l(std::forward<L>(l))
        , r(std::forward<R>(r)) {
    }
    virtual int operator[](int index) const = 0;

    template <int N>
    operator Vector<N>() {
        Vector<N> result;
        for (int i = 0; i < N; i++) {
            result[i] = (*this)[i];
        }
        return result;
    }
};

template <typename L, typename R>
class AddNode : public Node<L, R> {
public:
    AddNode(L&& l, R&& r)
        : Node<L, R>(std::forward<L>(l), std::forward<R>(r)) {
    }
    int operator[](int index) const {
        return this->l[index] + this->r[index];
    }
};

template <typename L, typename R>
class SubNode : public Node<L, R> {
public:
    SubNode(L&& l, R&& r)
        : Node<L, R>(std::forward<L>(l), std::forward<R>(r)) {
    }
    int operator[](int index) const {
        return this->l[index] - this->r[index];
    }
};

template <typename L, typename R>
class MulNode : public Node<L, R> {
public:
    MulNode(L&& l, R&& r)
        : Node<L, R>(std::forward<L>(l), std::forward<R>(r)) {
    }
    int operator[](int index) const {
        return this->l * this->r[index];
    }
};

template <typename L, typename R>
AddNode<L, R> operator+(L&& l, R&& r) {
    return AddNode<L, R>(std::forward<L>(l), std::forward<R>(r));
}

template <typename L, typename R>
SubNode<L, R> operator-(L&& l, R&& r) {
    return SubNode<L, R>(std::forward<L>(l), std::forward<R>(r));
}

template <typename L, typename R>
MulNode<L, R> operator*(L&& l, R&& r) {
    return MulNode<L, R>(std::forward<L>(l), std::forward<R>(r));
}

#endif /* vectoroperators_hpp */
