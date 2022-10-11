class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        if (n == 0) {
            return 0;
        }
        if (n < 2) {
            return 1;
        }

        for (int i = 2; i < n; i++) {
            int carry = a + b + c;
            a = b;
            b = c;
            c = carry;
        }

        return c;
    }
};