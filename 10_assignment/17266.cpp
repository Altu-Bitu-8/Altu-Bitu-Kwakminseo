#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> Arr;

bool possible(int target) {
    int prev = 0;

    for (int i = 0; i < M; i++) {
        if (Arr[i] - target <= prev) {
            prev = Arr[i] + target;
        } else {
            return false;
        }
    }

    return N - prev <= 0;
}

int main() {
    cin >> N >> M;
    Arr.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> Arr[i];
    }

    int left = 1, right = N;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (possible(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}