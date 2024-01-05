#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 20001

int dist[MAX];
int vertex;
int edge;
int startVertex;
vector<pair<int, int>> connect[MAX];
bool visited[MAX];

void setSystem() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void makeInput() {
    cin >> vertex;
    cin >> edge;
    cin >> startVertex;

    for (int i=0; i<edge; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        connect[start].push_back({ end, weight });
    }

    for (int j=0; j<MAX; j++) {
        dist[j] = INT32_MAX;
        visited[j] = false;
    }
}

void startDijistra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, startVertex});
    dist[startVertex] = 0;

    while(!pq.empty()) {
        int curVertex = pq.top().second;
        int curDistance = -pq.top().first;
        visited[curVertex] = true;
        pq.pop();

        for (int i=0; i<connect[curVertex].size(); i++) {
            int nextVertex = connect[curVertex][i].first;
            int nextDistance = connect[curVertex][i].second;

            if (dist[nextVertex] > curDistance + nextDistance && !visited[nextVertex]) {
                dist[nextVertex] = curDistance + nextDistance;
                pq.push({-dist[nextVertex], nextVertex});
            }
        }
    }
}

void printResult() {
    for (int i=1; i<vertex+1; i++) {
        if (dist[i] == INT32_MAX)  cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

int main() {
    setSystem();
    makeInput();
    startDijistra();
    printResult();
    return 0;
}
