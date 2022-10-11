// UNSOLVED

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;

public class S4 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] nwd = reader.readLine().trim().split(" ");
        int n = Integer.parseInt(nwd[0]);
        int w = Integer.parseInt(nwd[1]);
        int d = Integer.parseInt(nwd[2]);
        Node[] stations = new Node[n];
        stations[n - 1] = new Node(n - 1, null);
        for (int i = n - 2; i >= 0; i--) {
            stations[i] = new Node(i, stations[i + 1]);
        }
        for (int i = 0; i < w; i++) {
            String[] walkways = reader.readLine().trim().split(" ");
            int w1 = Integer.parseInt(walkways[0]);
            int w2 = Integer.parseInt(walkways[1]);
            stations[w1].walkways.add(stations[w2]);
        }

        ArrayDeque<Node> queue = new ArrayDeque<>();

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            current.visited = true;
            if (!current.nextStation.visited) {
                queue.add(current.nextStation);
            }

            for (int i = 0; i < current.walkways.size(); i++) {
                if (!current.walkways.get(i).visited) {
                    queue.add(current.walkways.get(i));
                }
            }
        }
    }
}

class Node {
    int n;
    boolean visited = false;
    Node nextStation;
    ArrayList<Node> walkways = new ArrayList<>();

    Node(int n, Node nextStation) {
        this.n = n;
        this.nextStation = nextStation;
    }
}