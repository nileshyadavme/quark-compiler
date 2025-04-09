#include "FileUtils.h"
#include <fstream>
#include <sstream>

namespace quark::io {
    std::string readFileAsString(const std::string &path) {
        std::ifstream file(path);
        if (!file) throw std::runtime_error("failed to open file : "+path);
        return{
            std::istreambuf_iterator<char>(file),
            std::istreambuf_iterator<char>(),
        };
    }
} // namespace quark::file
