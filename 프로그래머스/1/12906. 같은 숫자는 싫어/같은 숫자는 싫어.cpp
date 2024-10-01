#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    stack<int> s;
    
    for (auto a: arr) {
        if (s.empty()) {
            s.push(a);
            continue;
        }
        
        if (s.top() != a) s.push(a);
    }
    
    stack<int> s2;
    
    while (!s.empty()) {
        s2.push(s.top());
        s.pop();
    }
    
    while (!s2.empty()) {
        answer.push_back(s2.top());
        s2.pop();
    }
    
    return answer;
}