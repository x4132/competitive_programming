#include <bits/stdc++.h>

using namespace std;

bool compare(unordered_map<char, int> a, unordered_map<char, int> b) {
    for (auto i : a) {
        if (b[i.first] != i.second) {
            return false;
        }
    }

    for (auto i : b) {
        if (a[i.first] != i.second) {
            return false;
        }
    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string in;
    int q;

    cin >> in >> q;

    for (int queryCount = 0; queryCount < q; queryCount++) {
        string searchStr;
        int occurence;
        cin >> searchStr >> occurence;

        unordered_map<char, int> needleMap;
        unordered_map<char, int> haystackMap;

        for (int i = 0; i < searchStr.size(); i++) {
            needleMap[searchStr[i]]++;
        }

        int curOccurence = 0;
        int output = -1;
        for (int i = 0; i < in.size(); i++) {
            if (i >= searchStr.size()) {
                haystackMap[in[i-searchStr.size()]]--;
            }

            haystackMap[in[i]]++;

            if (compare(needleMap, haystackMap) && searchStr == in.substr(i - searchStr.size() + 1, searchStr.size())) {
                curOccurence++;

                if (curOccurence == occurence) {
                    output = i - searchStr.size() + 2; // 1-indexed
                    break;
                }
            }
        }

        cout << output << "\n";
    }
}