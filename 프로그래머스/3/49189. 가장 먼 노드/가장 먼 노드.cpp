#include <string>
#include <vector>

#include <queue>
#include <iostream>

#define MAX_N 20001
#define INFF 500001

bool adj[MAX_N][MAX_N] = {false, };
int dist[MAX_N] = {0, };

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    // 거리 배열 초기화
    for (int i=1; i<MAX_N; i++) {
        dist[i] = INFF;
    }
    
    // 인접 행렬 초기화
    for (auto e: edge) {
        int from = e[0];
        int to = e[1];
        adj[from][to] = true;
        adj[to][from] = true;
    }
    
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        int cur_v = cur.second;
        int cur_d = -cur.first;
        
        if (cur_d > dist[cur_v]) continue;
        
        for (int i=1; i<=n; i++) {
            if (adj[cur_v][i]) {
                int next_d = cur_d + 1;
                int next_v = i;
                
                if (dist[next_v] > next_d) {
                    dist[next_v] = next_d;
                    pq.push({-next_d, next_v});
                }
            }
        }
    }
    
    int max = 0;
    for (int i=1; i<=n; i++) {
        if (dist[i] > max) {
            max = dist[i];
            answer = 1;
        } else if (dist[i] == max) {
            answer++;
        }
    }
    
    return answer;
}