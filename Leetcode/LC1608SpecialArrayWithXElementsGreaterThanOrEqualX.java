import java.util.Arrays;

public class LC1608SpecialArrayWithXElementsGreaterThanOrEqualX {
    public int specialArray(int[] nums) {
        if (nums.length == 0) return 0;

        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[nums.length - i - 1] >= i + 1 && (i == nums.length - 1 || nums[nums.length - i - 2] < i + 1)) {
                return i + 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        LC1608SpecialArrayWithXElementsGreaterThanOrEqualX lc1608SpecialArrayWithXElementsGreaterThanOrEqualX = new LC1608SpecialArrayWithXElementsGreaterThanOrEqualX();
        lc1608SpecialArrayWithXElementsGreaterThanOrEqualX.specialArray(new int[] {3, 6, 7, 7, 0});
    }
}
