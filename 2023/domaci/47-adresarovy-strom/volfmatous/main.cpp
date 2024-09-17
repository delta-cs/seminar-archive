#include <iostream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

void printDirectoryContents(const std::string& folderPath, int nestLevel) {
    std::vector<std::string> files, directories;

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file())
            files.push_back(entry.path().filename().string());
        else if (entry.is_directory())
            directories.push_back(entry.path().filename().string());
    }

    std::sort(files.begin(), files.end());
    std::sort(directories.begin(), directories.end());

    std::cout << std::string(std::max(nestLevel - 1, 0) * 2, ' ');
    if (nestLevel > 0) {
        std::cout << "- ";
    }
    std::cout << fs::path(folderPath).filename().string() << std::endl;

    for (const auto& file : files) {
        std::cout << std::string(nestLevel * 2, ' ') << "- " << file << std::endl;
    }

    for (const auto& directory : directories) {
        printDirectoryContents(folderPath + "/" + directory, nestLevel + 1);
    }
}

int main() {
    std::string folderPath;
    std::getline(std::cin, folderPath);

    if (!fs::exists(folderPath)) {
        std::cout << "not found" << std::endl;
        return 0;
    }

    printDirectoryContents(folderPath, 0);
    return 0;
}
