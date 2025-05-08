#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> lengths(N);
    for (int i = 0; i < N; i++) {
        cin >> lengths[i];
    }

    int left = *max_element(lengths.begin(), lengths.end()), right = 0;
    for (int i = 0; i < N; i++) {
        right += lengths[i];
    }

    int answer = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 1, sum = 0;

        for (int i = 0; i < N; i++) {
            if (sum + lengths[i] > mid) {
                count++;
                sum = lengths[i];
            } else {
                sum += lengths[i];
            }
        }

        if (count <= M) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}