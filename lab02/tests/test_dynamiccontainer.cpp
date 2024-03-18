//
//  test_dynamiccontainer.cpp
//  lab02
//
//  Created by Jakub Matysek on 05/03/2024.
//

#include "../dynamiccontainer.hpp"
#include <iostream>
#include <utility>

int main() {
    Box::verbose = true;
    Container::verbose = false;

    Container p1(10);

    std::cout << "== Copy semantics \n";
    Container p2(p1);
    Container p3 = p1 + p2; // copy elision
    p1 = p1 = p3;

    std::cout << p1 << p2 << p3 << std::endl;

    std::cout << "== Move semantics \n"; // No copy after this line
    p1 = p2 + p3;
    Container p4 = std::move(p2);

    std::cout << p1 << p3 << p4 << std::endl;
    // std::cout << p2 << std::endl; // p2 should not be used here!!!
    std::cout << "== Cleaning up!\n";

    return 0;
}

/* Expected output:
 Box[1] constructor with content = 10
== Copy semantics
 Box[2] copy constructor from Box[1]
 Box[3] constructor with content = 20
 Box[1] copy assignment from Box[3]
 [20]  [10]  [20]
== Move semantics
 Box[4] constructor with content = 30
 Box[1] destructor
 [30]  [20]  [10]
== Cleaning up!
 Box[2] destructor
 Box[3] destructor
 Box[4] destructor
*/
