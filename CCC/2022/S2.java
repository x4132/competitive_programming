import java.util.*;
import java.io.*;

public class S2 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(reader.readLine());
        HashSet<String> sameGroup = new HashSet<>();
        for (int i = 0; i < x; i++) {
            sameGroup.add(reader.readLine().trim());
        }
        int y = Integer.parseInt(reader.readLine());
        HashSet<String> diffGroup = new HashSet<>();
        for (int i = 0; i < y; i++) {
            diffGroup.add(reader.readLine().trim());
        }
        int g = Integer.parseInt(reader.readLine());
        int violated = 0;

        for (int i = 0; i < g; i++) {
            String[] group = reader.readLine().trim().split(" ");
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    if (b == a) {
                        continue;
                    }

                    if (sameGroup.contains(group[a] + " " + group[b])) {
                        sameGroup.remove(group[a] + " " + group[b]);
                    } else if (diffGroup.contains(group[a] + " " + group[b])) {
                        violated++;
                        diffGroup.remove(group[a] + " " + group[b]);
                    }
                }
            }
        }

        violated += sameGroup.size();
        System.out.println(violated);
    }
}
