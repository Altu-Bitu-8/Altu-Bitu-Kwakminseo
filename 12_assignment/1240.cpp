#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[1001];
bool visited[1001];
int res;

void dfs(int now, int target, int dist) {
    if (now == target) {
        res = dist;
        return;
    }
    visited[now] = true;
    for (auto [next, cost] : tree[now]) {
        if (!visited[next]) dfs(next, target, dist + cost);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        fill(visited, visited + n + 1, false);
        res = 0;
        dfs(a, b, 0);
        cout << res << '\n';
    }

    return 0;
}