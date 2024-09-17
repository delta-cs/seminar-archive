#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

double expressionValue(const std::vector<std::string> &lineSplit, const std::unordered_map<std::string, double> &variables) {
    if (lineSplit.size() % 2 != 1) {
        return NAN;
    }

    bool expressionAdd = true;
    double expressionValue = 0;

    for (size_t w = 0; w < lineSplit.size(); w++) {
        if (w % 2 == 0) {
            double value;
            try {
                value = std::stod(lineSplit[w]);
            } catch (const std::invalid_argument &e) {
                if (variables.find(lineSplit[w]) == variables.end()) {
                    return NAN;
                }

                value = variables.at(lineSplit[w]);
            }

            expressionValue += expressionAdd ? value : -value;
        } else {
            if (lineSplit[w] == "a") {
                expressionAdd = true;
            } else if (lineSplit[w] == "bez") {
                expressionAdd = false;
            } else {
                return NAN;
            }
        }
    }

    return expressionValue;
}

std::pair<bool, bool> conditionPass(const std::vector<std::string> &lineSplit, const std::unordered_map<std::string, double> &variables) {
    std::vector<int> orIndexes;
    orIndexes.push_back(-1);
    for (size_t i = 0; i < lineSplit.size(); i++) {
        if (lineSplit[i] == "nebo") {
            orIndexes.push_back(i);
        }
    }

    orIndexes.push_back(lineSplit.size());

    bool conditionPass = false;
    bool validExpression = true;

    for (size_t i = 0; i < orIndexes.size() - 1; i++) {
        int startIndex = orIndexes[i] + 1;
        int endIndex = orIndexes[i + 1] - 1;

        int comparatorIndex = -1;
        for (int c = startIndex; c <= endIndex; c++) {
            if (lineSplit[c] == "rovno" || lineSplit[c] == "aspon" || lineSplit[c] == "nejvic") {
                comparatorIndex = c;
                break;
            }
        }

        if (comparatorIndex == -1) {
            validExpression = false;
            break;
        }

        std::string comparator = lineSplit[comparatorIndex];
        double expression1Result = expressionValue(std::vector<std::string>(lineSplit.begin() + startIndex, lineSplit.begin() + comparatorIndex), variables);
        double expression2Result = expressionValue(std::vector<std::string>(lineSplit.begin() + comparatorIndex + 1, lineSplit.begin() + endIndex + 1), variables);

        if (std::isnan(expression1Result) || std::isnan(expression2Result)) {
            validExpression = false;
            break;
        }

        if (!conditionPass) {
            double expression1 = expression1Result;
            double expression2 = expression2Result;

            if (comparator == "rovno") {
                conditionPass = expression1 == expression2;
            } else if (comparator == "aspon") {
                conditionPass = expression1 >= expression2;
            } else if (comparator == "nejvic") {
                conditionPass = expression1 <= expression2;
            }
        }
    }

    return std::make_pair(validExpression, conditionPass);
}

int main() {
    std::unordered_map<std::string, double> variables;

    int c;
    std::cin >> c;
    std::cin.ignore();

    std::vector<std::vector<std::string>> linesSplit;
    std::vector<int> linesNestLevels;

    for (int i = 0; i < c; i++) {
        std::string line;
        std::getline(std::cin, line);

        line = line.substr(0, line.find("//"));
        int j = line.length() - 1;
        while (j >= 0 && std::isspace(line[j])) {
            line.pop_back();
            j--;
        }

        if (line.empty()) {
            continue;
        }

        int nestLevel = 0;
        while (line.length() > 2 && line.substr(0, 2) == "  ") {
            line = line.substr(2);
            nestLevel++;
        }

        linesSplit.push_back(split(line, ' '));
        linesNestLevels.push_back(nestLevel);
    }

    std::vector<double> output;

    bool repeating = false;
    int repeatStartLineIndex = 0;
    int nestLevelCurrent = 0;

    for (size_t i = 0; i < linesSplit.size(); i++) {
        auto lineSplit = linesSplit[i];
        int nestLevel = linesNestLevels[i];

        if (nestLevel > nestLevelCurrent) {
            continue;
        }

        bool atLastLine = i >= linesSplit.size() - 1;

        if (repeating && (nestLevel < linesNestLevels[repeatStartLineIndex] + 1 || atLastLine)) {
            repeating = false;
            i = repeatStartLineIndex - 1;
            if (!atLastLine) {
                continue;
            }
        } else if (nestLevel < nestLevelCurrent) {
            nestLevelCurrent = nestLevel;
        }

        if (lineSplit[0] == "kdyz") {
            if (lineSplit.size() < 5 || lineSplit.back() != "tak") {
                std::cout << "error" << std::endl;
                return 0;
            }

            auto conditionResult = conditionPass(std::vector<std::string>(lineSplit.begin() + 1, lineSplit.end() - 1), variables);

            if (!conditionResult.first) {
                std::cout << "error" << std::endl;
                return 0;
            }

            if (conditionResult.second) {
                nestLevelCurrent++;
            }
        } else if (lineSplit[0] == "dokud") {
            if (lineSplit.size() < 5 || lineSplit.
                    back() != "tak") {
                std::cout << "error" << std::endl;
                return 0;
            }

            auto conditionResult = conditionPass(std::vector<std::string>(lineSplit.begin() + 1, lineSplit.end() - 1), variables);

            if (!conditionResult.first) {
                std::cout << "error" << std::endl;
                return 0;
            }

            if (conditionResult.second) {
                nestLevelCurrent++;
                repeating = true;
                repeatStartLineIndex = i;
            }
        } else if (lineSplit[0] == "vypsat") {
            double expressionResult = expressionValue(std::vector<std::string>(lineSplit.begin() + 1, lineSplit.end()), variables);

            if (std::isnan(expressionResult)) {
                std::cout << "error" << std::endl;
                return 0;
            }

            output.push_back(expressionResult);
        } else {
            std::string variableName = lineSplit[0];

            if (!(std::isalpha(variableName[0]) && std::islower(variableName[0])) || lineSplit.size() < 2 || lineSplit[1] != "je") {
                std::cout << "error" << std::endl;
                return 0;
            }

            if (variableName == "je" || variableName == "a" || variableName == "bez" || variableName == "kdyz" ||
                variableName == "tak" || variableName == "rovno" || variableName == "aspon" || variableName == "nejvic" ||
                variableName == "nebo" || variableName == "dokud" || variableName == "vypsat") {
                std::cout << "error" << std::endl;
                return 0;
            }

            double expressionResult = expressionValue(std::vector<std::string>(lineSplit.begin() + 2, lineSplit.end()), variables);

            if (std::isnan(expressionResult)) {
                std::cout << "error" << std::endl;
                return 0;
            }

            variables[variableName] = expressionResult;
        }
    }

    for (double line : output) {
        std::string output = std::to_string(line);
        output.erase(output.find_last_not_of('0') + 1, std::string::npos);
        output.erase(output.find_last_not_of('.') + 1, std::string::npos);

        std::cout << output << std::endl;
    }

    return 0;
}
