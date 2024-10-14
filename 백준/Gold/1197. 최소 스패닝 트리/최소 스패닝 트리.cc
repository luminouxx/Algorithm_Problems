#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_V 10001

int V, E;
int parent[MAX_V];

// 부모 찾기
int findParent(int x) {
    if (parent[x] == x) return x;
    else return findParent(parent[x]);
}

// 부모 합치기
void uni(int x, int y) {
    int p_x = findParent(x);
    int p_y = findParent(y);

    parent[p_y] = p_x;
}

// 같은 부모인지 판별
bool isSameParent(int x, int y) {
    return findParent(x) == findParent(y);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    vector<pair<int, pair<int, int>>> v;

    for (int i=0; i<E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back({cost, {from, to}});
    }

    // 1. 노드 부모 자기 자신으로 초기화
    for (int i=1; i<=V; i++) { parent[i] = i; }

    // 2. cost 기준 오름차순 정렬
    sort(v.begin(), v.end());

    // 3. 전체 간선 탐색
    int answer = 0;
    int edgeCount = 0;
    for (int i=0; i<v.size(); i++) {
        int from = v[i].second.first;
        int to = v[i].second.second;
        int cost = v[i].first;

        if (!isSameParent(from, to)) {
            uni(from, to);
            answer += cost;
            edgeCount++;
        }

        if (edgeCount == V-1) break;
    }

    cout << answer << endl;

    return 0;
}