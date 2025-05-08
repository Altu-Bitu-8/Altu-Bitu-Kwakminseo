#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_set<int> cards;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cards.insert(num);
    }

    int M;
    cin >> M;

    vector<int> result;
    for (int i = 0; i < M; i++) {
        int query;
        cin >> query;
        if (cards.find(query) != cards.end()) {
            result.push_back(1);
        } else {
            result.push_back(0);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}