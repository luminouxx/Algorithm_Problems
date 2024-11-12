#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 502

int dp[MAX_N][MAX_N] = {0, };
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            int temp;
            cin >> temp;
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + temp;
        }
    }

    int answer = 0;

    for (int k=1; k<=n; k++) {
        answer = max(answer, dp[n][k]);
    }

    cout << answer;

    return 0;
}