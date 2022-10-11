import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = reader.readLine().trim().split(" ");
        int num_rows = Integer.parseInt(nm[0]);
        int num_cols = Integer.parseInt(nm[1]);

        Node[][] grid = new Node[num_rows][num_cols];
        Node start = new Node('S', -1, -1);
        ArrayList<Node> empty = new ArrayList<>();
        ArrayList<Node> cameras = new ArrayList<>();

        for (int row = 0; row < num_rows; row++) {
            char[] arr = reader.readLine().trim().toCharArray();
            for (int col = 0; col < num_cols; col++) {
                grid[row][col] = new Node(arr[col], col, row);
                if (grid[row][col].type == 'S') {
                    start = grid[row][col];
                } else if (grid[row][col].type == '.') {
                    empty.add(grid[row][col]);
                } else if (grid[row][col].type == 'C') {
                    cameras.add(grid[row][col]);
                }
            }
        }

        // Camera Assigning
        for (int i = 0; i < cameras.size(); i++) {
            Node camera = cameras.get(i);
            camera.type = 'W';
            for (int cam_col = camera.col + 1; cam_col < num_cols; cam_col++) {
                if (grid[camera.row][cam_col].type == 'U' || grid[camera.row][cam_col].type == 'D'
                        || grid[camera.row][cam_col].type == 'L'
                        || grid[camera.row][cam_col].type == 'R') {
                    continue;
                } else if (grid[camera.row][cam_col].type == 'W') {
                    break;
                }

                grid[camera.row][cam_col].underWatch = true;
            }
            for (int cam_col = camera.col - 1; cam_col >= 0; cam_col--) {
                if (grid[camera.row][cam_col].type == 'U' || grid[camera.row][cam_col].type == 'D'
                        || grid[camera.row][cam_col].type == 'L'
                        || grid[camera.row][cam_col].type == 'R') {
                    continue;
                } else if (grid[camera.row][cam_col].type == 'W') {
                    break;
                }

                grid[camera.row][cam_col].underWatch = true;
            }
            for (int cam_row = camera.row + 1; cam_row < num_rows; cam_row++) {
                if (grid[cam_row][camera.col].type == 'U' || grid[cam_row][camera.col].type == 'D'
                        || grid[cam_row][camera.col].type == 'L'
                        || grid[cam_row][camera.col].type == 'R') {
                    continue;
                } else if (grid[cam_row][camera.col].type == 'W') {
                    break;
                }

                grid[cam_row][camera.col].underWatch = true;
            }
            for (int cam_row = camera.row - 1; cam_row >= 0; cam_row--) {
                if (grid[cam_row][camera.col].type == 'U' || grid[cam_row][camera.col].type == 'D'
                        || grid[cam_row][camera.col].type == 'L'
                        || grid[cam_row][camera.col].type == 'R') {
                    continue;
                } else if (grid[cam_row][camera.col].type == 'W') {
                    break;
                }

                grid[cam_row][camera.col].underWatch = true;
            }
        }

        ArrayDeque<Node> queue = new ArrayDeque<>();
        if (start.underWatch == false) {
            queue.add(start);
        }
        start.visited = true;
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            switch (cur.type) {
                case 'U':
                    if (cur.row - 1 >= 0 && isValid(grid[cur.row - 1][cur.col], cur)) {
                        grid[cur.row - 1][cur.col].dist = cur.dist;
                        queue.add(grid[cur.row - 1][cur.col]);
                    }
                    break;
                case 'D':
                    if (cur.row + 1 < num_rows && isValid(grid[cur.row + 1][cur.col], cur)) {
                        grid[cur.row + 1][cur.col].dist = cur.dist;
                        queue.add(grid[cur.row + 1][cur.col]);
                    }
                    break;
                case 'L':
                    if (cur.col - 1 >= 0 && isValid(grid[cur.row][cur.col - 1], cur)) {
                        grid[cur.row][cur.col - 1].dist = cur.dist;
                        queue.add(grid[cur.row][cur.col - 1]);
                    }
                    break;
                case 'R':
                    if (cur.col + 1 < num_cols && isValid(grid[cur.row][cur.col + 1], cur)) {
                        grid[cur.row][cur.col + 1].dist = cur.dist;
                        queue.add(grid[cur.row][cur.col + 1]);
                    }
                    break;
                default:
                    if (cur.row - 1 >= 0 && isValid(grid[cur.row - 1][cur.col], cur)) { // up
                        grid[cur.row - 1][cur.col].dist = cur.dist + 1;
                        queue.add(grid[cur.row - 1][cur.col]);
                    }
                    if (cur.row + 1 < num_rows && isValid(grid[cur.row + 1][cur.col], cur)) { // down
                        grid[cur.row + 1][cur.col].dist = cur.dist + 1;
                        queue.add(grid[cur.row + 1][cur.col]);
                    }
                    if (cur.col - 1 >= 0 && isValid(grid[cur.row][cur.col - 1], cur)) { // left
                        grid[cur.row][cur.col - 1].dist = cur.dist + 1;
                        queue.add(grid[cur.row][cur.col - 1]);
                    }
                    if (cur.col + 1 < num_cols && isValid(grid[cur.row][cur.col + 1], cur)) { // right
                        grid[cur.row][cur.col + 1].dist = cur.dist + 1;
                        queue.add(grid[cur.row][cur.col + 1]);
                    }
                    break;
            }
        }

        for (int i = 0; i < empty.size(); i++) {
            Node cur = empty.get(i);
            if (cur.dist == 0) {
                System.out.println(-1);
            } else {
                System.out.println(cur.dist);
            }
        }
    }

    static boolean isValid(Node test, Node cur) {
        if (test.type != 'C' && test.type != 'W' && (!test.visited || (cur.type == '.' && cur.dist + 1 < test.dist) || (cur.type != '.' && cur.dist < test.dist)) && !test.underWatch) {
            test.visited = true;
            return true;
        }

        return false;
    }
}

class Node {
    char type;
    boolean visited = false;
    boolean underWatch = false;
    int col;
    int row;
    int dist = 0;

    Node(char type, int col, int row) {
        this.type = type;
        this.col = col;
        this.row = row;
    }
}