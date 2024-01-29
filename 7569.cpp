#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100

struct Node{
    int x, y, z;
    Node(int a, int b, int c): x(a), y(b), z(c) {}
};

int M, N, H;
int tomato_container[MAX_N][MAX_N][MAX_N] = { 0, };
int dist[MAX_N][MAX_N][MAX_N] = { 0, };
queue<Node> q;

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};


void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> M >> N >> H;

    for (int i=0; i<H; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<M; k++) {
                cin >> tomato_container[k][j][i];
                if (tomato_container[k][j][i] == 1) {
                    q.push(Node(k, j, i));
                }
            }
        }
    }
}

void BFS() {
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int cur_x = cur.x;
        int cur_y = cur.y;
        int cur_z = cur.z;

        for (int i=0; i<6; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            int next_z = cur_z + dz[i];

            if (next_x >= 0 && next_x < M && next_y >=0 && next_y < N && next_z >= 0 && next_z < H) {
                if (tomato_container[next_x][next_y][next_z] == 0) {
                    tomato_container[next_x][next_y][next_z] = 1;
                    dist[next_x][next_y][next_z] = dist[cur_x][cur_y][cur_z] + 1;
                    q.push(Node(next_x, next_y, next_z));
                }
            }
        }
    }
}

void getOutput() {
    int answer = 0;

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<H; k++) {
                if (tomato_container[i][j][k] == 0 && dist[i][j][k] == 0) {
                    cout << -1;
                    return;
                } 
                answer = max(answer, dist[i][j][k]);
            }
        }
    }

    cout << answer;
}

void solve() {
    BFS();
    getOutput();
}

int main() {
    setSystem();
    setInput();
    solve();
    return 0;
}
