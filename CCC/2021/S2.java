import java.io.BufferedReader;
import java.io.InputStreamReader;

public class S2 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(reader.readLine());
        int n = Integer.parseInt(reader.readLine());
        boolean[] ma = new boolean[m];
        boolean[] na = new boolean[n];
        int k = Integer.parseInt(reader.readLine());
        for (int i = 0; i < k; i++) {
            String[] in = reader.readLine().split(" ");
            boolean r = in[0].equals("R");
            if (r) {
                ma[Integer.parseInt(in[1]) - 1] = !ma[Integer.parseInt(in[1]) - 1];
            } else {
                na[Integer.parseInt(in[1]) - 1] = !na[Integer.parseInt(in[1]) - 1];
            }
        }

        int ml = 0;
        int nl = 0;
        for (int i = 0; i < m; i++) {
            if (ma[i]) {
                ml++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (na[i]) {
                nl++;
            }
        }


        System.out.println((n * ml) + (m * nl) - (ml * nl * 2));
    }
}
