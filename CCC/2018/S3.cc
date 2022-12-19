#include <bits/stdc++.h>

using namespace std;

enum nodeType
{
    wall,
    blank,
    camera,
    start,
    left,
    right,
    up,
    down
};

struct node
{
    nodeType type;
    pair<int, int> to;
    bool visited;
    int dist;

    int x;
    int y;
};

int main(void)
{
    int N, M;

    cin >> N >> M;

    vector<node> emptySpots;
    vector<node> cameras;
    vector<vector<node>> grid(N, vector<node>(M));
    node start;

    unordered_map<char, nodeType> charToNode({{'W', nodeType::wall}, {'.', nodeType::blank}, {'C', nodeType::camera}, {'S', nodeType::start}, {'L', nodeType::left}, {'R', nodeType::right}, {'U', nodeType::up}, {'D', nodeType::down}});

    for (int y = 0; y < N; y++)
    {
        string row;
        cin >> row;

        for (int x = 0; x < M; x++)
        {
            node toAdd;
            toAdd.type = charToNode[row[x]];
            toAdd.visited = false;
            toAdd.dist = -1;
            toAdd.x = x;
            toAdd.y = y;
            toAdd.to = {-1, -1};

            if (toAdd.type == nodeType::start)
            {
                start = toAdd;
            }
            else if (toAdd.type == nodeType::camera)
            {
                cameras.push_back(toAdd);
            }
            else if (toAdd.type == nodeType::blank)
            {
                emptySpots.push_back(toAdd);
            }

            grid[y][x] = toAdd;
        }
    }

    for (int c = 0; c < cameras.size(); c++)
    {
        node cur = cameras[c];

        int pos = cur.x;
        while (grid[cur.y][pos].type != nodeType::wall)
        {
            if (grid[cur.y][pos].type != nodeType::up && grid[cur.y][pos].type != nodeType::down && grid[cur.y][pos].type != nodeType::left && grid[cur.y][pos].type != nodeType::right)
            {
                node& toAdd = grid[cur.y][pos];
                toAdd.type = nodeType::wall;
            }

            pos++;
        }

        pos = cur.x - 1;
        while (grid[cur.y][pos].type != nodeType::wall)
        {
            if (grid[cur.y][pos].type != nodeType::up && grid[cur.y][pos].type != nodeType::down && grid[cur.y][pos].type != nodeType::left && grid[cur.y][pos].type != nodeType::right)
            {
                node& toAdd = grid[cur.y][pos];
                toAdd.type = nodeType::wall;
            }

            pos--;
        }

        pos = cur.y + 1;
        while (grid[pos][cur.x].type != nodeType::wall)
        {
            if (grid[pos][cur.x].type != nodeType::up && grid[pos][cur.x].type != nodeType::down && grid[pos][cur.x].type != nodeType::left && grid[pos][cur.x].type != nodeType::right)
            {
                node& toAdd = grid[pos][cur.y];
                toAdd.type = nodeType::wall;
            }

            pos++;
        }

        pos = cur.y - 1;
        while (grid[pos][cur.x].type != nodeType::wall)
        {
            if (grid[pos][cur.x].type != nodeType::up && grid[pos][cur.x].type != nodeType::down && grid[pos][cur.x].type != nodeType::left && grid[pos][cur.x].type != nodeType::right)
            {
                node& toAdd = grid[pos][cur.y];
                toAdd.type = nodeType::wall;
            }

            pos--;
        }
    }

    queue<node> bfsq;
    if (grid[start.y][start.x].type != nodeType::wall)
    {
        start.dist = 0;
        bfsq.push(start);
    }

    while (!bfsq.empty())
    {
        node cur = bfsq.front();
        bfsq.pop();

        vector<node> toCache;
        while (cur.type == nodeType::up || cur.type == nodeType::down || cur.type == nodeType::left || cur.type == nodeType::right)
        {
            if (cur.to != std::make_pair(-1, -1))
            {
                cur = grid[cur.to.first][cur.to.second];
                break;
            }

            switch (cur.type)
            {
            case nodeType::up:
                cur = grid[cur.y + 1][cur.x];
                break;
            case nodeType::down:
                cur = grid[cur.y - 1][cur.x];
                break;
            case nodeType::left:
                cur = grid[cur.y][cur.x - 1];
                break;
            case nodeType::right:
                cur = grid[cur.y][cur.x + 1];
                break;
            }

            cur.visited = true;

            toCache.push_back(cur);
        }

        for (node i : toCache)
        {
            grid[i.x][i.y].to = {cur.x, cur.y};
        }

        if (grid[cur.y][cur.x + 1].visited == false && grid[cur.y][cur.x + 1].type != nodeType::wall)
        {
            grid[cur.y][cur.x + 1].visited = true;
            grid[cur.y][cur.x + 1].dist = cur.dist + 1;
            bfsq.push(grid[cur.y][cur.x + 1]);
        }

        if (grid[cur.y][cur.x - 1].visited == false && grid[cur.y][cur.x - 1].type != nodeType::wall)
        {
            grid[cur.y][cur.x - 1].visited = true;
            grid[cur.y][cur.x - 1].dist = cur.dist + 1;
            bfsq.push(grid[cur.y][cur.x - 1]);
        }

        if (grid[cur.y + 1][cur.x].visited == false && grid[cur.y + 1][cur.x].type != nodeType::wall)
        {
            grid[cur.y + 1][cur.x].visited = true;
            grid[cur.y + 1][cur.x].dist = cur.dist + 1;
            bfsq.push(grid[cur.y + 1][cur.x]);
        }

        if (grid[cur.y - 1][cur.x].visited == false && grid[cur.y - 1][cur.x].type != nodeType::wall)
        {
            grid[cur.y - 1][cur.x].visited = true;
            grid[cur.y - 1][cur.x].dist = cur.dist + 1;
            bfsq.push(grid[cur.y - 1][cur.x]);
        }
    }

    for (node i : emptySpots)
    {
        node cur = grid[i.y][i.x];

        cout << cur.dist << endl;
    }
}