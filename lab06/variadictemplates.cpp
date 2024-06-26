//
//  variadictemplates.cpp
//  lab06
//
//  Created by Jakub Matysek on 09/04/2024.
//

#include <boost/type_index.hpp>
#include <iostream>
#include <typeinfo>

double f(int x, double y, const int& z, int& w) {
    w += 2;
    std::cout << x << " " << y << " " << z << " " << w << std::endl;
    return (x * y - z * w);
}

template <typename... Args>
void showNames(Args&&... args) {
    int i = 0;
    ((std::cout << ++i << " > "
                << boost::typeindex::type_id_with_cvr<Args>().pretty_name()
                << " [" << typeid(args).name() << "] = " << args << std::endl),
        ...);
}

template <typename F>
class Proxy {
private:
    F f;

public:
    Proxy(F&& f)
        : f(std::forward<F>(f)) {
    }

    template <typename... T>
    auto operator()(T&&... args) -> decltype(f(std::forward<T>(args)...)) {
        std::cout << "Proxy" << std::endl;
        showNames(std::forward<T>(args)...);
        return f(std::forward<T>(args)...);
    }
};

template <typename F>
auto make_proxy(F&& f) {
    return Proxy<F>(std::forward<F>(f));
}

int main() {
    int x = 4;
    const int y = 8;
    showNames(x, 4.5, y, f);
    showNames(1, 1.0f, 1.0, 1LL, &x, &y);

    auto p = make_proxy(f);
    //   auto p = Proxy(f);    /// with C++ 17
    auto result1 = p(12, 5.1, y, x);
    std::cout << "result1 = " << result1 << std::endl;
    auto result2 = p(12, 5.1, y, x);
    std::cout << "result2 = " << result2 << std::endl;
    auto result3 = p(3, 3, 5, x);
    std::cout << "result3 = " << result3 << std::endl;

    auto g = make_proxy([](int&& x, int& y) {
        y = x;
        return y;
    });
    //   auto g = Proxy([](int &&x, int & y){ y = x; return y; }) ; // with C++
    //   17
    std::cout << g(5, x) << std::endl;
    std::cout << "x = " << x << std::endl;
    return 0;
}
/** Expected output
 1 > int& [i] = 4
 2 > double [d] = 4.5
 3 > int const& [i] = 8
 4 > double (&)(int, double, int const&, int&) [FdidRKiRiE] = 1
 1 > int [i] = 1
 2 > float [f] = 1
 3 > double [d] = 1
 4 > long long [x] = 1
 5 > int* [Pi] = 0x7ffde80f14c4
 6 > int const* [PKi] = 0x7ffde80f14c0

Proxy
 1 > int [i] = 12
 2 > double [d] = 5.1
 3 > int const& [i] = 8
 4 > int& [i] = 4
12 5.1 8 6
result1 = 13.2

Proxy
 1 > int [i] = 12
 2 > double [d] = 5.1
 3 > int const& [i] = 8
 4 > int& [i] = 6
12 5.1 8 8
result2 = -2.8

Proxy
 1 > int [i] = 3
 2 > int [i] = 3
 3 > int [i] = 5
 4 > int& [i] = 8
3 3 5 10
result3 = -41

Proxy
 1 > int [i] = 5
 2 > int& [i] = 10
5
x = 5
*/