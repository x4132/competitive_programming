#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<int> vertices;
vector<int> vSums;

int prefixQuery(int start, int len) { // adds circularity
    int output = vSums[min(start + len, C) - 1] - (start > 0 ? vSums[start - 1] : 0);
    if (start + len >= C) {
        int remainLen = start + len - C;
        output += vSums[remainLen];
    }

    return output;
}

int main(void) {
    cin >> N >> C;
    vertices.resize(C);
    fill(vertices.begin(), vertices.end(), 0);

    for (int i = 0; i < N; i++) {
        int toAdd;
        cin >> toAdd;
        vertices[toAdd]++;
    }

    // generate a prefix array
    int prefix = 0;
    vSums.resize(C);
    fill(vSums.begin(), vSums.end(), 0);
    for (int i = 0; i < C; i++) {
        prefix += vertices[i];

        vSums[i] = prefix;
    }

    long long totalTriangles = (N * (N - 1) * (N - 2)) / 6;
    for (int i = 0; i < C; i++) {
        int totalIn = prefixQuery(i + 1, C / 2);

        totalTriangles -= vertices[i] * (totalIn * totalIn - 1) / 2;
        totalTriangles -= totalIn * (vertices[i] * vertices[i] - 1) / 2;
        totalTriangles -= vertices[i] * vertices[i] - 1 * vertices[i] - 2 / 6;
    }

    if (C % 2 == 0) {
        for (int i = 0; i < (C / 2); i++) {
            totalTriangles += vertices[i] * vertices[i] - 1 / 2 * vertices[C / 2];
            totalTriangles += vertices[C / 2] * vertices[C / 2] - 1 / 2 * vertices[i];
        }
    }

    cout << totalTriangles << endl;
}