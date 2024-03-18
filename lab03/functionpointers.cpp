//
//  functionpointers.cpp
//  lab03
//
//  Created by Jakub Matysek on 12/03/2024.
//

#include <cmath>
#include <iostream>

double sqrtn(int n, double x) { return std::exp(std::log(x) / n); }

double power(double x, double y) { return std::exp(std::log(x) * y); }

template <typename F, typename G>
double function(int n, double y, double z, F f, G g) {
    return (f(n, y) > z) ? g(z, y) : g(y, z);
}

int main() {
    double (*fp1)(int, double) = sqrtn;
    double (*fp2)(double, double) = power;
    double (*fp3)(int, double, double, double (*)(int, double),
        double (*)(double, double))
        = function<double (*)(int, double), double (*)(double, double)>;

    std::cout << fp3(2, 10, 3, fp1, fp2) << std::endl;
    std::cout << fp3(3, 10, 3, fp1, fp2) << std::endl;

    return 0;
}
