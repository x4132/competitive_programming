public class LC167TwoSumIIInputArrayIsSorted {
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length; i++) {
            int start = 0;
            int end = numbers.length - 1;
            while (start <= end) {
                int middle = (start + end) / 2;
                if (numbers[i] + numbers[middle] == target && i != middle) {
                    return new int[] {i + 1, middle + 1};
                } else if (numbers[i] + numbers[middle] > target) {
                    end = middle - 1;
                } else {
                    start = middle + 1;
                }
            }
        }

        return new int[] {-1, -1};
    }

    public static void main(String[] args) {
        LC167TwoSumIIInputArrayIsSorted lc167TwoSumIIInputArrayIsSorted = new LC167TwoSumIIInputArrayIsSorted();
        lc167TwoSumIIInputArrayIsSorted.twoSum(new int[] {2, 7, 11, 15}, 9);
    }
}
