import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.HashSet;

public class S2 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(reader.readLine());
        int n = Integer.parseInt(reader.readLine());

        int[][] rooms = new int[m][n];
        HashSet<Integer> visited = new HashSet<>();

        for (int i = 0; i < m; i++) {
            String[] input = reader.readLine().trim().split(" ");
            for (int x = 0; x < n; x++) {
                rooms[i][x] = Integer.parseInt(input[x]);
            }
        }

        ArrayDeque<Integer> queue = new ArrayDeque<>();
        queue.push(rooms[0][0]);
        visited.add(rooms[0][0]);
        while (!queue.isEmpty()) {
            int current = queue.pop();

            for (int i = 1; i <= Math.sqrt(current); i++) {
                int factor = current / i;
                if (factor * i == current) {
                    if ((i == m && current / i == n) || (i == n && current / i == m)) {
                        System.out.println("yes");
                        return;
                    }
                    if (current / i <= n && i <= m && !visited.contains(rooms[i - 1][factor - 1])) {
                        visited.add(rooms[i - 1][factor - 1]);
                        queue.add(rooms[i - 1][factor - 1]);
                    }
                    if (current / i <= m && i <= n && !visited.contains(rooms[factor - 1][i - 1])) {
                        visited.add(rooms[factor - 1][i - 1]);
                        queue.add(rooms[factor - 1][i - 1]);
                    }
                }
            }
        }

        System.out.println("no");
    }
}
