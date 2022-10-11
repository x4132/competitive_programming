public class LC852PeakIndexInAMountainArray {
    public int peakIndexInMountainArray(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int middle = (start + end) / 2;

            if (arr[middle] > arr[middle + 1]) {
                end = middle - 1;
            } else start = middle + 1;
        }

        return start;
    }
}
