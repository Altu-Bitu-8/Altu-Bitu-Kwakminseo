#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job {
    int requestTime;
    int duration;
    int index;
    
    bool operator<(const Job& other) const {
        if (duration != other.duration) return duration > other.duration;
        return requestTime > other.requestTime;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<Job> pq;
    
    int time = 0, totalTurnaround = 0, jobIndex = 0, jobCount = jobs.size();
    
    while (jobIndex < jobCount || !pq.empty()) {
        while (jobIndex < jobCount && jobs[jobIndex][0] <= time) {
            pq.push({jobs[jobIndex][0], jobs[jobIndex][1], jobIndex});
            jobIndex++;
        }
        
        if (!pq.empty()) {
            Job current = pq.top();
            pq.pop();
            time += current.duration;
            totalTurnaround += time - current.requestTime;
        } else {
            time = jobs[jobIndex][0];
        }
    }
    
    return totalTurnaround / jobCount;
}