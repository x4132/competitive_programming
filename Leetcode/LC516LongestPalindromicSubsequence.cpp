#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// so the dp here seems to be 2d?
// we can store one dimension as the left pair
// one dimension as the right pos
// and then number is the length of the subseq

class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

        // go through each pair, updating how many pairs are between those pairs (start from farthest-out pairs)
        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i][i] = 1;

            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][s.length() - 1];
    }
};