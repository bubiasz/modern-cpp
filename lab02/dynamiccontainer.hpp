//
//  dynamiccontainer.hpp
//  lab02
//
//  Created by Jakub Matysek on 05/03/2024.
//

#ifndef dynamiccontainer_hpp
#define dynamiccontainer_hpp

#include "box.hpp"
#include <iostream>
#include <memory>
#include <utility>

class Container {
    std::unique_ptr<Box> pbox { nullptr };

public:
    static bool verbose;

    Container(int content)
        : pbox(std::make_unique<Box>(content)) {
        if (verbose)
            std::cout << "Creating Container" << std::endl;
        this->pbox->setContent(content);
    }

    Container(const Container& container)
        : pbox(std::make_unique<Box>(*container.pbox)) {
        if (verbose)
            std::cout << "Creating copy of Container\n";
    }

    Container& operator=(const Container& container) {
        if (this != &container) {
            if (verbose)
                std::cout << "Copying Container\n";
            *this->pbox = *container.pbox;
        }
        return *this;
    }

    Container(Container&& container)
        : pbox(std::move(container.pbox)) { }

    Container& operator=(Container&& container) {
        if (this != &container) {
            this->pbox = std::move(container.pbox);
        }
        return *this;
    }

    ~Container() {
        if (verbose)
            std::cout << "Destroying Container \n";
    }

    friend Container operator+(const Container& p1, const Container& p2);

    friend std::ostream& operator<<(std::ostream& out, const Container& p) {
        return (out << " [" << p.pbox->getContent() << "] ");
    }
};

bool Container::verbose = false;

inline Container operator+(const Container& p1, const Container& p2) {
    Container sum(p1.pbox->getContent() + p2.pbox->getContent());
    return sum;
}

#endif /* dynamiccontainer_hpp */
