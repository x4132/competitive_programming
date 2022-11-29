#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int W, N;
    cin >> W >> N;

    vector<int> cars(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> cars[i + 1];
    }

    int sum = 0;

    if (cars[1] > W) {
        cout << 0;
        return 0;
    }
    sum += cars[1];
    for (int i = 2; i < N; i++) {
        sum += cars[i];

        if (i > 4) {
            sum -= cars[i - 4];
        }

        if (sum > W) {
            cout << i - 1;
            return 0;
        }
    }

    cout << N;
}