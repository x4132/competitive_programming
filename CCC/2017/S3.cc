#include <bits/stdc++.h>

using namespace std;

int main(void) {
    unordered_map<int, int> planks;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int toAdd;
        cin >> toAdd;
        if (planks.find(toAdd) != planks.end()) {
            planks[toAdd] = 0;
        }

        planks[toAdd]++;
    }

        int maxDist = 0;
    int distCount = 0;

    for (int h = 2; h < 4000; h++) {
        int dist = 0;
        unordered_map<int, int> planksCopy = planks;
        for (auto i = planksCopy.begin(); i != planksCopy.end();) {
            int complement = h - (*i).first;

            /*
                Cases:
                complement == (*i).first

                divide by 2, remove

                complement doesn't exist
                remove

                complement does exist

                
            */

            if (complement == (*i).first) {
                dist += planksCopy[complement] / 2;
                i = planksCopy.erase(i);
                continue;
            }

            if (planksCopy.find(complement) == planksCopy.end()) {

                i = planksCopy.erase(i);
                continue;
            }

            int total = planksCopy[complement] - (*i).second;

            if (total >= 0) {
                dist += (*i).second;
            } else {
                dist += (*i).second - planksCopy[complement];
            }

            i = planksCopy.erase(i);
        }

        if (dist == maxDist) {
            distCount++;
        } else if (dist > maxDist) {
            maxDist = dist;
            distCount = 1;
        }
    }

    cout << maxDist << " " << distCount << endl;
}