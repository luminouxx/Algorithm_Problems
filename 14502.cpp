#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int map[8][8] = {0,};
int row, col;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int answer = 0;

void makeInput() {
    
    cin >> row >> col;

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            int temp = 0;
            cin >> temp;
            map[i][j] = temp;
        }
    }
}

void copyArray(int origin[8][8], int target[8][8]) {
    for(int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            target[i][j] = origin[i][j];
        }
    }
}

void spreadVirus() {
    int count = 0;
    int tempArray[8][8];
    queue<pii> q;

    copyArray(map, tempArray);
    
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (tempArray[i][j] == 2) {
                q.push({i,j});
            }
        }

        while (!q.empty()) {
            pii cur = q.front();
            q.pop();

            for (int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;;

                if (tempArray[nx][ny] == 0) {
                    tempArray[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (tempArray[i][j] == 0) count++;
        }
        answer = max(count, answer);
    }
}

void makeWall(int wallCount) {
    if (wallCount == 3) {
        spreadVirus();
        return;
    }

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                makeWall(wallCount + 1);
                map[i][j] = 0;
            }
        }
    }
}

void setSystem() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void printAnswer() {
    cout << answer;
}

int main() {
    setSystem();
    makeInput();
    makeWall(0);
    printAnswer();
    return 0;
}
