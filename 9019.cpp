#include <iostream>
#include <queue>
#include <string>
#include <cstring>

#define MAX_N 10000

using namespace std;

int T;

bool visited[MAX_N] = {false,};

void BFS() {
    queue<pair<int, string>> q;

    int orgin, temp;
    cin >> orgin >> temp;

    q.push({orgin, ""});
    visited[orgin] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == temp) {
            cout << cur.second << endl;
            break;
        }

        int d = (cur.first * 2) % 10000;
        int s = cur.first - 1 < 0 ? 9999 : cur.first - 1;
        int l = (cur.first % 1000) * 10 + (cur.first / 1000);
        int r = (cur.first % 10) * 1000 + (cur.first / 10);

        if (!visited[d]) {
            visited[d] = true;
            q.push({d, cur.second + "D"});
        }
        if (!visited[s]) {   
            visited[s] = true;
            q.push({s, cur.second + "S"});
        }
        if (!visited[l]) {
            visited[l] = true;
            q.push({l, cur.second + "L"});
        }
        if (!visited[r]) {
            visited[r] = true;
            q.push({r, cur.second + "R"});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i=0; i<T; i++) {
        memset(visited, false, sizeof(visited));
        BFS();
    }
    return 0;
}
