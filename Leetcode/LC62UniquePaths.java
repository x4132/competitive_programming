public class LC62UniquePaths {
    public int uniquePaths(int m, int n) {
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            grid[0][i] = 1;
        }

        for (int y = 1; y < m; y++) {
            for (int x = 1; x < n; x++) {
                grid[y][x] = grid[y][x - 1] + grid[y - 1][x];
            }
        }

        return grid[m - 1][n - 1];
    }
}