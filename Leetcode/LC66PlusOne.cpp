#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] % 10 != digits[i]) {
                if (i == 0) {
                    digits.insert(digits.begin(), 1);
                    i++;
                } else {
                    digits[i - 1]++;
                }
                digits[i] = digits[i] % 10;
            } else {
                break;
            }
        }

        return digits;
    }
};
