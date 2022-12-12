#include <bits/stdc++.h>

using namespace std;

struct node {
    unordered_set<int> children;
    bool visited;
    bool isPho;
    int num;
    int dist;
};

map<int, node> nodes;

bool dfs(node &subtree) {
    bool hasPho = false;
    subtree.visited = true;

    hasPho = subtree.isPho;

    for (auto i = subtree.children.begin(); i != subtree.children.end();) {
        if (!nodes[*i].visited) {
            bool result = dfs(nodes[*i]);

            if (result) {
                hasPho = true;
                i++;
            } else {
                nodes.erase(*i);
                i = subtree.children.erase(i);
            }
        } else {
            i++;
        }
    }

    return hasPho;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    node init = {{}, false, false, 0, 0};
    vector<int> phoNodes;

    for (int i = 0; i < N; i++) {
        nodes[i] = init;
        nodes[i].num = i;
    }

    for (int i = 0; i < M; i++) {
        int isPho;
        cin >> isPho;
        nodes[isPho].isPho = true;
        phoNodes.push_back(isPho);
    }

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;

        nodes[a].children.insert(b);
        nodes[b].children.insert(a);
    }

    dfs(nodes[0]);

    for (auto i = nodes.begin(); i != nodes.end(); i++) {
        (*i).second.dist = 0;
        (*i).second.visited = false;
    }

    stack<int> nodestk;
    nodestk.push(phoNodes[0]);
    nodes[phoNodes[0]].dist = 0;

    int maxIndex = 0;
    int maxDist = 0;

    while (!nodestk.empty()) {
        node cur = nodes[nodestk.top()];
        nodestk.pop();

        if (cur.dist > maxDist) {
            maxIndex = cur.num;
            maxDist = cur.dist;
        }

        for (int a : cur.children) {
            node &i = nodes[a];
            if (!i.visited) {
                i.visited = true;
                i.dist = cur.dist + 1;

                nodestk.push(i.num);
            }
        }
    }

    for (; !nodestk.empty(); nodestk.pop())
        ;

    for (auto i = nodes.begin(); i != nodes.end(); i++) {
        (*i).second.dist = 0;
        (*i).second.visited = false;
    }

    nodestk.push(maxIndex);
    nodes[maxIndex].dist = 0;

    maxIndex = 0;
    maxDist = 0;

    while (!nodestk.empty()) {
        node cur = nodes[nodestk.top()];
        nodestk.pop();

        if (cur.dist > maxDist) {
            maxIndex = cur.num;
            maxDist = cur.dist;
        }

        for (int a : cur.children) {
            node &i = nodes[a];
            if (!i.visited) {
                i.visited = true;
                i.dist = cur.dist + 1;

                nodestk.push(i.num);
            }
        }
    }

    cout << 2 * (nodes.size() - 1) - maxDist << endl;
}