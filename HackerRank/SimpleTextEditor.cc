#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int q;
    cin >> q;
    string s = "";

    stack<tuple<int, string>> history;

    for (int i = 0; i < q; i++)
    {
        int query;
        cin >> query;
        switch (query)
        {
        case 1:
        {
            string toAppend;
            cin >> toAppend;
            history.push(tuple<int, string>{1, toAppend});
            s.append(toAppend);
            break;
        }
        case 2:
        {
            int toRemove;
            cin >> toRemove;
            history.push(tuple<int, string>{2, s.substr(s.size() - toRemove, toRemove)});
            s.erase(s.size() - toRemove);
            break;
        }
        case 3:
        {
            int toPrint;
            cin >> toPrint;
            cout << s[toPrint - 1] << endl;
            break;
        }
        case 4:
        {
            tuple<int, string> prev = history.top();
            history.pop();
            if (get<0>(prev) == 1) {
                s.erase(s.size() - get<1>(prev).size());
            } else {
                s.append(get<1>(prev));
            }
        }
        }
    }
}
