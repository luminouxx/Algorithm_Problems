#include <iostream>

using namespace std;

#define MAX_N 1000001

int N, M;
bool brokenBtn[10] = { false, };

void setSystem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void setInput() {           // Input
    cin >> N >> M;
    
    for (int i=0; i<M; i++) {
        int temp;
        cin >> temp;
        brokenBtn[temp] = true;
    }
}

// 해당 숫자가 만들어질 수 있는 숫자인가?
bool checkValidation(int n) {                   

    if (n == 0) return !brokenBtn[0];           // 0을 누를 수 없는 경우 체크

    while (n) {                                 
        if (brokenBtn[n % 10] == true) return false;
        n /= 10;
    }
    return true;
}

// 채널을 조정한 후, 최소값 찾기
int adjustChannel() {                           

    int minimum = MAX_N;

    for (int i=0; i<MAX_N; i++) {               // 0 ..< 10000001까지의 일련의 수 탐색
        if (checkValidation(i)) {               // i에 고장난 숫자가 포함됐는지 판단
            int count = to_string(i).length();  // 자리수 == 버튼을 누르는 횟수 ex) 132 => 3번  
            count += abs(N-i);                  // +,- 버튼을 누르는 횟수  
            minimum = min(count, minimum);      // 최소값 갱신
        }
    }
    
    return minimum;                             // 전체 탐색이 끝난 후, 최소값 반환
}

// 그냥 +,- 버튼으로만 만들 수 있는 값 반환
int justPlusMinus() {                           
    return abs(N-100);
}

void solve() {
    int answer = min(justPlusMinus(), adjustChannel());
    cout << answer;
}

int main() {
    setSystem();
    setInput();
    solve();
    return 0;
}
