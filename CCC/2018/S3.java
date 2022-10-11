/*import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;

public class S3 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = reader.readLine().trim().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        Node[][] grid = new Node[n][m];
        Node start = new Node('S', -1, -1);
        ArrayList<Node> cameras = new ArrayList<>();
        ArrayList<Node> cells = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char[] mVals = reader.readLine().trim().toCharArray();
            for (int x = 0; x < m; x++) {
                grid[i][x] = new Node(mVals[x], x, i);
                if (mVals[x] == 'S') {
                    start = grid[i][x];
                } else if (mVals[x] == 'C') {
                    cameras.add(grid[i][x]);
                } else if (mVals[x] == '.') {
                    cells.add(grid[i][x]);
                }
            }
        }

        for (int i = 0; i < cameras.size(); i++) {
            Node cur = cameras.get(i);
            for (int x = cur.x; x < m; x++) {
                if (grid[cur.y][x].type == 'W') {
                    break;
                }

                if (grid[cur.y][x].type == 'U' || grid[cur.y][x].type == 'D' || grid[cur.y][x].type == 'L' || grid[cur.y][x].type == 'R') {
                    continue;
                }

                grid[cur.y][x].underWatch = true;
            }
            for (int x = cur.x; x >= 0; x--) {
                if (grid[cur.y][x].type == 'W') {
                    break;
                }

                if (grid[cur.y][x].type == 'U' || grid[cur.y][x].type == 'D' || grid[cur.y][x].type == 'L' || grid[cur.y][x].type == 'R') {
                    continue;
                }

                grid[cur.y][x].underWatch = true;
            }

            for (int y = cur.y; y < n; y++) {
                if (grid[y][cur.x].type == 'W') {
                    break;
                }

                if (grid[y][cur.x].type == 'U' || grid[y][cur.x].type == 'D' || grid[y][cur.x].type == 'L' || grid[y][cur.x].type == 'R') {
                    continue;
                }

                grid[y][cur.x].underWatch = true;
            }
            for (int y = cur.y; y >= 0; y--) {
                if (grid[y][cur.x].type == 'W') {
                    break;
                }

                if (grid[y][cur.x].type == 'U' || grid[y][cur.x].type == 'D' || grid[y][cur.x].type == 'L' || grid[y][cur.x].type == 'R') {
                    continue;
                }

                grid[y][cur.x].underWatch = true;
            }
        }

        for (int i = 0; i < cells.size(); i++) {
            ArrayDeque<Node> queue = new ArrayDeque<>();
            queue.add(start);
            start.visited = true;
            int targetX = cells.get(i).x;
            int targetY = cells.get(i).y;
            boolean flag = true;
            // System.out.println("TARGET " + targetX + " " + targetY);
            while (!queue.isEmpty()) {
                Node cur = queue.poll();
                if (cur.underWatch) {
                    continue;
                }

                if (cur.type == 'W' || cur.type == 'C') {
                    continue;
                } else if (cur.type == '.' && cur.x == targetX && cur.y == targetY) {
                    System.out.println(cur.dist);
                    flag = false;
                    break;
                }

                // System.out.println(cur.type + " " + cur.x + " " + cur.y);
                switch (cur.type) {
                    case 'L':
                        if (cur.x - 1 > 0 && grid[cur.y][cur.x - 1].visited == false && grid[cur.y][cur.x - 1].underWatch == false) {
                            grid[cur.y][cur.x - 1].dist = cur.dist;
                            grid[cur.y][cur.x - 1].visited = true;
                            queue.add(grid[cur.y][cur.x - 1]);
                        }
                        break;
                    case 'R':
                        if (cur.x + 1 < m && grid[cur.y][cur.x + 1].visited == false && grid[cur.y][cur.x + 1].underWatch == false) {
                            grid[cur.y][cur.x + 1].dist = cur.dist;
                            grid[cur.y][cur.x - 1].visited = true;
                            queue.add(grid[cur.y][cur.x + 1]);
                        }
                        break;
                    case 'U':
                        if (cur.y - 1 > 0 && grid[cur.y - 1][cur.x].visited == false && grid[cur.y - 1][cur.x].underWatch == false) {
                            grid[cur.y - 1][cur.x].dist = cur.dist;
                            grid[cur.y - 1][cur.x].visited = true;
                            queue.add(grid[cur.y - 1][cur.x]);
                        }
                        break;
                    case 'D':
                        if (cur.y + 1 > 0 && grid[cur.y + 1][cur.x].visited == false && grid[cur.y + 1][cur.x].underWatch == false) {
                            grid[cur.y + 1][cur.x].dist = cur.dist;
                            grid[cur.y + 1][cur.x].visited = true;
                            queue.add(grid[cur.y + 1][cur.x]);
                        }
                        break;
                    case 'S':
                    case '.':
                        if (cur.x - 1 > 0 && grid[cur.y][cur.x - 1].visited == false && grid[cur.y][cur.x - 1].underWatch == false) {
                            grid[cur.y][cur.x - 1].dist = cur.dist + 1;
                            grid[cur.y][cur.x - 1].visited = true;
                            queue.add(grid[cur.y][cur.x - 1]);
                        }
                        if (cur.x + 1 < m && grid[cur.y][cur.x + 1].visited == false && grid[cur.y][cur.x + 1].underWatch == false) {
                            grid[cur.y][cur.x + 1].dist = cur.dist + 1;
                            grid[cur.y][cur.x + 1].visited = true;
                            queue.add(grid[cur.y][cur.x + 1]);
                        }
                        if (cur.y - 1 > 0 && grid[cur.y - 1][cur.x].visited == false && grid[cur.y - 1][cur.x].underWatch == false) {
                            grid[cur.y - 1][cur.x].dist = cur.dist + 1;
                            grid[cur.y - 1][cur.x].visited = true;
                            queue.add(grid[cur.y - 1][cur.x]);
                        }
                        if (cur.y + 1 > 0 && grid[cur.y + 1][cur.x].visited == false && grid[cur.y + 1][cur.x].underWatch == false) {
                            grid[cur.y + 1][cur.x].dist = cur.dist + 1;
                            grid[cur.y + 1][cur.x].visited = true;
                            queue.add(grid[cur.y + 1][cur.x]);
                        }
                        break;
                }
            }

            if (flag) {
                System.out.println("-1");
            }

            for (int y = 0; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    grid[y][x].visited = false;
                    grid[y][x].dist = 0;
                }
            }
        }
    }
}

class Node {
    char type;
    boolean visited;
    boolean underWatch;
    int x;
    int y;
    int dist = 0;

    Node(char type, int x, int y) {
        this.type = type;
        this.x = x;
        this.y = y;
    }
}*/