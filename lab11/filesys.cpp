//
//  filesys.cpp
//  lab11
//
//  Created by Jakub Matysek on 19/05/2024.
//

#include <filesystem>
#include <iostream>
#include <regex>
#include <string_view>

/**
 * Prints content of directory given by path
 * Format
 * [X] file_name file_size
 * where X equals D for directories, F for regular files, L for symlinks and
 * space otherwise.
 * @param path directory path
 */
void printDirectory(std::string_view path) {
    for (const auto& x : std::filesystem::directory_iterator(path)) {
        if (x.is_directory()) {
            std::cout << "[D] ";
        } else if (x.is_regular_file()) {
            std::cout << "[F] ";
        } else if (x.is_symlink()) {
            std::cout << "[L] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << x.path().filename() << " " << x.file_size() << std::endl;
    }
}

/**
 * Makes copies of all files matching fileNames regular expression in directory
 * given by path * to files in the same directory but with changes extension to
 * newExtension
 * @param path directory path
 * @param fileNames regular expression
 * @param newExtension new extension
 */
void changeExtension(std::filesystem::path path, std::string fileNames,
    std::string_view newExtension) {
    for (const auto& x : std::filesystem::directory_iterator(path)) {
        if (std::regex_match(x.path().filename().string(), std::regex(fileNames))) {
            auto filePath = x.path();
            filePath.replace_extension(newExtension);
            std::filesystem::copy_file(x.path(), filePath);
        }
    }
}