public class LC64MinimumPathSum {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Integer[][] cache = new Integer[m][n];
        return solve(grid, cache, 0, 0);
    }

    public int solve(int[][] grid, Integer[][] cache, int y, int x) {
        if (y == grid.length - 1 && x == grid[0].length - 1) {
            return grid[y][x];
        }
        if (cache[y][x] != null) {
            return cache[y][x];
        }
        int res1 = 4000001;
        int res2 = 4000001;
        if (y < grid.length - 1) {
            res1 = solve(grid, cache, y + 1, x);
        }
        if (x < grid[0].length - 1) {
            res2 = solve(grid, cache, y, x + 1);
        }

        cache[y][x] = Math.min(res1, res2) + grid[y][x];
        return Math.min(res1, res2) + grid[y][x];
    }

    public static void main(String[] args) {
        LC64MinimumPathSum lc64MinimumPathSum = new LC64MinimumPathSum();
        lc64MinimumPathSum.minPathSum(new int[][] {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
    }
}