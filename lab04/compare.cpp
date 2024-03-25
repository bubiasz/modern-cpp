//
//  compare.cpp
//  lab04
//
//  Created by Jakub Matysek on 19/03/2024.
//

#include <cstring>
#include <iostream>

struct Rational {
    int nominator = 0, denominator = 1;
    friend bool operator<(const Rational& a, const Rational& b) {
        return a.nominator * b.denominator < b.nominator * a.denominator;
    }
};

template <typename T>
int compare(T a, T b) {
    return (a < b) ? 1 : (b < a) ? -1 : 0;
}

template <typename T>
int compare(T* a, T* b) {
    return (*a < *b) ? 1 : (*b < *a) ? -1 : 0;
}

template <>
int compare<const char>(const char* a, const char* b) {
    return std::strcmp(a, b) < 0 ? 1 : std::strcmp(b, a) < 0 ? -1 : 0;
}

int main() {
    int a = 1, b = -6;
    float y = 1.0 + 1e20 - 1e20, x = 1.0;
    Rational p { 2 }, q { 1, 4 }, r { 8, 4 };
    std::cout << "values\n";
    std::cout << compare(a, b) << " " << compare(b, a) << " " << compare(a, a)
              << std::endl;
    std::cout << compare(x, y) << " " << compare(y, x) << " " << compare(x, x)
              << std::endl;
    std::cout << compare(p, q) << " " << compare(q, p) << " " << compare(p, r)
              << std::endl;
    std::cout << "pointers\n";
    std::cout << compare(&a, &b) << " " << compare(&b, &a) << " "
              << compare(&a, &a) << std::endl;
    std::cout << compare(&x, &y) << " " << compare(&y, &x) << " "
              << compare(&x, &x) << std::endl;
    std::cout << compare(&p, &q) << " " << compare(&q, &p) << " "
              << compare(&p, &r) << std::endl;

    const char *s = "Alpha", *t = "Alfa", *t2 = "Alfa";
    std::cout << "C-strings\n";
    std::cout << compare(s, t) << " " << compare(t, s) << " " << compare(t, t)
              << " " << compare(t, t2) << " " << compare(t, "Beta")
              << std::endl;

    return 0;
}