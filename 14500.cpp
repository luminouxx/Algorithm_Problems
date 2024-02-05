#include <iostream>

using namespace std;

#define MAX_N 501

int answer = 0;

int N, M;
int m[MAX_N][MAX_N] = {0, };
bool visited[MAX_N][MAX_N] = {false, };

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> M >> N;

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> m[i][j];
        }
    }
}

void DFS(int x, int y, int depth, int sum) {
    if (depth == 3) {
        answer = max(answer, sum);
        return;
    }
    for (int i=0; i<4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {
            int next_sum = sum + m[next_x][next_y];

            if (!visited[next_x][next_y]) {
                visited[next_x][next_y] = true;
                DFS(next_x, next_y, depth+1, next_sum);
                visited[next_x][next_y] = false;
            }
        }
    }
}

void calExtra(int x, int y) {
    int cal_x = x + 2;
    int cal_y = y - 1;
    int sum = 0;

    if (cal_x < M && cal_y >= 0) {
        for (int i=x; i<=cal_x; i++) {
            sum += m[i][y];
        }
        sum += m[x+1][cal_y];
        answer = max(sum, answer);
    }

    sum = 0;
    cal_x = x + 2;
    cal_y = y + 1;

    if (cal_x < M && cal_y < N) {
        for (int i=x; i<=cal_x; i++) {
            sum += m[i][y];
        }
        sum += m[x+1][cal_y];
        answer = max(sum, answer);
    }

    sum = 0;
    cal_x = x + 1;
    cal_y = y + 2;

    if (cal_x < M && cal_y < N) {
        for (int i=y; i<=cal_y; i++) {
            sum += m[x][i];
        }
        sum += m[cal_x][y+1];
        answer = max(sum, answer);
    }

    sum = 0;
    cal_x = x - 1;
    cal_y = y + 2;

    if (cal_x >= 0 && cal_y < N) {
        for (int i=y; i<=cal_y; i++) {
            sum += m[x][i];
        }
        sum += m[cal_x][y+1];
        answer = max(sum, answer);
    }
}

void solve() {

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            visited[i][j] = true;
            DFS(i, j, 0, m[i][j]);
            visited[i][j] = false;
            calExtra(i, j);
        }
    }

    cout << answer << endl;
}

int main() {
    setSystem();
    setInput();
    solve();
    return 0;
}
