//
//  test_conversion.cpp
//  lab05
//
//  Created by Jakub Matysek on 02/04/2024.
//

#include "../dynamicvector.hpp"
#include "../staticvector.hpp"
#include <iomanip>
#include <iostream>

template <int N>
using SWektor = Vector<double, N>;
using DWektor = Vector<double, 0>;

int main() {
    std::cout << std::fixed << std::setprecision(2);

    DWektor m1 = { 1, 2, 3 }; // dynamic z initialization_list
    std::cout << m1 << std::endl;

    SWektor<3> m2 = { 1, -1, 0 }; // static
    std::cout << m2 << std::endl;

    auto m3 = (SWektor<3>)(m1); // conversion from dynamic to static
    std::cout << m3 << std::endl;

    auto m4 = m1 + m2 + m1;
    std::cout << m4 << std::endl;

    auto m5 = static_cast<DWektor>(m4);
    std::cout << m5 << std::endl;

    return 0;
}