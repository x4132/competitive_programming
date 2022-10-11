#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    string input;
    cin >> input;

    int lEnd = input.size();
    int mEnd = input.size();
    int switches = 0;
    for (int i = 0; i < input.size(); i++) {
        char cur = input[i];
        if (cur == 'L' && i > lEnd) {
            switches++;
        }

        if (cur == 'M' && i > mEnd) {
            switches++;
        }

        if (cur == 'M') {
            lEnd = i;
        }
        if (cur == 'S') {
            lEnd = i;
            mEnd = i;
        }
    }

    cout << switches;
}