#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> swifts(N);
    vector<int> semaphores(N);
    for (int i = 0; i < N; i++) {
        cin >> swifts[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> semaphores[i];
    }

    int swsum = 0, sesum = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        swsum += swifts[i];
        sesum += semaphores[i];

        if (swsum == sesum) {
            max = i + 1;
        }
    }

    cout << max << endl;
}