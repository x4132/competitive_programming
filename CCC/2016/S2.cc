#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int qtype, N;
    cin >> qtype >> N;

    // memory efficiency? what memory efficiency?
    priority_queue<int> maxDmoj; 
    priority_queue<int, vector<int>, greater<int>> minDmoj;

    priority_queue<int> maxPeg;
    priority_queue<int, vector<int>, greater<int>> minPeg;

    for (int i = 0; i < N; i++) {
        int toAdd;
        cin >> toAdd;

        maxDmoj.push(toAdd);
        minDmoj.push(toAdd);
    }

    for (int i = 0; i < N; i++) {
        int toAdd;
        cin >> toAdd;

        maxPeg.push(toAdd);
        minPeg.push(toAdd);
    }

    int totalScore = 0;
    for (int i = 0; i < N; i++) {
        int dmoj, peg;

        if (qtype == 2) {
            if (maxDmoj.top() > maxPeg.top()) {
                dmoj = maxDmoj.top();
                maxDmoj.pop();
                peg = minPeg.top();
                minPeg.pop();
            } else {
                peg = maxPeg.top();
                maxPeg.pop();
                dmoj = minDmoj.top();
                minDmoj.pop();
            }
        } else {
            dmoj = minDmoj.top();
            minDmoj.pop();
            peg = minPeg.top();
            minPeg.pop();
        }

        totalScore += max(dmoj, peg);
    }

    cout << totalScore << endl;
}