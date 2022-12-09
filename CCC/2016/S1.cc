#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    unordered_map<char, int> firstmap, secondmap;

    string first, second;

    cin >> first >> second;

    int wildcards = 0;
    for (int i = 0; i < first.size(); i++)
    {
        firstmap[first[i]]++;
        if (second[i] == '*')
        {
            wildcards++;
        }
        else
        {
            secondmap[second[i]]++;
        }
    }

    for (auto i : firstmap)
    {
        int fc = i.second;
        int sc = secondmap[i.first];

        if (fc == sc)
        {
            continue;
        }
        else if (fc > sc && wildcards >= (fc - sc))
        {
            wildcards -= (fc - sc);
        } else {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "A" << endl;
}