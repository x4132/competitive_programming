#include <bits/stdc++.h>

using namespace std;

int prefixQuery(int start, int numDigits, vector<int> prefixes) {
    if (numDigits == 0) {
        return 0;
    }

    int output = prefixes[min(start + numDigits, (int) prefixes.size()) - 1] - (start == 0 ? 0 : prefixes[min((int) prefixes.size(), start) - 1]);
    if (start + numDigits > prefixes.size()) {
        output += prefixes[(start + numDigits - prefixes.size()) - 1];
    }

    return output;
}

int main(void) {
    string in;
    cin >> in;
    vector<int> sumA(in.size());
    vector<int> sumB(in.size());
    vector<int> sumC(in.size());

    int prefixA = 0;
    int prefixB = 0;
    int prefixC = 0;

    int Astart = -1;

    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 'A') {
            prefixA++;
        } else if (in[i] == 'B') {
            prefixB++;
        } else {
            prefixC++;
        }

        sumA[i] = prefixA;
        sumB[i] = prefixB;
        sumC[i] = prefixC;

        if (Astart == -1 && in[i] == 'A') {
            Astart = i;
        }
    }

    int countA = sumA[in.size() - 1];
    int countB = sumB[in.size() - 1];
    int countC = sumC[in.size() - 1];

    if (Astart == -1) {
        Astart = 0;
    }

    int minMoves = in.size();

    string in2 = in + in;
    for (int i = 0; i < in.size(); i++) {
        int Na = prefixQuery(i, countA, sumB) + prefixQuery(i, countA, sumC);
        int Nb = prefixQuery(i + countA, countB, sumA) + prefixQuery(i + countA, countB, sumC); // b first
        int Nc = prefixQuery(i + countA, countC, sumA) + prefixQuery(i + countA, countC, sumB); // c first

        int Sab = prefixQuery(i, countA, sumB);
        int Sba = prefixQuery(i + countA, countB, sumA);
        int Sca = prefixQuery(i + countA, countC, sumA);

        minMoves = min(minMoves, Na + Nb - min(Sab, Sba));
        minMoves = min(minMoves, Na + Nc - min(Sab, Sca));
    }

    cout << minMoves << endl;
}