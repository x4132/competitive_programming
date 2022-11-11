#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> sorted;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int toAdd;
        cin >> toAdd;
        sorted.insert(lower_bound(sorted.begin(), sorted.end(), toAdd), toAdd);
        cout << std::fixed << setprecision(1);
        if (sorted.size() % 2 == 0) {
            cout << ((float) sorted[sorted.size() / 2] + (float) sorted[(sorted.size() / 2) - 1]) / 2.0 << endl;
        } else {
            cout << static_cast<float>(sorted[(sorted.size() / 2)]) << endl;
        }
    }
}