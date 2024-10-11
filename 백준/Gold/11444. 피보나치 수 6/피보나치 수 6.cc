#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

#define MOD 1000000007

matrix operator*(matrix &a,  matrix &b) {

    matrix temp(2, vector<long long>(2));
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= MOD;
        }
    }

    return temp;
}

matrix answer = {{1, 0}, {1, 0}};
matrix m = {{1, 1}, {1, 0}};

// 무조건 2분이지 않을까?
long long n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (n > 0) {
        if (n%2 == 1) {
            answer = answer * m;
        }

        m = m * m;
        n /= 2;
    }

    cout << answer[0][1];
    
    return 0;
}