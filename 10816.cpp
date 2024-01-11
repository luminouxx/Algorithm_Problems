#include <iostream>
#include <map>

using namespace std;

int N,M;

map<int, int> m;

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
        m[temp]++;
    }
}

void getOutput() {
    cin >> M;
    for (int i=0; i<M; i++) {
        int temp;
        cin >> temp;
        cout << m[temp] << ' ';
    }
}

int main() {
    setSystem();
    setInput();
    getOutput();
    return 0;
}
