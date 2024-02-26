#include <iostream>
#include <vector>

#define MAX_N 10001

using namespace std;

// 노드 간의 관계 저장하기 위한 Vector
vector<pair<int, int>> v[MAX_N];

// 방문 여부 체크를 위한 배열 : false로 초기화
bool visited[MAX_N] = {false, };

// 최대 거리 저장용 변수
int max_dist = 0;

// 지름의 시작 노드 저장
int start_v;

// 노드의 개수
int N;

// DFS 함수 
// @param node: 현재 방문 노드
// @param dist: 현재까지 누적거리
void DFS(int node, int dist) {
    int cur = node;
    int cur_dist = dist;

    // 1. 현재까지 누적거리 > 최대거리 : 업데이트
    if (max_dist < cur_dist) {
        max_dist = cur_dist;
        start_v = node;
    }

    // 2. 벡터에 저장된 노드 간의 관계 전부 탐색
    for(int i=0; i<v[cur].size(); i++) {
        int next = v[cur][i].first;
        int next_dist = dist + v[cur][i].second;

        // 3. 다음 노드가 방문한 노드가 아니라면
        if (!visited[next]) {
            visited[next] = true; // 방문처리
            DFS(next, next_dist); // DFS함수 호출
        }
    }
}

// 인풋을 받는 함수
void setInput() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int start, end, weight;

    for(int i=0; i<N-1; i++) {
        cin >> start >> end >> weight;
        // 양방향 간선
        v[start].push_back({end, weight});
        v[end].push_back({start, weight});
    }
}

// 메인 알고리즘
void solve() {

    visited[1] = true;

    DFS(1, 0);

    for (int i=1; i<=N; i++) { visited[i] = false; }

    max_dist = 0;

    visited[start_v] = true;

    DFS(start_v, 0);
}

void getOutput() {
    cout << max_dist << endl;
}


int main() {
    setInput();

    solve();

    getOutput();
    
    return 0;
}
