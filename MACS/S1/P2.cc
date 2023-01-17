#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string row1, row2;
    cin >> row1 >> row2;

    int total = 0;
    for (int i = 0; i < N && total < 3; i++) {
        if (row1[i] == 'S' && row2[i] == 'S') {
            total++;
        }
    }

    if (total > 2) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}