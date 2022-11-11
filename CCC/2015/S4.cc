#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<tuple<int, int, int>>> paths(n + 1);
    vector<int> output(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;

        paths[a].push_back({b, t, h});
        paths[b].push_back({a, t, h});
    }

    auto qcomp = [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<1>(b) > get<1>(a);
    };
    priority_queue<tuple<int, int, int>>, vector<tuple<int, int, int>>, decltype(qcomp)> bfsq(qcomp);
} 