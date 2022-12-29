#include <bits/stdc++.h>

using namespace std;

bool isCompleted(vector<vector<int>> square) {
    for (int y = 0; y < 3; y++) {
        if (square[y][0] == 1000001 || square[y][1] == 1000001 ||
            square[y][2] == 1000001) {
            return false;
        }
    }

    return true;
}

bool isValid(vector<vector<int>> square, int x, int y) {
    if (square[y][x] == 1000001) {
        return false;
    }

    int noXs = 0;
    for (int xi = 0; xi < 3; xi++) {
        if (square[y][xi] == 1000001) {
            noXs++;
        }
    }
    if (noXs == 0 &&
        (square[y][1] - square[y][0]) != (square[y][2] - square[y][1])) {
        return false;
    } else if (noXs == 1 && square[y][1] == 1000001 && std::abs(square[y][0] + square[y][2]) % 2 == 1) {
        return false;
    } else if (noXs == 3) {
        return false;
    }

    noXs = 0;
    for (int yi = 0; yi < 3; yi++) {
        if (square[yi][x] == 1000001) {
            noXs++;
        }
    }
    if (noXs == 0 &&
        (square[1][x] - square[0][x]) != (square[2][x] - square[1][x])) {
        return false;
    } else if (noXs == 1 && square[1][x] == 1000001 && std::abs(square[0][x] + square[2][x]) % 2 == 1) {
        return false;
    } else if (noXs == 3) {
        return false;
    }

    return true;
}

int main(void) {
    vector<vector<int>> square(3, vector<int>(3, -1));

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            string toAdd;
            cin >> toAdd;

            if (toAdd == "X") {
                square[y][x] = 1000001;
            } else {
                square[y][x] = stoi(toAdd);
            }
        }
    }

    while (!isCompleted(square)) {
        bool no1Xs = true;

        for (int y = 0; y < 3; y++) {
            int noXs = 0;
            for (int x = 0; x < 3; x++) {
                if (square[y][x] == 1000001) {
                    noXs++;
                }
            }

            if (noXs == 1) {
                no1Xs = false;
            }

            if (noXs != 1) {
                continue;
            } else if (square[y][0] == 1000001) {
                square[y][0] = square[y][1] - (square[y][2] - square[y][1]);
            } else if (square[y][1] == 1000001) {
                square[y][1] = square[y][0] + (square[y][2] - square[y][0]) / 2;
            } else {
                square[y][2] = square[y][1] + (square[y][1] - square[y][0]);
            }
        }

        for (int x = 0; x < 3; x++) {
            int noXs = 0;

            for (int y = 0; y < 3; y++) {
                if (square[y][x] == 1000001) {
                    noXs++;
                }
            }

            if (noXs == 1) {
                no1Xs = false;
            }

            if (noXs != 1) {
                continue;
            } else if (square[0][x] == 1000001) {
                square[0][x] = square[1][x] - (square[2][x] - square[1][x]);
            } else if (square[1][x] == 1000001) {
                square[1][x] = square[0][x] + (square[2][x] - square[0][x]) / 2;
            } else {
                square[2][x] = square[1][x] + (square[1][x] - square[0][x]);
            }
        }

        if (!no1Xs) {
            continue;
        }

        bool no2Xs = true;
        for (int y = 0; y < 3; y++) {
            int noXs = 0;
            for (int x = 0; x < 3; x++) {
                if (square[y][x] == 1000001) {
                    noXs++;
                }
            }

            if (noXs != 2) {
                continue;
            } else if (square[y][0] == 1000001 && square[y][1] == 1000001) {
                int d = 0;
                while (!isValid(square, 0, y) || !isValid(square, 1, y)) {
                    square[y][0] = square[y][2] - 2 * d;
                    square[y][1] = square[y][2] - d;
                    d++;
                }

            } else if (square[y][0] == 1000001 && square[y][2] == 1000001) {
                int d = 0;
                while (!isValid(square, 0, y) || !isValid(square, 2, y)) {
                    square[y][0] = square[y][1] - d;
                    square[y][2] = square[y][1] + d;
                    d++;
                }
            } else {
                int d = 0;
                while (!isValid(square, 1, y) || !isValid(square, 2, y)) {
                    square[y][1] = square[y][0] + d;
                    square[y][2] = square[y][0] + 2 * d;
                    d++;
                }
            }

            if (noXs == 2) {
                no2Xs = false;
                break;
            }
        }

        if (!no2Xs) {
            continue;
        }

        for (int x = 0; x < 3; x++) {
            int noXs = 0;
            for (int y = 0; y < 3; y++) {
                if (square[y][x] == 1000001) {
                    noXs++;
                }
            }

            if (noXs != 2) {
                continue;
            } else if (square[0][x] == 1000001 && square[1][x] == 1000001) {
                int d = 0;
                while (!isValid(square, x, 0) || !isValid(square, x, 1)) {
                    square[0][x] = square[2][x] - 2 * d;
                    square[1][x] = square[2][x] - d;
                    d++;
                }
            } else if (square[0][x] == 1000001 && square[2][x] == 1000001) {
                int d = 0;
                while (!isValid(square, x, 0) || !isValid(square, x, 2)) {
                    square[0][x] = square[1][x] - d;
                    square[2][x] = square[1][x] + d;
                    d++;
                }
            } else {
                int d = 0;
                while (!isValid(square, x, 1) || !isValid(square, x, 2)) {
                    square[1][x] = square[0][x] + d;
                    square[2][x] = square[0][x] + 2 * d;
                    d++;
                }
            }

            if (noXs == 2) {
                no2Xs = false;
                break;
            }
        }

        if (!no2Xs) {
            continue;
        }

        square[1][1] = 1;
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << square[y][x] << " ";
        }
        cout << endl;
    }
}