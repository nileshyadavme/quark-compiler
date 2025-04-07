//
// Created by Nilesh on 08-04-2025.
//

#ifndef FILEUTILS_H
#define FILEUTILS_H
#include<fstream>
#include<string>

namespace quark::io {
    template<typename T>
    auto readFile(const std::string& path, T process) -> decltype(process(std::ifstream())) {
        std::ifstream file(path);
        if (!file.is_open()) {
            throw std::runtime_error("Quark: Failed to open file: " + path);
        }
        return process(file);
    }
    std::string readFileAsString(const std::string& path);
}



#endif //FILEUTILS_H
