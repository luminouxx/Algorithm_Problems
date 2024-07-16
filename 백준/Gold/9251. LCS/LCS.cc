#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 1001

int dp[MAX_N][MAX_N] = {0,};

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    for (int i=1; i<=a.length(); i++) {
        for (int j=1; j<=b.length(); j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int x = a.length();
    int y = b.length();

    cout << dp[x][y];

    return 0;
}