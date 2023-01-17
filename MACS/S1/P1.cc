#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, A, S;
    cin >> H >> A >> S;

    cout << max(min(H, A) - S,0) << "\n";
}