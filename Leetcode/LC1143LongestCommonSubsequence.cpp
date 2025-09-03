#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*

aceg
abcdefg

initial dp grid

  a c e g
a 0 0 0 0
b 0 0 0 0
c 0 0 0 0
d 0 0 0 0
e 0 0 0 0
f 0 0 0 0
g 0 0 0 0

start from point 1
ok so we can probably just loop a through aceg and check if it is the same, and
then +1 to the previous subseq at that position?

  a c e g
a 1 1 1 1
b 1 1 1 1
c 1 2 2 2
d 0 0 0 0
e 0 0 0 0
f 0 0 0 0
g 0 0 0 0

 */

class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text2.length(), vector<int>(text1.length(), 0));

        for (int i2 = 0; i2 < text2.length(); i2++) {
            for (int i1 = 0; i1 < text1.length(); i1++) {
                if (text1[i1] == text2[i2]) {
                    int past = 0;
                    if (i1 > 0 && i2 > 0) {
                        past = dp[i2 - 1][i1 - 1];
                    }

                    dp[i2][i1] = past + 1;
                } else if (i1 > 0) {
                    dp[i2][i1] = max(dp[i2][i1], dp[i2 - 1][i1]);
                } else if (i2 > 0) {
                    dp[i2][i1] = max(dp[i2][i1], dp[i2][i1 - 1]);
                }
            }
        }

        return dp[text1.length() - 1][text2.length() - 1];
    }
};