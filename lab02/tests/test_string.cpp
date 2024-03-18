//
//  test_string.cpp
//  lab02
//
//  Created by Jakub Matysek on 05/03/2024.
//

#include "../string.hpp"
#include <iostream>

int main() {
    String a("hi"); // Constructor from C string
    String b; // Default constructor
    const String c = a; // no copy (c points to string in a)
    String d = a + b; // no copy (d points to string in a)
    a.set(0, 'l'); // Copy constructor
    a.set(1, 'l'); // no copy
    d = c + a; // Constructing new string
    std::cout << c << " " << d << std::endl; // hi hill  (no copy)
    std::cout << c.get(0) << std::endl; // h        (no copy)

    return 0;
}

/* Expected output
Constructor from C string
Default constructor
Copy constructor
Constructor from C string
hi hill
h
*/
