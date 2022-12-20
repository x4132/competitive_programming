#include <bits/stdc++.h>

using namespace std;

bool isCompleted() {
    
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

    
}