//
//  vectortraits.hpp
//  lab07
//
//  Created by Jakub Matysek on 22/04/2024.
//

#ifndef vectortraits_hpp
#define vectortraits_hpp

#include <string>

template <typename T>
class vector_traits {
public:
    typedef const T& ArgType;
    typedef T ScalarType;

    static ArgType mult(ScalarType x, ArgType arg) {
        return x * arg;
    }

    static ArgType zero() {
        return 0;
    }
};

template <>
class vector_traits<int> {
public:
    typedef int ArgType;
    typedef ArgType ScalarType;

    static ArgType mult(ScalarType x, ArgType arg) {
        return x * arg;
    }

    static ArgType zero() {
        return 0;
    }
};

template <>
class vector_traits<double> {
public:
    typedef double ArgType;
    typedef ArgType ScalarType;

    static ArgType mult(ScalarType x, ArgType arg) {
        return x * arg;
    }

    static ArgType zero() {
        return 0;
    }
};

template <>
class vector_traits<std::string> {
public:
    typedef std::string ArgType;
    typedef int ScalarType;

    static ArgType mult(ScalarType x, ArgType arg) {
        ArgType res = "";
        for (int i = 0; i < x; i++) {
            res += arg;
        }
        return res;
    }

    static ArgType zero() {
        return "0";
    }
};

#endif /* vectortraits_hpp */
