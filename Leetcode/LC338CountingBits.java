public class LC338CountingBits {
    public int[] countBits(int n) {
        int[] out = new int[n + 1];
        int multiple = 1;
        for (int i = 1; i < n + 1; i++) {
            if (multiple * 2 == i) {
                multiple *= 2;
            }

            out[i] = out[i - multiple] + 1;
        }

        return out;
    }
}
