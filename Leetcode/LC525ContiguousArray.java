import java.util.HashMap;

public class LC525ContiguousArray {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int total = 0;
        int maxLength = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                total++;
            } else {
                total--;
            }

            if (total == 0) {
                maxLength = Math.max(maxLength, i + 1);
            }

            if (map.containsKey(total)) {
                int length = i - map.get(total);
                maxLength = Math.max(maxLength, length);
            } else {
                map.put(total, i);
            }
        }

        return maxLength;
    }
}
