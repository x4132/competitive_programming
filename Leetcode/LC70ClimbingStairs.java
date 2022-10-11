public class LC70ClimbingStairs {
    public int climbStairs(int n) {
        Integer[] cache = new Integer[n];
        return solve(cache, 0, n);
    }
    public int solve(Integer[] cache, int pos, int n) {
        if (pos > n) {
            return 0;
        }
        if (pos == n) {
            return 1;
        }
        if (cache[pos] != null) {
            return cache[pos];
        }
        int value = solve(cache, pos + 1, n) + solve(cache, pos + 2, n);
        cache[pos] = value;
        return value;
    }

    public static void main(String[] args) {
        LC70ClimbingStairs lc70ClimbingStairs = new LC70ClimbingStairs();
        lc70ClimbingStairs.climbStairs(2);
    }
}
