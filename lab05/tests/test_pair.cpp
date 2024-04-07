//
//  test_pair.cpp
//  lab05
//
//  Created by Jakub Matysek on 02/04/2024.
//

#include "../pair.cpp"
#include <iostream>

int main() {
    Pair<int, double> p { 1, 3.1415 };
    std::cout << p.getFirst() << " " << p.getSecond() << std::endl;
    std::cout << p << std::endl;
    auto p2 = p.reverse();
    std::cout << p2 << std::endl;
    {
        Pair<int, int> p3(p);
        std::cout << p3 << std::endl;
        std::cout << Pair<int, int>::getNumberOfPairs() << std::endl;
    }
    std::cout << Pair<int, int>::getNumberOfPairs() << std::endl;

    return 0;
}

/* Expected output
1 3.1415
(1, 3.1415)
(3.1415, 1)
(1, 3)
1
0
*/