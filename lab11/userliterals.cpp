//
//  userliterals.cpp
//  lab11
//
//  Created by Jakub Matysek on 19/05/2024.
//

long double operator""_cm(long double x) {
    return x / 100;
}

long double operator""_cm(unsigned long long x) {
    return static_cast<long double>(x) / 100;
}

long double operator""_m(long double x) {
    return x;
}
long double operator""_m(unsigned long long x) {
    return static_cast<long double>(x);
}

long double operator""_km(long double x) {
    return x * 1000;
}

long double operator""_km(unsigned long long x) {
    return static_cast<long double>(x) * 1000;
}

long double operator""_ms(long double x) {
    return x / 1000;
}

long double operator""_ms(unsigned long long x) {
    return static_cast<long double>(x) / 1000;
}

long double operator""_s(long double x) {
    return x;
}

long double operator""_s(unsigned long long x) {
    return static_cast<long double>(x);
}

long double operator""_h(long double x) {
    return x * 3600;
}

long double operator""_h(unsigned long long x) {
    return static_cast<long double>(x) * 3600;
}
