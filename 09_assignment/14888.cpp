#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> numbers;
int op[4]; // +, -, *, /
int max_result = -1e9;
int min_result = 1e9;

void dfs(int idx, int result) {
    if (idx == N) {
        max_result = max(max_result, result);
        min_result = min(min_result, result);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;

            int next_result = result;
            if (i == 0) next_result += numbers[idx];
            else if (i == 1) next_result -= numbers[idx];
            else if (i == 2) next_result *= numbers[idx];
            else if (i == 3) {
                if (result < 0) next_result = -(-result / numbers[idx]);
                else next_result /= numbers[idx];
            }

            dfs(idx + 1, next_result);
            op[i]++;
        }
    }
}

int main() {
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];
    for (int i = 0; i < 4; i++) cin >> op[i];

    dfs(1, numbers[0]);

    cout << max_result << '\n' << min_result << '\n';
    return 0;
}