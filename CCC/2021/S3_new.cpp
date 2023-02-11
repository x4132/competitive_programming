#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    ll pos;
    ll dist;
    ll speed;
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    auto nodecomp = [](node a, node b) { return greater<ll>{}(a.pos, b.pos); };
    set<node, decltype(nodecomp)> nodeList;
    unordered_map<ll, vector<node>> startList;
    unordered_map<ll, vector<node>> endList;

    for (int i = 0; i < n; i++) {
        ll pos, dist, speed;

        cin >> pos >> speed >> dist;

        node toAdd;
        toAdd.pos = pos;
        toAdd.speed = speed;
        toAdd.dist = dist;

        ll startPos = max((long long) 0, pos - dist);
        ll endPos = pos + dist;

        startList.insert(startPos, {});
        endList.insert(endPos, {});

        startList[startPos].push_back(toAdd);
        endList[endPos].push_back(toAdd);
        nodeList.emplace(toAdd);
    }

    ll leftSum = 0, rightSum = 0;

    // initial rightsum calculations
    for (int i = 0; i < nodeList.end()->pos; i++) {
        
    }
}