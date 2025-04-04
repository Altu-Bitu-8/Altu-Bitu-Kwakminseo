#include <iostream>
#include <deque>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    deque<int> dodo(n);
    deque<int> suyeon(n);

    for(int i = 0; i < n; i++) {
        cin >> dodo[i] >> suyeon[i];
    }

    deque<int> doGround;
    deque<int> suGround;

    bool dodoTurn = true;
    int cnt = 0;
    string winner = "";

    while(true) {
        cnt++;

        if(dodoTurn) {
            doGround.push_back(dodo.back());
            dodo.pop_back();
        }
        else {
            suGround.push_back(suyeon.back());
            suyeon.pop_back();
        }

        if(dodo.size() == 0) {
            winner = "su";
            break;
        }
        else if(suyeon.size() == 0) {
            winner = "do";
            break;
        }

        if(doGround.size() != 0 && suGround.size() != 0 && doGround.back() + suGround.back() == 5) {
            while(doGround.size() > 0) {
                suyeon.push_front(doGround.front());
                doGround.pop_front();
            }
            while(suGround.size() > 0) {
                suyeon.push_front(suGround.front());
                suGround.pop_front();
            }
        }
        else if(doGround.size() != 0 && doGround.back() == 5 || suGround.size() != 0 && suGround.back() == 5) {
            while(suGround.size() > 0) {
                dodo.push_front(suGround.front());
                suGround.pop_front();
            }
            while(doGround.size() > 0) {
                dodo.push_front(doGround.front());
                doGround.pop_front();
            }
        }

        if(cnt == m) {
            int result = dodo.size() - suyeon.size();
            if(result < 0) winner = "su";
            else if(result > 0) winner = "do";
            else winner = "dosu";
            break;
        }

        dodoTurn = !dodoTurn;
    }

    cout << winner;

    return 0;
}