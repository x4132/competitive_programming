#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int T, G;

    cin >> T >> G;

    int teams[5] = {0};
    bool toGoAgainst[5][5] = {true};

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

    for (int i = 1; i < 5; i++) {
        for (int x = i; x < 5; x++) {
            if (toGoAgainst[i][x]) {
                
            }
        }
    }
}

void scenario(&vector<vector<int>> scenarios, bool toGoAgainst[][]) {

}