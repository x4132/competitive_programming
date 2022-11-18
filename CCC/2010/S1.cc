#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int n;
    cin >> n;

    auto qcomp = [](tuple<string, int> a, tuple<string, int> b) {
        if (get<1>(a) == get<1>(b)) {
            if (strcmp(get<0>(a).c_str(), get<0>(b).c_str()) > 0) {
                return true;
            } else {
                return false;
            }
        } else if (get<1>(a) > get<1>(b)) {
            return false;
        } else {
            return true;
        }

        return false;
    };

    priority_queue<tuple<string, int>, vector<tuple<string, int>>, decltype(qcomp)> computers(qcomp);


    for (int i = 0; i < n; i++) {
        string name;
        int ram, cpu, disk;

        cin >> name >> ram >> cpu >> disk;

        computers.push({name, 2 * ram + 3 * cpu + disk});
    }

    for (int i = 0; i < 2 && !computers.empty(); i++) {
        cout << get<0>(computers.top()) << endl;
        computers.pop();
    }
}