#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    int m, n, k;
    cin >> m >> n >> k;

    vector<bool> ma(m);
    vector<bool> na(n);
    for (int i = 0; i < k; i++) {
        char r;
        int index;
        cin >> r >> index;
        if (r == 'R') {
            ma[index - 1] = !ma[index - 1];
        } else {
            na[index - 1] = !na[index - 1];
        }
    }

    int ml = 0;
    int nl = 0;
    for (int i = 0; i < m; i++) {
        if (ma[i]) {
            ml++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (na[i]) {
            nl++;
        }
    }

    cout << ((n * ml) + (m * nl) - (ml * nl * 2));
}