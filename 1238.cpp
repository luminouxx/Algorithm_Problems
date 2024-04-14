#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_N 1001

int adj[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int N, M, X;

void dijstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start][start] = 0;

    while (!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_d = pq.top().first;
        pq.pop();

        if (dist[start][cur_v] < cur_d) continue;

        for (int i=1; i<=N; i++) {
            if (adj[cur_v][i] != -1) {
                int next_v = i;
                int next_d = cur_d + adj[cur_v][i];

                if (dist[start][next_v] > next_d) {
                    dist[start][next_v] = next_d;
                    pq.push({next_d, next_v});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;

    // 거리, 인접 행렬 초기화
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            adj[i][j] = -1;
            dist[i][j] = INT_MAX;
        }
    }

    // 인풋 받기
    for (int l=0; l<M; l++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        adj[start][end] = cost;
    }

    // 다익스트라 실행
    for (int m=1; m<=N; m++) {
        dijstra(m);
    }

    int max_dist = 0;
    for (int n=1; n<=N; n++) {
        int total_dist = dist[X][n] + dist[n][X];
        max_dist = max(total_dist, max_dist);
    }

    cout << max_dist << endl;
    
    return 0;
}
