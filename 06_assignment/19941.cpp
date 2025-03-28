#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    vector<bool> used(N, false);
    int result = 0;

    for (int i = 0; i < N; ++i) {
        if (s[i] == 'P') {
            for (int j = max(0, i - K); j <= min(N - 1, i + K); ++j) {
                if (s[j] == 'H' && !used[j]) {
                    used[j] = true;
                    result++;
                    break;
                }
            }
        }
    }

    cout << result << '\n';
    return 0;
}