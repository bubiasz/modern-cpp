//
//  test_vectortraits.cpp
//  lab07
//
//  Created by Jakub Matysek on 22/04/2024.
//

#include "../vector.hpp"
#include "../vectorpolicies.hpp"
#include <iostream>

int main() {
    Vector<double, 4, FastPolicy> a {};
    for (int i = 0; i < a.size(); i++) {
        a.set(i, 2.0 - i);
    }
    std::cout << "a   = " << a << std::endl;
    std::cout << "5.2*a = " << 5.2 * a << std::endl;

    Vector<int, 5, FastPolicy> b { 1, 2, 5, 6, 8 };
    std::cout << "b   = " << b << std::endl;
    std::cout << "2*b = " << 2 * b << std::endl;

    Vector<std::string, 4, FastPolicy> c { "curiosity", "killed", "the", "cat" };
    std::cout << "c   = " << c << std::endl;
    std::cout << "2*c = " << 2 * c << std::endl;

    return 0;
}

// Expected output:
// a   = 2 1 0 -1
// 5.2*a = 10.4 5.2 0 -5.2
// b   = 1 2 5 6 8
// 2*b = 2 4 10 12 16
// c   = curiosity killed the cat
// 2*c = curiositycuriosity killedkilled thethe catcat
