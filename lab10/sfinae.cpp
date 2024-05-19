//
//  sfinae.cpp
//  lab10
//
//  Created by Jakub Matysek on 11/05/2024.
//

#include <iostream>

template <typename T, typename = void>
struct hasSize : std::false_type { };

template <typename T>
struct hasSize<T, std::void_t<decltype(std::declval<T>().size())>>
    : std::true_type { };

template <typename T, typename = void>
struct hasValueType : std::false_type { };

template <typename T>
struct hasValueType<T, std::void_t<typename T::value_type>> : std::true_type {
};

namespace v1 {
template <typename T>
typename std::enable_if<hasSize<T>::value, size_t>::type getSize(const T& x) {
    return x.size() * sizeof(typename T::value_type);
}

template <typename T>
typename std::enable_if<!hasSize<T>::value, size_t>::type getSize(const T& x) {
    return sizeof(T);
}
}

namespace v2 {
template <typename T>
int getSize(const T& x) {
    if constexpr (hasSize<T>::value) {
        return x.size() * sizeof(typename T::value_type);
    } else {
        return sizeof(T);
    }
}
}