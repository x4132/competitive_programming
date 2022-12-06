#include <bits/stdc++.h>

using namespace std;

void solve();

int main(void) {
    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
}

void solve() {
    int N;
    cin >> N;

    stack<int> branch;
    stack<int> mountain;
    int prevLargest = 0;

    for (int i = 0; i < N; i++) {
        int toAdd;
        cin >> toAdd;
        mountain.push(toAdd);
    }

    while (!branch.empty() || !mountain.empty()) {
        int toGet = prevLargest + 1;

        if (!branch.empty() && branch.top() == toGet) {
            branch.pop();
            prevLargest = toGet;
        } else if (mountain.empty()) {
            cout << "N" << endl;
            return;
        } else if (mountain.top() == toGet) {
            mountain.pop();
            prevLargest = toGet;
        } else {
            branch.push(mountain.top());
            mountain.pop();
        }
    }

    cout << "Y" << endl;
}