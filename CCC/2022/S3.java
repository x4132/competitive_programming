import java.util.*;
import java.io.*;

public class S3 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] nmk = reader.readLine().trim().split(" ");
        int n = Integer.parseInt(nmk[0]);
        int m = Integer.parseInt(nmk[1]);
        long k = Long.parseLong(nmk[2]);
        if (k < n /* || k > (long) ((n / 2d) * (n + 1) - (((n - m) / 2d) * (n - m + 1)))*/ ) {
            System.out.println(-1);
            return;
        }

        int[] vals = new int[n];
        long currentSamples = n;
        for (int i = 0; i < n; i++) {
            vals[i] = 1;
        }

        int index = 0;
        while (currentSamples < k - 1) {
            vals[index * 2 + 1] = 2;
            currentSamples = currentGoodSamples(vals);
            index++;
        }

        if (index * 2 + 1 > vals.length) {
            System.out.println(-1);
            return;
        }

        if (currentSamples == k - 1) {
            vals[vals.length - 1] = 2;
            currentSamples = currentGoodSamples(vals);
        }
        if (currentSamples == k - 1) {
            System.out.println(-1);
            return;
        }

        for (int i = 0; i < vals.length - 1; i++) {
            System.out.print(vals[i] + " ");
        }

        System.out.println(vals[vals.length - 1]);
    }

    static long currentGoodSamples(int[] vals) {
        long samples = vals.length;
        for (int i = 2; i <= vals.length; i++) {
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int a = 0; a < i; a++) {
                map.putIfAbsent(vals[a], 0);
                map.put(vals[a], map.get(vals[a]) + 1);
            }

            boolean flag = true;
            for (int z : map.keySet()) {
                if (map.get(z) > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                samples++;
            } else {
                flag = true;
            }
            

            for (int a = i; a < vals.length; a++) {
                map.put(vals[a - i], map.get(vals[a - i]) - 1);
                map.putIfAbsent(vals[a], 0);
                map.put(vals[a], map.get(vals[a]) + 1);
                for (int z : map.keySet()) {
                    if (map.get(z) > 1) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    samples++;
                } else
                    flag = true;
            }
        }

        return samples;
    }
}