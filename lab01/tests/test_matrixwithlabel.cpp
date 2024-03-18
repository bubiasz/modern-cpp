//
//  test_matrixwithlabel.cpp
//  lab01
//
//  Created by Jakub Matysek on 04/03/2024.
//

#include "../matrixwithlabel.hpp"
#include <iostream>
#include <utility>

int main() {
    std::cout << "Inheritance \n";
    MatrixWithLabel l0("B", 3, 4);
    MatrixWithLabel l1({ { 1, 2 }, { 4, 5 } });
    l1.setLabel("A");
    MatrixWithLabel l2 = l1;
    MatrixWithLabel l3 = std::move(l1);
    std::cout << l2.getLabel() << " " << l3.getLabel() << std::endl;
    std::cout << l1.getLabel() << std::endl;

    return 0;
}
