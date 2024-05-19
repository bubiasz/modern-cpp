//
//  median.cpp
//  lab10
//
//  Created by Jakub Matysek on 11/05/2024.
//

#include <algorithm>
#include <list>
#include <vector>

template <typename C>
double median(C& x, std::random_access_iterator_tag) {
    auto n = x.size();

    std::sort(x.begin(), x.end());
    if (n % 2 == 0) {
        return (x[n / 2 - 1] + x[n / 2]) / 2.0;
    } else {
        return x[n / 2];
    }
}

template <typename C>
double median(C& x, std::forward_iterator_tag) {
    auto n = std::distance(x.begin(), x.end());

    x.sort();
    auto m = x.begin();
    std::advance(m, n / 2);

    if (n % 2 == 0) {
        auto prev = m;
        std::advance(prev, -1);
        return (*m + *prev) / 2.0;
    } else {
        return *m;
    }
}

template <typename C>
double median(C& x) {
    return median(x,
        typename std::iterator_traits<
            decltype(x.begin())>::iterator_category());
}