//
//  stdalgorithms.cpp
//  lab09
//
//  Created by Jakub Matysek on 06/05/2024.
//

#include <iostream>
#include <string>

template <typename C>
void print(const C& c) {
    // Print elements of the container separated by ", " using std::copy
    // and std::ostream_iterator (1 line)
    std::copy(c.begin(), c.end(),
        std::ostream_iterator<typename C::value_type>(std::cout, ", "));
    std::cout << std::endl;
}

/**
Removes all non alphanumeric characters from given word and converts to lower
case.
    @param[in,out] word on return word consist only of lower case characters.
*/
void toLowerAlpha(std::string& word) {
    // Implement using stl algorithms only hint: use remove_if, transform, erase
    word.erase(std::remove_if(word.begin(), word.end(),
                   [](char c) { return !std::isalnum(c); }),
        word.end());

    std::transform(word.begin(), word.end(), word.begin(),
        [](char c) { return std::tolower(c); });
}

/**
Checks if the first word is an anagram of the second word.
    - All non alphanumeric chars are ignored (remove them).
    - It is case insensitive (convert to lower case).
    - Words cannot be the same (at least one change needed).
    - They should contain the same letters (sort letters in each word to
compare).

    @param word1 not empty string
    @param word2 not empty string
    @return true if and only if word1 is an anagram of word2.
*/
bool isAnagram(std::string word1, std::string word2) {
    // Implement isAnagram function using stl algorithms only hint: use
    // toLowerAlpha, sort, equal (several lines)
    toLowerAlpha(word1);
    toLowerAlpha(word2);

    if (word1 == word2) {
        return false;
    }

    std::sort(word1.begin(), word1.end());
    std::sort(word2.begin(), word2.end());

    return std::equal(word1.begin(), word1.end(), word2.begin(), word2.end());
}
