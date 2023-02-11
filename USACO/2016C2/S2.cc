#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;

    int firstModPos[7] = {n + 1, n + 1, n + 1, n + 1, n + 1, n + 1, n + 1};
    int lastModPos[7] = {0, 0, 0, 0, 0, 0, 0};

    ll curPrefix = 0;

    for (int i = 0; i < n; i++) {
        ll toAdd;
        cin >> toAdd;

        curPrefix += toAdd;
        curPrefix %= 7;

        firstModPos[curPrefix] = min(firstModPos[curPrefix], i);
        lastModPos[curPrefix] = i;
    }

    int maxSize = 0;
    for (int i = 0; i < 7; i++) {
        maxSize = max(maxSize, lastModPos[i] - firstModPos[i]);
    }

    cout << maxSize << endl;
}