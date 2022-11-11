#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int cases = 0; cases < t; cases++) {
        int n, m;
        cin >> n >> m;
        vector<vector<tuple<int, int>>> nodes(n);
        vector<int> outputDist(n, -1);

        for (int queries = 0; queries < m; queries++) {
            int x, y, r;
            cin >> x >> y >> r;

            nodes[x - 1].push_back({y - 1, r});
            nodes[y - 1].push_back({x - 1, r});
        }

        int s;
        cin >> s;
        s--;

        auto bfscomp = [](tuple<int, int> a, tuple<int, int> b) {
            if (get<1>(b) > get<1>(a)) {
                return true;
            } else {
                return false;
            }
        };
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, decltype(bfscomp)> bfsq(bfscomp);
        bfsq.push({s, 0});

        while (!bfsq.empty()) {
            int cur = get<0>(bfsq.top());
            int dist = get<1>(bfsq.top());
            bfsq.pop();

            for (tuple<int, int> node : nodes[cur]) {
                int to = get<0>(node);
                int toDist = get<1>(node);

                if (outputDist[to] == -1 || outputDist[to] > dist + toDist) {
                    outputDist[to] = dist + toDist;
                    bfsq.push({to, dist + toDist});
                }
            }
        }

        for (int i = 0; i < (int) outputDist.size() - 1; i++) {
            if (i != s) {
                cout << outputDist[i] << " ";
            }
        }

        cout << outputDist[outputDist.size() - 1] << endl;
    }
}