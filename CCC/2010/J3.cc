#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int A = 0, B = 0;

    int INSTR;
    cin >> INSTR;
    while (INSTR != 7) {
        string varS;
        cin >> varS;

        int* var = &A;
        int* var2 = &A;
        if (varS == "B") {
            var = &B;
        }

        if (INSTR > 2) {
            cin >> varS;
            if (varS == "B") {
                var2 = &B;
            }
        }

        switch(INSTR) {
            case 1:
                cin >> *var;
                break;
            case 2:
                cout << *var << endl;
                break;
            case 3: 
                *var = *var + *var2;
                break;
            case 4:
                *var = (*var) * (*var2);
                break;
            case 5:
                *var = *var - *var2;
                break;
            case 6:
                *var = *var / *var2;
                break;
        }

        cin >> INSTR;
    }
}