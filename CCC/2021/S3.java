import java.io.BufferedReader;
import java.io.InputStreamReader;

public class S3 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        int[] p = new int[n];
        int[] w = new int[n];
        int[] d = new int[n];

        int start = 1000000000;
        int end = 0;
        for (int i = 0; i < n; i++) {
            String[] s = reader.readLine().trim().split(" ");
            p[i] = Integer.parseInt(s[0]);
            start = Math.min(p[i], start);
            end = Math.max(p[i], end);
            w[i] = Integer.parseInt(s[1]);
            d[i] = Integer.parseInt(s[2]);
        }

        long result = 100000000000000000L;
        while (start <= end) {
            int middle = (start + end) / 2;
            long midr = walkTime(middle + 1, p, w, d);
            long midl = walkTime(middle - 1, p, w, d);
            long mid = walkTime(middle, p, w, d);
            result = Math.min(result, midr);
            result = Math.min(result, midl);
            result = Math.min(result, mid);
            if (midr < midl) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }

        System.out.println(result);
    }

    static long walkTime(int x, int[]p, int[] w, int[] d) {
        long time = 0;
        for (int i = 0; i < p.length; i++) {
            int rmax = p[i] + d[i];
            int lmax = p[i] - d[i];
            if (lmax <= x && x <= rmax) {
                continue;
            }
            int closest = lmax;
            if (x >= rmax) {
                closest = rmax;
            }

            time += (long) w[i] * Math.abs(x - closest);
        }

        return time;
    }
}
