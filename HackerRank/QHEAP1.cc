#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;
    
    set<int> heap;

    for (int i = 0; i < Q; i++)
    {
        int query;
        cin >> query;
        if (query == 1) {
            int toAdd;
            cin >> toAdd;
            heap.insert(toAdd);
        } else if (query == 2) {
            int toRemove;
            cin >> toRemove;
            heap.erase(toRemove);
        } else {
            cout << (int) *heap.begin() << endl;
        }
    }
}
