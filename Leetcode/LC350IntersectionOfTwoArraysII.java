import java.util.ArrayList;
import java.util.HashMap;

public class LC350IntersectionOfTwoArraysII {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> num2Vals = new HashMap<>();
        for (int i : nums2) {
            num2Vals.putIfAbsent(i, 0);
            num2Vals.put(i, num2Vals.get(i) + 1);
        }
        ArrayList<Integer> vals = new ArrayList<>();
        for (int i : nums1) {
            if (num2Vals.get(i) != null && num2Vals.get(i) > 0) {
                num2Vals.put(i, num2Vals.get(i) - 1);
                vals.add(i);
            }
        }

        int[] result = new int[vals.size()];
        for (int i = 0; i < vals.size(); i++) {
            result[i] = vals.get(i);
        }

        return result;
    }
}
