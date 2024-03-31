#include <iostream>

#define MAX_N 10000

using namespace std;

int node[MAX_N];

void postfix(int start, int end) {

    if (start > end) return;

    if (start == end) {
        cout << node[start] << endl;
        return;
    }

    int part_idx = start+1;

    for (int i=start+1; i<=end; i++) {
        if (node[i] > node[start]) {
            part_idx = i;
            break;
        }
    }

    postfix(start+1, part_idx-1);
    postfix(part_idx, end);

    cout << node[start] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int idx = 0;

    while (cin >> n) {
        node[idx] = n;
        idx++;
    }

    postfix(0, idx-1);

    return 0;
}
