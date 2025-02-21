#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    set<string> substrings;

    for (int i = 0; i < s.length(); i++) {
        string sub = "";
        for (int j = i; j < s.length(); j++) {
            sub += s[j];
            substrings.insert(sub);
        }
    }

    cout << substrings.size() << endl;
    return 0;
}
