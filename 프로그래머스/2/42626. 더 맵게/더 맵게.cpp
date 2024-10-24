#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto s: scoville) {
        pq.push(s);
    }
    
    while (pq.top() < K && pq.size() >= 2) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        pq.push(first + second * 2);
        answer++;
    }
    
    if (!pq.empty() && pq.top() < K) answer = -1;
    
    return answer;
}