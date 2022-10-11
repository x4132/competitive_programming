public class LC1351CountNegativeNumbersInASortedMatrix {
    public int countNegatives(int[][] grid) {
        int total = 0;
        for (int i = 0; i < grid.length; i++) {
            int start = 0;
            int end = grid[i].length - 1;
            while (start <= end) {
                int middle = (start + end) / 2;
                if (grid[i][middle] >= 0) {
                    start = middle + 1;
                } else {
                    end = middle - 1;
                }
            }

            total += grid[i].length - start;
        }

        return total;
    }
}
