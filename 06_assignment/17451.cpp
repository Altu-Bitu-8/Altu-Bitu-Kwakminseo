#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    ll speed = v[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        speed = ceil_div(speed, v[i]) * v[i];
    }

    cout << speed << '\n';
    return 0;
}