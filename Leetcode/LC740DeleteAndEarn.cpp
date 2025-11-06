#include <climits>
#include <vector>

using namespace std;

class Solution {
  public:
    int deleteAndEarn(vector<int> &nums) {
        int numMax = INT_MIN;
        for (auto i : nums) {
            numMax = max(numMax, i);
        }
        vector<int> dp(nums.size() + 1, 0);

        for (int i = 1; i < numMax; i++) {

        }
    }
};