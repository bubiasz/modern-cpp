//
//  test_matrix_modifiers.cpp
//  lab08
//
//  Created by Jakub Matysek on 24/04/2024.
//

#include "../matrix.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>

int main() {
    using DMatrix = Matrix<double, 3, 4>;
    const DMatrix m({ { 1, 2, 3, 4 }, { 5, 6, 7, 8 },
        { 9, 10, 11, 12 } }); // constructor from initialization_list

    std::cout << std::fixed << std::setprecision(2);
    printMatrix(m, 3);

    Matrix<int, m.numberOfColumns() - 2, m.numberOfRows()> m2 {};
    printMatrix(m2, 3);

    auto m3 = m + m + m;
    printMatrix(m3, 3);

    return 0;
}

/*
Expected output:
1.00 2.00 3.00 4.00
5.00 6.00 7.00 8.00
9.00 10.00 11.00 12.00
  0   0   0
  0   0   0
3.00 6.00 9.00 12.00
15.00 18.00 21.00 24.00
27.00 30.00 33.00 36.00
*/
