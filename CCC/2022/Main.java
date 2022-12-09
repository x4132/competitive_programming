import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] nc = reader.readLine().trim().split(" ");
        int N = Integer.parseInt(nc[0]);
        int C = Integer.parseInt(nc[1]);
        String[] narr = reader.readLine().trim().split(" ");
        int[] positions = new int[narr.length];
        for (int i = 0; i < positions.length; i++) {
            positions[i] = Integer.parseInt(narr[i]);
        }

        int total = 0;
        for (int a = 0; a < N; a++) {
            for (int b = a + 1; b < N; b++) {
                for (int c = b + 1; c < N; c++) {
                    if (C % 2 == 0) {
                        int aOpposite = (positions[a] + (C / 2)) % C;
                        int bOpposite = (positions[b] + (C / 2)) % C;
                        int cOpposite = (positions[c] + (C / 2)) % C;

                        if (aOpposite == positions[b] || aOpposite == positions[c] || bOpposite == positions[a] || bOpposite == positions[c] || cOpposite == positions[a]
                                || cOpposite == positions[b]) {
                            continue;
                        } else if ((positions[a] > C / 4 || positions[b] > C / 4 || positions[c] > C / 4)
                        && (positions[a] < C / 4 || positions[b] < C / 4 || positions[c] < C / 4)
                        && ((positions[a] + C / 4) % C > C / 4 || (positions[b] + C / 4) % C > C / 4
                                || positions[c] + C / 4 > C / 4)
                        && ((positions[a] + C / 4) % C < C / 4 || (positions[b] + C / 4) % C < C / 4
                                || (positions[c] + C / 4) % C < C / 4)) {
                            total++;
                        }
                    } else if ((positions[a] > C / 4 || positions[b] > C / 4 || positions[c] > C / 4)
                            && (positions[a] < C / 4 || positions[b] < C / 4 || positions[c] < C / 4)
                            && ((positions[a] + C / 4) % C > C / 4 || (positions[b] + C / 4) % C > C / 4
                                    || positions[c] + C / 4 > C / 4)
                            && ((positions[a] + C / 4) % C < C / 4 || (positions[b] + C / 4) % C < C / 4
                                    || (positions[c] + C / 4) % C < C / 4)) {
                        total++;
                    }
                }
            }
        }

        System.out.println(total);
    }
}
