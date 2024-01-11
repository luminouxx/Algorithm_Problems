#include <iostream>
#include <queue>
#include <string>

#define MAX_N 600

using namespace std;

int N, M;

char campus[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int start_x, start_y;
int result = 0;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;

        for (int j=0; j<M; j++) {
            campus[i][j] = s[j];
            visited[i][j] = false;

            if (s[j] == 'I') {
                start_x = i;
                start_y = j;
            }
        }
    }
}

void solve() {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int cur_x = cur.first;
        int cur_y = cur.second;

        for (int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
                if (!visited[next_x][next_y]) {
                    if (campus[next_x][next_y] != 'X') {
                        q.push({next_x, next_y});
                        visited[next_x][next_y] = true;
                        if (campus[next_x][next_y] == 'P') result++;
                    }
                }
            }
        }
    }

    if (result == 0) {
        cout << "TT";

    } else {
        cout << result; 
    }
}


int main() {
    setSystem();
    setInput();
    solve();
    return 0;
}
