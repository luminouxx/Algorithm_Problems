#include<iostream>
#include<vector>
#include<queue>

#define MAX_N 501
#define MAX_DIST 10000000

using namespace std;

int TC, N, M, W;

vector<pair<pair<int, int>, int>> edge;

bool bellman_ford() {
    int dist[MAX_N];

    for (int i=1; i<N; i++) {
        dist[i] = MAX_DIST;
    }

    for (int j=1; j<N; j++) {
        for (int k=0; k<edge.size(); k++) {
            int from = edge[k].first.first;
            int to = edge[k].first.second;
            int cost = edge[k].second;

            if (dist[to] > dist[from] + cost) { 
                dist[to] = dist[from] + cost;
            }
        }
    }

    for (int j=1; j<N; j++) {
        for (int k=0; k<edge.size(); k++) {
            int from = edge[k].first.first;
            int to = edge[k].first.second;
            int cost = edge[k].second;

            if (dist[to] > dist[from] + cost) { 
                dist[to] = dist[from] + cost;
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> TC;

    for (int i=0; i<TC; i++) {
        cin >> N >> M >> W;
        edge.clear();

        for (int j=0; j<M; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            edge.push_back({{S, E}, T});
            edge.push_back({{E, S}, T});
        }
        for (int k=0; k<W; k++) {
            int wS, wE, wT;
            cin >> wS >> wE >> wT;
            edge.push_back({{wS, wE}, -wT});
        }
        if (bellman_ford()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}