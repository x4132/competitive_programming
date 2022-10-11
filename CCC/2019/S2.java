import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class S2 {
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine().trim());
        HashMap<Integer, Boolean> cache = new HashMap<>();

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(reader.readLine().trim());
            for (int x = n; x > 0; x--) {
                if (isPrime(cache, x) && isPrime(cache, n + (n - x))) {
                    System.out.println(x + " " + (n + (n - x)));
                    break;
                }
            }
        }
    }

    static boolean isPrime(HashMap<Integer, Boolean> cache, int num) {
        if (cache.containsKey(num)) {
            return cache.get(num).booleanValue();
        }

        for (int i = 2; i <= Math.sqrt(num); i++) {
            int factor = num / i;
            if (factor * i == num) {
                cache.put(num, false);
                return false;
            }
        }

        cache.put(num, true);
        return true;
    }
}