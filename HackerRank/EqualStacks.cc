#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n1, n2, n3, h1 = 0, h2 = 0, h3 = 0;
    cin >> n1 >> n2 >> n3;
    deque<int> s1, s2, s3;

    for (int i = 0; i < n1; i++)
    {
        int h;
        cin >> h;
        s1.push_back(h);
        h1 += h;
    }

    for (int i = 0; i < n2; i++)
    {
        int h;
        cin >> h;
        s2.push_back(h);
        h2 += h;
    }

    for (int i = 0; i < n3; i++)
    {
        int h;
        cin >> h;
        s3.push_back(h);
        h3 += h;
    }

    while (h1 != h2 || h1 != h3 || h2 != h3)
    {
        if (h1 > h2 && h1 > h3) // h1 is tallest
        {
            h1 -= s1.front();
            s1.pop_front();
        }
        else if (h2 > h3) // h2 is tallest
        {
            h2 -= s2.front();
            s2.pop_front();
        }
        else
        {
            h3 -= s3.front();
            s3.pop_front();
        }
    }

    cout << h1;
}