#include<iostream>
#include<algorithm>

using namespace std;

#define WEIGHT_MAX 100001
#define ITEM_MAX 1001

int dp[ITEM_MAX][WEIGHT_MAX] = { 0, };
int weight[ITEM_MAX] = {0, };
int value[ITEM_MAX] = {0, };

int N, K;

void DP() {
    for (int j=1; j<=K; j++) {
        for (int i=1; i<=N; i++) {
            if (weight[i] <= j) { // 물건을 넣을 수 있는 경우
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i=1; i<=N; i++) {
        cin >> weight[i] >> value[i];
    }

    DP();

    cout << dp[N][K];

    return 0;
}
