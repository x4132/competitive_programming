import java.util.HashSet;

public class LC888FairCandySwap {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        HashSet<Integer> bobSizesTable = new HashSet<>();
        int aliceSum = 0;
        int bobSum = 0;
        int difference = 0;

        for (int i : aliceSizes) {
            aliceSum += i;
        }
        for (int i : bobSizes) {
            bobSum += i;
            bobSizesTable.add(i);
        }
        difference = (bobSum - aliceSum) / 2;

        for (int i : aliceSizes) {
            if (bobSizesTable.contains(i + difference)) {
                return new int[] {i, i + difference};
            }
        }

        return new int[] {-1, -1};
    }

    public static void main(String[] args) {
        LC888FairCandySwap lc888FairCandySwap = new LC888FairCandySwap();
        lc888FairCandySwap.fairCandySwap(new int[] {1, 1}, new int[] {2, 2});
    }
}
