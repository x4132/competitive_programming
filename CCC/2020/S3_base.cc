#include <bits/stdc++.h>

using namespace std;

hash<string> hasher;

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
    unordered_set<size_t> matches;

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
        matches.insert(hasher(haystack.substr(0, needle.length())));
    }

    for (int i = 0; i < haystack.size() - needle.size() + 2; i++) {
        haystackFreq[haystack[i]]--;
        haystackFreq[haystack[i + needle.size()]]++;

        if (compare(needleFreq, haystackFreq)) {
            size_t toCheck = hasher(haystack.substr(i + 1, needle.size()));
            if (matches.find(toCheck) == matches.end()) {
                matches.insert(toCheck);
            }
        }
    }

    cout << matches.size() << endl;
}