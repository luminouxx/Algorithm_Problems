#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_V 801
#define MAX_DIST 2147483647

int N, E;
int v1, v2;
int adj[MAX_V][MAX_V] = {0,};

using namespace std;

int dijkstra(int x, int y) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > q;

    int dist[MAX_V];
    for (int i=1; i<=N; i++) {
        dist[i] = MAX_DIST;
    }
    dist[x] = 0;

    bool visited[MAX_V] = { false, };
    visited[x] = true;

    q.push({0,x});

    while (!q.empty()) {
        int cur_v = q.top().second;
        int cur_dist = q.top().first;
        q.pop();

        for (int i=1; i<=N; i++) {
            if (adj[cur_v][i] != 0) {
                int next_v = i;
                int next_dist = cur_dist + adj[cur_v][i];

                if (dist[next_v] > next_dist) {
                    dist[next_v] = next_dist;
                    q.push({next_dist, next_v});
                }
            }
        }
    }

    return dist[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;

    for (int i=0; i<E; i++) {
        int t1, t2, dist;
        cin >> t1 >> t2 >> dist;
        adj[t1][t2] = dist;
        adj[t2][t1] = dist;
    }

    cin >> v1 >> v2;

    int firstToV1 = dijkstra(1, v1);
    int firstToV2 = dijkstra(1, v2);
    int v1ToV2 = dijkstra(v1, v2);
    int lastToV1 = dijkstra(N, v1);
    int lastToV2 = dijkstra(N, v2);

    int case1 = -1;
    int case2 = -1;

    if (firstToV1 != MAX_DIST && v1ToV2 != MAX_DIST && lastToV2 != MAX_DIST) {
        case1 = firstToV1 + v1ToV2 + lastToV2;
    }

    if (firstToV2 != MAX_DIST && v1ToV2 != MAX_DIST && lastToV1 != MAX_DIST) {
        case2 = firstToV2 + v1ToV2 + lastToV1;
    }

    if (case1 != -1 && case2 != -1) {
        cout << min(case1, case2);
    } else {
        if (case1 == -1) {
            cout << case2;
        } else {
            if (case2 == -1) {
                cout << case1;
            }
        }
    }

    return 0;
}