public class LC63UniquePathsII {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                grid[i][0] = 1;
            } else {
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 0) {
                grid[0][i] = 1;
            } else {
                break;
            }
        }

        for (int y = 1; y < m; y++) {
            for (int x = 1; x < n; x++) {
                if (obstacleGrid[y][x] == 0) {
                    grid[y][x] = grid[y][x - 1] + grid[y - 1][x];
                }
            }
        }

        return grid[m - 1][n - 1];
    }

    public static void main(String[] args) {
        LC63UniquePathsII lc63UniquePathsII = new LC63UniquePathsII();
        lc63UniquePathsII.uniquePathsWithObstacles(new int[][] {{0, 0}, {1, 1}, {0, 0}});
    }
}
