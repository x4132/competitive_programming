public class LC53MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        int prevSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            prevSum += nums[i];
            if (prevSum < nums[i]) {
                prevSum = nums[i];
            }
            if (max < prevSum) {
                max = prevSum;
            }
        }

        return max;
    }
}
