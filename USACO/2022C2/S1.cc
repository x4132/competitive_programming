#include <bits/stdc++.h>

using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    unordered_map<char, int> charToLetter;

    for (int i = 0; i < 52; i++) {
        charToLetter[alpha[i]] = i;
    }

    for (int cases = 0; cases < T; cases++) {
        string start, end;

        cin >> start >> end;

        vector<int> adj(52, -1);
        
        for (int i = 0; i < start.size(); i++) {
            if (adj[charToLetter[start[i]]] == -1) {
                adj[charToLetter[start[i]]] = charToLetter[end[i]];
            } else if (adj[charToLetter[start[i]]] != charToLetter[end[i]]) {
                cout << -1 << endl;
                return 0;
            }
        }

        int totalEdges = 0;
        for (int i = 0; i < 52; i++) {
            if (adj[i] != -1) {
                totalEdges++;
            }
        }

        if (totalEdges == 52) {
            cout << -1 << endl;
            return 0;
        }

        vector<bool> visited(52, false);

        for (int i = 0; i < 52; i++) {
            
        }
    }
}