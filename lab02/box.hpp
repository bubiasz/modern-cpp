//
//  box.hpp
//  lab02
//
//  Created by Jakub Matysek on 05/03/2024.
//

#ifndef box_hpp
#define box_hpp

#include <algorithm>
#include <iostream>

class Box {
    int id;
    int content { 0 };
    static int lastID;

public:
    static bool verbose;

    Box()
        : id(++lastID) {
        if (verbose)
            std::cout << " Box[" << this->id << "] default constructor" << std::endl;
    }

    Box(int content)
        : id(++lastID)
        , content(content) {
        if (verbose)
            std::cout << " Box[" << this->id
                      << "] constructor with content = " << this->content
                      << std::endl;
    }

    Box(const Box& box)
        : id(++lastID)
        , content(box.content) {
        if (verbose)
            std::cout << " Box[" << this->id << "] copy constructor from Box["
                      << box.id << "]" << std::endl;
    }

    Box& operator=(const Box& box) {
        if (verbose)
            std::cout << " Box[" << this->id << "] copy assignment from Box["
                      << box.id << "]" << std::endl;
        this->content = box.content;
        return *this;
    }

    Box(Box&& box)
        : id(++lastID)
        , content(box.content) {
        if (verbose)
            std::cout << " Box[" << this->id << "] move constructor from Box["
                      << box.id << "]" << std::endl;
        box.content = 0;
    }

    Box& operator=(Box&& box) {
        if (verbose)
            std::cout << " Box[" << this->id
                      << "] move assignment, swapping content with Box["
                      << box.id << "]" << std::endl;
        std::swap(this->content, box.content);
        return *this;
    }

    ~Box() {
        if (verbose)
            std::cout << " Box[" << this->id << "] destructor " << std::endl;
    }

    void setContent(int content) { this->content = content; }

    int getContent() const { return this->content; }
};

int Box::lastID = 0;
bool Box::verbose = false;

#endif /* box_hpp */
