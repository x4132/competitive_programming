#include <bits/stdc++.h>

using namespace std;

struct rect {
    int x1;
    int x2;
    int y1;
    int y2;
    int t;
};

int main(void) {
    int N, T;
    cin >> N >> T;

    int maxX = 0, maxY = 0;

    vector<rect> rects(N);
    vector<int> xLen;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2, t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;

        maxX = max(max(maxX, x1), x2);
        maxY = max(max(maxY, y1), y2);

        rect init;
        init.x1 = x1;
        init.x2 = x2;
        init.y1 = y1;
        init.y2 = y2;
        init.t = t;

        rects[i] = init;
    }

    vector<vector<int>> queries(maxY);


    for (auto a : rects) {
        for (int i = a.y1; i < a.y2; i++) {
            queries[i][a.x1] += a.t;
            queries[i][a.x2] -= a.t;
        }
    }

    long output = 0;
    for (int y = 0; y < queries.size(); y++) {
        int t = 0;
        for (int x = 0; x < queries[0].size(); x++) {
            t += queries[y][x];
            if (t >= T) {
                output++;
            }
        }
    }

    cout << output << endl;
}