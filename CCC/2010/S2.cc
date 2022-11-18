#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int k;
    cin >> k;
    
    unordered_map<string, string> charmap;
    for (int i = 0; i < k; i++) {
        char addChar;
        string binCode;

        cin >> addChar >> binCode;
        charmap[binCode] = addChar;
    }

    string encoded;
    string output = "";
    cin >> encoded;

    int from = 0;
    for (int i = 1; i <= encoded.size(); i++) {
        string toMatch = encoded.substr(from, i - from);

        if (charmap.find(toMatch) != charmap.end()) {
            output += charmap.at(toMatch);
            from = i;
        }
    }

    cout << output << endl;
}