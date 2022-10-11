import java.util.Arrays;

public class LC1385FindTheDistanceValueBetweenTwoArrays {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);

        int dist = 0;
        for (int i = 0; i < arr1.length; i++) {
            int start = 0;
            int end = arr2.length - 1;
            boolean flag = false;
            while (start <= end) {
                int middle = (start + end) / 2;
                if (Math.abs(arr1[i] - arr2[middle]) <= d) {
                    flag = true;
                    break;
                }
                else if (arr1[i] - arr2[middle] > d) {
                    start = middle + 1;
                } else {
                    end = middle - 1;
                }
            }

            if ((end < 0 || start >= arr2.length || Math.abs(arr1[i] - arr2[start]) > d) && !flag) {
                dist++;
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        LC1385FindTheDistanceValueBetweenTwoArrays lc1385FindTheDistanceValueBetweenTwoArrays = new LC1385FindTheDistanceValueBetweenTwoArrays();
        int[] arr1 = { 4, 5, 8 };
        int[] arr2 = { 10, 9, 1, 8 };
        int d = 2;
        lc1385FindTheDistanceValueBetweenTwoArrays.findTheDistanceValue(arr1, arr2, d);
    }
}
