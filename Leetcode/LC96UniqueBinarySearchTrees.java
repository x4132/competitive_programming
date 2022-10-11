public class LC96UniqueBinarySearchTrees {
    public int numTrees(int n) {
        int[] cache = new int[n + 1];
        cache[0] = 1;
        cache[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            for (int x = 1; x <= i; x++) {
                cache[i] += cache[i - x]*cache[x - 1];
            }
        }

        return cache[n];
    }
}
