#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<bool> restaurants(N, false);
    for (int i = 0; i < M; i++) {
        int isPho;
        cin >> isPho;
        restaurants[isPho] = true;
    }

    vector<vector<int>> paths(N);
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }


}