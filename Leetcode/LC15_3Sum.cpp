#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (nums[0] > 0) {
            return {};
        }

        unordered_map<int, int> numMap;
        vector<vector<int>> output;

        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                break;
            }

            for (int j = i + 1; j < nums.size() - 1; j++) {
                int required = (nums[i] + nums[j]) * -1;

                if (numMap.find(required) != numMap.end() && numMap.find(required)->second > j) {
                    output.push_back({nums[i], nums[j], required});
                }

                j = numMap.find(nums[j])->second;
            }

            i = numMap.find(nums[i])->second;
        }

        return output;
    }
};
