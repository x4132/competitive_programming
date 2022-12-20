#include <bits/stdc++.h>

using namespace std;

enum nodeType { wall, blank, camera, start, left, right, up, down };

struct node {
    nodeType type;
    pair<int, int> to;
    bool visited;
    bool underWatch;
    int dist;

    int x;
    int y;
};

bool isConveyor(node *n) {
    if (n->type == nodeType::up || n->type == nodeType::down ||
        n->type == nodeType::left || n->type == nodeType::right) {
        return true;
    }

    return false;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    unordered_map<char, nodeType> ctNT({{'W', nodeType::wall},
                                        {'.', nodeType::blank},
                                        {'C', nodeType::camera},
                                        {'S', nodeType::start},
                                        {'L', nodeType::left},
                                        {'R', nodeType::right},
                                        {'U', nodeType::up},
                                        {'D', nodeType::down}});

    vector<vector<node *>> grid(N, vector<node *>(M));

    vector<node *> cameras;
    vector<node *> blanks;

    node *start;

    for (int y = 0; y < N; y++) {
        string row;

        cin >> row;

        for (int x = 0; x < M; x++) {
            node *toAdd = new node();
            toAdd->type = ctNT[row[x]];
            toAdd->to = {-1, -1};
            toAdd->visited = false;
            toAdd->underWatch = false;
            toAdd->dist = -1;

            toAdd->x = x;
            toAdd->y = y;

            grid[y][x] = toAdd;
            if (toAdd->type == nodeType::camera) {
                cameras.push_back(toAdd);
            } else if (toAdd->type == nodeType::blank) {
                cameras.push_back(toAdd);
            } else if (toAdd->type == nodeType::start) {
                start = toAdd;
            }
        }
    }

    for (auto c : cameras) {
        int pos = c->x;

        while (grid[c->y][pos]->type != nodeType::wall) {
            if (!isConveyor(grid[c->y][pos])) {
                grid[c->y][pos]->underWatch = true;
            }

            pos++;
        }

        pos = c->x - 1;
        while (grid[c->y][pos]->type != nodeType::wall) {
            if (!isConveyor(grid[c->y][pos])) {
                grid[c->y][pos]->underWatch = true;
            }

            pos--;
        }

        pos = c->y;
        while (grid[pos][c->x]->type != nodeType::wall) {
            if (!isConveyor(grid[pos][c->x])) {
                grid[pos][c->x]->underWatch = true;
            }

            pos++;
        }

        pos = c->y - 1;
        while (grid[pos][c->x]->type != nodeType::wall) {
            if (!isConveyor(grid[pos][c->x])) {
                grid[pos][c->x]->underWatch = true;
            }

            pos--;
        }
    }

    queue<node *> bfsq;
    if (!start->underWatch) {
        start->dist = 0;
        start->visited = true;
        bfsq.push(start);
    }

    while (!bfsq.empty()) {
        node *cur = bfsq.front();
        bfsq.pop();

        switch(cur->type) {
            case nodeType::blank:
            case nodeType::start:
                if (!grid[cur->y][cur->x + 1]->visited && !grid[cur->y][cur->x + 1]->underWatch && grid[cur->y][cur->x + 1]->type != nodeType::wall) {
                    grid[cur->y][cur->x + 1]->visited = true;
                    grid[cur->y][cur->x + 1]->dist = cur->dist + 1;
                    bfsq.push(grid[cur->y][cur->x + 1]);
                }
                break;
        }
    }

    return 0;
}