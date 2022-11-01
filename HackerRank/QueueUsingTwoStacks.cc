#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int q;
    cin >> q;
    queue<int> output;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int toAdd;
            cin >> toAdd;
            output.push(toAdd);
        } else if (op == 2) {
            output.pop();
        } else {
            cout << output.front() << endl;
        }
    }
}