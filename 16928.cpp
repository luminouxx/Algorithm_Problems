#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 101

int N, M;
int answer = INT_MAX;

vector<pair<int, int>> m;
bool visited[101] = { false, };

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;

        m.push_back({a, b});
    }

    for (int j=0; j<M; j++) {
        int c, d;
        cin >> c >> d;

        m.push_back({c, d});
    }
}

void BFS() {
    queue<pair<int,int>> q;
    q.push({1, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        for (int i=6; i>=1; i--) {
            int next = cur + i;
            int next_depth = depth + 1;

            for (int j=0; j<m.size(); j++) {
                if (next == m[j].first) {
                    next = m[j].second;
                }
            }

            if (next < 100) {
                if (!visited[next]) {
                    q.push({next, next_depth});                    
                    visited[next] = true;
                }

            } else if (next == 100) {
                answer = min(answer, next_depth);
                visited[next] = true;
            }
        }
    }
}

void getOutput() {
    cout << answer << endl;
}

int main() {
    setSystem();
    setInput();
    BFS();
    getOutput();
    return 0;
}
