public class LC33SearchInRotatedSortedArray {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;

        
        while (start <= end) {
            int middle = (start + end) / 2;
            
            if (nums[middle] == target) {
                return middle;
            }
            
            if (nums[start] <= nums[middle]) {
                if (nums[start] <= target && nums[middle] >= target) {
                    end = middle - 1;
                } else {
                    start = middle + 1;
                }
            } else {
                if (nums[middle] <= target && nums[end] >= target) {
                    start = middle + 1;
                } else {
                    end = middle - 1;
                }
            }
        }
        
        return -1;
    }

    public static void main(String[] args) {
        LC33SearchInRotatedSortedArray lc33SearchInRotatedSortedArray = new LC33SearchInRotatedSortedArray();
        int[] nums = {3, 1};
        System.out.println(lc33SearchInRotatedSortedArray.search(nums, 1));
    }
}