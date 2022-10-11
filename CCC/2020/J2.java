import java.io.BufferedReader;
import java.io.InputStreamReader;

public class J2 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int p = Integer.parseInt(reader.readLine());
        int n = Integer.parseInt(reader.readLine());
        int r = Integer.parseInt(reader.readLine());
        int day = 0;
        int total = n;

        while (total <= p) {
            n *= r;
            total += n;
            day++;
        }

        System.out.println(day);
    }
}