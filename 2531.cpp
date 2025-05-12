#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n);
    for (int i = 0; i < n; ++i) cin >> sushi[i];

    vector<int> cnt(d + 1, 0);
    int kind = 0, res = 0;

    for (int i = 0; i < k; ++i) {
        if (cnt[sushi[i]]++ == 0) ++kind;
    }
    res = (cnt[c] == 0) ? kind + 1 : kind;

    for (int i = 1; i < n; ++i) {
        if (--cnt[sushi[i - 1]] == 0) --kind;
        int next = sushi[(i + k - 1) % n];
        if (cnt[next]++ == 0) ++kind;
        int total = (cnt[c] == 0) ? kind + 1 : kind;
        if (total > res) res = total;
    }
    cout << res;
    return 0;
}