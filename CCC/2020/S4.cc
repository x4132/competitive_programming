#include <bits/stdc++.h>

using namespace std;

int prefixQuery(int start, int numDigits, vector<int> prefixes) {
    if (numDigits == 0) {
        return 0;
    }
    return prefixes[start + numDigits - 1] - (start == 0 ? 0 : prefixes[start - 1]);
}

int main(void) {
    string in;
    cin >> in;
    in = in + in;
    vector<int> prefixBs(in.size());
    vector<int> prefixAs(in.size());
    vector<int> prefixCs(in.size());

    int prefixB = 0;
    int prefixA = 0;
    int prefixC = 0;
    int Astart = -1;

    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 'B') {
            prefixB++;
        } else if (in[i] == 'A') {
            prefixA++;
        } else if (in[i] == 'C') {
            prefixC++;
        }

        prefixBs[i] = prefixB;
        prefixAs[i] = prefixA;
        prefixCs[i] = prefixC;

        if (Astart == -1 && in[i] == 'A') {
            Astart = i;
        }
    }

    int Acount = prefixAs[in.size() - 1] / 2;
    int Bcount = prefixBs[in.size() - 1] / 2;
    int Ccount = prefixCs[in.size() - 1] / 2;

    if (Astart == -1) {
        Astart = 0;
    }

    int minMoves = in.size();
    for (int i = 0; i <= in.size() - Acount - Bcount; i++) {
        int Na = prefixQuery(i, Acount, prefixBs) + prefixQuery(i, Acount, prefixCs);
        int Nb = prefixQuery(i + Acount, Bcount, prefixAs) + prefixQuery(i + Acount, Bcount, prefixCs);
        int Nc = prefixQuery(i + Acount, Ccount, prefixAs) + prefixQuery(i + Acount, Ccount, prefixBs);

        int Sab = prefixQuery(i, Acount, prefixBs);
        int Sba = prefixQuery(i + Acount, Bcount, prefixAs);
        int Sca = prefixQuery(i + Acount, Ccount, prefixAs);

        minMoves = min(minMoves, Na + Nb - min(Sab, Sba));
        minMoves = min(minMoves, Na + Nc - min(Sab, Sca));
    }

    cout << minMoves << endl;

    return 0;
}