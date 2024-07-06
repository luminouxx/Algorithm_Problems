#include<iostream>

using namespace std;
#define MAX_N 51

int parent[MAX_N] = {0,};
int party[MAX_N][MAX_N] = {0,};

int N, M;

int findParent(int x) {
    if (x != parent[x]) {
        return findParent(parent[x]);
    } else {
        return x;
    }
    return 0;
}

void unionTwo(int x, int y) {
    int pX = findParent(x);
    int pY = findParent(y);

    if (pX < pY) {
        parent[pY] = parent[pX];
    } else if (pX > pY) {
        parent[pX] = parent[pY];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        parent[i] = i;
    }

    int TotalCountWhoKnowTruth;
    cin >> TotalCountWhoKnowTruth;

    for (int j=0; j<TotalCountWhoKnowTruth; j++) {
        int whoKnowTruth;
        cin >> whoKnowTruth;
        parent[whoKnowTruth] = 0;
    }

    int partySize[MAX_N] = {0,};

    for (int k=1; k<=M; k++) {
        int numOfPeople;
        cin >> numOfPeople;
        partySize[k] = numOfPeople;

        int firstMan;
        cin >> firstMan;
        party[k][1] = firstMan;

        for (int l=2; l<=numOfPeople; l++) {
            int man;
            cin >> man;
            party[k][l] = man;
            unionTwo(firstMan, man);
        }
    }

    int answer = M;

    for (int a=1; a<=M; a++) {
        int pS = partySize[a];
        for (int b=1; b<=pS; b++) {
            if (findParent(party[a][b]) == 0) {
                answer--;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}