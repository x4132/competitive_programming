import java.util.ArrayList;
import java.util.HashMap;

class Solution {

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                int[] output = { i, map.get(target - nums[i]) };
                return output;
            }

            map.put(nums[i], i);
        }

        throw new Error("idk");
    }
}
