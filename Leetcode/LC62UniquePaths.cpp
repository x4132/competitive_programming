#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(n, vector<int>(m, 0));
        paths[0][0] = 1;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (x > 0) {
                    paths[y][x] += paths[y][x - 1];
                }

                if (y > 0) {
                    paths[y][x] += paths[y - 1][x];
                }
            }
        }

        return paths[n - 1][m - 1];
    }
};