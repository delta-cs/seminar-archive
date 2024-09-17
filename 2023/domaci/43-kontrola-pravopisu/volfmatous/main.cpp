#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::unordered_set<std::string> dictionaryWords;

    int d;
    std::cin >> d;

    for (int i = 0; i < d; i++) {
        std::string word;
        std::cin >> word;
        dictionaryWords.insert(word);
    }

    bool sentenceStarts = true;
    bool previousWordWasNumber = false;

    int l;
    std::cin >> l;
    std::cin.ignore();

    for (int i = 0; i < l; i++) {
        std::string line;
        std::getline(std::cin, line);

        std::cout << line << std::endl;

        if (line.length() < 1) {
            continue;
        }

        std::vector<int> errorIndexes;
        std::vector<int> errorLengths;
        std::vector<std::string> errorMessages;

        int currentIndex = 0;
        bool duplicateSpaceFlag = false;

        line += ' ';
        size_t pos;
        std::string word;
        while ((pos = line.find(' ', currentIndex)) != std::string::npos) {
            word = line.substr(currentIndex, pos - currentIndex);

            if (word.length() < 1) {
                if (duplicateSpaceFlag) {
                    errorLengths[errorLengths.size() - 1]++;
                } else {
                    errorIndexes.push_back(std::max(0, currentIndex - 1));
                    errorLengths.push_back(2);
                    errorMessages.push_back("duplicate space");
                    duplicateSpaceFlag = true;
                }

                currentIndex++;
                continue;
            }

            duplicateSpaceFlag = false;

            bool endsWithDot = false;
            if (word.back() == '.') {
                word = word.substr(0, word.length() - 1);
                endsWithDot = true;
            }

            bool isNumber = true;
            for (char c : word) {
                if (!std::isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }

            std::string wordCapitalized = std::string(1, std::toupper(word[0])) + word.substr(1);
            std::string wordLowercase = word;
            std::transform(word.begin(), word.end(), wordLowercase.begin(), ::tolower);

            if (isNumber) {
                if (word.length() > 3) {
                    errorIndexes.push_back(currentIndex);
                    errorLengths.push_back(word.length());
                    errorMessages.push_back("incorrect number formatting");
                }
            } else if (dictionaryWords.find(wordCapitalized) == dictionaryWords.end() && dictionaryWords.find(wordLowercase) == dictionaryWords.end()) {
                errorIndexes.push_back(currentIndex);
                errorLengths.push_back(word.length());
                errorMessages.push_back("unknown word");
            } else if (std::isupper(word[0]) && !sentenceStarts && !previousWordWasNumber && dictionaryWords.find(word) == dictionaryWords.end()) {
                errorIndexes.push_back(currentIndex);
                errorLengths.push_back(word.length());
                errorMessages.push_back("incorrect leading uppercase");
            } else if (std::islower(word[0]) && (sentenceStarts || dictionaryWords.find(wordLowercase) == dictionaryWords.end())) {
                errorIndexes.push_back(currentIndex);
                errorLengths.push_back(word.length());
                errorMessages.push_back("incorrect leading lowercase");
            }

            currentIndex = pos + 1;
            sentenceStarts = endsWithDot && !isNumber;
            previousWordWasNumber = isNumber;
        }

        if (errorIndexes.empty()) {
            continue;
        }

        currentIndex = 0;
        for (size_t j = 0; j < errorIndexes.size(); j++) {
            for (int k = 0; k < errorIndexes[j] - currentIndex; k++) {
                std::cout << ' ';
            }

            for (int k = 0; k < errorLengths[j]; k++) {
                std::cout << '~';
            }

            currentIndex = errorIndexes[j] + errorLengths[j];
        }

        std::cout << std::endl;

        currentIndex = 0;
        for (size_t j = 0; j < errorIndexes.size(); j++) {
            for (int k = 0; k < errorIndexes[j] - currentIndex; k++) {
                std::cout << ' ';
            }

            std::cout << '^';

            currentIndex = errorIndexes[j] + 1;
        }

        std::cout << std::endl;

        for (int lineIndex = 0; lineIndex < errorIndexes.size() * 2; lineIndex++) {
            currentIndex = 0;

            for (size_t j = 0; j < errorIndexes.size() - lineIndex / 2; j++) {
                for (int k = 0; k < errorIndexes[j] - currentIndex; k++) {
                    std::cout << ' ';
                }

                if (j == errorIndexes.size() - (lineIndex + 1) / 2) {
                    std::cout << "----- " << errorMessages[j];
                } else {
                    std::cout << '|';
                }

                currentIndex = errorIndexes[j] + 1;
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
