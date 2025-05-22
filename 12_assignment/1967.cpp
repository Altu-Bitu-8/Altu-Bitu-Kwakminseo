#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int far_node, max_dist;

void dfs(int node, int dist) {
    visited[node] = true;
    if (dist > max_dist) {
        max_dist = dist;
        far_node = node;
    }
    for (auto [next, cost] : tree[node]) {
        if (!visited[next]) dfs(next, dist + cost);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    max_dist = 0;
    dfs(far_node, 0);

    cout << max_dist;
    return 0;
}