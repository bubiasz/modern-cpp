//
//  test_typetraits.cpp
//  lab07
//
//  Created by Jakub Matysek on 22/04/2024.
//

#include "../typetraits.cpp"

int main() {
    info(1);
    info(2.0f);
    info(3U);

    return 0;
}

// Expected output:
// signed,  integer, min : -2147483648 max : 2147483647
// signed, not integer, min : 1.17549e-38 max : 3.40282e+38
// unsigned,  integer, min : 0 max : 4294967295
