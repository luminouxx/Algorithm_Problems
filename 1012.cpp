#include <iostream>
#include <queue>

#define MAX_N 51

using namespace std;

int T, M, N, K;
int answer = 0;

bool maps[MAX_N][MAX_N] = {
    false,
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int, int>> q;

void BFS(int x, int y) {

    q.push({x, y});
    maps[x][y] = false;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur.first + dx[i];
            int next_y = cur.second + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
                continue;
            if (!maps[next_x][next_y])
                continue;

            q.push({next_x, next_y});
            maps[next_x][next_y] = false;
        }
    }

    answer++;
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {

        cin >> M >> N >> K;

        for (int j = 0; j < K; j++) {
            int a, b;
            cin >> a >> b;
            maps[a][b] = true;
        }

        for (int k = 0; k < M; k++) {
            for (int l = 0; l < N; l++) {
                if (maps[k][l]) BFS(k, l);
            }
        }

        cout << answer << endl;
        answer = 0;
    }

    return 0;
}
