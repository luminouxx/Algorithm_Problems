#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;

// 연산자 우선순위를 결정하는 함수
int priority(char c) {
    if (c == '(') return 0;
    else if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else return 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    for (int i=0; i<str.length(); i++) {
        char cur = str[i];
        
        if (cur == '(') {                                                   // 1. '(' : Stack에 PUSH               
            s.push('(');
        } else if (cur == ')') {                                            // 2. ')' : '(' 을 만날 때까지 POP
            while (s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
        } else if (cur == '-' || cur == '+' || cur == '*' || cur == '/') {  // 3. 새로운 연산자의 우선순위 <= 스택 탑의 우선순위 : 스택 탑 POP
            while (!s.empty() && priority(cur) <= priority(s.top())) {      // 그 후, Stack에 새로운 연산자 저장
                cout << s.top();
                s.pop();
            }
            s.push(cur);    
        } else {                                                            // 4. 그 외(A..Z) : 바로 출력
            cout << cur;
        }
    }

    while (!s.empty()) {                                                    // 5. Stack이 빌때 까지 POP
        cout << s.top();
        s.pop();
    }
    
    return 0;
}
