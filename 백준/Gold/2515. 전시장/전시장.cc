#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 300001

using namespace std;

int N, S;
int dp[MAX_N] = {0, };
vector<pair<int, int>> v;

int search_idx(int cur_idx) {
    int start = 0;
    int end = cur_idx - 1;

    int idx = -1;
    
    while (start <= end) {
        int mid = (start + end) / 2;

        if (v[cur_idx].first - v[mid].first >= S) {
            idx = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i=0; i<N; i++) {
        int H, C;
        cin >> H >> C;
        v.push_back({H, C});
    }

    // Sorting - NlogN
    sort(v.begin(), v.end());

    // O(N^2)
    for (int i=0; i<v.size(); i++) {

        if (i==0) {
            dp[i] = v[i].second;    
            continue;
        }

        int highest = search_idx(i);

        if (highest != -1) {
            dp[i] = max(dp[i-1], dp[highest] + v[i].second);
        } else {
            dp[i] = max(dp[i-1], v[i].second);
        }
    }

    cout << dp[v.size()-1] << '\n';

    return 0;
}