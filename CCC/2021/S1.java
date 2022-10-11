import java.io.BufferedReader;
import java.io.InputStreamReader;

class S1 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        if (n == 0) {
            System.out.println(0);
            return;
        }
        String[] hs = reader.readLine().split(" ");
        int[] h = new int[n + 1];
        for (int i = 0; i < h.length; i++) {
            h[i] = Integer.parseInt(hs[i]);
        }

        String[] ws = reader.readLine().split(" ");
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(ws[i]);
        }

        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (double) (w[i] * (h[i] + h[i + 1])) / 2;
        }

        System.out.println(sum);
    }
}