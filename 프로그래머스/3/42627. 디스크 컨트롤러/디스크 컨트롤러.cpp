#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct cmp {
    bool operator() (vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int cur_time = 0;
    int total_time = 0;
    
    int idx = 0;
    int cnt = 0;
    
    while (true) {
        
        if (idx < jobs.size() && jobs[idx][0] <= cur_time) {
            pq.push(jobs[idx]);
            idx++;
            continue;
        }
        
        // 작업이 있을 경우
        if (!pq.empty()) {
            cur_time += pq.top()[1];
            cout << cur_time << endl;
            total_time = total_time + cur_time - pq.top()[0];
            pq.pop();
            cnt ++;
            if (cnt == jobs.size()) break;
        } else { // 작업이 없을 경우
            cur_time = jobs[idx][0];
        }
    }
    
    return total_time / jobs.size();
}