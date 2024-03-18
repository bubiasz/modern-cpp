//
//  staticcontainer2.hpp
//  lab02
//
//  Created by Jakub Matysek on 05/03/2024.
//

#ifndef staticcontainer2_hpp
#define staticcontainer2_hpp

#include "box.hpp"
#include <iostream>

class Container : public Box {
public:
    static bool verbose;

    Container(int content)
        : Box(content) {};

    Container(const Container& container) = delete;

    Container& operator=(const Container& container) = delete;

    Container(Container&& container) = default;

    Container& operator=(Container&& container) = default;

    ~Container() = default;

    friend Container operator+(const Container& p1, const Container& p2);

    friend std::ostream& operator<<(std::ostream& out, const Container& p) {
        return (out << " [" << p.getContent() << "] ");
    }
};

bool Container::verbose = false;

inline Container operator+(const Container& p1, const Container& p2) {
    Container suma(p1.getContent() + p2.getContent());
    return suma;
}

#endif /* staticcontainer2_hpp */
