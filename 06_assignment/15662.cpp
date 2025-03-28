#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int T, K;
vector<deque<int>> gears;

void rotate(int idx, int dir) {
    if (dir == 1) {
        int back = gears[idx].back();
        gears[idx].pop_back();
        gears[idx].push_front(back);
    } else {
        int front = gears[idx].front();
        gears[idx].pop_front();
        gears[idx].push_back(front);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    gears.resize(T);
    for (int i = 0; i < T; ++i) {
        string s;
        cin >> s;
        for (char c : s) gears[i].push_back(c - '0');
    }

    cin >> K;
    while (K--) {
        int num, dir;
        cin >> num >> dir;
        --num;

        vector<int> rotate_dir(T, 0);
        rotate_dir[num] = dir;

        for (int i = num - 1; i >= 0; --i) {
            if (gears[i][2] != gears[i + 1][6]) rotate_dir[i] = -rotate_dir[i + 1];
            else break;
        }

        for (int i = num + 1; i < T; ++i) {
            if (gears[i - 1][2] != gears[i][6]) rotate_dir[i] = -rotate_dir[i - 1];
            else break;
        }

        for (int i = 0; i < T; ++i)
            if (rotate_dir[i] != 0) rotate(i, rotate_dir[i]);
    }

    int count = 0;
    for (int i = 0; i < T; ++i)
        if (gears[i][0] == 1) ++count;

    cout << count << '\n';
    return 0;
}