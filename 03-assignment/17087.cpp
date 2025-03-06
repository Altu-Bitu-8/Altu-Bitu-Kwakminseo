#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    vector<int> distances(N);
    for (int i = 0; i < N; i++) {
        int Ai;
        cin >> Ai;
        distances[i] = abs(Ai - S);
    }

    int result = distances[0];
    for (int i = 1; i < N; i++) {
        result = gcd(result, distances[i]);
    }

    cout << result << "\n";

    return 0;
}