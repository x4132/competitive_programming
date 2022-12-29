#include <bits/stdc++.h>

using namespace std;

struct barn {
    long long bales;
    int num;
    long long disparity;
    vector<barn *> children;
};

vector<barn *> barns;
vector<tuple<int, int, long long>> changes;
int N;
long long avg = 0;

int getDisparity(barn *cur, barn *root) {
    long long sum = cur->bales - avg;
    for (auto i : cur->children) {
        if (i != root) {
            sum += getDisparity(i, cur);
        }
    }

    cur->disparity = sum;
    return sum;
}

void solve(barn *cur, barn *root) {
    // disparity > 0
    for (auto i : cur->children) {
        if (i == root) {
            continue;
        }

        if (i->disparity >= 0) {
            solve(i, cur);
        }

        if (i->disparity > 0) {
            changes.push_back({i->num, cur->num, i->disparity});
        }
    }

    // disparity < 0
    for (auto i : cur->children) {
        if (i->disparity < 0 && i != root) {
            changes.push_back({cur->num, i->num, -i->disparity});
            solve(i, cur);
        }
    }
}

int main(void) {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    barns = vector<barn *>(N);

    for (int i = 0; i < N; i++) {
        int toAdd;
        cin >> toAdd;
        avg += toAdd;
        barns[i] = new barn();
        barns[i]->num = i;
        barns[i]->bales = toAdd;
        barns[i]->children = vector<barn *>();
    }

    avg /= N;

    for (int i = 0; i < N - 1; i++) {
        int b1, b2;
        cin >> b1 >> b2;
        b1--;
        b2--;
        barns[b1]->children.push_back(barns[b2]);
        barns[b2]->children.push_back(barns[b1]);
    }

    getDisparity(barns[0], barns[0]);

    solve(barns[0], barns[0]);

    cout << changes.size() << "\n";
    for (auto [f, t, b] : changes) {
        cout << f + 1 << " " << t + 1 << " " << b << "\n";
    }
}