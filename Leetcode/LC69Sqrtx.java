public class LC69Sqrtx {
    // this is a binary search question
    public int mySqrt(int x) {
        long start = 0;
        long end = x;
        while (start <= end) {
            long middle = (start + end) / 2;
            if (middle * middle >= x) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }

        if (start * start > x) {
            start--;
        }

        return (int) start;
    }

    public static void main(String[] args) {
        LC69Sqrtx lc69Sqrtx = new LC69Sqrtx();
        lc69Sqrtx.mySqrt(2147395599);
    }
}
