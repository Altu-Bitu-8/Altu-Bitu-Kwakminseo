#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<char, int> getCharCount(const string& word) {
    unordered_map<char, int> charCount;
    for (char c : word) {
        charCount[c]++;
    }
    return charCount;
}

bool isSimilar(const string& base, const string& word) {
    unordered_map<char, int> baseCount = getCharCount(base);
    unordered_map<char, int> wordCount = getCharCount(word);
    
    int add = 0, remove = 0, change = 0;
    
    for (char c = 'A'; c <= 'Z'; c++) {
        if (baseCount[c] != wordCount[c]) {
            int diff = abs(baseCount[c] - wordCount[c]);
            if (baseCount[c] > wordCount[c]) remove += diff;
            else add += diff;
        }
    }
    
    return (add == 1 && remove == 0) || (remove == 1 && add == 0) || (add == 0 && remove == 0) || (add == 1 && remove == 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<string> words(N);
    
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    int similarCount = 0;
    for (int i = 1; i < N; i++) {
        if (isSimilar(words[0], words[i])) {
            similarCount++;
        }
    }
    
    cout << similarCount << "\n";
    return 0;
}