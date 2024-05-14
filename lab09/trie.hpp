//
//  trie.hpp
//  lab09
//
//  Created by Jakub Matysek on 06/05/2024.
//

#ifndef trie_hpp
#define trie_hpp

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/*
Trie structure hint: use std::map to implement it! my implementation adds less
than 25 lines of code.
*/
class Trie {
    std::map<std::string, Trie*> endings {};

public:
    static void printSentence(const std::vector<std::string>& sentence) {
        for (const auto& w : sentence) {
            std::cout << w << " ";
        }
    }
    void add(const std::vector<std::string>& sentece) {
        std::cout << "Adding : ";
        printSentence(sentece);
        std::cout << std::endl;

        auto cursor = this;
        for (const auto& x : sentece) {
            if (cursor->endings.find(x) == cursor->endings.end()) {
                cursor->endings[x] = new Trie();
            }
            cursor = cursor->endings[x];
        }
    }

    void printEnding(const std::string& prefix) {
        if (this->endings.empty()) {
            std::cout << prefix << std::endl;
            return;
        }
        for (const auto& x : endings) {
            x.second->printEnding(prefix + " " + x.first);
        }
    }

    void printPossibleEndings(
        const std::vector<std::string>& beginningOfSentece) {
        std::cout << "Endings for \"";
        printSentence(beginningOfSentece);
        std::cout << "\" are :\n";

        auto cursor = this;
        for (const auto& x : beginningOfSentece) {
            if (cursor->endings.find(x) == cursor->endings.end()) {
                std::cout << "No endings found\n";
            }
            cursor = cursor->endings[x];
        }
        cursor->printEnding("");
    }
    void load(const std::string& fileName) {
        std::ifstream file(fileName);
        if (!file) {
            std::cerr << "Error when openning file " << fileName << std::endl;
            return;
        }
        std::string word;
        std::vector<std::string> sentence;
        while (file >> word) {
            sentence.push_back(word);
            // is it end of the sentence?
            if (word.find_last_of('.') != std::string::npos) {
                add(sentence);
                sentence.clear();
            }
        }
    }
};

#endif /* trie_hpp */
