#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> visited(n + 1, -1);
    queue<int> q;
    q.push(a);
    visited[a] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : graph[cur]) {
            if (visited[next] == -1) {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << visited[b] << '\n';
    return 0;
}