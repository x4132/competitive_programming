#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, queryType, maxPtr = 0;
    vector<int> elements;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> queryType;
        switch (queryType)
        {
        case 1:
            int x;
            cin >> x;

            if (maxPtr < elements.size() && elements[maxPtr] < x)
            {
                maxPtr = elements.size();
            }

            elements.push_back(x);
            break;
        case 2:
            elements.pop_back();
            if (maxPtr == elements.size())
            {
                maxPtr = 0;
                for (int i = 1; i < elements.size(); i++)
                {
                    if (elements[maxPtr] < elements[i])
                    {
                        maxPtr = i;
                    }
                }
            }
            break;
        case 3:
            cout << elements[maxPtr] << "\n";
            break;
        }
    }
}