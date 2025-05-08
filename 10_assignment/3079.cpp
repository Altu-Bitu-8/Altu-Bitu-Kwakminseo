#include <vector>
#include <iostream>
using namespace std;

class ImmigrationCheck {
public:
    long long N, M;
    long long tk_max = 0;
    vector<long long> oper;

    void input() {
        cin >> N >> M;
        oper.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> oper[i];
            if (tk_max < oper[i]) tk_max = oper[i];
        }
    }

    bool iscan(long long t) {
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += t / oper[i];
            if (sum >= M) return true;
        }
        return false;
    }

    void binary_search() {
        long long low = 1, high = tk_max * M, result = high;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (iscan(mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << result << endl;
    }

    void run() {
        input();
        binary_search();
    }
};

int main() {
    ImmigrationCheck immigrationCheck;
    immigrationCheck.run();
    return 0;
}