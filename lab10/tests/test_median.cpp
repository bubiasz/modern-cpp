//
//  test_median.cpp
//  lab10
//
//  Created by Jakub Matysek on 11/05/2024.
//

#include "../median.cpp"

#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

int main() {
    std::forward_list<int> a { 3, 2, 5, 1, 4 };
    std::cout << median(a) << std::endl; // 3
    std::vector<int> v { 3, 1, 4, 2 };
    std::cout << median(v) << std::endl; // 2.5
}