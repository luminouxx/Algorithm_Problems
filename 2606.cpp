#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 101

bool visited[MAX_N] = {false, };
bool edges[MAX_N][MAX_N] ={false, };

queue<int> q;

int main() {
    int V, E;
    cin >> V >> E;

    for (int i=0; i<E; i++) {
        int a, b;
        cin >> a >> b;

        edges[a][b] = true;
        edges[b][a] = true;
    }

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int j=1; j<=V; j++) {
            if (edges[cur][j] && !visited[j]) {
                visited[j] = true;
                q.push(j);
            }
        }
    }

    int ans = 0;
    for (int k=1; k<=V; k++) {
        if (visited[k]) ans++;
    }

    cout << ans-1 << endl;

    return 0;
}
