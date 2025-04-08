#include <iostream>
using namespace std;

int board[19][19];
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

bool check(int x, int y) {
    if (board[x][y] == 0) return false;
    int color = board[x][y];
    for (int d = 0; d < 4; ++d) {
        int cnt = 1;
        int nx = x + dx[d], ny = y + dy[d];
        while (nx >= 0 && ny >= 0 && nx < 19 && ny < 19 && board[nx][ny] == color) {
            cnt++;
            nx += dx[d];
            ny += dy[d];
        }
        nx = x - dx[d], ny = y - dy[d];
        while (nx >= 0 && ny >= 0 && nx < 19 && ny < 19 && board[nx][ny] == color) {
            cnt++;
            nx -= dx[d];
            ny -= dy[d];
        }
        if (cnt == 5) {
            int px = x - dx[d], py = y - dy[d];
            if (!(px >= 0 && py >= 0 && px < 19 && py < 19 && board[px][py] == color)) {
                cout << color << '\n' << x + 1 << ' ' << y + 1 << '\n';
                return true;
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 19; ++i)
        for (int j = 0; j < 19; ++j)
            cin >> board[i][j];

    for (int i = 0; i < 19; ++i)
        for (int j = 0; j < 19; ++j)
            if (check(i, j)) return 0;

    cout << 0 << '\n';
    return 0;
}