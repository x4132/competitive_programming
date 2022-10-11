public class LC1539KthMissingPositiveNumber {
    public int findKthPositive(int[] arr, int k) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int middle = (start + end) / 2;
            if (arr[middle] - middle > k) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }

        return start + k;
    }

    public static void main(String[] args) {
        LC1539KthMissingPositiveNumber lc1539KthMissingPositiveNumber = new LC1539KthMissingPositiveNumber();
        lc1539KthMissingPositiveNumber.findKthPositive(new int[] {2, 3, 4, 7, 11}, 5);
    }
}
