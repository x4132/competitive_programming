#include <bits/stdc++.h>

using namespace std;

long long walkTime(int x, vector<int> p, vector<int> w, vector<int> d);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> w(n);
    vector<int> d(n);

    int start = 1000000000;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i] >> d[i];
        start = min(p[i], start);
        end = max(p[i], end);
    }

    long long result = 100000000000000000;
    while (start <= end) {
        int middle = (start + end) / 2;
        long long midr = walkTime(middle + 1, p, w, d);
        long long midl = walkTime(middle - 1, p, w, d);
        long long mid = walkTime(middle, p, w, d);
        result = min(result, midr);
        result = min(result, midl);
        result = min(result, mid);
        if (midr < midl) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    cout << result;
}

long long walkTime(int x, vector<int> p, vector<int> w, vector<int> d) {
    long long time = 0;
    for (int i = 0; (size_t) i < p.size(); i++) {
        int rmax = p[i] + d[i];
        int lmax = p[i] - d[i];
        if (lmax <= x && x <= rmax) {
            continue;
        }
        int closest = lmax;
        if (x >= rmax) {
            closest = rmax;
        }

        time += (long long) w[i] * abs(x - closest);
    }

    return time;
}