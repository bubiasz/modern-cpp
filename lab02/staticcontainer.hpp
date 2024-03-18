//
//  staticcontainer.hpp
//  lab02
//
//  Created by Jakub Matysek on 05/03/2024.
//

#ifndef staticcontainer_hpp
#define staticcontainer_hpp

#include "box.hpp"
#include <iostream>
#include <utility>

class Container : public Box {
public:
    static bool verbose;

    Container(int content)
        : Box(content) { }

    Container(const Container& container)
        : Box(container) {
        if (verbose)
            std::cout << "Container: copy constructor.\n";
    }

    Container& operator=(const Container& container) {
        if (verbose)
            std::cout << "Container: copy assignment.\n";
        if (this != &container) {
            Box::operator=(container);
        }
        return *this;
    }

    Container(Container&& container)
        : Box(std::move(container)) {
        if (verbose)
            std::cout << "Container: move constructor.\n";
    }

    Container& operator=(Container&& container) {
        if (verbose)
            std::cout << "Container: move assignment.\n";
        if (this != &container) {
            Box::operator=(std::move(container));
        }
        return *this;
    }

    ~Container() {
        if (verbose)
            std::cout << "Container destructor. \n";
    }

    friend Container operator+(const Container& p1, const Container& p2);

    friend std::ostream& operator<<(std::ostream& out, const Container& p) {
        return (std::cout << " [" << p.getContent() << "] ");
    }
};

bool Container::verbose = false;

inline Container operator+(const Container& p1, const Container& p2) {
    Container sum(p1.getContent() + p2.getContent());
    return sum;
}

#endif /* staticcontainer_hpp */
