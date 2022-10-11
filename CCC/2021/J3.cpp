#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;

    string cur;
    cin >> cur;
    bool prev = false;
    while (cur != "99999") {
        int dig1 = (int) cur[0] - '0';
        int dig2 = (int) cur[1] - '0';

        if (dig1 + dig2 == 0 && prev) {
            cout << "left ";
        } else if ((dig1 + dig2) % 2 == 0) {
            cout << "right ";
            prev = false;
        } else {
            cout << "left ";
            prev = true;
        }

        cout << cur.substr(2, 4) << "\n";
        cin >> cur;
    }
}