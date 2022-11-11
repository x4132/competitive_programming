#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int q;
    cin >> q;
    
    for (int graphs = 0; graphs < q; graphs++) {
        int n, m;
        cin >> n >> m;
        vector<unordered_set<int>> nodes(n);
        vector<int> outputDist(n, -1);
        vector<bool> visited(n, false);

        for (int queries = 0; queries < m; queries++) {
            int start, end;
            cin >> start >> end;
            nodes[start - 1].insert(end - 1);
            nodes[end - 1].insert(start - 1);
        }

        queue<tuple<int, int>> bfsq;
        int startPos;
        cin >> startPos;
        startPos--;
        bfsq.push({startPos, 6});

        while (!bfsq.empty()) {
            int curr = get<0>(bfsq.front());
            int dist = get<1>(bfsq.front());
            bfsq.pop();

            for (int node : nodes[curr]) {
                if (!visited[node]) {
                    visited[node] = true;
                    bfsq.push({node, dist + 6});
                    outputDist[node] = dist;
                }
            }
        }

        for (int i = 0; i < outputDist.size() - 1; i++) {
            if (i != startPos) {
                cout << outputDist[i] << " ";
            }
        }
        cout << outputDist[outputDist.size() - 1] << endl;
    }
}