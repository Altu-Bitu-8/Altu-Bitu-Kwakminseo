#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000;
vector<bool> isPrime(MAX_N + 1, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int n;
    while (cin >> n && n != 0) {
        bool found = false;
        for (int a = 3; a <= n / 2; a += 2) {
            int b = n - a;
            if (isPrime[a] && isPrime[b]) {
                cout << n << " = " << a << " + " << b << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}