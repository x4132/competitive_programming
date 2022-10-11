import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;

public class S1 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        NodeCompare nodeCompare = new NodeCompare();
        ArrayList<Node> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = reader.readLine().trim().split(" ");
            list.add(new Node(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
        }

        list.sort(nodeCompare);

        double maxSpeed = 0;
        for (int i = 0; i < n - 1; i++) {
            int timeDiff = list.get(i + 1).t - list.get(i).t;
            int posDiff = Math.abs(list.get(i + 1).p - list.get(i).p);
            maxSpeed = Math.max((double) posDiff / timeDiff, maxSpeed);
        }

        System.out.println(maxSpeed);
    }
}

class NodeCompare implements Comparator<Node> {
    public int compare(Node a, Node b) {
        return a.t - b.t;
    }
}

class Node {
    int t;
    int p;
    Node(int t, int p) {
        this.t = t;
        this.p = p;
    }
}