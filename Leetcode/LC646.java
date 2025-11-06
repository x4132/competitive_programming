import java.util.*;

class Solution {
    public int findLongestChain(int[][] p) {
        ArrayList<ArrayList<Integer>> pairs = new ArrayList<>();
        for (int[] pair : p) {
            ArrayList<Integer> t = new ArrayList<>();
            t.add(pair[0]);
            t.add(pair[1]);

            pairs.add(t);
        }

        pairs.sort((ArrayList<Integer> a, ArrayList<Integer> b) -> a.get(1) - b.get(1));

        int chainLength = 1;
        ArrayList<Integer> lastPair = pairs.get(0);
        for (int i = 1; i < p.length; i++) {
            if (pairs.get(i).get(0) > lastPair.get(1)) {
                chainLength++;
                lastPair = pairs.get(i);
            }
        }

        return chainLength;
    }
}