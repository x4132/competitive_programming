#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int J, A;
    cin >> J >> A;

    vector<int> jerseys(J);
    unordered_map<string, int> jm = {{"S", 0}, {"M", 1}, {"L", 2}};

    for (int i = 0; i < J; i++) {
        string jersey;
        cin >> jersey;

        jerseys[i] = jm[jersey];
    }

    int fufilled = 0;
    for (int i = 0; i < A; i++) {
        string jersey;
        int athlete;
        cin >> jersey >> athlete;
        athlete--;

        if (jerseys[athlete] >= jm[jersey]) {
            jerseys[athlete] = -1;
            fufilled++;
        }
    }

    cout << fufilled;
}