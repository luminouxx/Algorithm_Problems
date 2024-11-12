#include <iostream>

using namespace std;

int A, B, C;

long long divide(long long b) {
    if (b==0) return 1;
    if (b==1) return A%C;
    if (b%2 == 0) return divide(b/2)%C * divide(b/2)%C;
    return  divide(b/2)%C * divide(b/2)%C * A%C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    cout << divide(B);

    return 0;
}