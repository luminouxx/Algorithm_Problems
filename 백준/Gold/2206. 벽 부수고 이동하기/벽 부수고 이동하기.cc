#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 1001

int N, M;

int field[MAX_N][MAX_N] = {0, };
bool visited[MAX_N][MAX_N][2] = {false, };

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0 , -1};

int main() {
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) {
            field[i][j] = s[j] - '0';
        }
    }

    queue<pair<pair<int, int>, pair<int, bool>>> q;

    q.push({{0, 0},{1, false}});
    visited[0][0][0] = true;

    int answer = 1000001;

    while(!q.empty()) {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int dist = q.front().second.first;
        int isBreak = q.front().second.second;

        q.pop();

        if (cur_y==N-1 && cur_x==M-1) answer = min(answer, dist);

        for (int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x>=0 && next_x<M && next_y>=0 && next_y<N) {
                if (visited[next_y][next_x][isBreak]) continue;

                if (!field[next_y][next_x]) {
                    q.push({{next_x, next_y}, {dist+1, isBreak}});
                    visited[next_y][next_x][isBreak] = true;
                } else if (!isBreak){
                    q.push({{next_x, next_y}, {dist+1, true}});
                    visited[next_y][next_x][true] = true;
                }
            }
        }
    }

    if (answer == 1000001) {
        cout << -1;
    } else {
        cout << answer;
    }

    return 0;
}