public class LC540SingleElementInASortedArray {
    public int singleNonDuplicate(int[] nums) {
        int start = 0;
        int end = nums.length - 1;

        while (start < end) {
            int mid = (start + end) / 2;
            if (mid % 2 == 1) mid--;

            if (nums[mid] != nums[mid + 1]) {
                end = mid;
            } else start = mid + 2;
        }

        return nums[start];
    }

    public static void main(String[] args) {
        LC540SingleElementInASortedArray lc540SingleElementInASortedArray = new LC540SingleElementInASortedArray();
        int[] test = {3,3,7,7,10,11,11};
        System.out.println(lc540SingleElementInASortedArray.singleNonDuplicate(test));
    }
}