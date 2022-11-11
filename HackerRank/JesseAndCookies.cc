#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> cookies;
    for (int i = 0; i < n; i++)
    {
        int toAdd;
        cin >> toAdd;
        cookies.push(toAdd);
    }

    int max = 0;
    while (cookies.top() < k && cookies.size() >= 2)
    {
        int c1 = cookies.top();
        cookies.pop();
        int c2 = cookies.top();
        cookies.pop();
        cookies.push(c1 + (2 * c2));
        max++;
    }

    if (cookies.size() < 2 && !(!cookies.empty() && cookies.top() >= k)) {
        max = -1;
    }
    cout << max << endl;
}