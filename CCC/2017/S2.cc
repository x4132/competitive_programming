#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> measurements;

    for (int i = 0; i < N; i++) {
        int toAdd;
        cin >> toAdd;
        auto addPos =
            lower_bound(measurements.begin(), measurements.end(), toAdd);

        measurements.insert(addPos, toAdd);
    }

    // the size of the two measurements
    int high = N / 2;
    int low = N - high;

    bool isLowTide = true;
    for (int i = 0; i < N; i++) {
        if (isLowTide) {
            cout << measurements[low - 1 - i / 2];
        } else {
            cout << measurements[low + i / 2];
        }

        if (i != N - 1) {
            cout << " ";
        }

        isLowTide = !isLowTide;
    }

    cout << endl;
}