#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    unordered_map<int, int> acidities;
    for (int i = 0; i < n; i++)
    {
        int ac;
        cin >> ac;

        if (!acidities.contains(ac))
        {
            acidities[ac] = 0;
        }

        acidities[ac]++;
    }

    auto comparator = [](pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    };

    vector<pair<int, int>> sorted(acidities.begin(), acidities.end());

    sort(sorted.begin(), sorted.end(), comparator);

    if (sorted[0].second == sorted[1].second)
    {
        int min = 1001;
        int max = 0;

        for (int i = 0; i < sorted.size(); i++)
        {
            if (sorted[i].second != sorted[0].second)
            {
                break;
            }

            if (sorted[i].first > max)
            {
                max = sorted[i].first;
            }
            if (sorted[i].first < min)
            {
                min = sorted[i].first;
            }
        }

        cout << std::abs(max - min);
    }
    else if (sorted[1].second == sorted[2].second)
    {
        int maxDiff = 0;

        for (int i = 1; i < sorted.size(); i++) {
            if (sorted[i].second != sorted[1].second)
            {
                break;
            }

            maxDiff = std::max(maxDiff, std::abs(sorted[0].first - sorted[i].first));
        }

        cout << maxDiff;
    }
    else
    {
        cout << std::abs(sorted[0].first - sorted[1].first);
    }
}