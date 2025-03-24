#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Employee {
    int experience;
    int urgency;
    int line;
    int index;
    
    bool operator<(const Employee& other) const {
        if (experience != other.experience) return experience < other.experience;
        if (urgency != other.urgency) return urgency < other.urgency;
        return line > other.line;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<queue<Employee>> lines(M);
    priority_queue<Employee> pq;
    Employee deca;
    
    for (int i = 0; i < N; i++) {
        int D, H;
        cin >> D >> H;
        Employee emp = {D, H, i % M, i};
        lines[i % M].push(emp);
        if (i == K) deca = emp;
    }
    
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }
    
    int count = 0;
    while (!pq.empty()) {
        Employee current = pq.top();
        pq.pop();
        
        if (current.index == K) {
            cout << count << "\n";
            return 0;
        }
        
        count++;
        if (!lines[current.line].empty()) {
            pq.push(lines[current.line].front());
            lines[current.line].pop();
        }
    }
    
    return 0;
}