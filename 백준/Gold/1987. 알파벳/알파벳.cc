#include<iostream>
#include<algorithm>

using namespace std;

#define MAX_N 21

int R, C;

char board[MAX_N][MAX_N];
bool alphabet[26] = { false, };

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int answer = 0;

void DFS(int x, int y, int depth) {

    answer = max(answer, depth);
    alphabet[board[x][y] - 65] = true;
    
    for (int i=0; i<4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 0 && next_x < C && next_y >= 0 && next_y < R) {
            char next_alphabet = board[next_x][next_y];
            if (!alphabet[next_alphabet-65]) {
                DFS(next_x, next_y, depth+1);        
            }
        }
    }
    alphabet[board[x][y] - 65] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            char temp;
            cin >> temp;
            board[j][i] = temp;
        }
    }

    DFS(0, 0, 1);
    
    cout << answer;

    return 0;
}