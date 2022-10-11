public class LC81SearchInRotatedSortedArrayII {
    public boolean search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        if (nums.length == 0) return false;

        while (start <= end) {
            int middle = (start + end) / 2;

            if (nums[middle] == target) {
                return true;
            }

            if (nums[middle] == nums[start]) { // Can't figure out which rotation middle is in, iterate up
                start++;
                continue;
            }

            if (nums[start] < nums[middle]) { // rotation point is after middle
                if (target < nums[middle] && target >= nums[start]) {
                    end = middle - 1;
                } else {
                    start = middle + 1;
                }
            } else {
                if (target > nums[middle] && target <= nums[end]) {
                    start = middle + 1;
                } else {
                    end = middle - 1;
                }
            }
        }

        return false;
    }
}