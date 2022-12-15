#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> villages(N);

    for (int i = 0; i < N; i++) {
        cin >> villages[i];
    }

    sort(villages.begin(), villages.end());

    double minSize = DBL_MAX;

    for (int i = 1; i < N - 1; i++) {
        double villageSize = (double) (villages[i] - villages[i - 1]) / 2 + (double) (villages[i + 1] - villages[i]) / 2;
        minSize = min(minSize, villageSize);
    }

    cout << std::fixed << std::setprecision(1) << minSize << endl;
}