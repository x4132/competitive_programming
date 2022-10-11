#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }

        int start = 1, prev = 1;
        for (int i = 2; i < n; i++) {
            int carry = prev;
            prev = start + prev;
            start = carry;
        }

        return prev;
    }

    int fib_mem(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        
        int sum = fib(n - 1) + fib(n-2);
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.fib(23);
}