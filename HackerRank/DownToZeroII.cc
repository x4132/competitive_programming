#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int q;
    cin >> q;
    vector<int> cache;
    cache.push_back(0);
    for (int i = 1; i <= 1000000; i++) {
        cache.push_back(cache[i - 1] + 1);

        for (int x = 2; x * x <= i; x++) {
            if (i % x == 0) {
                cache[i] = min(cache[i], cache[i / x] + 1);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        cout << cache[n] << endl;
    }
}