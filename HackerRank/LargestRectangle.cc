#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    stack<int> s;
    vector<int> heights;
    long result = 0;

    for (int i = 0; i <= n; i++) {

        int toAdd = 0;
        if (i != n) {
            cin >> toAdd;
            heights.push_back(toAdd);
        }

        while (!s.empty() && toAdd < heights[s.top()]) {
            int top = s.top();
            s.pop();

            int width = s.empty() ? i : i - s.top() - 1;
            long area = heights[top] * width;

            result = max(area, result);
        }

        s.push(i);
    }

    cout << result << endl;
}