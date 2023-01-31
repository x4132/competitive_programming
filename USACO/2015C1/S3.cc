#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> prefixes;

int prefixQuery(int start, int end, int type) {
    return (prefixes[end][type] - prefixes[start - 1][type]);
}

int main(void) {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    prefixes.resize(n + 1);    
    prefixes[0] = {0, 0, 0};


    int prefixH = 0, prefixG = 0, prefixJ = 0;
    for (int i = 1; i <= n; i++) {
        int type;
        cin >> type;

        prefixes[i] = prefixes[i - 1];
        prefixes[i][type - 1]++;
    }

    for (int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;

        cout << prefixQuery(start, end, 0) << " " << prefixQuery(start, end, 1) << " " << prefixQuery(start, end, 2) << "\n";
    }
}