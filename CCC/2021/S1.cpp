#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    int h[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        cin >> h[i];
    }

    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (double)(w[i] * (h[i] + h[i + 1])) / 2;
    }

    cout << sum;
}