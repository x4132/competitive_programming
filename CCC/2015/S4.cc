#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<tuple<int, int, int>>> paths(n + 1);
    vector<int> dists(n + 1, -1);
    vector<int> hullDmg(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;

        paths[a].push_back({b, t, h});
        paths[b].push_back({a, t, h});
    }

    int A, B;
    cin >> A >> B;

    auto qcomp = [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<1>(b) > get<1>(a);
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(qcomp)> bfsq(qcomp);

    bfsq.push({A, 0, 0});
    dists[A] = 0;

    while (!bfsq.empty()) {
        tuple<int, int, int> curTuple = bfsq.top();
        int cur = get<0>(curTuple);
        int dist = get<1>(curTuple);
        int damage = get<2>(curTuple);
        bfsq.pop();

        for (tuple<int, int, int> path : paths[cur]) {
            int to = get<0>(path);
            int toDist = get<1>(path) + dist;
            int toDmg = get<2>(path) + damage;

            if (((dists[to] == -1 || dists[to] > toDist) || (hullDmg[to] == -1 || hullDmg[to] > toDmg)) && toDmg < k) {
                dists[to] = dists[to] == -1 ? toDist : std::min(dists[to], toDist);
                hullDmg[to] = hullDmg[to] == -1 ? toDmg : std::min(hullDmg[to], toDmg);
                bfsq.push({to, toDist, toDmg});
            }
        }
    }

    cout << dists[B] << endl;
} 