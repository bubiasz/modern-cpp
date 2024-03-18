//
//  printer.cpp
//  lab03
//
//  Created by Jakub Matysek on 12/03/2024.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

class Printer {
    std::ostream& out;
    std::string prefix { "" };
    std::string postfix { "" };

public:
    Printer(
        std::ostream& out, const std::string prefix, const std::string postfix)
        : out(out)
        , prefix(prefix)
        , postfix(postfix) { }

    template <typename T> void operator()(const T& x) const {
        this->out << this->prefix << x << this->postfix;
    }
};

int main() {
    // Creates unary functor that takes one argument x (of any type)
    // and outputs to given stream x surrounded by given prefix na postfix
    // e.g. in the following  [ x ]
    // Hint: define function template.

    Printer printer(std::cout, "[ ", " ] ");
    printer("hello"); // [ hello ]
    std::cout << "\nv = ";
    std::vector<int> v = { 1, 2, 3, 4 };
    std::for_each(v.begin(), v.end(), printer); // v = [ 1 ] [ 2 ] [ 3 ] [ 4 ]

    std::ofstream file("myFile.txt");
    Printer filePrinter(file, "- ", "\n");
    filePrinter(5);
    filePrinter("My text");
    
    return 0;
}

/* Expected output
myFile.txt
 - 5
 - My text
*/
