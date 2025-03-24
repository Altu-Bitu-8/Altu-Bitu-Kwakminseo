#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    
    vector<char> wheel(N, '?');  
    int index = 0;  
    bool used[26] = {false};  

    for (int i = 0; i < K; i++) {
        int S;
        char letter;
        cin >> S >> letter;

        index = (index - S % N + N) % N; 

        if (wheel[index] == '?') {
            if (used[letter - 'A']) {  
                cout << "!\n";
                return 0;
            }
            wheel[index] = letter;
            used[letter - 'A'] = true;
        } else if (wheel[index] != letter) {
            cout << "!\n";
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << wheel[(index + i) % N];
    }
    cout << "\n";

    return 0;
}