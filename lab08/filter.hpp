//
//  filter.hpp
//  lab08
//
//  Created by Jakub Matysek on 24/04/2024.
//

#ifndef filter_hpp
#define filter_hpp

#include <iostream>
#include <utility>

template <typename C, typename P>
class Filter;

template <typename C, typename P>
Filter<C, P> make_filter(C&& container, P predicate) {
    return Filter<C, P>(std::forward<C>(container), predicate);
}

template <typename C, typename P>
class Filter {
private:
    C container;
    P predicate;

public:
    Filter(C&& container, const P predicate)
        : container(std::forward<C>(container))
        , predicate(predicate) {
    }

    class Iterator {
    private:
        using IteratorType = typename std::remove_reference_t<C>::iterator;
        IteratorType current;
        IteratorType end;
        P predicate;

    public:
        Iterator(IteratorType begin, IteratorType end, P predicate)
            : current(begin)
            , end(end)
            , predicate(predicate) {
            while (current != end && !predicate(*current)) {
                ++current;
            }
        }

        Iterator& operator++() {
            ++current;
            while (current != end && !predicate(*current)) {
                ++current;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        auto operator*() const {
            return *current;
        }
    };

    using iterator = Iterator;

    Iterator begin() {
        return Iterator(container.begin(), container.end(), predicate);
    }

    Iterator end() {
        return Iterator(container.end(), container.end(), predicate);
    }
};

#endif /* filter_hpp */
