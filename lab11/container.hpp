//
//  container.hpp
//  lab11
//
//  Created by Jakub Matysek on 19/05/2024.
//

#ifndef container_hpp
#define container_hpp

#include <concepts>
#include <iostream>
#include <numeric>
#include <vector>

template <typename C>
concept Container = requires(C container) {
    typename C::value_type;
    { container.begin() } -> std::same_as<typename C::iterator>;
    { container.end() } -> std::same_as<typename C::iterator>;
};

template <typename C>
concept PrintFunction = requires(C container) {
    { container.print() };
};

template <typename C>
concept PrintOperator = requires(C container) {
    { std::cout << container };
};

template <typename C>
void print(const C& container) {
    if constexpr (Container<C>) {
        for (const auto& x: container) {
            print(x);
        }
    } else if constexpr (PrintOperator<C>) {
        std::cout << container << std::endl;
    } else if constexpr (PrintFunction<C>) {
        container.print();
        std::cout << std::endl;
    } else {
        std::cout << container << std::endl;
    }
}

template <typename C>
auto sum(const C& container) {
    if constexpr (Container<C>) {
        return std::accumulate(container.begin(), container.end(), typename C::value_type());
    } else {
        return container;
    }
}

#endif /* container_hpp */