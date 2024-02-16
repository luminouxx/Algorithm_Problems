#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

#define MAX_N 32

int cal_dist(string a, string b) {

    int count = 0;

    for (int i=0; i<4; i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }
        
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        int ans = INT_MAX;
        int N;
        cin >> N;

        vector<string> v;

        for (int j=0; j<N; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        if (N > MAX_N) {
            cout << "0\n";
        } else {
            for (int i=0; i<v.size()-2; i++) {
                for (int j=i+1; j<v.size()-1; j++) {
                    for (int k=j+1; k<v.size(); k++) {
                        int dist_one = cal_dist(v[i], v[j]);
                        int dist_two = cal_dist(v[j], v[k]);
                        int dist_three = cal_dist(v[i], v[k]);
                        
                        int sum = dist_one + dist_two + dist_three;
                        ans = min(ans, sum);
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
