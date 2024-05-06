//
//  typetraits.cpp
//  lab07
//
//  Created by Jakub Matysek on 22/04/2024.
//

#include <iostream>
#include <limits>
#include <type_traits>

// Outputs information about numerical type T:
//(un)signed, (not) integer, min & max values

template <typename T>
void info(T x) {
    std::cout << ((std::is_signed<T>::value) ? "signed" : "unsigned") << ", "
              << ((std::is_integral<T>::value) ? "integer" : "not integer")
              << ", min: " << std::numeric_limits<T>::min()
              << ", max: " << std::numeric_limits<T>::max() << std::endl;
}
