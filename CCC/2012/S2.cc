#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string in;
    cin >> in;

    unordered_map<char, int> romans({{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}});

    int sum = 0;
    int prevRoman = 10000;
    int prevArabic = 0;

    for (int i = 0; i < in.size(); i += 2)
    {
        int arabic = atoi(&in[i]);
        int roman = romans[in[i + 1]];

        if (roman > prevRoman) {
            sum -= (prevRoman * prevArabic) * 2;
        }

        sum += arabic * roman;
        prevRoman = roman;
        prevArabic = arabic;
    }

    cout << sum;
}