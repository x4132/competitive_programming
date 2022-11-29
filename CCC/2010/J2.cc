#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;

    int Nsum = a + b;
    int Ndist = a - b;
    int Bsum = c + d;
    int Bdist = c - d;

    int NSteps = (s / Nsum) * Ndist;
    if (s % Nsum > a) {
        NSteps += a;
        NSteps -= (s % Nsum) - a;
    } else {
        NSteps += s % Nsum;
    }

    int BSteps = (s / Bsum) * Bdist;
    if (s % Bsum > c) {
        BSteps += c;
        BSteps -= (s % Bsum) - c;
    } else {
        BSteps += s % Bsum;
    }

    if (BSteps == NSteps) {
        cout << "Tied" << endl;
    } else if (BSteps > NSteps) {
        cout << "Byron" << endl;
    } else {
        cout << "Nikky" << endl;
    }
}