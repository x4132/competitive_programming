public class LC153FindMinimumInRotatedSortedArray {
    public int findMin(int[] nums) {
        int start = 0;
        int end = nums.length - 1;
        while (start < end) {
            int middle = (start + end) / 2;

            if (nums[middle] > nums[middle + 1]) {
                return nums[middle + 1];
            } else if (nums[middle - 1] > nums[middle]) {
                return nums[middle];
            }

            if (nums[middle] > nums[0]) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }

        return start;
    }

    public static void main(String[] args) {
        LC153FindMinimumInRotatedSortedArray lc153FindMinimumInRotatedSortedArray = new LC153FindMinimumInRotatedSortedArray();
        lc153FindMinimumInRotatedSortedArray.findMin(new int[] {4, 5, 6, 7, 0, 1, 2});
    }
}
