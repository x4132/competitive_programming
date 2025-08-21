#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> costToReach(cost.size(), INT_MAX);
        costToReach[0] = 0;
        costToReach[1] = 0;

        for (int i = 2; i < cost.size(); i++) {
            costToReach[i] =
                min(costToReach[i], costToReach[i - 1] + cost[i - 1]);
            costToReach[i] =
                min(costToReach[i], costToReach[i - 2] + cost[i - 2]);
        }

        return min(costToReach[cost.size() - 1] + cost[cost.size() - 1],
                   costToReach[cost.size() - 2] + cost[cost.size() - 2]);
    }
};