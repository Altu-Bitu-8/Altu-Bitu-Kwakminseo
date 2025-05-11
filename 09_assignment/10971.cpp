#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int W[10][10];
bool visited[10];
int answer = 1e9;

void dfs(int start, int curr, int cost, int depth) {
    if (depth == N) {
        if (W[curr][start] != 0)
            answer = min(answer, cost + W[curr][start]);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && W[curr][i] != 0) {
            visited[i] = true;
            dfs(start, i, cost + W[curr][i], depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    for (int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(i, i, 0, 1);
        visited[i] = false;
    }

    cout << answer << '\n';
    return 0;
}