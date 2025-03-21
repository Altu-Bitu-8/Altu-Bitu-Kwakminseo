#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;

    int weight1 = W0, weight2 = W0;
    int BMR1 = I0, BMR2 = I0;

    for (int i = 0; i < D; i++) {
        int diff1 = I - (BMR1 + A);
        weight1 += diff1;

        int diff2 = I - (BMR2 + A);
        weight2 += diff2;
        if (abs(diff2) > T) {
            BMR2 += diff2 / 2;
        }

        if (weight1 <= 0 || weight2 <= 0 || BMR2 <= 0) {
            cout << "Danger Diet" << endl;
            return 0;
        }
    }

    cout << weight1 << " " << BMR1 << endl;
    cout << weight2 << " " << BMR2 << " " << ((I0 > BMR2) ? "YOYO" : "NO") << endl;

    return 0;
}
