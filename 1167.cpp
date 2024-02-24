#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_N 100001

vector<pair<int, int>> v[MAX_N];
bool visited[MAX_N] = {false, };

int max_dist = 0;
int start_v = 0;

// DFS 함수
// @param 
// int node : 현재 방문 노드 번호
// @param 
// int dist : 현재 방문 노드까지의 누적 거리
void DFS(int node, int dist) {

    int cur = node;
    int cur_dist = dist;

    // 1. 현재까지의 누적거리 > 지금까지의 최장거리 = 업데이트
    if (cur_dist > max_dist) {
        max_dist = cur_dist;
        start_v = cur; 
    }

    // 2. 방문할 수 있는 모든 노드 탐색
    for (int i=0; i<v[node].size(); i++) {
        int next = v[node][i].first;
        int next_dist = v[node][i].second + dist;

        // 3. 방문하지 않은 노드일 경우
        // + 방문 처리할 것
        // + DFS함수 호출
        if (!visited[next]) {
            visited[next] = true;
            DFS(next, next_dist);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;

    // 0. 인풋을 받습니다. 설명은 생략합니다.
    for (int i=0; i<V; i++) {
        int cur_v;
        cin >> cur_v;

        int target_v, weight;

        while (true) {
            cin >> target_v;
            if (target_v == -1) break;
            cin >> weight;
            v[cur_v].push_back({target_v, weight});
        }
    }

    // 1. 임의의 노드를 방문처리 : 여기서는 1번노드에서 출발
    visited[1] = true;

    // 2. 1번 노드에서부터 DFS 출발
    DFS(1, 0);

    // 3. 첫번째 탐색 후 최장 거리 (max_dist 초기화) & visited 배열 초기화
    max_dist = 0;

    for (int j=1; j<=V; j++) { visited[j] = false; }

    // 4. 찾은 지름의 출발 V에서 DFS함수 호출
    visited[start_v] = true;

    DFS(start_v, 0);

    // 5. 두번째 DFS 이후 찾은 최장거리 = 정답
    cout << max_dist << endl;

    return 0;
}
