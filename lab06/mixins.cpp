//
//  mixins.cpp
//  lab06
//
//  Created by Jakub Matysek on 09/04/2024.
//

#include <iostream>
#include <vector>

/* Colors */
class Red {
public:
    static constexpr char color[] = "red";
};

class Yellow {
public:
    static constexpr char color[] = "yellow";
};

class Blue {
public:
    static constexpr char color[] = "blue";
};

/* Shapes*/
class Circle {
    double r = 0;

public:
    Circle() = default;
    Circle(double r)
        : r(r) { }
    double area() { return 3.24 * r * r; }
};
class Rectangle {
    double a = 0, b = 0;

public:
    Rectangle() = default;
    Rectangle(double a, double b)
        : a(a)
        , b(b) { }
    double area() { return a * b; }
};
/* Other Features */
class Note {
    std::vector<std::string> notes;

public:
    Note(const std::string& note) { add(note); }
    void add(const std::string& note) { notes.push_back(note); }
};

template<typename... Args>
class Mixins : public Args... {
public:
    Mixins(const Args&... args)
        : Args(args)... { }
};

int main() {
    using RedCircle = Mixins<Red, Circle>;
    RedCircle x(Red {}, Circle { 3 });
    std::cout << x.color << " area = " << x.area() << std::endl;

    using BlueRectangleWithNotes = Mixins<Blue, Rectangle, Note>;
    BlueRectangleWithNotes y(Blue {}, Rectangle { 3, 4 }, Note { "Hey" });
    y.add("Ho");
    std::cout << y.color << " area = " << y.area() << std::endl;
}