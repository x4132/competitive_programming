#include <bits/stdc++.h>

using namespace std;

void scenario(int t1s, int t2s, vector<vector<int>> &scenarios, vector<vector<bool>> toGoAgainst, vector<int> teams, int matches);

int main(void)
{
    int T, G;

    cin >> T >> G;

    vector<int> teams(5, 0);
    vector<vector<bool>> toGoAgainst(5, vector<bool>(5, true));

    for (int i = 1; i < 5; i++)
    {
        toGoAgainst[i][i] = false;
    }

    for (int i = 0; i < G; i++)
    {
        int A, B, Sa, Sb;

        cin >> A >> B >> Sa >> Sb;

        toGoAgainst[A][B] = false;
        toGoAgainst[B][A] = false;

        if (Sa == Sb)
        {
            teams[A]++;
            teams[B]++;
        }
        else if (Sa > Sb)
        {
            teams[A] += 3;
        }
        else
        {
            teams[B] += 3;
        }
    }

    vector<vector<int>> scenarios;

    for (int i = 1; i < 5; i++)
    {
        bool flag = false;
        for (int x = i + 1; x < 5; x++)
        {
            if (toGoAgainst[i][x])
            {
                teams[i] += 3;
                scenario(i, x, scenarios, toGoAgainst, teams, G);
                teams[i] -= 3;
                teams[x] += 3;
                scenario(i, x, scenarios, toGoAgainst, teams, G);
                teams[x] -= 2;
                teams[i] += 1;
                scenario(i, x, scenarios, toGoAgainst, teams, G);
                flag = true;
                break;
            }
        }

        if (flag)
        {
            break;
        }
    }

    int totalWinCases = 0;
    for (vector<int> scenario : scenarios)
    {
        int maxIndex = 1;
        bool tie = false;
        for (int i = 1; i < 5; i++)
        {
            if (scenario[maxIndex] == scenario[i])
            {
                tie = true;
            }
            else if (scenario[maxIndex] < scenario[i])
            {
                tie = false;
                maxIndex = i;
            }
        }

        if (maxIndex == T && !tie)
        {
            totalWinCases++;
        }
    }

    cout << totalWinCases;
}

void scenario(int t1, int t2, vector<vector<int>> &scenarios, vector<vector<bool>> toGoAgainst, vector<int> teams, int matches)
{
    toGoAgainst[t1][t2] = false;
    toGoAgainst[t2][t1] = false;

    bool flag = true;
    for (int i = 1; i < 5; i++)
    {
        for (int x = i + 1; x < 5; x++)
        {
            if (toGoAgainst[i][x])
            {
                flag = false;
                toGoAgainst[i][x] = false;
                toGoAgainst[x][i] = false;
                teams[i] += 3;
                scenario(i, x, scenarios, toGoAgainst, teams, matches + 1);
                teams[i] -= 3;
                teams[x] += 3;
                scenario(i, x, scenarios, toGoAgainst, teams, matches + 1);
                teams[x] -= 2;
                teams[i] += 1;
                scenario(i, x, scenarios, toGoAgainst, teams, matches + 1);
            }
        }
    }

    if (flag)
    {
        scenarios.push_back(teams);
    }
}