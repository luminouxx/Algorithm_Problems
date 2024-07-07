#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define MAX_N 1001
#define MAX_DIST 987654321

int N, M;

vector<pair<int, int>> bus[MAX_N];

int dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    int dist[MAX_N];
    for (int i=1; i<=N; i++) {
        dist[i] = MAX_DIST;
    }
    dist[start] = 0;
    

    while (!pq.empty()) {
        int cur_v = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        if(dist[cur_v] < cur_dist) {
            continue;
        }

        for (int j=0; j<bus[cur_v].size(); j++) {
            int next_v = bus[cur_v][j].first;
            int next_dist = cur_dist + bus[cur_v][j].second;

            if (dist[next_v] > next_dist) {
                dist[next_v] = next_dist;
                pq.push({next_dist, next_v});
            }
        }
    }
    
    return dist[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i=0; i<M; i++) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;
        bus[v1].push_back({v2, dist});
    }

    int start, end;
    cin >> start >> end;

    int answer = dijkstra(start, end);
    cout << answer << endl;

    return 0;
}