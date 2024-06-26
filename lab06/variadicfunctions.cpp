//
//  variadicfunctions.cpp
//  lab06
//
//  Created by Jakub Matysek on 09/04/2024.
//

#include <iostream>
#include <vector>

int f(int x) { return x * x; }
int cube(int x) { return x * x * x; }

template <typename... Targs>
double average(const Targs&... args) {
    return static_cast<double>((args + ...)) / static_cast<double>((sizeof...(args)));
}

template <typename T, typename... Targs>
double computeSum(T (*f)(T), const Targs&... args) {
    return static_cast<double>((f(args) + ...));
}

template <typename C, typename... Args>
void insert(C& c, const Args&... args) {
    (c.push_back(args), ...);
}

int main() {
    std::cout << average(1, 2) << std::endl; // 1.5
    std::cout << average(1.0, 10, 1, 34.5f, 12u) << std::endl; // 11.7
    std::cout << computeSum(f, 1, 2, 3, 4) << std::endl; // f(1)+f(2)+f(3)+f(4) = 30
    std::cout << computeSum(cube, 1, 2, 3, 4) << std::endl; // 1^3 + 2^3 + 3^3 + 4^3 = 100

    std::vector<int> v;
    insert(v, 1, 2, 3, 4, 5, 6);
    insert(v, 7, 8);

    for (auto x : v) // 1 2 3 4 5 6 7 8
        std::cout << x << " ";

    return 0;
}