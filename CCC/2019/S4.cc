#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> scores;

unordered_map<int, unordered_map<int, int>> cache;

int solve(int start, int end) {
    int N = end - start;
    int R = N % K;

    if (cache[start][end]) {
        cout << "cached" << start << " " << end << "\n";
        return cache[start][end];
    }

    if (N <= K) {
        long long totalMax = 0;
        for (int i = start; i < end; i++) {
            totalMax = max(totalMax, (long long)scores[i]);
        }

        cache[start][end] = totalMax;
        return totalMax;
    }

    // between R & K
    long long totalMax = 0;
    if (R == 0) {
        long long firstMax = 0;
        for (int i = start; i < start + K; i++) {
            firstMax = max(firstMax, (long long)scores[i]);
        }

        return firstMax + solve(start + K, end);
    } else {
        for (int i = R; i <= K; i++) {
            long long firstMax = 0;

            if (cache[start][start + i]) {
                firstMax = cache[start][start + i];
            } else {
                for (int x = start; x < start + i; x++) {
                    firstMax = max(firstMax, (long long)scores[x]);
                }
            }

            cache[start][start + i] = firstMax;
            long long sum = solve(start + i, end);

            totalMax = max(totalMax, firstMax + sum);
        }
    }

    cache[start][end] = totalMax;
    return totalMax;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;

    scores = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    cout << solve(0, N) << endl;
}