#include <bits/stdc++.h>

using namespace std;

int dist(int s, int H, vector<int> houses);

int main(void)
{
    int H;
    cin >> H;
    vector<int> houses(H);
    for (int i = 0; i < H; i++)
    {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int k;
    cin >> k;

    int low = -1;
    int high = 1000001;

    if (k >= H) {
        cout << 0 << endl;
        return 0;
    }

    while (low < high - 1)
    {
        int mid = (low + high) / 2;

        if (dist(mid, H, houses) > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << high << endl;
}

int dist(int s, int H, vector<int> houses) // 4, [0, 67000, 68000, 77000]
{
    int size = s * 2;
    int ans = H;
    int i = 0;

    while (i < H && houses[i] <= houses[0] + size)
    {
        int cur = 1;
        int end = houses[i];
        int j = i + 1;
        while (j < H && houses[j] < houses[i] - size + 1000000)
        {
            if (houses[j] > end)
            {
                end = houses[j] + size;
                cur += 1;
            }

            j++;
        }
        
        i++;
        ans = min(cur, ans);
    }

    return ans;
}