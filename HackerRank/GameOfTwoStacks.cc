#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int g;
    cin >> g;
    for (int games = 0; games < g; games++)
    {
        int n, m, maxSum;
        cin >> n >> m >> maxSum;
        vector<int> a, b;
        int sum = 0, result = 0;

        int toAdd;
        for (int i = 0; i < n; i++)
        {
            cin >> toAdd;
            if (sum + toAdd > maxSum)
            {
                break;
            }
            sum += toAdd;
            a.push_back(toAdd);
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        result = a.size();

        for (int i = 0; i < m; i++)
        {
            cin >> toAdd;
            sum += toAdd;
            b.push_back(toAdd);

            while (sum > maxSum && a.size() > 0) {
                sum -= a.back();
                a.pop_back();
            }

            if (sum > maxSum) break;

            result = max(result, (int) a.size() + (int) b.size());
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << result << endl;
    }
}