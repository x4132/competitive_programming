#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int right;
    int left = 0;
    cin >> right;

    if (right / 5 == 1) {
        left = right % 5;
        right = 5;
    }

    int out = 0;
    while (right > 0 && right >= left) {
        out++;
        left++;
        right--;
    }

    cout << out << endl;
}