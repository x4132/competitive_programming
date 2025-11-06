#include <exception>
#include <iostream>
using namespace std;

class Solution {
  public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 0, r = neededApples + 1;

        // 0 4 18 48 100

        auto fn = [&](long long mid) {
            long long sum_1d = ((mid + 1) * mid / 2);
            // final is (mid + 1)*mid + sum_1d, initial is sum_1d
            // so it's (0..mid)(mid + 1) so gap is mid + 1, everyone has sum_1d
            // so sum_1d * (mid + 1) + that arith. seq?
            long long sum_2d =
                4 * (sum_1d * mid + (mid * (mid + 1)) * (mid + 1) / 2);
            return sum_2d;
        };

        while (1) {
            long long mid = (r - l) / 2;
            long long down = fn(mid - 1);
            try {
                long long up = fn(mid);
            } catch (exception e) {
            }

            if (up < neededApples) {
                l = mid;
            } else if (down > neededApples) {
                r = mid;
            } else {
                return 8 * mid;
            }
        }
    }
};