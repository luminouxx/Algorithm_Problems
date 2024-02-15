#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define MAX_N 1001

bool maps[MAX_N][MAX_N] = {false,};
bool visited[MAX_N] = {false,};

int N, M, V;

queue<int> q;
stack<int> s;

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> N >> M >> V;

    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;

        maps[a][b] = true;
        maps[b][a] = true;
    }
}

void resetVisited() {
    for (int i=1; i<=N; i++)  visited[i] = false;
}

void BFS() {
    cout << endl;

    q.push(V);
    visited[V] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i=1; i<=N; i++) {
            if (maps[cur][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int v) {
    cout << v << " ";
    visited[v] = true;

    for (int i=1; i<=N; i++) {
        if (!visited[i] && maps[v][i]) {
            DFS(i);
        }
    }
}

void solve() {
    DFS(V);
    resetVisited();
    BFS();
}

int main() {
    setSystem();
    setInput();
    solve();
    return 0;
}
