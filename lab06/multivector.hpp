//
//  multivector.hpp
//  lab06
//
//  Created by Jakub Matysek on 09/04/2024.
//

#ifndef multivector_hpp
#define multivector_hpp

#include <iostream>
#include <vector>

template <typename... Args>
class MultiVector {
public:
    void print(bool) {};
};

template <typename T, typename... Args>
class MultiVector<T, Args...> {
    std::vector<T> data;
    MultiVector<Args...> rest;

public:
    void push_back(const T& x) {
        data.push_back(x);
    }

    template <typename Arg>
    void push_back(const Arg& x) {
        rest.push_back(x);
    }

    void print(bool islast = true) {
        std::cout << "[ ";
        for (const auto& x : data) {
            std::cout << x << " ";
        }
        std::cout << "] ";
        rest.print(false);
        if (islast) {
            std::cout << std::endl;
        }
    }
};

#endif // multivector_hpp