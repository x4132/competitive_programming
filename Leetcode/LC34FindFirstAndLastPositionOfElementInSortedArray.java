public class LC34FindFirstAndLastPositionOfElementInSortedArray {
    public int[] searchRange(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int[] out = { -1, -1 };

        while (start <= end) {
            int middle = (start + end) / 2;
            if (nums[middle] == target)
                out[0] = middle;
            if (nums[middle] >= target) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }

        if (start == nums.length || nums[start] != target) {
            return out;
        }

        end = nums.length - 1;
        while (start <= end) {
            int middle = (start + end) / 2;
            if (nums[middle] == target)
                out[1] = middle;
            if (nums[middle] <= target) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }

        return out;
    }

    public static void main(String[] args) {
        LC34FindFirstAndLastPositionOfElementInSortedArray lc34FindFirstAndLastPositionOfElementInSortedArray = new LC34FindFirstAndLastPositionOfElementInSortedArray();

        int[] nums = { 1, 2, 3 };
        int target = 1;

        System.out.println(lc34FindFirstAndLastPositionOfElementInSortedArray.searchRange(nums, target)[0]);
    }
}