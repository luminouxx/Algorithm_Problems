#include <iostream>
#include <set>

using namespace std;

int T ,k;

multiset<int> ms;

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void insert(int n) {
    ms.insert(n);
}

void deleteMin() {
    if (!ms.empty()) {
        ms.erase(ms.begin());
    }
}

void deleteMax() {
    if (!ms.empty()) {
        auto iter = ms.end();
        iter--;
        ms.erase(iter);
    }
}

void solve() {
    cin >> T;

    for (int i=0; i<T; i++) {
        
        cin >> k;

        for (int j=0; j<k; j++) {
            char op;
            int num;
            cin >> op >> num;

            switch (op) {
            case 'I':
                insert(num); 
                break;
            case 'D':
                if (num == 1) {
                    deleteMax();
                } else if (num == -1) {
                    deleteMin();
                }
                break;
            default:
                break;
            }
        }

        if (ms.empty()) {
            cout << "EMPTY" << endl;
        } else {
            auto iter = ms.end();
            iter--;
            cout << *iter << ' ' << *ms.begin() << endl;
        }

        ms.clear();
    }
}

int main() {
    setSystem();
    solve();
    return 0;
}
