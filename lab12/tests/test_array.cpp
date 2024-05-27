//
//  test_array.cpp
//  lab12
//
//  Created by Jakub Matysek on 27/05/2024.
//

#include "../array.hpp"
#include <iostream>
#include <thread>
#include <vector>

int THREADS_COUNT = 2;

int main() {
    srand(2019);

    // constant values
    using A = Array<1000>;
    A array(THREADS_COUNT);

    // generate array
    std::vector<std::thread> threads;
    for (int i = 0; i < THREADS_COUNT; i++) {
        threads.push_back(std::thread(&A::generateArray, &array));
    }
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    // print array
    for (int i = 0; i < 20; i++) {
        std::cout << array.a[0 + i] << "  ";
    }
    std::cout << std::endl;

    // compute sum
    for (int i = 0; i < THREADS_COUNT; i++) {
        threads.push_back(std::thread(&A::computeSum, &array));
    }
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    std::cout << "sum = " << array.getSum() << std::endl;
}