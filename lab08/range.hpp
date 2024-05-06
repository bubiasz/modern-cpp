//
//  range.hpp
//  lab08
//
//  Created by Jakub Matysek on 24/04/2024.
//

#ifndef range_hpp
#define range_hpp

template <typename T>
class Range;

template <typename T>
Range<T> make_range(T stop) {
    return Range<T>(stop);
}

template <typename T>
Range<T> make_range(T start, T stop) {
    return Range<T>(start, stop);
}

template <typename T>
Range<T> make_range(T start, T stop, T step) {
    return Range<T>(start, stop, step);
}

template <typename T>
class Range {
    T start;
    T stop;
    T step;

public:
    Range(T stop)
        : start(0)
        , stop(stop)
        , step(1) {
    }
    Range(T start, T stop)
        : start(start)
        , stop(stop)
        , step(1) {
    }
    Range(T start, T stop, T step)
        : start(start)
        , stop(stop)
        , step(step) {
    }

    class iterator {
        T value;
        T step;

    public:
        iterator(T value, T step)
            : value(value)
            , step(step) {
        }

        T operator*() const {
            return value;
        }

        iterator& operator++() {
            value += step;
            return *this;
        }

        iterator operator++(int) {
            iterator copy = *this;
            value += step;
            return copy;
        }

        bool operator!=(const iterator& other) const {
            return step > 0 ? value < other.value : value > other.value;
        }
    };

    iterator begin() const {
        return iterator(start, step);
    }

    iterator end() const {
        return iterator(stop, step);
    }
};

#endif /* range_hpp */
