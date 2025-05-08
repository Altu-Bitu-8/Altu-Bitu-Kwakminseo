#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<int> lengths(N);
    for (int i = 0; i < N; i++) {
        cin >> lengths[i];
    }

    sort(lengths.begin(), lengths.end());

    int left = 1, right = lengths[N-1], answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;

        for (int i = 0; i < N; i++) {
            count += lengths[i] / mid;
        }

        if (count >= M) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}