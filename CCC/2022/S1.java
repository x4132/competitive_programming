import java.util.*;
import java.io.*;

public class S1 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        int ways = 0;
        if (n % 4 == 0) {
            ways++;
        }

        for (int i = n; i > 0; i -= 4) {
            if (i % 5 == 0) {
                ways++;
            }
        }

        System.out.println(ways);
    }
}
