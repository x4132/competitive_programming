#include <vector>
using namespace std;

// trad dp
class Solution {
  public:
    int climbStairs(int n) {
        vector<int> ways(n + 1, 0);
        ways[0] = 1;

        for (int i = 0; i <= n; i++) {
            if (i - 1 >= 0) {
                ways[i] += ways[i - 1];
            }
            if (i - 2 >= 0) {
                ways[i] += ways[i - 2];
            }
        }

        return ways[n];
    }
};