class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] longestLen = new int[n];
        int[] numSeq = new int[n];

        for (int i = 0; i < n; i++) {
            longestLen[i] = 1;
            numSeq[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && longestLen[i] < longestLen[j] + 1) {
                    longestLen[i] = longestLen[j] + 1;
                    numSeq[i] = numSeq[j];
                } else if (nums[j] < nums[i] && longestLen[i] == longestLen[j] + 1) {
                    numSeq[i] += numSeq[j];
                }
            }
        }

        int longestSeq = 0;
        for (int len : longestLen) {
            longestSeq = Math.max(len, longestSeq);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (longestLen[i] == longestSeq) {
                result += numSeq[i];
            }
        }

        return result;
    }
}