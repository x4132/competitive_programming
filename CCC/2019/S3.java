import java.io.BufferedReader;
import java.io.InputStreamReader;

public class S3 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] row0Strings = reader.readLine().trim().split(" ");
        String[] row1Strings = reader.readLine().trim().split(" ");
        String[] row2Strings = reader.readLine().trim().split(" ");
        int[][] grid = new int[3][3];
        for (int i = 0; i < 3; i++) {
            if (!row0Strings[i].equals("X"))
                grid[0][i] = Integer.parseInt(row0Strings[i]);
            else
                grid[0][i] = 1000000001;
            if (!row1Strings[i].equals("X"))
                grid[1][i] = Integer.parseInt(row1Strings[i]);
            else
                grid[1][i] = 1000000001;
            if (!row2Strings[i].equals("X"))
                grid[2][i] = Integer.parseInt(row2Strings[i]);
            else
                grid[2][i] = 1000000001;
        }
        int status = solvable(grid);
        while (status != 2) {
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    if (grid[y][x] == 1000000001) {
                        int solve = calcNum(grid[y], x);
                        if (solve == -1000000002) {
                            solve = calcNum(new int[] { grid[0][x], grid[1][x], grid[2][x] }, y);
                            if (solve == -1000000002) {
                                solve = grid[y][x];
                            }
                        }
                        grid[y][x] = solve;
                    }
                }
            }

            status = solvable(grid);

            if (status == 0) {
                for (int y = 0; y < 3; y++) {
                    boolean flag = false;
                    for (int x = 0; x < 3; x++) {
                        if (grid[y][x] == 1000000001) {
                            grid[y][x] = 1;
                            flag = true;
                            int validStatus = valid(grid, x, y);
                            if (validStatus == -1000000069) {
                                grid[y][x]++;
                            } else if (validStatus != -1000000420) {
                                grid[y][x] = validStatus;
                            }

                            break;
                        } 
                    }

                    if (flag)
                        break;
                }

                status = solvable(grid);
            }
        }

        for (int i = 0; i < 3; i++) {
            System.out.println(grid[i][0] + " " + grid[i][1] + " " + grid[i][2]);
        }
    }

    static int calcNum(int[] arr, int index) {
        int numOfZeros = 0;
        for (int i = 0; i < 3; i++) {
            if (arr[i] == 1000000001) {
                numOfZeros++;
            }
        }

        switch (numOfZeros) {
            case 0:
                return arr[index];
            case 1:
                switch (index) {
                    case 0:
                        return arr[1] - (arr[2] - arr[1]);
                    case 1:
                        return arr[0] + ((arr[2] - arr[0]) / 2);
                    case 2:
                        return arr[1] + (arr[1] - arr[0]);
                }
            case 2:
            case 3:
                return -1000000002;
        }
        return -1000000003;
    }

    static int solvable(int[][] grid) {
        int rows = 0;
        for (int y = 0; y < 3; y++) {
            int empty = 0;
            for (int x = 0; x < 3; x++) {
                if (grid[y][x] == 1000000001) {
                    empty++;
                }
            }

            if (empty == 1) {
                return 1;
            } else if (empty == 0) {
                rows++;
            }
        }

        if (rows == 3) {
            return 2;
        }

        for (int x = 0; x < 3; x++) {
            int empty = 0;
            for (int y = 0; y < 3; y++) {
                if (grid[y][x] == 1000000001) {
                    empty++;
                } 
            }

            if (empty == 1) {
                return 1;
            }
        }

        return 0;
    }

    static int valid(int[][] grid, int x, int y) {
        int emptyX = 0;
        int emptyY = 0;
        int sumX = 0;
        int sumY = 0;
        for (int i = 0; i < 3; i++) {
            if (grid[i][x] == 1000000001) {
                emptyX++;
            } else {
                sumX += grid[i][x];
            }
            if (grid[y][i] == 1000000001) {
                emptyY++;
            } else {
                sumY += grid[y][i];
            }
        }

        if ((emptyX == 1 && sumX % 2 != 0) || (emptyY == 1 && sumY % 2 != 0)) {
            if (x == 1) {
                if (y == 0 && (grid[0][0] + grid[0][2] - 1000000001 + grid[2][1]) % 2 == 1) {
                    return grid[2][1];
                } else if (y == 2 && (grid[2][0] + grid[2][2] - 1000000001 + grid[0][1]) % 2 == 1) {
                    return grid[0][1];
                }
            } else if (y == 1) {
                if (x == 0 && (grid[0][0] + grid[2][0] - 1000000001 + grid[1][2]) % 2 == 1) {
                    return grid[1][2];
                } else if (x == 2 && (grid[0][2] + grid[2][2] - 1000000001 + grid[1][0]) % 2 == 1) {
                    return grid[1][0];
                }
            }
            return -1000000069;
        }
        return -1000000420;
    }
}
