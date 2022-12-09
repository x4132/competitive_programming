#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> taller(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        taller[x - 1].push_back(y - 1);
    }

    int p, q;
    cin >> p >> q;
    p--;
    q--;

    queue<int> hasShorter;
    hasShorter.push(p);

    bool qTaller = false;
    bool pTaller = false;

    vector<bool> visited(N, false);
    while (!hasShorter.empty()) {
        int cur = hasShorter.front();
        hasShorter.pop();

        if (cur == q) {
            pTaller = true;
            break;
        }

        if (!visited[cur]) {
            visited[cur] = true;

            for (int i : taller[cur]) {
                if (!visited[i]) {
                    hasShorter.push(i);
                }
            }
        }
    }

    hasShorter = {};
    visited.assign(visited.size(), false);
    hasShorter.push(q);
    while (!hasShorter.empty()) {
        int cur = hasShorter.front();
        hasShorter.pop();

        if (cur == p) {
            qTaller = true;
            break;
        }

        if (!visited[cur]) {
            visited[cur] = true;

            for (int i : taller[cur]) {
                if (!visited[i]) {
                    hasShorter.push(i);
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