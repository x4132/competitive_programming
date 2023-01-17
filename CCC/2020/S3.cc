#include <bits/stdc++.h>

using namespace std;
int m1 = 1000000007;
int m2 = 982451653;
int m3 = 1000000009;
long long p_base = 29791;

long long power(long long x, unsigned int y, int p) {
    long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

size_t hashInitial(string init, int m) {
    size_t H = 0;
    long long p = 1;
    for (int i = init.length() - 1; i >= 0; i--) {
        char c = init[i];
        c -= 'a' - 1;

        H = (H + (c * p)) % m;
        p = (p * p_base) % m;
    }

    return H;
}

size_t roll_hash(long long H, long long hashlen, char prev, char next, int m) {
    prev -= 'a' - 1;
    next -= 'a' - 1;

    long long output = (H - (prev * power(p_base, hashlen - 1, m))) % m;

    if (output < 0) {
        output = m + output;
    }

    output = (((output * p_base) % m) + next) % m;

    return output;
}

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
    unordered_map<size_t, unordered_map<size_t, unordered_set<size_t>>> matches;

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

    size_t roll1 = hashInitial(haystack.substr(0, needle.size()), m1);
    size_t roll2 = hashInitial(haystack.substr(0, needle.size()), m2);
    size_t roll3 = hashInitial(haystack.substr(0, needle.size()), m3);
    if (compare(needleFreq, haystackFreq)) {
        matches[roll1] = {{roll2, {roll3}}};
    }

    for (int i = 0; i < haystack.size() - needle.size() + 2; i++) {
        haystackFreq[haystack[i]]--;
        haystackFreq[haystack[i + needle.size()]]++;

        roll1 = roll_hash(roll1, needle.size(), haystack[i], haystack[i + needle.size()], m1);
        roll2 = roll_hash(roll1, needle.size(), haystack[i], haystack[i + needle.size()], m2);
        roll3 = roll_hash(roll1, needle.size(), haystack[i], haystack[i + needle.size()], m3);

        if (compare(needleFreq, haystackFreq)) {
            if (matches.find(roll1) == matches.end()) {
                matches[roll1] = {{roll2, {roll3}}};
            } else if (matches[roll1].find(roll2) == matches[roll1].end()) {
                cout << "roll1 collision" << "\n";
                
                matches[roll1][roll2] = {roll3};
            } else if (matches[roll1][roll2].find(roll3) == matches[roll1][roll2].end()) {
                cout << "roll1 && roll2 collision" << "\n";
                matches[roll1][roll2].insert(roll3);
            } else {
                cout << "dupe" << "\n" << haystack.substr(i + 1, needle.size()) << "\n";
            }
        }
    }

    cout << matches.size() << endl;
}