#include <iostream>

bool areWordsInOrder(std::string word1, std::string word2, bool descending) {
    bool letterCaseInOrder = true;
    bool letterCaseInOrderDecided = false;

    int shorterLength = std::min(word1.length(), word2.length());
    for (int i = 0; i < shorterLength; ++i) {
        char char1 = word1[i];
        char char2 = word2[i];

        if (std::tolower(char1) != std::tolower(char2)) {
            bool alphabetAscendingOrder = std::tolower(char1) < std::tolower(char2);
            return descending ? !alphabetAscendingOrder : alphabetAscendingOrder;
        }

        if (letterCaseInOrderDecided) {
            continue;
        }

        if (std::islower(char1) && std::isupper(char2)) {
            letterCaseInOrder = true;
            letterCaseInOrderDecided = true;
            continue;
        }

        if (std::isupper(char1) && std::islower(char2)) {
            letterCaseInOrder = false;
            letterCaseInOrderDecided = true;
            continue;
        }
    }

    if (word1.length() != word2.length()) {
        return word1.length() < word2.length();
    }

    return letterCaseInOrder;
}

int main() {
    int n;
    std::cin >> n;

    bool descending = false;
    bool descendingDecided = false;
    std::string previousWord;
    for (int i = 0; i < n; ++i) {
        std::string currentWord;
        std::cin >> currentWord;

        bool inOrderAscending = areWordsInOrder(previousWord, currentWord, false);
        bool inOrderDescending = areWordsInOrder(previousWord, currentWord, true);

        previousWord = currentWord;

        if (descendingDecided) {
            if ((descending && !inOrderDescending) || (!descending && !inOrderAscending)) {
                std::cout << "unordered" << std::endl;
                return 0;
            }
        } else {
            if (inOrderAscending && inOrderDescending) {
                continue;
            }

            descendingDecided = true;

            if (inOrderAscending) {
                descending = false;
                continue;
            }

            if (inOrderDescending) {
                descending = true;
                continue;
            }

            std::cout << "unordered" << std::endl;
            return 0;
        }
    }

    std::cout << "ordered" << std::endl;
    return 0;
}
