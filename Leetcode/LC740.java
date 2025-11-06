import java.util.*;

class Solution {
    public int deleteAndEarn(int[] nums) {
        int n = 10001;

        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        int skip = 0;
        int take = 0;

        for (int i = 1; i < n; i++) {
            int curSkip = Math.max(skip, take);
            int curTake = skip + i * freq.getOrDefault(i, 0);

            skip = curSkip;
            take = curTake;
        }

        return Math.max(skip, take);
    }
}
