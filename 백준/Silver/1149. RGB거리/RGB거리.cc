#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1001

int N;

int dp[MAX_N][3] = {0, };

int main() {
    cin >> N;

    for (int i=1; i<=N; i++) {
        int R, G, B;
        cin >> R >> G >> B;

        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + R;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + G;
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + B;
    }

    cout << min(dp[N][0],min(dp[N][1], dp[N][2]));
    
    return 0;
}