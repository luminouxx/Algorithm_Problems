#include <iostream>

using namespace std;

int N, answer;
int arr[15];

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {
    cin >> N;
}

bool checkIsPossible(int n, int m) {
    for (int i=0; i<n; i++) {
        int x = i;
        int y = arr[i];
        int cur_x = n;
        int cur_y = m;
        
        if (abs(x-cur_x) == abs(y-cur_y) || y == cur_y) {
            return false;
        }
    }
    return true;
}

void n_queen(int n) {
    if (n == N) {
        answer++;
        return;
    }

    for (int i=0; i<N; i++) {
        if (checkIsPossible(n, i)) {
            arr[n] = i;
            n_queen(n+1);
        }
    }
}

void getOutput() {
    cout << answer;
}

void solve() {
    n_queen(0);
    getOutput();
}

int main() {
    setSystem();
    setInput();
    solve();
    return 0;
}