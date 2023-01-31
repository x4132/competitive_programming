#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        int maxDP = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int x = 0; x < i; x++) {
                if (nums[i] > nums[x] && dp[i] < dp[x] + 1) {
                    dp[i] = dp[x] + 1;
                    maxDP = max(maxDP, dp[i]);
                }
            }
        }

        return maxDP;
    }
};