#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    string winner;
    int winVal = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string curBidder;
        int curBid;
        cin >> curBidder >> curBid;
        if (curBid > winVal) {
            winner = curBidder;
            winVal = curBid;
        }
    }

    cout << winner;
}