#include <vector>
using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxPrev = 0;
        int last = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int cur = maxPrev + nums[i];
            maxPrev = max(maxPrev, last);
            last = cur;
        }

        return max(maxPrev, last);
    }
};