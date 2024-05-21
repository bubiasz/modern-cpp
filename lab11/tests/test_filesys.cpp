//
//  test_filesys.cpp
//  lab11
//
//  Created by Jakub Matysek on 19/05/2024.
//

#include "../filesys.cpp"

int main() {
    printDirectory("./lab11/tests/");

    changeExtension("./lab11/tests/", "file.*", ".txt");
}