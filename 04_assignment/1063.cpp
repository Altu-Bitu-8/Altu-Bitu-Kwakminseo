#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string king, stone;
    int N;
    cin >> king >> stone >> N;

    int kx = king[0] - 'A', ky = king[1] - '1';
    int sx = stone[0] - 'A', sy = stone[1] - '1';

    map<string, pair<int, int>> moves = {
        {"R", {1, 0}}, {"L", {-1, 0}}, {"B", {0, -1}}, {"T", {0, 1}},
        {"RT", {1, 1}}, {"LT", {-1, 1}}, {"RB", {1, -1}}, {"LB", {-1, -1}}
    };

    for (int i = 0; i < N; i++) {
        string move;
        cin >> move;

        int nx = kx + moves[move].first;
        int ny = ky + moves[move].second;

        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;

        if (nx == sx && ny == sy) {
            int nsx = sx + moves[move].first;
            int nsy = sy + moves[move].second;

            if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8) continue;

            sx = nsx;
            sy = nsy;
        }

        kx = nx;
        ky = ny;
    }

    cout << char(kx + 'A') << char(ky + '1') << "\n";
    cout << char(sx + 'A') << char(sy + '1') << "\n";

    return 0;
}