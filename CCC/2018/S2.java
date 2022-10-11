import java.io.BufferedReader;
import java.io.InputStreamReader;

public class S2 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        int[][] grid = new int[n][n];
        for (int y = 0; y < n; y++) {
            String[] rowStrings = reader.readLine().trim().split(" ");
            for (int x = 0; x < n; x++) {
                grid[y][x] = Integer.parseInt(rowStrings[x]);
            }
        }

        while (!validate(grid)) {
            grid = rotate(grid);
        }

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n - 1; x++) {
                System.out.print(grid[y][x] + " ");
            }
            System.out.println(grid[y][n - 1]);
        }
    }

    static boolean validate(int[][] grid) {
        for (int y = 0; y < grid.length - 1; y++) {
            for (int x = 0; x < grid.length - 1; x++) {
                if (grid[y][x] > grid[y][x + 1]|| grid[y][x] > grid[y + 1][x]) {
                    return false;
                }
            }
        }

        return true;
    }

    static int[][] rotate(int[][] grid) {
        int[][] output = new int[grid.length][grid.length];
        for (int x = 0; x < grid.length; x++) {
            for (int y = 0; y < grid.length; y++) {
                output[x][grid.length - y - 1] = grid[y][x];
            }
        }

        return output;
    }
}
