#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_map<int, int> count;
    int left = 0, res = 0;

    for (int right = 0; right < n; ++right) {
        count[a[right]]++;
        while (count[a[right]] > k) {
            count[a[left]]--;
            left++;
        }
        res = max(res, right - left + 1);
    }

    cout << res;
    return 0;
}