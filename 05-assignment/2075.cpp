#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N * N; i++) {
        int num;
        cin >> num;
        minHeap.push(num);
        if (minHeap.size() > N) {
            minHeap.pop();
        }
    }

    cout << minHeap.top() << "\n";
    return 0;
}