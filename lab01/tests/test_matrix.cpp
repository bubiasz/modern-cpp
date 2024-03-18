//
//  test_matrix.cpp
//  lab01
//
//  Created by Jakub Matysek on 04/03/2024.
//

#include "../matrix.hpp"
#include <iostream>
#include <utility>

int main() {
    Matrix m1;
    Matrix m2(3, 4);
    Matrix m3({ { 1, 2, 3 }, { 32, 23, 22 }, { 3, 234, 23, 44 } });
    std::cout << m2(1, 1) << std::endl; // 0
    std::cout << m3(2, 2) << std::endl; // 23
    std::cout << m3;

    std::cout << "Copy semantics \n";
    Matrix m4 = m2;
    m4 = m3;

    std::cout << "Move semantics \n";
    Matrix m7 = std::move(m2);
    m4 = -m3;

    std::cout << "Copy elision \n";
    Matrix m6 = -m4;
    Matrix* pm = new Matrix(-m4);
    std::cout << m6(2, 1) << std::endl; // 32

    delete pm;

    return 0;
}
