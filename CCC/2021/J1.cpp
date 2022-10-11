#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    int b;
    cin >> b;
    int p = 5 * b - 400;
    int o;
    if (p == 100) {
        o = 0;
    } else if (p < 100) {
        o = 1;
    } else {
        o = -1;
    }
    cout << p << "\n" << o;
}