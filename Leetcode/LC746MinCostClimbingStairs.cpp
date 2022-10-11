#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), 0);
        for (int i = 0; i < cost.size(); i++) {
            if (i<2) memo[i] = cost[i];
            else memo[i] = cost[i] + min(memo[i - 1], memo[i - 2]);
        }

        return min(memo[memo.size() - 1], memo[memo.size() - 2]);
    }
};

int main() {
    Solution s;
    vector<int> v = {10, 15, 20};
    cout << s.minCostClimbingStairs(v);
}