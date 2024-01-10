#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;

#define MAX_N 100

char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int N;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int cnt = 0;
int rgcnt = 0;

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> N;
    string temp;

    for (int i=0; i<N; i++) {
        cin >> temp;

        for (int j=0; j<N; j++) {
            map[i][j] = temp[j];
            visited[i][j] = false;
        }
    }
}


void DFS(int x, int y, char target) {
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;

    while(!s.empty()) {
        pair<int, int> cur = s.top();

        int cur_x = cur.first;
        int cur_y = cur.second;

        visited[cur_x][cur_y] = true;

        bool isMoved = false;

        for (int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
                if (map[next_x][next_y] == target && !visited[next_x][next_y]) {
                    s.push({next_x, next_y});
                    isMoved = true;
                }
            }
        }
        if (!isMoved) {
            s.pop();
        }
    }
    cnt++;
}

void nonegreen_DFS(int x, int y, char target) {
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;

    while(!s.empty()) {
        pair<int, int> cur = s.top();

        int cur_x = cur.first;
        int cur_y = cur.second;

        visited[cur_x][cur_y] = true;

        bool isMoved = false;

        for (int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
                if (map[next_x][next_y] == target && !visited[next_x][next_y]) {
                    s.push({next_x, next_y});
                    isMoved = true;
                }
            }
        }
        if (!isMoved) {
            s.pop();
        }
    }
    rgcnt++;
}

void solve() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!visited[i][j]) {
                DFS(i, j, map[i][j]);
            }
        }
    }
    cout << cnt << ' ';
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            visited[i][j] = false;
            if (map[i][j] == 'G') map[i][j] = 'R';
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!visited[i][j]) {
                nonegreen_DFS(i, j, map[i][j]);
            }
        }
    }
    cout << rgcnt;
}

int main() {
    setSystem();
    setInput();
    solve();
    return 0;
}
