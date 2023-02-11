#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> freq(k + 1, 0);
    vector<int> sequence(n);

    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        freq[id]++;

        sequence[i] = id;
    }

    vector<int> output;
    unordered_set<int> curContents;

    for (int i = 0; i < n; i++) {
        int cur = sequence[i];
        freq[cur]--;

        if (curContents.find(cur) == curContents.end()) {
            while (!output.empty() && output.back() > cur && freq[output.back()] > 0) {
                curContents.erase(output.back());
                output.pop_back();
            }

            curContents.insert(cur);
            output.push_back(cur);
        }
    }

    for (int i = 0; i < k - 1; i++) {
        cout << output[i] << " ";
    }

    cout << output[k - 1] << endl;
}