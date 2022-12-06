#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int K;
    cin >> K;
    stack<int> numbers;

    for (int i = 0; i < K; i++)
    {
        int toAdd;
        cin >> toAdd;
        if (toAdd == 0)
        {
            if (!numbers.empty())
            {
                numbers.pop();
            }
        }
        else
        {
            numbers.push(toAdd);
        }
    }

    int sum = 0;
    while (!numbers.empty()) {
        sum += numbers.top();
        numbers.pop();
    }

    cout << sum << endl;
}