#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 1001

int maps[MAX_N][MAX_N] = {0,};
bool visited[MAX_N][MAX_N] = {false,};
int M, N, start_x, start_y;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> maps[j][i];
            if (maps[j][i] == 2) {
                start_x = j;
                start_y = i;
            }
        }
    }
}

void solve() {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});

    maps[start_x][start_y] = 0;
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        visited[cur_x][cur_y] = true;
        q.pop();

        for (int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {
                if (!visited[next_x][next_y] && maps[next_x][next_y] == 1) {
                    q.push({next_x, next_y});
                    maps[next_x][next_y] = maps[cur_x][cur_y] + 1;
                }
            }
        }
    }

    for (int k=0; k<M; k++) {
        for (int l=0; l<N; l++) {
            if (maps[k][l] == 1 && !visited[k][l]) maps[k][l] = -1;
        }
    }
}

void getOutput() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << maps[j][i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    setSystem();
    setInput();
    solve();
    getOutput();
    return 0;
}
