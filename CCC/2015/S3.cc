#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int G, P;
    cin >> G >> P;

    set<int, std::greater<int>> gates;

    for (int i = 1; i <= G; i++)
    {
        gates.insert(i);
    }

    for (int i = 0; i < P; i++)
    {
        int plane;
        cin >> plane;

        auto lb = gates.lower_bound(plane);

        if (lb == gates.end())
        {
            cout << i << "\n";
            return 0;
        }
        gates.erase(lb);
    }

    cout << P << "\n";
}