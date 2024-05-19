//
//  chrono.hpp
//  lab10
//
//  Created by Jakub Matysek on 11/05/2024.
//

#ifndef chrono_hpp
#define chrono_hpp

#include <chrono>
#include <iostream>
#include <string>

class Timer {
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
    Timer(const std::string& name)
        : name(name)
        , start(std::chrono::high_resolution_clock::now()) {
    }
    ~Timer() {
        std::cout << name << " : "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::high_resolution_clock::now() - start)
                         .count()
                  << " ms. " << std::endl;
    }
    auto durationInNanoseconds() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now() - start)
            .count();
    }
};

#endif /* chrono_hpp */
