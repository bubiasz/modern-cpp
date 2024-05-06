//
//  vectorpolicies.hpp
//  lab07
//
//  Created by Jakub Matysek on 22/04/2024.
//

#ifndef vectorpolicies_hpp
#define vectorpolicies_hpp

#include "vectortraits.hpp"
#include <initializer_list>
#include <iostream>

class BasePolicy {
public:
    template <typename T>
    static void init(T* args, int N);

    template <typename T>
    static void init(T* args, const std::initializer_list<T>& list, int N);

    static void check(int index, int N);
};

class SafePolicy : public BasePolicy {
public:
    template <typename T>
    static void init(T* args, int N) {
        const T& val = vector_traits<T>::zero();
        std::fill(args, args + N, val);
    }

    template <typename T>
    static void init(T* args, const std::initializer_list<T>& list, int N) {
        if (list.size() > N) {
            //            throw std::runtime_error("Object std::initializer_list
            //            size is greater than passed template size argument");
            std::cout << "Exception" << std::endl;
        }
        std::copy(list.begin(), list.begin() + N, args);
    }

    static void check(int index, int N) {
        if (index < 0 or index >= N) {
            //            throw std::runtime_error("Index out of range");
            std::cout << "Exception" << std::endl;
        }
    }
};

class FastPolicy : public BasePolicy {
public:
    template <typename T>
    static void init(T* args, int N) {
    }

    template <typename T>
    static void init(T* args, const std::initializer_list<T>& list, int N) {
        std::copy(list.begin(), std::min(list.begin() + N, list.end()), args);
    }

    static void check(int index, int N) {
    }
};

class InitFastPolicy : public BasePolicy {
public:
    template <typename T>
    static void init(T* args, int N) {
        const T& val = vector_traits<T>::zero();
        std::fill(args, args + N, val);
    }

    template <typename T>
    static void init(T* args, const std::initializer_list<T>& list, int N) {
        std::copy(list.begin(), std::min(list.begin() + N, list.end()), args);
    }

    static void check(int index, int N) {
    }
};

#endif /* vectorpolicies_hpp */
