#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;
    std::getline(std::cin, filePath);

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "not found" << std::endl;
        return 0;
    }

    std::cout << file.rdbuf();

    return 0;
}
