#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, S = 0;
    cin >> M;

    string cmd;
    int x;
    vector<string> results;

    while (M--) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            S |= (1 << (x - 1));
        } else if (cmd == "remove") {
            cin >> x;
            S &= ~(1 << (x - 1));
        } else if (cmd == "check") {
            cin >> x;
            results.push_back((S & (1 << (x - 1))) ? "1" : "0");
        } else if (cmd == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1));
        } else if (cmd == "all") {
            S = (1 << 20) - 1;
        } else if (cmd == "empty") {
            S = 0;
        }
    }

    cout << "\n";
    for (const string &res : results) {
        cout << res << "\n";
    }

    return 0;
}