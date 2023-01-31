#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);

    long long N, M, K;

    cin >> N >> M >> K;

    vector<long long> sample;

    for (int i = 0; i < N; i++) {
        int remainLen = N - i - 1;

        long long curSamples = min(K - remainLen, M);

        if (curSamples <= 0) {
            break;
        }

        long long toAdd;
        if (curSamples > i) {
            toAdd = min(M, (long long) i + 1);
            curSamples = toAdd;
        } else {
            toAdd = sample[i - curSamples];
        }

        sample.push_back(toAdd);
        K -= curSamples;
    }

    if (K == 0 && sample.size() == N) {
        for (auto i : sample) {
            cout << i << " ";
        }

        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}