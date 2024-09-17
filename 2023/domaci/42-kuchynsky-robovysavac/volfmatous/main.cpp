#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

const int LEFT = 0;
const int RIGHT = 1;
const int FORWARD = 2;
const int BACK = 3;

bool tryProgram(const vector<vector<char>> &floor, int cleanerY, int cleanerX, int stationY, int stationX,
                const unordered_map<char, int> &program) {
    vector<bool> floorVisited(floor.size() * floor[0].size(), false);

    while (true) {
        char tile = floor[cleanerY][cleanerX];
        switch (program.at(tile)) {
            case LEFT:
                cleanerX--;
                break;
            case RIGHT:
                cleanerX++;
                break;
            case FORWARD:
                cleanerY--;
                break;
            case BACK:
                cleanerY++;
                break;
        }

        if (cleanerY < 0 || cleanerY >= floor.size() || cleanerX < 0 || cleanerX >= floor[0].size()
            || floorVisited[cleanerY * floor[0].size() + cleanerX]) {
            return false;
        }

        if (cleanerY == stationY && cleanerX == stationX) {
            return true;
        }

        floorVisited[cleanerY * floor[0].size() + cleanerX] = true;
    }
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> floor(h, vector<char>(w));

    vector<char> tileColors;
    unordered_map<char, int> program;
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            char tile;
            cin >> tile;
            floor[row][col] = tile;

            if (program.find(tile) == program.end()) {
                program[tile] = LEFT;
                tileColors.push_back(tile);
            }
        }
    }

    int cleanerY, cleanerX;
    cin >> cleanerY >> cleanerX;
    cleanerY--;
    cleanerX--;

    int stationY, stationX;
    cin >> stationY >> stationX;
    stationY--;
    stationX--;

    int totalPossiblePrograms = 0;

    while (true) {
        if (tryProgram(floor, cleanerY, cleanerX, stationY, stationX, program)) {
            totalPossiblePrograms++;
        }

        bool end = false;
        for (int i = 0; i < tileColors.size(); i++) {
            program[tileColors[i]]++;
            if (program[tileColors[i]] > 3) {
                if (i >= tileColors.size() - 1) {
                    end = true;
                }
                program[tileColors[i]] = 0;
            } else {
                break;
            }
        }

        if (end) {
            break;
        }
    }

    cout << totalPossiblePrograms << endl;

    return 0;
}
