#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int result = 0;
priority_queue<int, vector<int>, greater<int>> q;

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> N;

    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        q.push(temp);
    }
}

void solve() {
    while(q.size() != 1) {
        int cur_one = q.top();
        q.pop();
        int cur_two = q.top();
        q.pop();

        int cur_sum = cur_one + cur_two;
        result += cur_sum;
        q.push(cur_sum);
    }
    cout << result;
}

int main() {
    setSystem();
    setInput();
    solve();
    return 0;
}
