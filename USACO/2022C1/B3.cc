#include <bits/stdc++.h>

using namespace std;

struct caseT
{
    vector<int> input;
    int output;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    for (int cases1knsfdionfnsdf = 0; cases1knsfdionfnsdf < T; cases1knsfdionfnsdf++)
    {
        int N, M;

        cin >> N >> M;

        if (N <= 2 || M <= 2)
        {
            unordered_map<int, pair<int, int>> casemap;

            vector<caseT> cases(M);

            for (int i = 0; i < M; i++) // too lazy to flush so i just parse all of it
            {
                string bitstr;
                int output;

                cin >> bitstr >> output;

                caseT toAdd;

                for (int x = 0; x < bitstr.size(); x++)
                {
                    toAdd.input.push_back(bitstr[x] - '0');
                }

                toAdd.output = output;

                cases[i] = toAdd;
            }

            bool globalLie = false;
            for (int i = 0; i < M; i++)
            {
                caseT cur = cases[i];

                bool lie = true;
                int lies = 0;
                for (int bit = 0; bit < cur.input.size(); bit++)
                {
                    if (casemap.find(bit) == casemap.end())
                    {
                        casemap[bit] = {-1, -1};
                    }

                    if (cur.input[bit] == 1)
                    {
                        if (casemap[bit].first == -1)
                        {
                            casemap[bit].first = cur.output;
                            lie = false;
                        }
                        else if (casemap[bit].first == cur.output)
                        {
                            lie = false;
                        }
                        else
                        {
                            lies++;
                        }
                    }
                    else
                    {
                        if (casemap[bit].second == -1)
                        {
                            casemap[bit].second = cur.output;
                            lie = false;
                        }
                        else if (casemap[bit].second == cur.output)
                        {
                            lie = false;
                        }
                        else
                        {
                            lies++;
                        }
                    }
                }

                if (lie)
                {
                    globalLie = true;
                    break;
                }
            }

            if (globalLie)
            {
                cout << "LIE" << endl;
            }
            else
            {
                cout << "OK" << endl;
            }
        }
        else
        {
            unordered_map<string, int> combinations;

            for (int i = 0; i < M; i++) {
                string combstr;
                int combint;
                cin >> combstr >> combint;

                if (combinations.find(combstr) != combinations.end() && (*combinations.find(combstr)).second != combint) {
                    cout << "LIE" << endl;
                    break;
                }
            }

            cout << "OK" << endl;
        }
    }
}