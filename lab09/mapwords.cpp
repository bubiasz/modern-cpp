//
//  mapwords.cpp
//  lab09
//
//  Created by Jakub Matysek on 06/05/2024.
//

#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

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

int main() {
    int count = 0;
    std::string word;

    // unordered because is faster
    std::unordered_map<std::string, int> c;
    std::vector<int> v;
    while (std::cin >> word) {
        toLowerAlpha(word);

        if (word != "") {
            c[word]++;
            count++;
        }
    }

    std::multimap<int, std::string> m2;

    std::cout << "Number of distinct words : " << c.size() << std::endl;
    std::cout << "\nThe top 20 most popular words: \n";

    std::for_each(c.begin(), c.end(),
        [&m2](const auto& p) { m2.insert(std::make_pair(p.second, p.first)); });

    int i = 0;
    for (auto it = m2.rbegin(); it != m2.rend() && i < 20; ++it, ++i) {
        std::cout << it->second << " : " << it->first << std::endl;
    }

    return 0;
}

/*
Expected output for ./words < hamletEN.txt:

Number of distinct words : 4726

The top 20 most popular words:
the : 1145
and : 967
to : 745
of : 673
i : 569
you : 550
a : 536
my : 514
hamlet : 465
in : 437
it : 417
that : 391
is : 340
not : 315
lord : 311
this : 297
his : 296
but : 271
with : 268
for : 248
your : 242
*/
