//
//  pair.cpp
//  lab05
//
//  Created by Jakub Matysek on 02/04/2024.
//

#include <iostream>

// forward declarations
template <typename T, typename S>
class Pair;

template <typename T, typename S>
std::ostream& operator<<(std::ostream&, const Pair<T, S>&);

template <typename T, typename S>
class Pair {
    const T first;
    const S second;
    static int numberOfPair;

public:
    // constructor, increases numberOfPairs
    Pair(T first, S second);

    // converting constructor, increases numberOfPairs
    template <typename P, typename R>
    explicit Pair(const Pair<P, R>& pair);

    // destructor, decreases numberOfPair
    ~Pair();

    // returns first, mark it inline
    constexpr T getFirst() const;

    // returns second, mark it inline
    constexpr S getSecond() const;

    // returns a reversed Pair
    constexpr Pair<S, T> reverse() const;

    // return the number of existing objects of Pair<T,S>
    constexpr static int getNumberOfPairs();

    // friend declaration with single template function
    friend std::ostream& operator<< <>(std::ostream& out, const Pair& pair);

    // friend declaration with class template (any Pair<P,R>)
    template <typename, typename>
    friend class Pair;
};

template <typename T, typename S>
int Pair<T, S>::numberOfPair;

// implementation of methods
template <typename T, typename S>
Pair<T, S>::Pair(T first, S second)
    : first(first)
    , second(second) {
    ++Pair<T, S>::numberOfPair;
}

template <typename T, typename S>
template <typename P, typename R>
Pair<T, S>::Pair(const Pair<P, R>& pair)
    : first(pair.getFirst())
    , second(pair.getSecond()) {
    ++Pair<T, S>::numberOfPair;
}

template <typename T, typename S>
Pair<T, S>::~Pair() {
    --Pair<T, S>::numberOfPair;
}

template <typename T, typename S>
inline constexpr T Pair<T, S>::getFirst() const {
    return this->first;
}

template <typename T, typename S>
inline constexpr S Pair<T, S>::getSecond() const {
    return this->second;
}

template <typename T, typename S>
constexpr Pair<S, T> Pair<T, S>::reverse() const {
    return Pair<S, T>(second, first);
}

template <typename T, typename S>
constexpr int Pair<T, S>::getNumberOfPairs() {
    return Pair<T, S>::numberOfPair;
}

template <typename T, typename S>
std::ostream& operator<<(std::ostream& out, const Pair<T, S>& pair) {
    out << "(" << pair.getFirst() << ", " << pair.getSecond() << ")";
    return out;
}
