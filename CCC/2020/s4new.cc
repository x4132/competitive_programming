#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> prefixArr;
int n;

int prefixQuery(int start, int len, int arr) {
    if (len <= 0) {
        return 0;
    }

    int result = 0;
    start %= n; // circle lol
    int startVal = (start == 0 ? 0 : prefixArr[start - 1][arr]);
    int end = start + len - 1;

    if (end >= n) {
        result = prefixArr[n - 1][arr] - startVal;
        result += prefixArr[end % n][arr];
    } else {
        result = prefixArr[end][arr] - startVal;
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string in;
    cin >> in;
    n = in.size();

    prefixArr.resize(n);
    fill(prefixArr.begin(), prefixArr.end(), vector<int>{0, 0, 0});
    prefixArr[0][in[0] - 'A'] = 1;

    for (int i = 1; i < n; i++) {
        prefixArr[i] = prefixArr[i - 1];
        prefixArr[i][in[i] - 'A']++;
    }

    int minMoves = n; // n is obviously larger than minMoves;

    int Acount = prefixArr[n - 1][0], Bcount = prefixArr[n - 1][1], Ccount = prefixArr[n - 1][2];
    for (int i = 0; i < n; i++) {
        int Na = prefixQuery(i, Acount, 1) + prefixQuery(i, Acount, 2);
        int Nb = prefixQuery(i + Acount, Bcount, 0) + prefixQuery(i + Acount, Bcount, 2);

        int Sab = prefixQuery(i, Acount, 1);
        int Sba = prefixQuery(i + Acount, Bcount, 0);

        minMoves = min(minMoves, (Na + Nb) - min(Sab, Sba));
        
        int Nc = prefixQuery(i + Acount, Ccount, 0) + prefixQuery(i + Acount, Ccount, 1);
        int Sca = prefixQuery(i + Acount, Ccount, 0);
        int Sac = prefixQuery(i, Acount, 2);

        minMoves = min(minMoves, (Na + Nc) - min(Sac, Sca));
    }

    cout << minMoves << endl;
}