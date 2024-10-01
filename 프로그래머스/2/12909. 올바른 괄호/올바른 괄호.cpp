#include<string>
#include <iostream>

#include <stack>

using namespace std;

bool solution(string s) {
    
    if (s[0] == ')') return false;
    if (s[s.size()-1] == '(') return false;
    
    stack<char> st;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') st.push('(');
        else if (s[i] == ')' && !st.empty()) st.pop();
    }

    return st.empty();
}