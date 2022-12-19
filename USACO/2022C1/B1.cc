#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    
    map<int, int> cows;
    for (int i = 0; i < N; i++) {
        int toAdd;
        cin >> toAdd;

        if (cows.find(toAdd) == cows.end()) {
            cows[toAdd] = 0;
        }

        cows[toAdd]++;
    }

    long long maxRevenue = 0;
    int maxTuition = 0;
    int cowsLeft = N;
    while (cowsLeft > 0) {
        pair<int, int> cowp = (*cows.begin());
        int key = cowp.first;
        int val = cowp.second;

        long long revenue = (long long) key * (long long) cowsLeft;

        if (revenue > maxRevenue) {
            maxRevenue = revenue;
            maxTuition = key;
        }

        cows.erase(key);
        cowsLeft -= val;
    }

    cout << maxRevenue << " " << maxTuition << endl;
}