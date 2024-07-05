#include<iostream>
#include<algorithm>

using namespace std;

#define MAX_N 301

int N;

int dp[MAX_N] = {0,};
int s[MAX_N] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=1; i<=N; i++) {
        cin >> s[i];
    }

    dp[1] = s[1];
    dp[2] = s[1] + s[2];

    for (int j=3; j<=N; j++) {
        dp[j] = max(dp[j-2] + s[j], dp[j-3] + s[j] + s[j-1]);
    }
    cout << dp[N];

    return 0;
}
