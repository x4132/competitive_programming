#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    unordered_map<string, string> characterMap;
    vector<string> initialNames(n);

    for (int i = 0; i < n; i++) {
        cin >> initialNames[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> characterMap[initialNames[i]];
    }

    for (int i = 0; i < n; i++) {
        string key = initialNames[i];
        string part = characterMap[key];

        if (key == part) {
            cout << "bad";

            return 0;
        }

        if (characterMap[part] != key) {
            cout << "bad";

            return 0;
        }
    }

    cout << "good";
}