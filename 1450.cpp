#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long c;
vector<int> w;

void dfs(int idx, int end, long long sum, vector<long long>& res) {
    if (sum > c) return;
    if (idx == end) {
        res.push_back(sum);
        return;
    }
    dfs(idx + 1, end, sum, res);
    dfs(idx + 1, end, sum + w[idx], res);
}

int main() {
    cin >> n >> c;
    w.resize(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    vector<long long> a, b;
    dfs(0, n / 2, 0, a);
    dfs(n / 2, n, 0, b);

    sort(b.begin(), b.end());

    long long cnt = 0;
    for (long long x : a)
        cnt += upper_bound(b.begin(), b.end(), c - x) - b.begin();

    cout << cnt;
    return 0;
}