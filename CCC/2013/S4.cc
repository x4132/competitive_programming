#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> taller(N, vector<int>(N));

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        taller[x - 1].push_back(y - 1);
    }

    int p, q;
    cin >> p >> q;

    queue<int> hasLarger;
    hasLarger.push(p);

    bool qTaller = false;
    bool pTaller = false;

    vector<bool> visited(N, false);
    while (!hasLarger.empty()) {
        int cur = hasLarger.front();
        hasLarger.pop();

        if (cur == q) {
            qTaller = true;
            break;
        }

        if (!visited[cur]) {
            visited[cur] = true;

            for (int i : taller[cur]) {
                if (!visited[i]) {
                    hasLarger.push(i);
                }
            }
        }
    }

    hasLarger = {};
    visited.assign(visited.size(), false);
    hasLarger.push(q);
    while (!hasLarger.empty()) {
        int cur = hasLarger.front();
        hasLarger.pop();

        if (cur == p) {
            pTaller = true;
            break;
        }

        if (!visited[cur]) {
            visited[cur] = true;

            for (int i : taller[cur]) {
                if (!visited[i]) {
                    hasLarger.push(i);
                }
            }
        }
    }

    if (pTaller){
        cout << "yes" << "\n";
    } else if (qTaller) {
        cout << "no" << "\n";
    } else {
        cout << "unknown" << "\n";
    }

    return 0;
}