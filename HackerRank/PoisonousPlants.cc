#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> plants(n);
    vector<int> nextIndex(n);
    for (int i = 0; i < n; i++)
    {
        cin >> plants[i];
        nextIndex[i] = i + 1;
    }

    int days = 0;

    stack<int> killers;
    for (int i = 1; i < n; i++) {
        if (plants[i - 1] < plants[i]) {
            killers.push(i - 1);
        }
    }

    while (!killers.empty()) {
        days++;
        stack<int> newKillers;

        for (int i = 0; i <= killers.size(); i++) {
            int cur = killers.top();
            killers.pop();
            int killed = nextIndex[cur];
            nextIndex[cur] = nextIndex[killed];
            if (!newKillers.empty() && newKillers.top() == killed) {
                newKillers.pop();
            }

            if (nextIndex[cur] < n && plants[cur] < plants[nextIndex[cur]]) {
                newKillers.push(cur);
            }
        }

        killers = newKillers;
    }

    cout << days;
}