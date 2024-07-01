#include "main.hpp"

std::string replaceAllManual(const std::string& str, const std::string& from, const std::string& to) {
    std::string result;
    size_t pos = 0, fromLen = from.length();
    
    while (true) {
        size_t found = str.find(from, pos);
        if (found != std::string::npos) {
            result.append(str, pos, found - pos);
            result.append(to);
            pos = found + fromLen;
        }
        else {
            result.append(str, pos, std::string::npos);
            break;
        }
    }

    return result;
}

std::string readFileToString(const std::string& filePath) {
    std::ifstream fileStream(filePath.c_str());
    if (!fileStream.is_open()) {
        std::cerr << "Could not open the file: " << filePath + "\n";
        return "";
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}
