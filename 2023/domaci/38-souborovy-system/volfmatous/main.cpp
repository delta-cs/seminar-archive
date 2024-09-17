#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> dividePath(std::string path) {
    std::vector<std::string> pathSplit;
    size_t start = 0;
    size_t end = path.find('/');

    while (end != std::string::npos) {
        pathSplit.push_back(path.substr(start, end - start));
        start = end + 1;
        end = path.find('/', start);
    }

    pathSplit.push_back(path.substr(start, end));

    bool pathIsAbsolute = path[0] == '/';
    std::vector<std::string> pathSimplified;

    for (size_t i = pathIsAbsolute ? 1 : 0; i < pathSplit.size() - 1; ++i) {
        std::string segment = pathSplit[i];

        if (pathIsAbsolute && segment == "..") {
            if (!pathSimplified.empty()) {
                pathSimplified.pop_back();
            }
        } else {
            pathSimplified.push_back(segment);
        }
    }

    return pathSimplified;
}

int main() {
    std::string path1, path2;
    std::getline(std::cin, path1);
    std::getline(std::cin, path2);

    bool path2IsAbsolute = path2[0] == '/';

    std::vector<std::string> path1Segments = dividePath(path1);
    std::vector<std::string> path2Segments = dividePath(path2);

    std::string result = "";

    if (path2IsAbsolute) {
        size_t longerPathLength = std::max(path1Segments.size(), path2Segments.size());

        for (size_t i = 0; i < longerPathLength; ++i) {
            if (i < path1Segments.size() && i < path2Segments.size() && path1Segments[i] == path2Segments[i]) {
                continue;
            }

            for (size_t j = i; j < path1Segments.size(); ++j) {
                result += "../";
            }

            for (size_t j = i; j < path2Segments.size(); ++j) {
                result += path2Segments[j] + "/";
            }

            break;
        }
    } else {
        for (const std::string& segment : path2Segments) {
            if (segment == "..") {
                if (!path1Segments.empty()) {
                    path1Segments.pop_back();
                }
            } else {
                path1Segments.push_back(segment);
            }
        }

        result = "/";
        for (const std::string& segment : path1Segments) {
            result += segment + "/";
        }
    }

    std::cout << result << std::endl;

    return 0;
}
