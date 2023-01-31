#include <bits/stdc++.h>

using namespace std;

/*
    cases:
    - we can put the pie from bag in and take value from n-1
    - we can put pie from bag in and replace n
    - we can just not do anything
*/

vector<int> pies;
vector<int> canAdd;
vector<int> prevPies;
int n, m;

int solve(int pos, int addedPies, int p1, int p2, int curMax) {
    int maxVal = pies[pos];
    for (int i = 0; i < pos + addedPies - 1; i++) {
        maxVal = max(maxVal, prevPies[i]);
    }

    if (prevPies[pos + addedPies] > maxVal) {
        p1++;
        
    }
}

int main(void) {
    cin >> n;

    pies.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pies[i];
    }

    cin >> m;

    canAdd.resize(n);

    for (int i = 0; i < m; i++) {
        int toAdd;
        cin >> toAdd;
        canAdd.insert(lower_bound(canAdd.begin(), canAdd.end(), toAdd), toAdd);
    }

    prevPies.resize(m + n);
    fill(prevPies.begin(), prevPies.end(), 0);
    prevPies[0] = n[0];

    int result = solve(0, 0, 0, m - 1, prevPies[0]);

    cout << result << endl;
}