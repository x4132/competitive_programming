#include <string>
#include <vector>
using namespace std;

// l e e t c o d e
// 0 1 2 3 4 5 6 7
// leet.length = 4
// so i = 4,

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 0; i <= s.length(); i++) {
            if (dp[i]) {
                for (auto word : wordDict) {
                    if (i + word.length() < s.length() + 1 &&
                        word == s.substr(i, word.length())) {
                        dp[i + word.length()] = true;
                    }
                }
            }
        }

        return dp[s.length()];
    }
};