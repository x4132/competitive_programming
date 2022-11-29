#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int num;
    cin >> num;
    num++;

    unordered_set<int> digits;

    while (true) {
        int cur = num;
        bool flag = true;
        digits.clear();
        
        do {
            if (!digits.contains(cur % 10)) {
                digits.insert(cur % 10);
            } else {
                flag = false;
                break;
            }

            cur /= 10;
        } while (cur != 0);
        
        if (flag) {
            cout << num;
            break;
        }

        num++;
    }
}