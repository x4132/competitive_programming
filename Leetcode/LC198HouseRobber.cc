#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = nums;

        for (int i = 0; i < nums.size(); i++) {
            for (int x = 0; x < i - 1; x++) {
                if (dp[x] + nums[i] > dp[i]) {
                    dp[i] = dp[x] + nums[i];
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};