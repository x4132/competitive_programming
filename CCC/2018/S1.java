import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class S1 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        int[] villages = new int[n];
        for (int i = 0; i < n; i++) {
            villages[i] = Integer.parseInt(reader.readLine().trim());
        }

        Arrays.sort(villages);

        double minSize = Integer.MAX_VALUE;
        for (int i = 1; i < n - 1; i++) {
            double villageSize = ((double) villages[i + 1] - (double) villages[i]) / 2f + ((double) villages[i] - (double) villages[i - 1]) / 2f;
            minSize = Math.min(villageSize, minSize);
        }

        System.out.printf("%.1f", minSize);
    }
}