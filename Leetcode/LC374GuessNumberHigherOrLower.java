/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class LC374GuessNumberHigherOrLower {
    public int guessNumber(int n) {
        int min = 1;
        int max = n;
        while (min < max) {
            int middle = (int) ((long) min + (long) max) / 2;
            int val = guess(middle);
            if (val == 0) {
                return middle;
            } else if (val == 1) {
                min = middle + 1;
            } else {
                max = middle - 1;
            }
        }

        return min;
    }

    static int guess(int num) {
        int ans = 6;
        if (num == ans) {
            return 0;
        }
        else if (num > ans) {
            return 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        LC374GuessNumberHigherOrLower lc374GuessNumberHigherOrLower = new LC374GuessNumberHigherOrLower();
        lc374GuessNumberHigherOrLower.guessNumber(10);
    }
}

