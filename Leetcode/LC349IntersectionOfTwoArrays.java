import java.util.HashSet;

public class LC349IntersectionOfTwoArrays {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();

        for (int i : nums1) {
            set1.add(i);
        }
        for (int i : nums2) {
            set2.add(i);
        }

        set1.retainAll(set2);

        int[] output = new int[set1.size()];
        int i = 0;
        for (int s : set1) {
            output[i] = s;
            i++;
        }

        return output;
    }
}
