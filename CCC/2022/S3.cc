#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;

    if (K < N) {
        cout << "-1" << "\n";
        return 0;
    }

    vector<int> notes(N, 1);
    long long currentSamples = N;

    int index = 0;
    while (currentSamples < K - 1) {
        vals[index * 2 + 1] = 2;
    }
}