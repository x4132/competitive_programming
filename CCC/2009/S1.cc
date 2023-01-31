#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<long long> vals(101);

    for (int i = 0; i < 101; i++) {
        vals[i] = (long long) pow(i, 6);
    }

    int a, b;
    cin >> a >> b;

    int output = abs(lower_bound(vals.begin(), vals.end(), a) - upper_bound(vals.begin(), vals.end(), b));

    cout << output << endl;
}