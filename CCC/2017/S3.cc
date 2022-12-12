#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    unordered_map<int, int> planks;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int toAdd;
        cin >> toAdd;
        if (planks.find(toAdd) != planks.end())
        {
            planks[toAdd] = 0;
        }

        planks[toAdd]++;
    }

    int maxDist = 0;
    int distCount = 0;

    for (int h = 2; h < 4000; h++)
    {
        int dist = 0;
        unordered_map<int, int> planksCopy = planks;
        for (auto i = planksCopy.begin(); i != planksCopy.end();)
        {
            int fr = (*i).first;
            int complement = h - (*i).first;

            /*
                Cases:
                complement == (*i).first

                divide by 2, remove

                complement doesn't exist
                remove

                complement does exist
                find the difference between the toals
                total = complementCount - i.second
                if total is negative, then there are more i than complements
                so dist += complements
                if total is positive, there are more complements than i
                dist += i
                if total is equal then hhere are the same amount
                dist += i
            */

            if (complement == (*i).first) // Case 1
            {
                dist += (*i).second / 2;
            }
            else if (planksCopy.find(complement) != planksCopy.end()) // Element exists
            {
                int total = planksCopy[complement] - (*i).second;

                if (total > 0) {
                    dist += (*i).second;
                } else if (total < 0) {
                    dist += planksCopy[complement];
                } else {
                    dist += (*i).second;
                }

                planksCopy.erase(planksCopy.find(complement));
            }

            i = planksCopy.erase(planksCopy.find(fr));
        }

        if (dist == maxDist && )
        {
            distCount++;
        }
        else if (dist > maxDist)
        {
            maxDist = dist;
            distCount = 1;
        }
    }

    cout << maxDist << " " << distCount << endl;
}