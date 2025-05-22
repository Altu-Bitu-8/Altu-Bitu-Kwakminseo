#include <iostream>
#include <deque>
#include <map>

using namespace std;

int n, k, l;
int board[101][101];
map<int, char> dir;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> n >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    cin >> l;
    while (l--) {
        int t;
        char c;
        cin >> t >> c;
        dir[t] = c;
    }

    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    board[1][1] = 2;
    int time = 0, d = 0;

    while (true) {
        time++;
        int nx = snake.front().first + dx[d];
        int ny = snake.front().second + dy[d];

        if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 2) break;

        if (board[nx][ny] == 1)
            board[nx][ny] = 2;
        else {
            board[nx][ny] = 2;
            auto tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        snake.push_front({nx, ny});

        if (dir.count(time)) {
            if (dir[time] == 'D') d = (d + 1) % 4;
            else d = (d + 3) % 4;
        }
    }

    cout << time;
    return 0;
}