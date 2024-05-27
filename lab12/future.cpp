//
//  future.cpp
//  lab12
//
//  Created by Jakub Matysek on 27/05/2024.
//

#include <fstream>
#include <future>
#include <iostream>
#include <map>
#include <vector>

std::future<long long> sum_characters(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file) {
        throw std::runtime_error("Failed to open file");
    }

    long long sum = 0;
    char ch;

    while (file.get(ch)) {
        sum += static_cast<long long>(ch);
    }

    std::promise<long long> promise;
    promise.set_value(sum);

    return promise.get_future();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <file1> <file2> ..."
                  << std::endl;
        return 1;
    }

    std::vector<std::thread> threads;
    std::vector<std::future<long long>> futures(argc - 1);
    for (int i = 1; i < argc; i++) {
        threads.push_back(std::thread([i, &futures, &argv]() {
            futures[i - 1] = sum_characters(argv[i]);
        }));
    }
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    std::vector<long long> sums;
    for (auto& future : futures) {
        sums.push_back(future.get());
    }

    std::map<long long, std::vector<std::string>> files_map;
    for (int i = 1; i < argc; i++) {
        files_map[sums[i - 1]].push_back(argv[i]);
    }

    for (const auto& pair : files_map) {
        if (pair.second.size() > 1) {
            std::cout << "Files with the same sum: ";
            for (const auto& file : pair.second) {
                std::cout << file << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}