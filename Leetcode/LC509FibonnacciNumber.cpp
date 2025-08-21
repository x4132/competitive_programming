class Solution {
  public:
    int fib(int n) {
        int back1 = 1;
        int back2 = 1;

        if (n == 0) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }

        for (int i = 2; i < n; i++) {
            int cur = back1 + back2;
            back2 = back1;
            back1 = cur;
        }

        return back1;
    }
};