#include <bits/stdc++.h>

using namespace std;

bool compare(unordered_map<char, int> map1, unordered_map<char, int> map2) {
    for (int i = 0; i < 26; i++) {
        if (map1['a' + i] != map2['a' + i]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(false);

    string needle, haystack;
    cin >> needle >> haystack;

    if (needle.length() > haystack.length()) {
        cout << 0 << endl;
        return 0;
    }

    unordered_map<char, int> needleFreq;
    unordered_map<char, int> haystackFreq;
    unordered_set<string> matches;

    for (int i = 0; i < 26; i++) {
        needleFreq['a' + i] = 0;
        haystackFreq['a' + i] = 0;
    }

    for (char i : needle) {
        needleFreq[i]++;
    }

    
    for (int i = 0; i < needle.size(); i++) {
        haystackFreq[haystack[i]]++;
    }

    if (compare(needleFreq, haystackFreq)) {
        matches.insert(haystack.substr(0, needle.size()));
    }

    for (int i = 0; i < haystack.size() - needle.size(); i++) {
        haystackFreq[haystack[i]]--;
        haystackFreq[haystack[i + needle.size()]]++;

        if (compare(needleFreq, haystackFreq) && matches.find(haystack.substr(i + 1, needle.size())) == matches.end()) {
            matches.insert(haystack.substr(i + 1, needle.size()));
        }
    }

    cout << matches.size() << endl;
}