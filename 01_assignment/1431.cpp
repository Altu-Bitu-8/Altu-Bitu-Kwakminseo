#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digitSum(const string &s) {
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}

bool compare(const string &a, const string &b) {
    if (a.length() != b.length()) return a.length() < b.length();
    if (digitSum(a) != digitSum(b)) return digitSum(a) < digitSum(b);
    return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<string> serials(n);

    for (int i = 0; i < n; i++) {
        cin >> serials[i];
    }

    sort(serials.begin(), serials.end(), compare);

    for (const string &serial : serials) {
        cout << serial << "\n";
    }

    return 0;
}